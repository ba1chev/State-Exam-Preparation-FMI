// Да се напише програма, която получава 5 числа. 
// Първите две от тях образуват множеството A, където A 
// съдържа всички цели числа между въпросните две числа, включително самите тях. 
// Вторите две числа образуват множеството B, където B съдържа всички цели числа между въпросните две, 
// включително самите тях. Програмата да изведе:
// Дали 5-тото число принадлежи на обединението на A и B
// Дали 5-тото число принадлежи на сечението на A и B
// Дали 5-тото число принадлежи на разликата на A с B
// Без да използвате допълнителни проверки (освен резултатите от 1., 2. и 3.) 
// определете дали 5-тото число принадлежи само в някое от множествата A или B.
#include <iostream>

bool has_interesect(int left_1, int right_1, int left_2, int right_2) {
    return right_1 >= left_2 && right_2 >= left_1;
}

bool validate_input(int left, int right) {
    return left <= right;
}

bool is_in_intersect(int left_1, int right_1, int left_2, int right_2, int number) {
    if (!has_interesect(left_1, right_1, left_2, right_2)) {
        return false;
    } else {
        if (number >= left_1 && number <= right_1 &&
            number >= left_2 && number <= right_2) {
            return true;
        } else {
            return false;
        }
    }
}

bool is_in_union(int left_1, int right_1, int left_2, int right_2, int number) {
    bool pred = (number >= left_1 && number <= right_1) ||
                (number >= left_2 && number <= right_2);

    if (pred) {
        return true;
    } else {
        return false;
    }
}

bool is_in_diff(int left_1, int right_1, int left_2, int right_2, int number) {
    bool pred_1 = number >= left_1 && number <= right_1;
    bool pred_2 = !(number >= left_2 && number <= right_2);

    return pred_1 && pred_2;
}

int main() {
    int a, b, c, d, f = 0;

    std::cin >> a >> b >> c >> d >> f;

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