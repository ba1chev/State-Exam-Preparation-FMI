#include "exercise_05_reader.h"

Reader::Reader(const std::string& name, const size_t cardNumber) {
    this->name = name;
    this->cardNumber = cardNumber;
}

void Reader::borrowBook(const Book& book) {
    this->borrowedBooks.push_back(book);
}

void Reader::returnBook(const size_t id) {
    for (size_t i = 0; i < this->borrowedBooks.size(); i++) {
        if (this->borrowedBooks[i].getId() == id) {
            std::swap(this->borrowedBooks[i],
                this->borrowedBooks[this->borrowedBooks.size() - 1]);
            this->borrowedBooks.pop_back();
            break;
        }
    }
}

void Reader::printBorrowedBooks() const {
    std::cout << "[Reader]:      " << this->name << std::endl;
    std::cout << "[CardNumber]:  " << this->cardNumber << std::endl;
    for (size_t i = 0; i < this->borrowedBooks.size(); i++) {
        this->borrowedBooks[i].printBook();
    }
    std::cout << std::endl;
}

bool Reader::hasBook(const size_t id) const {
    for (size_t i = 0; i < this->borrowedBooks.size(); i++) {
        if (this->borrowedBooks[i].getId() == id) {
            return true;
        }
    }

    return false;
}

size_t Reader::getCardNumber() const {
    return this->cardNumber;
}

const std::string& Reader::getName() const {
    return this->name;
}
