// Да се напише програма, която по дадено реално число x 
// намира стойността на израза (…(((x+122)x+120)x+118)x+⋯+4)x+2
#include <iostream>

int main() {
    int x = 0;
    std::cin >> x;
    int result = (x + 122);
    int current_index = 120;
    
    while (true) {
        if (current_index == 0) {
            break;
        }
        result = result * x + current_index;
        current_index -= 2;
    }

    std::cout << result << std::endl;
    return 0;
}