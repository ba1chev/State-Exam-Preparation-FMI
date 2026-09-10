// Да се напише рекурсивна програма, която добавя елемент в 
// сортиран масив, като запазва наредбата на елементите.
#include <iostream>

void add_element(int* array, const int size, const int number,
    int left, int right) {
    if (left >= right) {
        while (left < size && array[left] < number) {
            left += 1;
        }

        for (int i = size; i >= left; i--) {
            array[i + 1] = array[i];
        }
        array[left] = number;
        return;
    } else {
        int middle = left + (right - left) / 2;
        if (array[middle] == number) {
            return add_element(array, size, number, middle, -1);
        } else if (array[middle] > number) {
            return add_element(array, size, number, left, middle - 1);
        } else {
            return add_element(array, size, number, middle + 1, right);
        }
    }
}

int main() {
    int array_1[10] = {1, 2, 3, 4};
    int array_2[10] = {1, 3, 4};
    add_element(array_1, 4, 2, 0, 4);
    add_element(array_2, 3, 2, 0, 3);

    for (size_t i = 0; i < 5; i++) {
        std::cout << array_1[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < 4; i++) {
        std::cout << array_2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}