#include "exercise_02_debit_card.h"

DebitCard::DebitCard(Debit debit, CardColor color): Card(color) {
    this->debit = debit;
}

Debit DebitCard::getDebit() const {
    return this->debit;
}

void DebitCard::printCard() const {
    std::cout << "[Debit]:  ";
    switch (this->debit) {
        case Debit::Four: {
            std::cout << "four" << std::endl;
            break;
        }
        case Debit::Six: {
            std::cout << "six" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupported debit");
        }
    }
    std::cout << "[Color]:  ";
    switch (this->color) {
        case CardColor::Blue: {
            std::cout << "blue" << std::endl;
            break;
        }
        case CardColor::Red: {
            std::cout << "red" << std::endl;
            break;
        }
        case CardColor::Green: {
            std::cout << "green" << std::endl;
            break;
        }
        case CardColor::Yellow: {
            std::cout << "yellow" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Not supported color of card");
        }
    }
}

Card* DebitCard::clone() const {
    return new DebitCard(*this);
}

CardType DebitCard::getType() const {
    return CardType::DebitCard;
}