#include "exercise_05_book.h"

size_t Book::idMask = 0;

Book::Book(const std::string& name, const std::string& author,
    const size_t releaseYear) {
    this->name = name;
    this->author = author;
    this->releaseYear = releaseYear;
    this->id = idMask;
    this->isBorrowed = false;
    idMask += 1;
}

void Book::borrowBook() {
    this->isBorrowed = true;
}

void Book::returnBook() {
    this->isBorrowed = false;
}

void Book::printBook() const {
    std::cout << "[Name]:        " << this->name << std::endl;
    std::cout << "[Author]:      " << this->author << std::endl;
    std::cout << "[ReleaseYear]: " << this->releaseYear << std::endl;
    std::cout << "[Id]:          " << this->id << std::endl;
    std::cout << "[Status]:      "
        << (this->isBorrowed ? "borrowed" : "available") << std::endl;
}

size_t Book::getId() const {
    return this->id;
}
