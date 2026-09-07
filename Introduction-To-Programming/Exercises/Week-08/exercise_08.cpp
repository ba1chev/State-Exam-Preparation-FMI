// Да се напише програма, която установява дали броят на срещанията на 
// думата 'begin' в даден низ е равен на броя на срещанията на думата 'end' в 
// същия низ
#include <iostream>

bool check_str(const char* str) {
    int counter_1 = 0;
    int counter_2 = 0;

    while (*str != '\0') {
        while (*str != '\0' && *str == ' ') {
            str += 1;
        }

        while (*str != '\0' && *str != ' ') {
            if (*str == 'b') {
                const char* temp_ptr = str;
                const char* buffer = "begin";
                while (*temp_ptr != '\0' && *temp_ptr == *buffer) {
                    temp_ptr += 1;
                    buffer += 1;
                }

                if (*buffer == '\0') {
                    counter_1 += 1;
                }
            } else if (*str == 'e') {
                const char* temp_ptr = str;
                const char* buffer = "end";
                while (*temp_ptr != '\0' && *temp_ptr == *buffer) {
                    temp_ptr += 1;
                    buffer += 1;
                }

                if (*buffer == '\0') {
                    counter_2 += 1;
                }
            }
            str += 1;
        }
    }

    return counter_1 == counter_2;
}

int main() {
    std::cout << check_str("asdasdbeginasdasendasdasbeginasdasend begin") << std::endl;
    std::cout << check_str("endginbegin") << std::endl;
    return 0;
}