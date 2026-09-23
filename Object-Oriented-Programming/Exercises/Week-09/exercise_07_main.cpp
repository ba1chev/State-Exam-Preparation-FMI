#include "exercise_07.hpp"

int main() {
    Queue<int> queue;
    for (int i = 1; i <= 4; i++) {
        queue.enqueue(i);
    }

    std::cout << queue.front() << " " << queue.getSize() << std::endl;

    queue.dequeue();
    std::cout << queue.front() << " " << queue.getSize() << std::endl;

    queue.enqueue(5);
    queue.enqueue(6);

    while (!queue.isEmpty()) {
        std::cout << queue.front() << " ";
        queue.dequeue();
    }
    std::cout << std::endl;

    Queue<int> big;
    for (int i = 0; i < 20; i++) {
        big.enqueue(i);
    }
    std::cout << big.front() << " " << big.getSize() << " " << big.getCapacity() << std::endl;

    return 0;
}
