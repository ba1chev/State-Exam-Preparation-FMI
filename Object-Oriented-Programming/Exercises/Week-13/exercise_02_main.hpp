// Преди няколко седмици писахме наша имплементация на стек, 
// но още не бяхме говорили за изключения. 
// Допълнете имплементацията да хвърля EmptyStackException,
// където е нужно.
#include <iostream>
#include "exercise_02_stack.hpp"

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "top: " << stack.top() << std::endl;
    stack.pop();
    stack.pop();
    std::cout << "top: " << stack.top() << std::endl;
    stack.pop();

    try {
        stack.top();
    }
    catch (const EmptyStackException& e) {
        std::cout << "top on empty: " << e.what() << std::endl;
    }

    try {
        stack.pop();
    }
    catch (const EmptyStackException& e) {
        std::cout << "pop on empty: " << e.what() << std::endl;
    }

    return 0;
}