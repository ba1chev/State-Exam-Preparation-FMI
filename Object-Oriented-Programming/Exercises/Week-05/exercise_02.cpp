// Да се създаде клас Animal, който съдържа следните полета:

// вид на животното (mammal, reptile, fish, bird, amphibian, 
// ivertebrates or insect)
// име на животното с произволна дължина
// години на животното ... може да добавите още
// Да се реалзират подходящи конструктори, голяма четворка, 
// гетъри и сетъри.
// Да се създаде клас Zoo, който има име с произволна дължина и пази 
// в себе си масив от животни. В конструктора си класът приема 
// стойност за максимален капацитет на масива. Класът да поддържа следните функционалности:

// добавяне на животни до достигане на максималния капацитет
// премахване на животно по име
// връщане на броя животни от даден вид
// извеждане на инфорамцията за всички животни
// записване на животните в .csv файл
#include <iostream>
#include <cstring>
#include <fstream>

enum class AnimalType {
    Mammal, Reptile, Fish, Bird, Amphibian, Ivertebrates, Insect
};

class Animal {
private:
    AnimalType type = AnimalType::Mammal;
    char* name = nullptr;
    uint32_t age = 10;

    void free() {
        delete[] this->name;
        this->name = nullptr;
        this->age = 0;
        this->type = AnimalType::Bird;
    }

    void copyFrom(const Animal& other) {
        this->name = new char[strlen(other.name) + 1]{};
        this->age = other.age;
        this->type = other.type;
        strncpy(this->name, other.name, strlen(other.name));
    }

    void moveTo(Animal&& other) noexcept {
        this->name = other.name;
        this->age = other.age;
        this->type = other.type;

        other.name = nullptr;
        other.age = 0;
        other.type = AnimalType::Amphibian;
    }

public:
    Animal() = default;

    Animal(const char* name, const uint32_t age, AnimalType type) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        this->name = new char[strlen(name) + 1]{};
        strncpy(this->name, name, strlen(name));
        this->age = age;
        this->type = type;
    }

    Animal(const Animal& other) {
        this->copyFrom(other);
    }

    Animal(Animal&& other) noexcept {
        this->moveTo(std::move(other));
    }

    Animal& operator = (const Animal& other) {
        if (this != &other) {
            this->free();
            this->copyFrom(other);
        }
        return *this;
    }

    Animal& operator = (Animal&& other) noexcept {
        if (this != &other) {
            this->free();
            this->moveTo(std::move(other));
        }
        return *this;
    }

    ~Animal() {
        this->free();
    }

    const char* getName() const {
        return this->name;
    }

    uint32_t getAge() const {
        return this->age;
    }

    AnimalType getType() const {
        return this->type;
    }

    const char* getTypeName() const {
        switch (this->type) {
            case AnimalType::Amphibian: return "Amphibian";
            case AnimalType::Bird: return "Bird";
            case AnimalType::Fish: return "Fish";
            case AnimalType::Reptile: return "Reptile";
            case AnimalType::Insect: return "Insect";
            case AnimalType::Ivertebrates: return "Ivertebrates";
            case AnimalType::Mammal: return "Mammal";
            default: throw std::runtime_error("Unsupported animal type");
        }
    }

    void print() const {
        std::cout << this->name << " ";
        std::cout << this->age << " ";
        std::cout << this->getTypeName() << std::endl;
    }
};

class Zoo {
private:
    Animal* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free() {
        delete[] this->data;
        this->data = nullptr;
        this->capacity = 0;
        this->size = 0;
    }

    void copyFrom(const Zoo& other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new Animal[other.capacity]{};
        for (size_t i = 0; i < this->size; i++) {
            this->data[i] = other.data[i];
        }
    }

    void moveTo(Zoo&& other) noexcept {
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = other.data;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

public:
    Zoo(const size_t capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->data = new Animal[this->capacity]{};
    }

    Zoo(const Zoo& other) {
        this->copyFrom(other);
    }

    Zoo(Zoo&& other) noexcept {
        this->moveTo(std::move(other));
    }

    Zoo& operator = (const Zoo& other) {
        if (this != &other) {
            this->free();
            this->copyFrom(other);
        }
        return *this;
    }

    Zoo& operator = (Zoo&& other) noexcept {
        if (this != &other) {
            this->free();
            this->moveTo(std::move(other));
        }
        return *this;
    }

    ~Zoo() {
        this->free();
    }

    void addAnimal(const Animal& animal) {
        if (this->size == this->capacity) {
            throw std::runtime_error("Maximum capacity reached");
        }
        this->data[this->size] = animal;
        this->size += 1;
    }

    void removeAnimal(const char* name) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        int foundIndex = -1;
        for (size_t i = 0; i < this->size; i++) {
            if (!strcmp(this->data[i].getName(), name)) {
                foundIndex = i;
                break;
            }
        }
        
        if (foundIndex != - 1) {
            for (size_t i = foundIndex; i < this->size - 1; i++) {
                this->data[i] = this->data[i + 1];
            }
            this->size -= 1;
        }
    }

    size_t getCountByType(AnimalType type) const {
        size_t counter = 0;
        for (size_t i = 0; i < this->size; i++) {
            if ((int)this->data[i].getType() == (int)type) {
                counter += 1;
            }
        }
    
        return counter;
    }

    void print() const {
        for (size_t i = 0; i < this->size; i++) {
            this->data[i].print();
        }
        std::cout << std::endl;
    }

    void writeToCSV(const char* fileName) const {
        if (!fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ofstream ofs(fileName);
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ofs << "name,age,type\n";
        for (size_t i = 0; i < this->size; i++) {
            ofs << this->data[i].getName() << ","
                << this->data[i].getAge() << ","
                << this->data[i].getTypeName() << "\n";
        }

        ofs.clear();
        ofs.close();
    }
};

int main() {
    Zoo zoo(5);

    zoo.addAnimal(Animal("Rex", 4, AnimalType::Mammal));
    zoo.addAnimal(Animal("Nemo", 1, AnimalType::Fish));
    zoo.addAnimal(Animal("Tweety", 2, AnimalType::Bird));
    zoo.addAnimal(Animal("Rocky", 7, AnimalType::Mammal));

    zoo.print();

    std::cout << "Mammals: " << zoo.getCountByType(AnimalType::Mammal) << std::endl;
    std::cout << "Fish: " << zoo.getCountByType(AnimalType::Fish) << std::endl;

    zoo.removeAnimal("Nemo");
    std::cout << "After removing Nemo:" << std::endl;
    zoo.print();

    Zoo copy = zoo;
    copy.addAnimal(Animal("Slither", 3, AnimalType::Reptile));
    std::cout << "Copy:" << std::endl;
    copy.print();

    zoo.writeToCSV("zoo.csv");

    return 0;
}
