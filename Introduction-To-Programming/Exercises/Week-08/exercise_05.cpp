// Напишете програма, която въвежда два знакови низа S1 и S2 и като 
// резултат отпечатва онези малки латински букви, които се съдържат в 
// низа S1, но не се съдържат в низа S2.
#include <iostream>

void print_lower_chars(const char* str_1, const char* str_2) {
    const char* str_2_start = str_2;
    while (*str_1 != '\0') {
        if (*str_1 >= 'a' && *str_1 <= 'z') {
            bool found = false;
            str_2 = str_2_start;
            while (*str_2 != '\0') {
                if (*str_1 == *str_2) {
                    found = true;
                    break;
                }
                str_2 += 1;
            }
            if (!found) {
                std::cout << *str_1 << " ";
            }
        }
        str_1 += 1;
    }
    std::cout << std::endl;
}

int main() {
    char str_1[1024]{};
    char str_2[1024]{};
    std::cin.getline(str_1, sizeof(str_1));
    std::cin.getline(str_2, sizeof(str_2));

    print_lower_chars(str_1, str_2);
    return 0;
}