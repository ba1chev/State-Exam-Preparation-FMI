// Да се реализира клас Car с член-данните:

// Марка – низ с дължина не повече от 100 символа
// Модел – низ с дължина не повече от 100 символа
// Тип двигател – тип, приемащ само 3 възможни стойности: GASOLINE, DIESEL, ELECTRICITY
// Булева променлива, показваща дали колата е употребявана или не
// Пробег (т.е. изминати километри) – цяло число без знак
// Цена – реално число.
// Реализирайте следните функционалности за класа:

// Конструиране на кола (с конструктор) по подадени параметри за всички данни без 
// пробег и употребяваност. Конструктора ще създава „нова“ кола. Задайте на стойности по 
// подразбиране за параметрите. Счита се, че новата кола не е употребявана и има пробег 0км.
// Принтиране на информация за кола – съобщава за всички нейни параметри
// Функция drive(unsigned kilometers), с която се „кара колата“ на посочения брой 
// километри – т.е. увеличава се пробега и ако не е употребявана, става употребена. 
// Цената да намалява с 0.1% за всеки изминат километър.
// getter-и за данните (можете да прецените от следващия клас за кои данни са нужни getter-и)
// Да се реализира клас Dealership, който представлява автокъща. Една автокъща съдържа 
// поредица от коли и нека максималният капацитет за коя да е автокъща е 1000 коли. 
// Реализирайте следните конструктори:

// Конструктор, приемащ масив от коли и размера му и инициализиращ колите в автокъщата 
// с дадените.
// Конструктор, приемащ масив от коли, размера му и тип двигател, и инициализиращ 
// колите в автокъщата с тези от дадените в масива, които са с подадения тип двигател.
// Конструктор, приемащ масив от коли, размера му и име на модел и инициализиращ колите в 
// автокъщата с тези от дадените в масива, които са от същия модел като подадения. Да се 
// реализират следните член-функции за класа Dealership:
// Функция, връщаща броя коли в автокъщата.
// Функция, добавяща кола в автокъщата (ако може)
// Функция, премахва кола от автокъщата по дадени марка и модел (ако има такава)
// Функцията, която прави test drive на всички коли в автокъщата – т.е. кара за по 1км 
// всяка от колите.
// Функция, приемаща име на модел и ако съществува кола от този модел в автокъщата, печата
//  пълна информация за него.
// Функция, която връща колата в автокъщата с най-висока цена.
// Функция, която приема обект кола и връща средната цена на всичките коли в автокъщата, 
// които са от същата марка като подадената кола.
#include <iostream>
#include <cstring>

enum class CarEngine {
    GASOLINE, DIESEL, ELECTRICITY
};

class Car {
private:
    char brand[100 + 1] = "";
    char model[100 + 1] = "";
    CarEngine engine = CarEngine::DIESEL;
    bool isSecondHand = false;
    unsigned int mileage = 0;
    float price = 0.0f;

public:
    Car(const char* brand = "", const char* model = "", CarEngine engine = CarEngine::DIESEL, const float price = 0.0f) {
        if (!brand || !model) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->brand, brand, strlen(brand));
        strncpy(this->model, model, strlen(model));
        this->engine = engine;
        this->isSecondHand = false;
        this->mileage = 0;
        this->price = price;
    }

    void print() const {
        std::cout << this->brand << " ";
        std::cout << this->model << " ";
        switch (this->engine) {
            case CarEngine::DIESEL: {
                std::cout << "DIESEL" << " ";
                break;
            }
            case CarEngine::ELECTRICITY: {
                std::cout << "ELECTRICITY" << " ";
                break;
            }
            case CarEngine::GASOLINE: {
                std::cout << "GASOLINE" << " ";
                break;
            }
            default: {
                throw std::runtime_error("Unsupported car engine");
            }
        }
        std::cout << this->price << " ";
        std::cout << this->isSecondHand << " ";
        std::cout << this->mileage << std::endl;
    }

    void drive(const unsigned int kilometers) {
        this->mileage += kilometers;
        for (unsigned int i = 0; i < kilometers; i++) {
            this->price -= this->price * 0.001f;
        }
        this->isSecondHand = true;
    }

    const char* getModel() const {
        return this->model;
    }

    const char* getBrand() const {
        return this->brand;
    }

    float getPrice() const {
        return this->price;
    }

    CarEngine getEngine() const {
        return this->engine;
    }

    unsigned int getMileage() const {
        return this->mileage;
    }

    bool getIsSecondHand() const {
        return this->isSecondHand;
    }
};

