#include "exercise_02_special_card.h"

SpecialCard::SpecialCard(SpecialMove move, CardColor color): Card(color) {
    this->move = move;
}

void SpecialCard::printCard() const {
    std::cout << "[SpecialMove]:  ";
    switch (this->move) {
        case SpecialMove::Reverse: {
            std::cout << "reverse" << std::endl;
            break;
        }
        case SpecialMove::Skip: {
            std::cout << "skip" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupported special move");
        }
    }

    std::cout << "[Color]:        ";
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

SpecialMove SpecialCard::getMove() const {
    return this->move;
}

Card* SpecialCard::clone() const {
    return new SpecialCard(*this);
}

CardType SpecialCard::getType() const {
    return CardType::SpecialCard;
}