// Да се напише програма, която получава 5 латински букви. 
// Първите две от тях са в горен регистър (A-Z) и образуват множеството A, 
// където A съдържа всички букви между въпросните две букви, включително самите тях. 
// Вторите два символа в долен регистър (a-z) и образуват множеството B, където B 
// съдържа всички букви между въпросните две, включително самите тях.
// Програмата да изведе без значение от регистрите:
// Дали 5-тата буква принадлежи на обединението на A и B
// Дали 5-тата буква принадлежи на сечението на A и B
// Дали 5-тата буква принадлежи на разликата на A с B
// Без да използвате допълнителни проверки (освен резултатите от 1., 2. и 3.) 
// определете дали 5-тата буква принадлежи само в някое от множествата A или B.
#include <iostream>
#include <cctype>

bool validate_input(char left, char right) {
    return left <= right;
}

bool has_interesect(char left_1, char right_1, char left_2, char right_2) {
    return right_1 >= left_2 && right_2 >= left_1;
}

bool is_in_intersect(char left_1, char right_1, char left_2, char right_2, char letter) {
    if (!has_interesect(left_1, right_1, left_2, right_2)) {
        return false;
    } else {
        if (letter >= left_1 && letter <= right_1 &&
            letter >= left_2 && letter <= right_2) {
            return true;
        } else {
            return false;
        }
    }
}

bool is_in_union(char left_1, char right_1, char left_2, char right_2, char letter) {
    bool pred = (letter >= left_1 && letter <= right_1) ||
        (letter >= left_2 && letter <= right_2);

    if (pred) {
        return true;
    } else {
        return false;
    }
}

bool is_in_diff(char left_1, char right_1, char left_2, char right_2, char letter) {
    bool pred_1 = letter >= left_1 && letter <= right_1;
    bool pred_2 = !(letter >= left_2 && letter <= right_2);

    return pred_1 && pred_2;
}

int main() {
    char a, b, c, d, f;
    std::cin >> a >> b >> c >> d >> f;
    a = std::toupper(a);
    b = std::toupper(b);
    c = std::toupper(c);
    d = std::toupper(d);
    f = std::toupper(f);

    if (!validate_input(a, b) || !validate_input(c, d)) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    bool in_union = is_in_union(a, b, c, d, f);
    bool in_intersect = is_in_intersect(a, b, c, d, f);
    bool in_diff = is_in_diff(a, b, c, d, f);

    std::cout << in_union << std::endl;
    std::cout << in_intersect << std::endl;
    std::cout << in_diff << std::endl;
    std::cout << (in_union && !in_intersect) << std::endl;

    return 0;
}