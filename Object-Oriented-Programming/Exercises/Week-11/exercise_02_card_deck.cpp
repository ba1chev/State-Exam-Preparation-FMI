#include "exercise_02_card_deck.h"
#include <cstdlib>

Card* CardDeck::generateRandomCard() {
    CardColor color = (CardColor)(std::rand() % 4);
    switch (std::rand() % 3) {
        case 0: {
            return new DigitCard(std::rand() % 10, color);
        }
        case 1: {
            return new SpecialCard((SpecialMove)(std::rand() % 2), color);
        }
        default: {
            return new DebitCard((Debit)(std::rand() % 2), color);
        }
    }
}

void CardDeck::free() {
    for (size_t i = 0; i < this->size; i++) {
        delete this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

void CardDeck::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    this->capacity = newCapacity;
    Card** newData = new Card* [this->capacity]{nullptr};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = newData;
}

void CardDeck::copyFrom(const CardDeck& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new Card* [this->capacity]{nullptr};
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i]->clone();
    }
}

void CardDeck::moveTo(CardDeck&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

CardDeck::CardDeck() {
    this->size = 0;
    this->capacity = 8;
    this->data = new Card* [this->capacity]{nullptr};
}

CardDeck::CardDeck(const CardDeck& other) {
    this->copyFrom(other);
}

CardDeck::CardDeck(CardDeck&& other) noexcept {
    this->moveTo(std::move(other));
}

CardDeck& CardDeck::operator = (const CardDeck& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

CardDeck& CardDeck::operator = (CardDeck&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

CardDeck::~CardDeck() {
    this->free();
}

void CardDeck::addCard() {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = generateRandomCard();
    this->size += 1;
}

void CardDeck::removeCard(const DigitCard& card) {
    if (!this->size) {
        throw std::runtime_error("The deck is empty");
    }

    int indexFound = -1;
    for (size_t i = 0; i < this->size; i++) {
        bool currentStatement = this->data[i]->getColor() == card.getColor();
        if ((this->data[i]->getType() == CardType::DigitCard) &&
            ((const DigitCard*)this->data[i])->getNumber() == card.getNumber()) {
            currentStatement = true;
        }
        if (currentStatement) {
            indexFound = i;
            break;
        }
    }

    if (indexFound != -1) {
        delete this->data[indexFound];
        for (size_t i = indexFound; i < this->size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->data[this->size - 1] = nullptr;
        this->size -= 1;
    } else {
        this->addCard();
    }
}

void CardDeck::printDeck() const {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i]->printCard();
    }
}