#include "exercise_02_digit_card.h"

DigitCard::DigitCard(const uint8_t number, CardColor color): Card(color) {
    if (number > 9) {
        throw std::runtime_error("Invalid input data");
    }
    this->number = number;
}

void DigitCard::printCard() const {
    std::cout << "[Number]: " << (int)this->number << std::endl;
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

Card* DigitCard::clone() const {
    return new DigitCard(*this);
}

CardType DigitCard::getType() const {
    return CardType::DigitCard;
}

uint8_t DigitCard::getNumber() const {
    return this->number;
}