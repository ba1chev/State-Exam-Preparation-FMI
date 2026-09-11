// Да се дефинира рекурсивна функция void 
// print_backwards(const char* begin, const char* end).
// Параметрите begin и end са указатели към елементи на буфер от символи, 
// като end ≥ begin. Символен низ с начало begin и край end наричаме 
// последователността от символи, започваща със символа, намиращ се на адрес 
// begin и завършваща със символа на адрес end - 1, включително, дори и ако 
// някой от тези символи е с код 0. Дума в такъв символен низ наричаме всяка 
// непразна подпоследователност от стандартни символи (с код>32), ограничена 
// от двете страни или от някой от краищата на низа, или от специален символ 
// (с код ≤ 32). Функцията print_backwards да извежда на стандартния 
// изход всички думи в низа с начало begin и край end в ред, обратен на 
// срещането им в низа, и разделени с точно един интервал.
#include <iostream>

void print_backwards(const char* begin, const char* end) {
    if (!begin || !end) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }
    if (begin == end) {
        return;
    }

    const char* word_end = end;
    while (word_end != begin && word_end[-1] <= 32) {
        word_end -= 1;
    }
    if (word_end == begin) {
        return;
    }

    const char* word_begin = word_end;
    while (word_begin != begin && word_begin[-1] > 32) {
        word_begin -= 1;
    }

    for (const char* current = word_begin; current != word_end; current++) {
        std::cout << *current;
    }
    if (word_begin != begin) {
        std::cout << " ";
        print_backwards(begin, word_begin);
    }
}

int main() {
    char array[16] = "I need a break!";
    const char* begin = &array[0];
    const char* end = &array[16];
    print_backwards(begin, end);
    std::cout << std::endl;
    return 0;
}