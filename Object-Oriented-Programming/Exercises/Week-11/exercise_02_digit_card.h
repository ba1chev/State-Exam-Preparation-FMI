#pragma once
#include <iostream>
#include "exercise_02_card.h"

class DigitCard: public Card {
private:
    uint8_t number = 0;
public:
    DigitCard(const uint8_t number, CardColor color);
    
    void printCard() const override;
    uint8_t getNumber() const;
    Card* clone() const override;
    CardType getType() const override;
};