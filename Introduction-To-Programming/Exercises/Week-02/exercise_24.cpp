// Напишете програма, която въвежда три 
// естествени числа a, b и c и като 
// резултат връща корените на квадратното 
// уравнение a2x + bx + c = 0 
// (приемете, че винаги ще има реални корени).
#include <iostream>
#include <cmath>

int main() {
    int a, b, c = 0;
    std::cin >> a >> b >> c;
    int determinant = b * b - 4 * a * c;
    float apprx = 1.0f;

    while (true) {
        float next_apprx = (apprx + determinant / apprx) / 2.0f;
        if (std::abs(next_apprx - apprx) < 1e-6f) {
            break;
        }

        apprx = next_apprx;
    }

    float root_1 = (-b + apprx) / (2 * a + 0.0f);
    float root_2 = (-b - apprx) / (2 * a + 0.0f);
    std::cout << root_1 << " " << root_2 << std::endl;  
    return 0;
}