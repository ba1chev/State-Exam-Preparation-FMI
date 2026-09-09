// Даден е масив от тип char съдържащ n символа (0 < n < INT_MAX) . 
// Да се състави програма, която определя дали масива е симетричен, т.е. 
// прочетен отляво надясно и отдясно наляво е един и същ.
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    char* array = new char[n + 1]{};
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    array[n] = '\0';

    for (size_t i = 0; i < n / 2; i++) {
        if (array[i] != array[n - i - 1]) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    
    std::cout << 1 << std::endl;
    return 0;
}