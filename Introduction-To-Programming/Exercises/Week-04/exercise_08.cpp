// Група от N деца отива на почивка. В почивната станция 
// разполагат със стаи с по 3 и 4 легла. Да се състави програма, 
// която въвежда от клавиатурата броя на децата N и отпечатва 
// различните разпределения на децата по стаите. Ако такова 
// разпределение е невъзможно, на екрана се извежда “NO”.
#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int counter = 0;
    for (size_t i = 0; i <= N / 3; i++) {
        for (size_t j = 0; j <= N / 4; j++) {
            if ((i * 3 + 4 * j) == N) {
                std::cout << i << "x3 + " << j << "x4" << std::endl;
                counter += 1;
            }
        }
    }
    
    if (!counter) {
        std::cout << "NO" << std::endl;
        return 1;
    } 

    std::cout << counter << std::endl;
    return 0;
}