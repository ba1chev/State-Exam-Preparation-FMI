// Напишете програма, която приема число n (-1000 <= n <= 1000), 
// която изписва стойността на n с думи. Помислете за някакъв pattern, 
// който може да се преизползва.
#include <iostream>
#include <cstdlib>

int handler_2(const int first_digit, const int second_digit) {
    if (first_digit == 0) {
        switch (second_digit) {
            case 0:
                return 0;
            case 1:
                std::cout << "One";
                break;
            case 2:
                std::cout << "Two";
                break;
            case 3:
                std::cout << "Three";
                break;
            case 4:
                std::cout << "Four";
                break;
            case 5:
                std::cout << "Five";
                break;
            case 6:
                std::cout << "Six";
                break;
            case 7:
                std::cout << "Seven";
                break;
            case 8:
                std::cout << "Eight";
                break;
            case 9:
                std::cout << "Nine";
                break;
            default:
                return -1;
        }
    } else if (first_digit == 1) {
        switch (second_digit) {
            case 0:
                std::cout << "Ten";
                break;
            case 1:
                std::cout << "Eleven";
                break;
            case 2:
                std::cout << "Twelve";
                break;
            case 3:
                std::cout << "Thirteen";
                break;
            case 4:
                std::cout << "Fourteen";
                break;
            case 5:
                std::cout << "Fifteen";
                break;
            case 6:
                std::cout << "Sixteen";
                break;
            case 7:
                std::cout << "Seventeen";
                break;
            case 8:
                std::cout << "Eighteen";
                break;
            case 9:
                std::cout << "Nineteen";
                break;
            default:
                return -1;
        }
    } else {
        switch (first_digit) {
            case 2:
                std::cout << "Twenty";
                break;
            case 3:
                std::cout << "Thirty";
                break;
            case 4:
                std::cout << "Forty";
                break;
            case 5:
                std::cout << "Fifty";
                break;
            case 6:
                std::cout << "Sixty";
                break;
            case 7:
                std::cout << "Seventy";
                break;
            case 8:
                std::cout << "Eighty";
                break;
            case 9:
                std::cout << "Ninety";
                break;
            default:
                return -1;
        }

        if (second_digit != 0) {
            std::cout << " ";
            handler_2(0, second_digit);
        }
    }

    return 1;
}

int handler_1(int number) {
    int first_digit = number / 100;
    int second_digit = (number / 10) % 10;
    int third_digit = number % 10;

    if (number == 0) {
        std::cout << "Zero";
        return 1;
    }

    if (number < 100) {
        return handler_2(second_digit, third_digit);
    }

    if (first_digit == 10) {
        std::cout << "One thousand";
        return 1;
    }

    switch (first_digit) {
        case 1:
            std::cout << "One hundred";
            break;
        case 2:
            std::cout << "Two hundred";
            break;
        case 3:
            std::cout << "Three hundred";
            break;
        case 4:
            std::cout << "Four hundred";
            break;
        case 5:
            std::cout << "Five hundred";
            break;
        case 6:
            std::cout << "Six hundred";
            break;
        case 7:
            std::cout << "Seven hundred";
            break;
        case 8:
            std::cout << "Eight hundred";
            break;
        case 9:
            std::cout << "Nine hundred";
            break;
        default:
            return -1;
    }

    if (second_digit != 0 || third_digit != 0) {
        std::cout << " and ";
        if (handler_2(second_digit, third_digit) == -1) {
            return -1;
        }
    }

    return 1;
}

int main() {
    int number = 0;
    std::cin >> number;

    if (number < -1000 || number > 1000) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    bool is_negative = number < 0;

    if (is_negative) {
        std::cout << "Negative ";
        number = std::abs(number);
    }

    if (handler_1(number) == -1) {
        std::cout << "Invalid" << std::endl;
        return 1;
    }

    std::cout << std::endl;

    return 0;
}