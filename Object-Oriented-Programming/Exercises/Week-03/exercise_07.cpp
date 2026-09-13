// Да се напише структура Car, която да съдържа, марка (enum class, създайте няколко 
// енумератора по избор) име на собственик (символен низ с максимална дължина 24 символа), 
// средна скорост (реална стойност), стойности на наложени глоби (реални стойности, най-много 20) 
// и техния брой

// Да се напише функция, която пресмята сумата от всички глоби на дадена кола.
// Да се напише функция, която добавя глоба към дадена кола. Функцията да не прави нищо, ако 
// максималният брой глоби е достигнат.
// Да се нашише функция, която извежда на стандартния изход информацията за дадена кола.
// Да се напише функция, която чете масив от коли с произволна дължина от двоичен файл. 
// Функцията сортира колите по средна скорост във възходящ ред и ги записва обратно в 
// двоичния файл.
#include <iostream>
#include <fstream>
#include <cstring>

enum class Brand{
    BWM, AUDI, MERCEDES
};

struct Car {
public:
    char nameOfOwner[24 + 1] = "";
    Brand brand = Brand::BWM;
    float avrageSpeed = 100.0f;
    float fines[20]{};
    size_t countOfFines = 0;
};

float getAllFinesValue(const Car& car) {
    float result = 0.0f;
    for (size_t i = 0; i < car.countOfFines; i++) {
        result += car.fines[i];
    }
    
    return result;
}

void addFine(Car& car, const float newFine) {
    if (car.countOfFines == 20) {
        return;
    }

    car.fines[car.countOfFines] = newFine;
    car.countOfFines += 1;
}

void printCar(const Car& car) {
    std::cout << "Owner of the car: " << car.nameOfOwner << std::endl;
    switch (car.brand) {
        case Brand::BWM: {
            std::cout << "Car brand is: BMW" << std::endl;
            break;
        }
        case Brand::AUDI: {
            std::cout << "Car brand is: AUDI" << std::endl;
            break;
        }
        case Brand::MERCEDES: {
            std::cout << "Car brand is: MERCEDES" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupporeted car brand");
        }
    }
    std::cout << "Avarage speed is: " << car.avrageSpeed << std::endl;
    std::cout << "Count of fines is: " << car.countOfFines << std::endl;
}

void serialize(std::ofstream& ofs, const Car& car) {
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs.write((const char*)car.nameOfOwner, sizeof(car.nameOfOwner));
    ofs.write((const char*)&car.brand, sizeof(Brand));
    ofs.write((const char*)&car.avrageSpeed, sizeof(float));
    ofs.write((const char*)car.fines, sizeof(car.fines));
    ofs.write((const char*)&car.countOfFines, sizeof(size_t));
    ofs.clear();
}

void dserialize(std::ifstream& ifs, Car& car) {
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ifs.read((char*)car.nameOfOwner, sizeof(car.nameOfOwner));
    ifs.read((char*)&car.brand, sizeof(Brand));
    ifs.read((char*)&car.avrageSpeed, sizeof(float));
    ifs.read((char*)car.fines, sizeof(car.fines));
    ifs.read((char*)&car.countOfFines, sizeof(size_t));
}

void sortCarsBySpeed(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    Car cars[100]{};
    size_t countOfCars = 0;
    while (countOfCars < 100) {
        Car current;
        dserialize(ifs, current);
        if (!ifs) {
            break;
        }
        cars[countOfCars] = current;
        countOfCars += 1;
    }

    ifs.clear();
    ifs.close();

    for (size_t i = 0; i + 1 < countOfCars; i++) {
        for (size_t j = 0; j + 1 < countOfCars - i; j++) {
            if (cars[j].avrageSpeed > cars[j + 1].avrageSpeed) {
                Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }

    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    for (size_t i = 0; i < countOfCars; i++) {
        serialize(ofs, cars[i]);
    }

    ofs.clear();
    ofs.close();
}

int main() {
    Car first{};
    strncpy(first.nameOfOwner, "Ivan", 24);
    first.brand = Brand::AUDI;
    first.avrageSpeed = 150.0f;
    addFine(first, 50.0f);
    addFine(first, 120.0f);

    Car second{};
    strncpy(second.nameOfOwner, "Petar", 24);
    second.brand = Brand::BWM;
    second.avrageSpeed = 90.0f;

    Car third{};
    strncpy(third.nameOfOwner, "Gosho", 24);
    third.brand = Brand::MERCEDES;
    third.avrageSpeed = 120.0f;

    std::ofstream ofs("cars.bin", std::ios::binary);
    serialize(ofs, first);
    serialize(ofs, second);
    serialize(ofs, third);
    ofs.close();

    sortCarsBySpeed("cars.bin");

    std::ifstream ifs("cars.bin", std::ios::binary);
    Car current{};
    while (true) {
        dserialize(ifs, current);
        if (!ifs) {
            break;
        }
        printCar(current);
        std::cout << "Sum of fines: " << getAllFinesValue(current) << std::endl;
    }
    ifs.close();

    return 0;
}