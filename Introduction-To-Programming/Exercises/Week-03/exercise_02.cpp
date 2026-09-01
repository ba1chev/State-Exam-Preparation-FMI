// Задача Внасяме K лева при сложна годишна лихва от p процента. 
// Да се напише програма, която въвежда K, p и n 
// и изчислява с каква сума ще разполагаме след n години.
#include <iostream>
#include <cmath>

int main() {
    int K, p, n = 0;
    std::cin >> K >> p >> n;
    std::cout << K * std::pow((1 + p / 100.0f), n) << std::endl;
    return 0;
}
