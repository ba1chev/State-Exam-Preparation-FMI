#include "exercise_02.hpp"
#include <iostream>

struct A {
public:
    char temp[4]{};
};

int main() {
    UnuquePtr<float> ptr1(new float(3.14f));
    std::cout << *ptr1.getData() << std::endl;

    UnuquePtr<A> ptr2(new A());
    std::cout << ptr2.getData()->temp << std::endl;

    return 0;
}