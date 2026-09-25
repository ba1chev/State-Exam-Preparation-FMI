#pragma once
#include <iostream>
#include <stdexcept>

enum class CardColor {
    Red, Green, Blue, Yellow
};

enum class CardType {
    DigitCard, SpecialCard, DebitCard
};

class Card {
protected:
    CardColor color = CardColor::Blue;
public:
    Card(CardColor color): color(color) {}

    CardColor getColor() const { return this->color; }
    virtual void printCard() const = 0;
    virtual ~Card() = default;
    virtual Card* clone() const = 0;
    virtual CardType getType() const = 0;
};