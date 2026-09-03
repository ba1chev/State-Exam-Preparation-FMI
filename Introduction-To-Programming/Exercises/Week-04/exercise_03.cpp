// Напишете програма, която да изписва таблицата 
// за умножение в даден интервал i X j (0 <= i <= j < 999), 
// който се задава от потребителя
#include <iostream>

int get_digits_count(int number) {
    if (!number) {
        return 1;
    }

    int counter = 0;
    while (number != 0) {
        counter += 1;
        number /= 10;
    }
    return counter;
}

int main() {
    int index_1, index_2 = 0;
    std::cin >> index_1 >> index_2;
    if (index_1 < 0 || index_1 > index_2 || index_2 >= 999) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << std::endl << "| X  | ";
    for (size_t i = index_1; i < index_2 ; i++) {
        int count_of_digits = get_digits_count(i);
        switch (count_of_digits) {
            case 1: {
                std::cout << "| " << i << "  | ";
                break;
            }
            case 2: {
                std::cout << "| " << i << " | ";
                break;
            }
            case 3: {
                std::cout << "| " << i << "| ";
                break;
            }
            default: {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }   
    }
    
    std::cout << std::endl;
    for (size_t i = index_1; i < index_2; i++) {
        for (size_t j = index_1; j < index_2; j++) {
            if (j == index_1) {
                int count_of_digits_1 = get_digits_count(i);
                switch (count_of_digits_1) {
                    case 1: {
                        std::cout << "| " << i << "  | ";
                        break;
                    }
                    case 2: {
                        std::cout << "| " << i << " | ";
                        break;
                    }
                    case 3: {
                        std::cout << "| " << i << "| ";
                        break;
                    }
                    default: {
                        std::cout << "Error" << std::endl;
                        return 1;
                    }
                    
                }
            }

            int count_of_digits_2 = get_digits_count(i * j);
            switch (count_of_digits_2) {
                case 1: {
                    std::cout << "| " << i * j << "  | ";
                    break;
                }
                case 2: {
                    std::cout << "| " << i * j << " | ";
                    break;
                }
                case 3: {
                    std::cout << "| " << i * j << "| ";
                    break;
                }
                default: {
                    std::cout << "Error" << std::endl;
                    return 1;
                }
            }
        }      
        std::cout << std::endl;  
    }
    
    return 0;
}