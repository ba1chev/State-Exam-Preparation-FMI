// Да се дефинира клас Ship със следните характеристики:

// Име на кораб – символен низ, разположен в динамичната памет
// Година на пускане по вода
// Клас на кораб – допустими стойности са единствено bb (battleship) и bc 
// (battlecruiser)
// Брой оръдия Да се реализират подходящи конструктори, гетъри и сетъри.
// Да се дефинира клас Navy (военоморски флот) със следните характеристики:

// Държава на военоморския флот – символен низ, разположен в динамичната памет

// Масив от кораби с максимален размер 30 Да се реализират член-функции за:

// Добавяне на кораб във флота

// Премахване на кораб от флота по име

// Връщане на констатна референция/указател за кораб на подадена позиция в масива

// Връщане на брой кораби във флота

// Сравняване с друг флот по общ брой оръдия на корабите. Функцията да връща -1, 
// ако текущият флот е с по-малко оръжия, 1 - ако е с повече, и 0 при равен брой.
#include <iostream>
#include <cstring>

enum class ShipClass {
    Battleship, Battlecruiser
};

class Ship {
private:
    char* name = nullptr;
    size_t releaseYear = 2000;
    ShipClass cls = ShipClass::Battlecruiser;
    size_t countOfWeapons = 0;

    void free() {
        delete[] this->name;
        this->name = nullptr;
        this->countOfWeapons = 0;
    }

    void copyFrom(const Ship& other) {
        this->name = new char[strlen(other.name) + 1]{};
        strncpy(this->name, other.name, strlen(other.name));
        this->releaseYear = other.releaseYear;
        this->cls = other.cls;
        this->countOfWeapons = other.countOfWeapons;
    }

    void moveTo(Ship&& other) noexcept {
        this->name = other.name;
        this->releaseYear = other.releaseYear;
        this->cls = other.cls;
        this->countOfWeapons = other.countOfWeapons;

        other.name = nullptr;
        other.countOfWeapons = 0;
        other.cls = ShipClass::Battlecruiser;
    }
 
public:
    Ship() = default;

    Ship(const char* name, const size_t countOfWeapons, const size_t releaseYear, ShipClass cls) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        this->name = new char[strlen(name) + 1]{};
        strncpy(this->name, name, strlen(name));
        this->countOfWeapons = countOfWeapons;
        this->releaseYear = releaseYear;
        this->cls = cls;
    }

    Ship(const Ship& other) {
        this->copyFrom(other);
    }

    Ship(Ship&& other) noexcept {
        this->moveTo(std::move(other));
    }

    Ship& operator = (const Ship& other) {
        if (this != &other) {
            this->free();
            this->copyFrom(other);
        }
        return *this;
    }

    Ship& operator = (Ship&& other) noexcept {
        if (this != &other) {
            this->free();
            this->moveTo(std::move(other));
        }
        return *this;
    }

    ~Ship() {
        this->free();
    }

    const char* getName() const {
        return this->name;
    }

    size_t getCountOfWeapons() const {
        return this->countOfWeapons;
    }

    size_t getReleaseYear() const {
        return this->releaseYear;
    }

    ShipClass getShipClass() const {
        return this->cls;
    }
};

class Navy {
private:
    char* name = nullptr;
    Ship ships[30]{};
    size_t countOfShips = 0;

    void free() {
        delete[] this->name;
        this->name = nullptr;
        this->countOfShips = 0;
    }

    void copyFrom(const Navy& other) {
        this->name = new char[strlen(other.name) + 1]{};
        strncpy(this->name, other.name, strlen(other.name));

        this->countOfShips = other.countOfShips;
        for (size_t i = 0; i < this->countOfShips; i++) {
            this->ships[i] = other.ships[i];
        }
    }

    void moveTo(Navy&& other) noexcept {
        this->name = other.name;
        this->countOfShips = other.countOfShips;
        for (size_t i = 0; i < this->countOfShips; i++) {
            this->ships[i] = other.ships[i];
        }

        other.name = nullptr;
        other.countOfShips = 0;
    }

    int findShipByName(const char* name) const {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        for (size_t i = 0; i < this->countOfShips; i++) {
            if (!strcmp(this->ships[i].getName(), name)) {
                return i;
            }
        }
        return -1;
    }

    size_t getOverallCountOfWeapons() const {
        size_t result = 0;
        for (size_t i = 0; i < this->countOfShips; i++) {
            result += this->ships[i].getCountOfWeapons();
        }
        return result;
    }

public:
    Navy() = default;

    Navy(const Navy& other) {
        this->copyFrom(other);
    }

    Navy(Navy&& other) noexcept {
        this->moveTo(std::move(other));
    }

    Navy& operator = (const Navy& other) {
        if (this != &other) {
            this->free();
            this->copyFrom(other);
        }
        return *this;
    }

    Navy& operator = (Navy&& other) noexcept {
        if (this != &other) {
            this->free();
            this->moveTo(std::move(other));
        }
        return *this;
    }

    ~Navy() {
        this->free();
    }

    void addShip(const Ship& ship) {
        if (this->countOfShips == 30) {
            throw std::runtime_error("No more available space");
        }
        this->ships[this->countOfShips] = ship;
        this->countOfShips += 1;
    }

    void removeShip(const char* name) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }
        int index = this->findShipByName(name);
        if (index != -1) {
            for (size_t i = index; i < this->countOfShips - 1; i++) {
                this->ships[i] = this->ships[i + 1];
            }
            this->countOfShips -= 1;
        }
    }

    Ship& operator [] (size_t index) {
        if (index >= this->countOfShips) {
            throw std::out_of_range("Index is out of range");
        }
        return this->ships[index];
    }

    const Ship& operator [] (size_t index) const {
        if (index >= this->countOfShips) {
            throw std::out_of_range("Index is out of range");
        }
        return this->ships[index];
    }

    size_t getCountOfShips() const {
        return this->countOfShips;
    }

    int compareWithOtherNavy(const Navy& other) {
        size_t leftCount = this->getOverallCountOfWeapons();
        size_t rightCount = other.getOverallCountOfWeapons();

        if (leftCount > rightCount) {
            return 1;
        } else if (leftCount < rightCount) {
            return -1;
        } else {
            return 0;
        }
    }
};

int main() {
    Navy navy;

    navy.addShip(Ship("Bismarck", 12, 1939, ShipClass::Battleship));
    navy.addShip(Ship("Hood", 8, 1918, ShipClass::Battlecruiser));
    navy.addShip(Ship("Yamato", 18, 1940, ShipClass::Battleship));

    std::cout << "Ships in navy: " << navy.getCountOfShips() << std::endl;
    for (size_t i = 0; i < navy.getCountOfShips(); i++) {
        std::cout << navy[i].getName() << " " << navy[i].getCountOfWeapons() << std::endl;
    }

    navy.removeShip("Hood");
    std::cout << "After removing Hood: " << navy.getCountOfShips() << std::endl;

    Navy other;
    other.addShip(Ship("Iowa", 9, 1942, ShipClass::Battleship));

    std::cout << "Compare: " << navy.compareWithOtherNavy(other) << std::endl;

    return 0;
}