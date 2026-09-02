// Да се напише програма, която получава число в интервала 0-100 и 
// изписва на конзолата неговата стойност под формата на текст. 
// (английски за предпочитане пред шльокавица)
#include <iostream>

void switch_for_right_digit(const int number) {
    switch (number)
    {
        case 0: {
            break;
        }
        case 1: {
            std::cout << "one";
            break;
        }
        case 2: {
            std::cout << "two";
            break;
        }
        case 3: {
            std::cout << "three";
            break;
        }
        case 4: {
            std::cout << "four";
            break;
        }
        case 5: {
            std::cout << "five";
            break;
        }
        case 6: {
            std::cout << "six";
            break;
        }
        case 7: {
            std::cout << "seven";
            break;
        }
        case 8: {
            std::cout << "eight";
            break;
        }
        case 9: {
            std::cout << "nine";
            break;
        }
        default: {
            std::cout << "Invalid input" << std::endl;
            return;
        }
    }
}

int main() {
    int number = 0;
    std::cin >> number;

    if (number < 0 || number > 100) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    if (number == 0) {
        std::cout << "zero" << std::endl;
        return 0;
    }

    if (number == 100) {
        std::cout << "one hundred" << std::endl;
        return 0;
    }

    int left_digit = number / 10;
    int right_digit = number % 10;

    switch (left_digit)
    {
        case 0: {
            switch_for_right_digit(right_digit);
            break;
        }

        case 1: {
            switch (number)
            {
                case 10: {
                    std::cout << "ten";
                    break;
                }
                case 11: {
                    std::cout << "eleven";
                    break;
                }
                case 12: {
                    std::cout << "twelve";
                    break;
                }
                case 13: {
                    std::cout << "thirteen";
                    break;
                }
                case 14: {
                    std::cout << "fourteen";
                    break;
                }
                case 15: {
                    std::cout << "fifteen";
                    break;
                }
                case 16: {
                    std::cout << "sixteen";
                    break;
                }
                case 17: {
                    std::cout << "seventeen";
                    break;
                }
                case 18: {
                    std::cout << "eighteen";
                    break;
                }
                case 19: {
                    std::cout << "nineteen";
                    break;
                }
            }
            break;
        }

        case 2: {
            std::cout << "twenty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 3: {
            std::cout << "thirty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 4: {
            std::cout << "forty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 5: {
            std::cout << "fifty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 6: {
            std::cout << "sixty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 7: {
            std::cout << "seventy ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 8: {
            std::cout << "eighty ";
            switch_for_right_digit(right_digit);
            break;
        }

        case 9: {
            std::cout << "ninety ";
            switch_for_right_digit(right_digit);
            break;
        }

        default: {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }

    std::cout << std::endl;

    return 0;
}