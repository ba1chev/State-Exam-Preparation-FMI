#pragma once
#include <vector>
#include <string>
#include "exercise_05_book.h"

class Archive {
private:
    std::vector<Book> books;
    std::string name = "";

public:
    Archive() = default;
    Archive(const std::string& name);

    void addBook(const Book& book);
    void removeBookBy(const size_t id);

    void borrowBook(const size_t id);
    void returnBook(const size_t id);

    void printAllBooks() const;
    const Book& searchBookBy(const size_t id) const;

    const std::string& getName() const;
};