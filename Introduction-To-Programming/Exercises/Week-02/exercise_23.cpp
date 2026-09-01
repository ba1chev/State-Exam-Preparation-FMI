// Напишете потребителски интерфейс, който изисква 
// от потребителя да въведе количество от даден 
// продукт (по ваш избор) и цената му. 
// Нека софтуерът попита за три различни продукта. 
// Накрая изведете сметката на потребителя: какъв 
// брой от какво си е поръчал и колко ще му струва.
#include <iostream>

int main() {
    int apples_count = 0;
    int oranges_count = 0;
    int bananas_count = 0;
    float apples_price = 0.f;
    float oranges_price = 0.f;
    float bananas_price = 0.f;

    std::cout << "Apples: ";
    std::cin >> apples_count >> apples_price;
    std::cout << "Oranges: ";
    std::cin >> oranges_count >> oranges_price;
    std::cout << "Bananas: ";
    std::cin >> bananas_count >> bananas_price;

    if (apples_count < 0 || oranges_count < 0 || bananas_count < 0 || 
        apples_price < 0.f || oranges_price < 0.f || bananas_price < 0.f) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    float apples_total = apples_count * apples_price;
    float oranges_total = oranges_count * oranges_price;
    float bananas_total = bananas_count * bananas_price;
    float total = apples_total + oranges_total + bananas_total;

    std::cout << "Your order is: apples for " << apples_total << 
        ", oranges for " << oranges_total << " and bananas for " << 
        bananas_total << ". Total: " << total << std::endl;
    return 0;
}