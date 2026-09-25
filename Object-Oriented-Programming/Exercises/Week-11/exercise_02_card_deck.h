#pragma once
#include <iostream>
#include "exercise_02_card.h"
#include "exercise_02_digit_card.h"
#include "exercise_02_debit_card.h"
#include "exercise_02_special_card.h"

class CardDeck {
private:
    Card** data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const CardDeck& other);
    void moveTo(CardDeck&& other) noexcept;

public:
    CardDeck();
    CardDeck(const CardDeck& other);
    CardDeck(CardDeck&& other) noexcept;
    CardDeck& operator = (const CardDeck& other);
    CardDeck& operator = (CardDeck&& other) noexcept;
    ~CardDeck();

    void addCard();
    void removeCard(const DigitCard& card);
    void printDeck() const;
};