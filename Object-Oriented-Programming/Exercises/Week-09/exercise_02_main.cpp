#include "exercise_02.hpp"
#include <string>

int main() {
    Stack<std::string> names;
    names.push("first");
    names.push("second");
    names.push("third");

    std::cout << names.size() << " " << names.isEmpty() << " " << names.top() << std::endl;

    names.pop();
    std::cout << names.size() << " " << names.top() << std::endl;

    names.clear();
    std::cout << names.size() << " " << names.isEmpty() << std::endl;

    return 0;
}
