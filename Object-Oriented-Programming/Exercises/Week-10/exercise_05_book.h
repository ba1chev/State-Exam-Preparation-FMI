#pragma once
#include <string>
#include <iostream>

class Book {
private:
    std::string name = "";
    std::string author = "";
    size_t releaseYear = 2004;
    bool isBorrowed = false;
    
    size_t id = 0;
    static size_t idMask;

public:
    Book() = default;
    Book(const std::string& name, const std::string& author,
        const size_t releaseYear);

    void borrowBook();
    void returnBook();

    size_t getId() const;
    void printBook() const;
};