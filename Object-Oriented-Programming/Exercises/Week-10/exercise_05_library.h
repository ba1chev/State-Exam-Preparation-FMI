#pragma once
#include <vector>
#include <string>
#include "exercise_05_archive.h"
#include "exercise_05_librarian.h"
#include "exercise_05_reader.h"

class Library {
private:
    std::vector<Archive> archives;
    std::vector<Librarian> librarians;
    std::vector<Reader> readers;

public:
    Library() = default;

    void addArchive(const Archive& archive);
    void removeArchiveBy(const std::string& name);
    void moveBookBetween(const std::string& fromName,
        const std::string& toName, const size_t id);

    Archive& searchArchiveBy(const std::string& name);

    void addLibrarian(const Librarian& librarian);
    Librarian& searchLibrarianBy(const size_t employeeNumber);
    void printAllLibrarians() const;

    void addReader(const Reader& reader);
    Reader& searchReaderBy(const size_t cardNumber);
    void printAllReaders() const;

    void printLibrary() const;
};
