// Колко най-малко бита са необходими, за да се представят в двоичен вид числата:
// 10(10); -132(10); -1010(10); 65(10); -65(10); -1024(10);
#include <iostream>

int get_hightest_bit_pos(int number) {
    if (number >= 0) {
        for (size_t i = 0; i < 32; i++) {
            if (number & (1 << (32 - i - 1))) {
                return 32 - i + 1;
            }
        }
        return 1;
    }

    for (size_t i = 0; i < 32; i++) {
        if (!(number & (1 << (32 - i - 1)))) {
            return 32 - i + 1;
        }
    }
    return 1;
}

int main() {
    std::cout << get_hightest_bit_pos(10) << std::endl;
    std::cout << get_hightest_bit_pos(-132) << std::endl;
    std::cout << get_hightest_bit_pos(-1010) << std::endl;
    std::cout << get_hightest_bit_pos(65) << std::endl;
    std::cout << get_hightest_bit_pos(-1024) << std::endl;
    return 0;
}