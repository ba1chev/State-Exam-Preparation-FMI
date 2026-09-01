// Да се напише програма, която има предварително 
// избрано число key и приема число value, а след 
// това генерира криптирана стойност на value - crypt, 
// която се извежда на екрана. След това кара потребителя 
// да въведе key и се опитва да декриптира crypt до 
// оригиналното състояние - value.
#include <iostream>

int main() {
    int key = 51223;
    int number = 0;
    std::cout << "Enter value: ";
    std::cin >> number;
    int crypted_number = number ^ key;
    std::cout << "You crypt is: " << crypted_number << std::endl;
    std::cout << "Enter key to decrypt: ";
    int decrypt_key = 0;
    std::cin >> decrypt_key;
    std::cout << "Your value is: " << 
        (crypted_number ^ decrypt_key) << std::endl;

    return 0;
}