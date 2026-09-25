#pragma once
#include "exercise_02_card.h"

enum class SpecialMove {
    Skip, Reverse
};  

class SpecialCard: public Card {
private:
    SpecialMove move = SpecialMove::Skip;

public:
    SpecialCard(SpecialMove move, CardColor color);

    void printCard() const override;
    SpecialMove getMove() const;
    Card* clone() const override;
    CardType getType() const override;
};