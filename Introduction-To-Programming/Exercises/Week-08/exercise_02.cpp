// Да се напише програма, която намира броя на срещанията на всеки 
// символ от вида ! , ? , , в даден низ.
#include <iostream>

void find_symbols_occ(const char* str, int size) {
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;

    for (size_t i = 0; i < size; i++) {
        switch (str[i]) {
            case '!': {
                counter_1 += 1;
                break;
            }
            case '?': {
                counter_2 += 1;
                break;
            }
            case ',': {
                counter_3 += 1;
                break;
            }
            default: {
                continue;
            }
        }
    }
    
    std::cout << "Symbol '!': " << counter_1 << ", " <<
        "symbol '?': " << counter_2 << ", " <<
        "symbol ',': " << counter_3 << std::endl;
}

int main() {
    char buffer[1024];
    std::cin.getline(buffer, sizeof(buffer));
    find_symbols_occ(buffer, strlen(buffer));
    return 0;
}