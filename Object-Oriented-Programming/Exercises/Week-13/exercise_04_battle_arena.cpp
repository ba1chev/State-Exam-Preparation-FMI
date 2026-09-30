#include "exercise_04_battle_arena.h"
#include "exercise_04_out_of_mana_exception.h"
#include "exercise_04_dead_character_exception.h"
#include <stdexcept>

BattleArena::BattleArena(Character* first, Character* second) {
    if (!first || !second) {
        throw std::runtime_error("Nullptr detected");
    }
    this->first = first;
    this->second = second;
}

void BattleArena::attackWith(Character& attacker, Character& defender) {
    if (attacker.isDead()) {
        return;
    }
    if (attacker.isStunned()) {
        std::cout << attacker.getName() << " is stunned and skips the turn" << std::endl;
        attacker.setStunned(false);
        return;
    }
    attacker.attack(defender);
}

void BattleArena::runRound() {
    this->tickEffects();

    try {
        this->attackWith(*this->first, *this->second);
    } catch (const OutOfManaException& e) {
        std::cout << e.what() << std::endl;
        this->first->rest();
    } catch (const DeadCharacterException& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    try {
        this->attackWith(*this->second, *this->first);
    } catch (const OutOfManaException& e) {
        std::cout << e.what() << std::endl;
        this->second->rest();
    } catch (const DeadCharacterException& e) {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << this->first->statusLine() << std::endl;
    std::cout << this->second->statusLine() << std::endl;
}

void BattleArena::tickEffects() {
    this->first->tickEffects();
    this->second->tickEffects();
}

bool BattleArena::isOver() const {
    return this->first->isDead() || this->second->isDead();
}

void BattleArena::addEffect(int characterIndex, StatusEffect* effect) {
    if (!effect) {
        throw std::runtime_error("Nullptr detected");
    }
    if (characterIndex == 0) {
        this->first->addEffect(effect);
    } else if (characterIndex == 1) {
        this->second->addEffect(effect);
    } else {
        throw std::runtime_error("Invalid input data");
    }
}