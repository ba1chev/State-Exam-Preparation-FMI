#include "exercise_05_library.h"
#include <stdexcept>

void Library::addArchive(const Archive& archive) {
    this->archives.push_back(archive);
}

void Library::removeArchiveBy(const std::string& name) {
    for (size_t i = 0; i < this->archives.size(); i++) {
        if (this->archives[i].getName() == name) {
            std::swap(this->archives[i],
                this->archives[this->archives.size() - 1]);
            this->archives.pop_back();
            break;
        }
    }
}

void Library::moveBookBetween(const std::string& fromName,
    const std::string& toName, const size_t id) {
    Archive& from = this->searchArchiveBy(fromName);
    Archive& to = this->searchArchiveBy(toName);

    Book book = from.searchBookBy(id);
    to.addBook(book);
    from.removeBookBy(id);
}

Archive& Library::searchArchiveBy(const std::string& name) {
    for (size_t i = 0; i < this->archives.size(); i++) {
        if (this->archives[i].getName() == name) {
            return this->archives[i];
        }
    }

    throw std::runtime_error("Archive with the given name was not found!");
}

void Library::addLibrarian(const Librarian& librarian) {
    this->librarians.push_back(librarian);
}

Librarian& Library::searchLibrarianBy(const size_t employeeNumber) {
    for (size_t i = 0; i < this->librarians.size(); i++) {
        if (this->librarians[i].getEmployeeNumber() == employeeNumber) {
            return this->librarians[i];
        }
    }

    throw std::runtime_error("Librarian with the given number was not found!");
}

void Library::printAllLibrarians() const {
    for (size_t i = 0; i < this->librarians.size(); i++) {
        this->librarians[i].printWatchedArchives();
    }
}

void Library::addReader(const Reader& reader) {
    this->readers.push_back(reader);
}

Reader& Library::searchReaderBy(const size_t cardNumber) {
    for (size_t i = 0; i < this->readers.size(); i++) {
        if (this->readers[i].getCardNumber() == cardNumber) {
            return this->readers[i];
        }
    }

    throw std::runtime_error("Reader with the given card number was not found!");
}

void Library::printAllReaders() const {
    for (size_t i = 0; i < this->readers.size(); i++) {
        this->readers[i].printBorrowedBooks();
    }
}

void Library::printLibrary() const {
    std::cout << "===== Library =====" << std::endl;

    std::cout << "----- Archives -----" << std::endl;
    for (size_t i = 0; i < this->archives.size(); i++) {
        std::cout << "[Archive]:     "
            << this->archives[i].getName() << std::endl;
        this->archives[i].printAllBooks();
    }

    std::cout << "----- Librarians -----" << std::endl;
    this->printAllLibrarians();

    std::cout << "----- Readers -----" << std::endl;
    this->printAllReaders();
}
