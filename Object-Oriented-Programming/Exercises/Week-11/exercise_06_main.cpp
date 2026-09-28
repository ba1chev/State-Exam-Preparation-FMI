// Моделирайте система за управление на зоопарк. Зоопаркът е разделен на секции: BirdSection, MammalSection и ReptileSection. Всяка секция съдържа една или повече клетки (Exhibit), а всяка клетка — група животни от един вид (Animal). Зоопаркът наема пазачи (ZooKeeper), които могат да бъдат назначавани за охрана на секция — но всяка секция има минимален брой години опит, който пазачът трябва да покрива.

// Имплементирайте следните класове:

// Animal с полета за име, вид и възраст.
// Exhibit с локация, вид животно, брой животни и капацитет. Осигурете метод addAnimal, който отказва добавяне при запълнен капацитет, и метод isFull.
// Section с име, минимален изискван опит и колекция от клетки. Добавете методи addExhibit, assignGuard и hasActiveGuard. Всяка секция има пазач, но не го притежава — пазачът може да бъде преместван между секции.
// Създайте три наследника на Section:

// BirdSection — без изискване за минимален опит
// MammalSection — минимален опит: 3 години
// ReptileSection — минимален опит: 5 години
// Имплементирайте клас Zoo, който притежава секциите и пазачите и има методи:

// addKeeper — добавя нов пазач и връща shared_ptr към него
// removeKeeper — премахва пазача по employeeID
// printAll — отпечатва всички секции, клетки и животни
// search(name) — търси животно по име из всички клетки
// За всеки клас обосновайте избора си между наследяване и композиция и обяснете дали и защо е спазен Rule of Zero.

// Напишете main(), който:

// Създава зоопарк с поне по една клетка в три различни секции
// Добавя поне три животни, разпределени в различни клетки
// Назначава пазач с недостатъчен опит и показва, че assignGuard го отхвърля
// Назначава пазач с достатъчен опит и показва, че hasActiveGuard връща true
// Извиква removeKeeper и показва, че hasActiveGuard след това връща false
// Извиква printAll и search
#include <iostream>
#include "exercise_06_zoo.h"
#include "exercise_06_bird_section.h"
#include "exercise_06_mammal_section.h"
#include "exercise_06_reptile_section.h"

int main() {
    Zoo zoo;

    // По една клетка в три различни секции.
    BirdSection* birds = new BirdSection("Birds");
    Exhibit birdCage("Aviary A", AnimalType::Bird, 3);
    birdCage.addAnimal(Animal("Rio", 2.0f, AnimalType::Bird));
    birds->addExhibit(birdCage);

    MammalSection* mammals = new MammalSection("Mammals");
    Exhibit mammalCage("Savanna", AnimalType::Mammal, 3);
    mammalCage.addAnimal(Animal("Leo", 5.0f, AnimalType::Mammal));
    mammals->addExhibit(mammalCage);

    ReptileSection* reptiles = new ReptileSection("Reptiles");
    Exhibit reptileCage("Terrarium", AnimalType::Reptile, 3);
    reptileCage.addAnimal(Animal("Kaa", 8.0f, AnimalType::Reptile));
    reptiles->addExhibit(reptileCage);

    zoo.addSection(birds);
    zoo.addSection(mammals);
    zoo.addSection(reptiles);

    // Пазач с недостатъчен опит за секцията с влечуги (изисква 5).
    std::shared_ptr<ZooKeeper> junior = zoo.addKeeper("Junior", 1, 2);
    std::cout << "assignGuard(junior, reptiles): "
        << (reptiles->assignGuard(junior.get()) ? "accepted" : "rejected")
        << std::endl;
    std::cout << "reptiles.hasActiveGuard(): "
        << (reptiles->hasActiveGuard() ? "true" : "false") << std::endl;

    // Пазач с достатъчен опит.
    std::shared_ptr<ZooKeeper> senior = zoo.addKeeper("Senior", 2, 7);
    std::cout << "assignGuard(senior, reptiles): "
        << (reptiles->assignGuard(senior.get()) ? "accepted" : "rejected")
        << std::endl;
    std::cout << "reptiles.hasActiveGuard(): "
        << (reptiles->hasActiveGuard() ? "true" : "false") << std::endl;

    // Премахване на пазача -> връзката в секцията се нулира.
    zoo.removeKeeper(2);
    std::cout << "after removeKeeper(2) reptiles.hasActiveGuard(): "
        << (reptiles->hasActiveGuard() ? "true" : "false") << std::endl << std::endl;

    std::cout << "===== printAll =====" << std::endl;
    zoo.printAll();

    std::cout << "===== search =====" << std::endl;
    const Animal* found = zoo.search("Leo");
    if (found) {
        std::cout << "Found Leo:" << std::endl << *found;
    }
    const Animal* missing = zoo.search("Nemo");
    std::cout << "search(Nemo): " << (missing ? "found" : "not found") << std::endl;

    return 0;
}