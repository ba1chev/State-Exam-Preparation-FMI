// Дадени са три стълба. На първият са поставени n диска с различен диаметър, 
// наредени един върху друг от най-големия към най-малкия диск. Да се преместят 
// всички дискове на третия стълб, като се запази подредбата им и при разместванията се 
// спазва правилото винаги да се поставя по-малък диск върху по-голям.
#include <iostream>

void move_disks(int n, char source, char target, char helper) {
    if (n == 0) {
        return;
    }
    move_disks(n - 1, source, helper, target);
    std::cout << source << " -> " << target << std::endl;
    move_disks(n - 1, helper, target, source);
}

int main() {
    move_disks(3, 'A', 'C', 'B');
    return 0;
}