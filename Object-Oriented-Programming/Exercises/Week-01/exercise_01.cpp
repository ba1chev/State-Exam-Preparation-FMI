// Реализирайте система за управление на библиотека:

// Структура/клас Book със следните полета:
// title (низ с дължина най-много 64 символа)
// author (низ с дължина най-много 32 символа)
// publicationYear (int)
// status (enum: Available, Borrowed, Reserved)
// Структура/клас Library, която съдържа:
// name (низ с дължина най-много 32 символа)
// Масив от Book (максимум 10 книги)
// bookCount (брой налични книги)
// Функции:
// addBook(Library&, const char*, const char*, int) – добавя книга в библиотеката.
// borrowBook(Book&) – маркира книга като заета.
// reserveBook(Book&) – маркира книга като резервирана.
// printLibrary(const Library&) – извежда всички книги и техния статус.
// printLibraryAlphabetically(const Library&) - извежда всички книги и техния статус в азбучен ред.
#include <iostream>
#include <cstring>

enum class Status {
    Available, Borrowed, Reserved
};

struct Book {
public:
    char tittle[64 + 1] = "";
    char author[32 + 1] = "";
    int publicationYear = 0;
    Status status = Status::Available;

    Book() = default;

    Book(const char* tittle, const char* author, int publicationYear) {
        if (!tittle || !author || publicationYear < 0) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->tittle, tittle, 64);
        strncpy(this->author, author, 32);
        this->publicationYear = publicationYear;
        this->status = Status::Available;
    }
};

class Library {
private:
    char name[32 + 1]{};
    Book books[10]{};
    int bookCount = 0;

public:
    Library(const char* name, const Book* books, int countOfBooks) {
        if (!name || !books || countOfBooks < 0 || strlen(name) >= 32) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->name, name, 32);
        this->bookCount = countOfBooks;
        for (size_t i = 0; i < countOfBooks; i++) {
            this->books[i] = books[i];
        }
    }

    const char* getName() const {
        return this->name;
    }

    int getBookCount() const {
        return this->bookCount;
    }

    const Book& getBook(size_t index) const {
        if (index >= this->bookCount) {
            throw std::out_of_range("Index is out of range");
        }
        return this->books[index];
    }

    Book& getBook(size_t index) {
        if (index >= this->bookCount) {
            throw std::out_of_range("Index is out of range");
        }
        return this->books[index];
    }

    void addBook(const Book& book) {
        if (this->bookCount == 10) {
            throw std::runtime_error("Not enought space");
        }

        this->books[this->bookCount] = book;
        this->bookCount += 1;
    }

};

bool compareBooksByTitle(const Book& left, const Book& right) {
    return strcmp(left.tittle, right.tittle) > 0;
}

void addBook(Library& library, const char* tittle, const char* author, int publicationYear) {
    Book book = Book(tittle, author, publicationYear);
    try {
        library.addBook(book);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void borrowBook(Book& book) {
    book.status = Status::Borrowed;
}

void reserveBook(Book& book) {
    book.status = Status::Reserved;
}

void printBook(const Book& book) {
    std::cout << book.tittle << " ";
    std::cout << book.author << " ";
    std::cout << book.publicationYear << " ";
    switch (book.status) {
        case Status::Available: {
            std::cout << "available" << std::endl;
            break;
        }
        case Status::Borrowed: {
            std::cout << "borrowed" << std::endl;
            break;
        }
        case Status::Reserved: {
            std::cout << "reserved" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupported book status");
        }
    }
}

void printLibrary(const Library& library) {
    for (size_t i = 0; i < library.getBookCount(); i++) {
        printBook(library.getBook(i));
    }
    std::cout << std::endl;
}

void printLibraryAlphabetically(const Library& library) {
    Book booksCopy[10]{};
    int countOfBooks = library.getBookCount();

    for (size_t i = 0; i < countOfBooks; i++) {
        booksCopy[i] = library.getBook(i);
    }
    
    for (size_t i = 0; i + 1 < countOfBooks; i++) {
        for (size_t j = 0; j + 1 < countOfBooks - i; j++) {
            if (compareBooksByTitle(booksCopy[j], booksCopy[j + 1])) {
                Book temp = booksCopy[j];
                booksCopy[j] = booksCopy[j + 1];
                booksCopy[j + 1] = temp;
            }
        }
    }

    Library newLib("TempLib", booksCopy, countOfBooks);
    printLibrary(newLib);
}

int main() {
    Book noBooks[1]{};
    Library library("Sofia Library", noBooks, 0);

    addBook(library, "The C++ Programming Language", "Bjarne Stroustrup", 2013);
    addBook(library, "Effective C++", "Scott Meyers", 2005);
    addBook(library, "Clean Code", "Robert Martin", 2008);

    borrowBook(library.getBook(0));
    reserveBook(library.getBook(1));

    std::cout << "Library:" << std::endl;
    printLibrary(library);

    std::cout << "Alphabetically:" << std::endl;
    printLibraryAlphabetically(library);

    return 0;
}