class Dealership {
private:
    Car cars[1000]{};
    size_t countOfCars = 0;

public:
    Dealership(const Car* cars, size_t countOfCars) {
        if (!cars) {
            throw std::runtime_error("Nullptr detected");
        }
        if (countOfCars > 1000) {
            throw std::runtime_error("No more space");
        }

        this->countOfCars = countOfCars;
        for (size_t i = 0; i < this->countOfCars; i++) {
            this->cars[i] = cars[i];
        }
    }

    Dealership(const Car* cars, size_t countOfCars, CarEngine targetedEngine) {
        if (!cars) {
            throw std::runtime_error("Nullptr detected");
        }

        size_t counter = 0;
        for (size_t i = 0; i < countOfCars; i++) {
            if (cars[i].getEngine() == targetedEngine) {
                this->cars[counter] = cars[i];
                counter += 1;
            }
        }
        this->countOfCars = counter;
    }

    Dealership(const Car* cars, size_t countOfCars, const char* targetedModel) {
        if (!cars || !targetedModel) {
            throw std::runtime_error("Nullptr detected");
        }

        size_t counter = 0;
        for (size_t i = 0; i < countOfCars; i++) {
            if (!strcmp(cars[i].getModel(), targetedModel)) {
                this->cars[counter] = cars[i];
                counter += 1;
            }
        }
        this->countOfCars = counter;
    }

    size_t getCarsCount() const {
        return this->countOfCars;
    }

    void addCar(const Car& car) {
        if (this->countOfCars == 1000) {
            throw std::runtime_error("No more space");
        }
        this->cars[this->countOfCars] = car;
        this->countOfCars += 1;
    }

    void removeCarByBrandAndModel(const char* brand, const char* model) {
        if (!brand || !model) {
            throw std::runtime_error("Nullptr detected");
        }

        int foundIndex = -1;
        for (size_t i = 0; i < this->countOfCars; i++) {
            if (!strcmp(this->cars[i].getBrand(), brand) &&
                !strcmp(this->cars[i].getModel(), model)) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            for (size_t i = foundIndex; i < this->countOfCars - 1; i++) {
                this->cars[i] = this->cars[i + 1];
            }
            this->countOfCars -= 1;
        }
    }

    void testDrive() {
        for (size_t i = 0; i < this->countOfCars; i++) {
            this->cars[i].drive(1);
        }
    }

    void findCarByModel(const char* model) const {
        if (!model) {
            throw std::runtime_error("Nullptre detected");
        }

        for (size_t i = 0; i < this->countOfCars; i++) {
            if (!strcmp(this->cars[i].getModel(), model)) { 
                this->cars[i].print();
            }
        }
    }

    Car getMostExpensiveCar() const {
        Car result = this->cars[0];
        for (size_t i = 1; i < this->countOfCars; i++) {
            if (this->cars[i].getPrice() > result.getPrice()) {
                result = this->cars[i];
            }
        }
        return result;
    }

    float getAvaragePriceBy(const Car& car) const {
        size_t counter = 0;
        float result = 0.0f;
        for (size_t i = 0; i < this->countOfCars; i++) {
            if (!strcmp(this->cars[i].getBrand(), car.getBrand())) {
                result += this->cars[i].getPrice();
                counter += 1;
            }
        }
        return result / (counter + 0.0f);
    }
};

int main() {
    Car cars[] = {
        {"BMW", "M3", CarEngine::GASOLINE, 50000.0f},
        {"BMW", "M5", CarEngine::GASOLINE, 70000.0f},
        {"Audi", "A4", CarEngine::DIESEL, 40000.0f},
        {"Tesla", "Model 3", CarEngine::ELECTRICITY, 45000.0f}
    };
    size_t countOfCars = sizeof(cars) / sizeof(Car);

    Dealership dealership(cars, countOfCars);
    std::cout << dealership.getCarsCount() << std::endl << std::endl;

    Dealership gasolineDealership(cars, countOfCars, CarEngine::GASOLINE);
    std::cout << gasolineDealership.getCarsCount() << std::endl << std::endl;

    Dealership modelDealership(cars, countOfCars, "M3");
    std::cout << modelDealership.getCarsCount() << std::endl << std::endl;

    dealership.addCar({"Audi", "A6", CarEngine::DIESEL, 55000.0f});
    std::cout << dealership.getCarsCount() << std::endl << std::endl;

    dealership.findCarByModel("A6");
    std::cout << std::endl;

    dealership.testDrive();
    dealership.findCarByModel("M3");
    std::cout << std::endl;

    dealership.getMostExpensiveCar().print();
    std::cout << std::endl;

    std::cout << dealership.getAvaragePriceBy(cars[0]) << std::endl << std::endl;

    dealership.removeCarByBrandAndModel("BMW", "M3");
    std::cout << dealership.getCarsCount() << std::endl;

    return 0;
}