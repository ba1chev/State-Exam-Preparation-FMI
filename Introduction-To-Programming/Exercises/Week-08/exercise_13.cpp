// Професор Х крие парола. На всеки ред от библиотеката му са 
// подредени книги, най-много 20 реда книги, с до 30 книги на 
// ред. Книгите на някои от редовете са подредени по азбучен 
// ред на заглавията си, всяко от които е до 100 символа.
// Паролата за сейфа на професор X се определя от числата, които
// задават последователните дължини на думите в заглавията на 
// книгите, разположени точно в средата на редовете, в които 
// книгите са подредени в азбучен ред. Ако на реда има четен 
// брой книги, за паролата се използва книгата, намираща се 
// по-близо до началото на реда. Думите в заглавията на книгите 
// са разделени от точно един интервал. Дължините на думите 
// формират паролата в реда, в който се срещат, от най-горния 
// към най-долния ред на библиотеката.
// Библиотеката на Х може да се представи като двумерен масив a 
// от низове с m реда по n низа всеки, представящи заглавията на
// книгите. Да се дефинира функция revealPassword, която по 
// подадени a, m и n, извежда на стандартния изход паролата на 
// професор X като последователност от числа, разделени с по 
// един интервал.
#include <iostream>

bool is_row_alphabetic(char row[30][100], int size) {
    for (size_t i = 1; i < size; i++) {
        if (strcmp(row[i], row[i - 1]) < 0) {
            return false;
        }
    }

    return true;
}

void revealPassword(char library[20][30][100],
    int count_of_rows, int count_of_cols) {
    bool even_books_per_row = count_of_cols % 2 == 0;
    
    for (size_t i = 0; i < count_of_rows; i++) {
        if (is_row_alphabetic(library[i], count_of_cols)) {
            int book_index = even_books_per_row ? count_of_cols / 2 - 1 : count_of_cols / 2;
            const char* targeted_book_tittle = library[i][book_index];

            while (*targeted_book_tittle != '\0') {
                while (*targeted_book_tittle != '\0' && *targeted_book_tittle == ' ') {
                    targeted_book_tittle += 1;
                }

                int counter = 0;
                while (*targeted_book_tittle != '\0' && *targeted_book_tittle != ' ') {
                    counter += 1;
                    targeted_book_tittle += 1;
                }
                std::cout << counter << " ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    char buffer[20][30][100]{};
    int count_of_rows = 3;
    int count_of_cols = 3;

    strncpy(buffer[0][0], "Algebra", strlen("Algebra"));
    strncpy(buffer[0][1], "Analytic Geometry", strlen("Analytic Geometry"));
    strncpy(buffer[0][2], "Geometry", strlen("Geometry"));

    strncpy(buffer[1][0], "Databases", strlen("Databases"));
    strncpy(buffer[1][1], "Artificial Intelligence", strlen("Artificial Intelligence"));
    strncpy(buffer[1][2], "Functional Programming", strlen("Functional Programming"));

    strncpy(buffer[2][0], "Data Structures and Algorithms", strlen("Data Structures and Algorithms"));
    strncpy(buffer[2][1], "Introduction to Programming", strlen("Introduction to Programming"));
    strncpy(buffer[2][2], "Object-oriented Programming", strlen("Object-oriented Programming"));

    revealPassword(buffer, count_of_rows, count_of_cols);
    return 0;
}