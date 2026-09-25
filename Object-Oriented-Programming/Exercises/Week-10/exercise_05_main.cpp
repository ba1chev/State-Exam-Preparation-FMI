// Да се реализира система за управление на библиотечен архив. 
// Системата трябва да моделира библиотека, която съдържа 
// архиви, книги, читатели и библиотекари.

// Book
// Всеки обект Book съдържа:

// заглавие
// автор
// година на издаване
// уникален идентификатор
// информация дали книгата е заета
// Archive
// Всеки Archive представлява архив или секция в 
// библиотеката и съдържа:

// име на архива
// масив от книги
// Archive трябва да реализира:
// добавяне на книга
// премахване на книга по идентификатор
// търсене на книга
// извеждане на всички книги
// заемане на книга
// връщане на книга
// Reader
// Всеки Reader представлява читател в библиотеката и съдържа:

// име
// номер на читателска карта
// колекция от заети книги
// Reader трябва да реализира:
// заемане на книга
// връщане на книга
// извеждане на всички взети книги
// проверка дали вече е взел конкретна книга
// Librarian
// Всеки Librarian представлява библиотекар и съдържа:

// име
// служебен номер
// архиви, които наблюдава
// Librarian трябва да реализира:
// добавяне на архив за наблюдение
// извеждане на всички наблюдавани архиви
// проверка дали архивът все още съществува
// Library
// Главният клас, който съдържа всички архиви.

// Library съдържа:

// колекция от архиви
// колекция от библиотекари
// колекция от читатели
// Library трябва да реализира:
// добавяне на архив
// премахване на архив
// преместване на книга между два архива
// извеждане на цялата информация за библиотеката
// търсене на архив по име
// добавяне на библиотекар
// търсене на библиотекар по служебен номер
// извеждане на всички библиотекари
// добавяне на читател
// търсене на читател по номер на карта
// извеждане на всички читатели
#include "exercise_05_library.h"

int main() {
    Library library;

    Archive fiction("Fiction");
    fiction.addBook(Book("1984", "George Orwell", 1949));
    fiction.addBook(Book("Brave New World", "Aldous Huxley", 1932));

    Archive science("Science");
    science.addBook(Book("A Brief History of Time", "Stephen Hawking", 1988));

    library.addArchive(fiction);
    library.addArchive(science);

    // Читател заема и връща книга.
    Reader reader("Ivan", 1001);
    const Book& borrowed = library.searchArchiveBy("Fiction").searchBookBy(0);
    library.searchArchiveBy("Fiction").borrowBook(borrowed.getId());
    reader.borrowBook(borrowed);
    library.addReader(reader);

    std::cout << "Reader has book 0: "
        << (library.searchReaderBy(1001).hasBook(0) ? "yes" : "no") << std::endl;
    std::cout << "Reader has book 5: "
        << (library.searchReaderBy(1001).hasBook(5) ? "yes" : "no") << std::endl;

    library.searchReaderBy(1001).returnBook(0);
    library.searchArchiveBy("Fiction").returnBook(0);

    // Библиотекар наблюдава архиви и проверява дали съществуват.
    Librarian librarian("Maria", 7);
    librarian.watchArchive(&library.searchArchiveBy("Fiction"));
    librarian.watchArchive(&library.searchArchiveBy("Science"));
    library.addLibrarian(librarian);

    std::cout << "Librarian watches Fiction: "
        << (library.searchLibrarianBy(7).archiveExists("Fiction") ? "yes" : "no")
        << std::endl;
    std::cout << "Librarian watches History: "
        << (library.searchLibrarianBy(7).archiveExists("History") ? "yes" : "no")
        << std::endl << std::endl;

    // Преместване на книга между два архива.
    library.moveBookBetween("Fiction", "Science", 1);

    library.printLibrary();

    return 0;
}
