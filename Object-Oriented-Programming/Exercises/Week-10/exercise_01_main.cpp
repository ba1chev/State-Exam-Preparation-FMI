#include "exercise_01.hpp"

int main() {
    SharedPtr<int> ptr1 = SharedPtr<int>(new int(3));
    std::cout << *ptr1.getData() << " " << ptr1.getCounter() << std::endl;
    SharedPtr<int> ptr2 = ptr1;
    std::cout << *ptr1.getData() << " " << ptr1.getCounter() << std::endl;
    std::cout << *ptr2.getData() << " " << ptr2.getCounter() << std::endl;
    return 0;
}