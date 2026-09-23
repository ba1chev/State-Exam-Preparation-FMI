#include "exercise_01.hpp"
#include <string>

int main() {
    MyVector<std::string> words;
    words.push_back("hello");
    words.push_back("world");
    std::string third = "third";
    words.push_back(std::move(third));

    std::cout << words.size() << " " << words.capacity() << " " << words.empty() << std::endl;
    std::cout << words.front() << " " << words.back() << " " << words[1] << std::endl;

    words.pop_back();
    std::cout << words.size() << " " << words.back() << std::endl;

    words.clear();
    std::cout << words.size() << " " << words.empty() << std::endl;

    return 0;
}
