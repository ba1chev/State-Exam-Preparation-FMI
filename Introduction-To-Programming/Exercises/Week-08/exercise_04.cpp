// Даден е низ, образуван от главни латински букви. 
// Да напише програма, която преобразува низа, но от 
// съответните малките латински букви.
#include <iostream>

char to_lower(const char ch) {
    return (char)((int)ch - (int)'A' + (int)'a');
}

void convert_str_to_lower(char* str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = to_lower(*str);
        }
        str += 1;
    }
}

int main() {
    char str[1024] = {"Hello my name is Yoan!"};
    convert_str_to_lower(str);
    std::cout << str << std::endl;
    return 0;
}