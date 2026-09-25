#pragma once
#include <vector>
#include <string>
#include "exercise_05_book.h"

class Reader {
private:
    std::string name = "";
    size_t cardNumber = 0;
    std::vector<Book> borrowedBooks;

public:
    Reader() = default;
    Reader(const std::string& name, const size_t cardNumber);

    void borrowBook(const Book& book);
    void returnBook(const size_t id);

    void printBorrowedBooks() const;
    bool hasBook(const size_t id) const;

    size_t getCardNumber() const;
    const std::string& getName() const;
};
