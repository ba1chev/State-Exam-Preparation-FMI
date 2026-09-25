#include "exercise_05_archive.h"
#include <stdexcept>

Archive::Archive(const std::string& name) {
    this->name = name;
}

void Archive::addBook(const Book& book) {
    this->books.push_back(book);
}

void Archive::removeBookBy(const size_t id) {
    int foundIndex = -1;
    for (size_t i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        std::swap(this->books[foundIndex], this->books[this->books.size() - 1]);
        this->books.pop_back();
    }
}

void Archive::borrowBook(const size_t id) {
    for (size_t i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == id) {
            this->books[i].borrowBook();
            break;
        }
    }
}

void Archive::returnBook(const size_t id) {
    for (size_t i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == id) {
            this->books[i].returnBook();
            break;
        }
    }
}

void Archive::printAllBooks() const {
    for (size_t i = 0; i < this->books.size(); i++) {
        this->books[i].printBook();
    }
    std::cout << std::endl;
}

const Book& Archive::searchBookBy(const size_t id) const {
    for (size_t i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == id) {
            return this->books[i];
        }
    }

    throw std::runtime_error("Book with the given id was not found!");
}

const std::string& Archive::getName() const {
    return this->name;
}