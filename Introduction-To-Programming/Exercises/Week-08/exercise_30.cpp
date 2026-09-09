// Да се напише програма, която създава файл, съдържащ информация за
// книгите на една библиотека. Всяка компонента на файла съдържа: инвентарен номер,
// заглавие, автор, националност и година на издаване. Инвентарните номера започват
// от 400000 и завършват с 450000. Програмата да може да извършва следните действия:
// включва нова книга във файла; изтрива книга от файла;
// променя всички полета, без инвентарен номер, на зададена чрез инвентарен номер книга;
// извежда върху екрана компонентите на файла;
// намира книгите от указна националност;
// намира книгите издадени през указана година.
#include <iostream>
#include <fstream>

struct Book {
public:
    int inventory_number = 0;
    char title[100]{};
    char author[100]{};
    char nationality[100]{};
    int year = 0;
};

Book read_book(std::ifstream& ifs) {
    Book book;
    ifs >> book.inventory_number;
    ifs >> book.title;
    ifs >> book.author;
    ifs >> book.nationality;
    ifs >> book.year;

    return book;
}

void write_book(std::ofstream& ofs, const Book& book) {
    ofs << book.inventory_number << " ";
    ofs << book.title << " ";
    ofs << book.author << " ";
    ofs << book.nationality << " ";
    ofs << book.year << std::endl;
}

int get_books_count(const char* file_name) {
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        return 0;
    }

    int result = 0;
    char dummy_buffer[1024]{};
    while (ifs.getline(dummy_buffer, sizeof(dummy_buffer))) {
        result += 1;
    }

    ifs.close();
    return result;
}

void append_book(const Book& book, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ofstream ofs(file_name, std::ios::app);
    if (!ofs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }

    write_book(ofs, book);
    ofs.close();
}

void remove_book_by_inventory_number(int inventory_number, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int count_of_books = get_books_count(file_name);
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    Book* books = new Book[count_of_books]{};
    for (size_t i = 0; i < count_of_books; i++) {
        books[i] = read_book(ifs);
    }
    ifs.close();

    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        delete[] books;
        return;
    }
    for (size_t i = 0; i < count_of_books; i++) {
        if (books[i].inventory_number == inventory_number) {
            continue;
        }
        write_book(ofs, books[i]);
    }

    ofs.close();
    delete[] books;
    books = nullptr;
}

void change_book_by_inventory_number(int inventory_number, const Book& new_data, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int count_of_books = get_books_count(file_name);
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    Book* books = new Book[count_of_books]{};
    for (size_t i = 0; i < count_of_books; i++) {
        books[i] = read_book(ifs);
    }
    ifs.close();

    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        delete[] books;
        return;
    }
    for (size_t i = 0; i < count_of_books; i++) {
        if (books[i].inventory_number == inventory_number) {
            Book updated = new_data;
            updated.inventory_number = inventory_number;
            books[i] = updated;
        }
        write_book(ofs, books[i]);
    }

    ofs.close();
    delete[] books;
    books = nullptr;
}

void print_books(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int count_of_books = get_books_count(file_name);
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    Book current_book;
    for (size_t i = 0; i < count_of_books; i++) {
        current_book = read_book(ifs);
        std::cout << current_book.inventory_number << " ";
        std::cout << current_book.title << " ";
        std::cout << current_book.author << " ";
        std::cout << current_book.nationality << " ";
        std::cout << current_book.year << std::endl;
    }

    ifs.close();
}

bool are_equal(const char* lhs, const char* rhs) {
    while (*lhs != '\0' && *rhs != '\0') {
        if (*lhs != *rhs) {
            return false;
        }
        lhs += 1;
        rhs += 1;
    }

    return *lhs == *rhs;
}

void print_books_by_nationality(const char* nationality, const char* file_name) {
    if (!nationality || !file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int count_of_books = get_books_count(file_name);
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    Book current_book;
    for (size_t i = 0; i < count_of_books; i++) {
        current_book = read_book(ifs);
        if (are_equal(current_book.nationality, nationality)) {
            std::cout << current_book.inventory_number << " ";
            std::cout << current_book.title << " ";
            std::cout << current_book.author << " ";
            std::cout << current_book.nationality << " ";
            std::cout << current_book.year << std::endl;
        }
    }

    ifs.close();
}

void print_books_by_year(int year, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int count_of_books = get_books_count(file_name);
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    Book current_book;
    for (size_t i = 0; i < count_of_books; i++) {
        current_book = read_book(ifs);
        if (current_book.year == year) {
            std::cout << current_book.inventory_number << " ";
            std::cout << current_book.title << " ";
            std::cout << current_book.author << " ";
            std::cout << current_book.nationality << " ";
            std::cout << current_book.year << std::endl;
        }
    }

    ifs.close();
}

int main() {
    Book b1 = {400000, "Pod-Igoto", "Vazov", "Bulgarian", 1894};
    Book b2 = {400001, "Hamlet", "Shakespeare", "English", 1603};
    Book b3 = {400002, "Tютюн", "Dimov", "Bulgarian", 1951};

    append_book(b1, "file.txt");
    append_book(b2, "file.txt");
    append_book(b3, "file.txt");
    print_books("file.txt");

    std::cout << std::endl << "Bulgarian books: " << std::endl;
    print_books_by_nationality("Bulgarian", "file.txt");

    std::cout << std::endl << "Books from 1603: " << std::endl;
    print_books_by_year(1603, "file.txt");

    return 0;
}
