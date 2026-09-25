#pragma once
#include "exercise_02_card.h"

enum class Debit {
    Four, Six
};

class DebitCard: public Card {
    Debit debit = Debit::Four;

public:
    DebitCard(Debit debit, CardColor color);

    Debit getDebit() const;
    void printCard() const override;
    Card* clone() const override;
    CardType getType() const override;
};