#include "exercise_05.hpp"
#include <string>

int main() {
    Pair<int, std::string> a(1, "one");
    Pair<int, std::string> b(1, "one");
    Pair<int, std::string> c(2, "two");

    std::cout << (a == b) << " " << (a != c) << " " << (a < c) << std::endl;
    std::cout << a.first << " " << a.second << std::endl;

    return 0;
}
