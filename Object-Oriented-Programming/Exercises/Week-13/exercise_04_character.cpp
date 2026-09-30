#include "exercise_04_character.h"
#include "exercise_04_weapon.h"
#include "exercise_04_status_effect.h"
#include "exercise_04_dead_character_exception.h"
#include <stdexcept>

void Character::free() {
    delete[] this->name;
    this->name = nullptr;

    delete this->weapon;
    this->weapon = nullptr;

    for (size_t i = 0; i < this->effectsCount; i++) {
        delete this->effects[i];
    }
    delete[] this->effects;
    this->effects = nullptr;
    this->effectsCount = 0;
    this->effectsCapacity = 0;

    this->hp = 0;
    this->maxHp = 0;
}

void Character::copyFrom(const Character& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->stunned = other.stunned;
    this->damageReduction = other.damageReduction;

    this->weapon = nullptr;
    this->effects = nullptr;
    this->effectsCount = 0;
    this->effectsCapacity = 0;
}

void Character::moveTo(Character&& other) noexcept {
    this->name = other.name;
    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->weapon = other.weapon;
    this->effects = other.effects;
    this->effectsCount = other.effectsCount;
    this->effectsCapacity = other.effectsCapacity;
    this->stunned = other.stunned;
    this->damageReduction = other.damageReduction;

    other.name = nullptr;
    other.weapon = nullptr;
    other.effects = nullptr;
    other.effectsCount = 0;
    other.effectsCapacity = 0;
    other.hp = 0;
    other.maxHp = 0;
}

void Character::resize(size_t newCapacity) {
    StatusEffect** newEffects = new StatusEffect*[newCapacity]{};
    for (size_t i = 0; i < this->effectsCount; i++) {
        newEffects[i] = this->effects[i];
    }
    delete[] this->effects;
    this->effects = newEffects;
    this->effectsCapacity = newCapacity;
}

Character::Character(const char* name, const int maxHp, Weapon* weapon) {
    if (!name || maxHp < 0 || !weapon) {
        throw std::runtime_error("Invalid input data");
    }
    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->hp = maxHp;
    this->maxHp = maxHp;
    this->weapon = weapon;
}

Character::Character(const Character& other) {
    this->copyFrom(other);
}

Character::Character(Character&& other) noexcept {
    this->moveTo(std::move(other));
}

Character& Character::operator = (const Character& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Character& Character::operator = (Character&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Character::~Character() {
    this->free();
}

void Character::takeDamage(int amount) {
    if (this->isDead()) {
        throw DeadCharacterException(this->name);
    }

    int mitigated = this->defend(amount);
    mitigated -= this->damageReduction;
    if (mitigated < 0) {
        mitigated = 0;
    }
    this->damageReduction = 0;

    this->hp -= mitigated;
    if (this->hp < 0) {
        this->hp = 0;
    }
}

bool Character::isDead() const {
    return this->hp <= 0;
}

void Character::takeDirectDamage(int amount) {
    if (this->isDead()) {
        throw DeadCharacterException(this->name);
    }
    this->hp -= amount;
    if (this->hp < 0) {
        this->hp = 0;
    }
}

void Character::addEffect(StatusEffect* effect) {
    if (!effect) {
        throw std::runtime_error("Nullptr detected");
    }
    if (this->effectsCount == this->effectsCapacity) {
        this->resize(this->effectsCapacity == 0 ? 2 : this->effectsCapacity * 2);
    }
    this->effects[this->effectsCount++] = effect;
}

void Character::tickEffects() {
    for (size_t i = 0; i < this->effectsCount; i++) {
        this->effects[i]->tick(this);
    }

    size_t alive = 0;
    for (size_t i = 0; i < this->effectsCount; i++) {
        if (this->effects[i]->isExpired()) {
            delete this->effects[i];
        } else {
            this->effects[alive++] = this->effects[i];
        }
    }
    this->effectsCount = alive;
}

bool Character::isStunned() const {
    return this->stunned;
}

void Character::setStunned(bool value) {
    this->stunned = value;
}

void Character::addDamageReduction(int amount) {
    this->damageReduction += amount;
}

const char* Character::getName() const {
    return this->name;
}

std::string Character::statusLine() const {
    std::string line = std::string(this->name) + " [" + std::string(this->type())
        + "] HP: " + std::to_string(this->hp) + "/" + std::to_string(this->maxHp);

    for (size_t i = 0; i < this->effectsCount; i++) {
        line += " - " + std::string(this->effects[i]->label());
    }
    return line;
}