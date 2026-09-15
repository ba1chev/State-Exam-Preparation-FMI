// Да се реализира клас TreasureMap, който представя карта със скрити съкровища. 
// Всяко съкровище се описва чрез клас Treasure, която съдържа:

// име на съкровището (символен низ с максимална дължина 32)
// координати x и y (цели числа)
// стойност на съкровището (цяло число)
// Класът съхранява масив от максимум 50 съкровища и поддържа следните 
// функционалности:

// Добавяне на ново съкровище
// Премахване на съкровище по име
// Намиране на съкровище по координати
// Сортиране на съкровищата по:
// стойност
// разстояние от началната точка (0,0)
// Принтиране на всички съкровища
// Намиране на най-ценното съкровище
// Четене и записване на картата във файл
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

struct Point {
public:
    int x = 0;
    int y = 0;

    bool operator == (const Point& other) const {
        return (this->x == other.x) && (this->y == other.y);
    }

    void print() const {
        std::cout << "(" << this->x;
        std::cout << "," << this->y;
        std::cout << ")";
    }

    float getDestanceFromZero() const {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }
};

struct Treasure {
public:
    char nameOfTreasure[31 + 1] = "";
    int treasureValue = 0;
    Point point;

    void print() const {
        std::cout << nameOfTreasure << " ";
        std::cout << treasureValue << " ";
        this->point.print();
        std::cout << std::endl;
    }

    void writeToFile(std::ofstream& ofs) const {
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ofs.write((const char*)this->nameOfTreasure, sizeof(this->nameOfTreasure));
        ofs.write((const char*)&this->treasureValue, sizeof(int));
        ofs.write((const char*)&this->point, sizeof(Point));
    }

    void readFromFile(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ifs.read((char*)this->nameOfTreasure, sizeof(this->nameOfTreasure));
        ifs.read((char*)&this->treasureValue, sizeof(int));
        ifs.read((char*)&this->point, sizeof(Point));
    }
};

class TreasureMap {
private:
    Treasure treasures[50]{};
    size_t countOfTreasures = 0;
    
public:
    TreasureMap() = default;

    void addTreasure(const Treasure& treasure) {
        if (this->countOfTreasures == 50) {
            throw std::runtime_error("No more space");
        }

        this->treasures[this->countOfTreasures] = treasure;
        this->countOfTreasures += 1;
    }

    void removeTreasureByName(const char* name) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        int foundIndex = -1;
        for (size_t i = 0; i < this->countOfTreasures; i++) {
            if (!strcmp(this->treasures[i].nameOfTreasure, name)) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            for (size_t i = foundIndex; i < this->countOfTreasures - 1; i++) {
                this->treasures[i] = this->treasures[i + 1];
            }
            this->countOfTreasures -= 1;
        }
    }

    Treasure findTreasureByCoordinates(const Point& point) const {
        for (size_t i = 0; i < this->countOfTreasures; i++) {
            if (this->treasures[i].point == point) {
                return this->treasures[i];
            }
        }
        throw std::runtime_error("Treasure not found");
    }

    typedef bool (*SortingPredicate)(const Treasure&, const Treasure&);
    void sortTreasures(SortingPredicate predicate) {
        for (size_t i = 0; i < this->countOfTreasures - 1; i++) {
            for (size_t j = 0; j < this->countOfTreasures - i - 1; j++) {
                if (predicate(this->treasures[j], this->treasures[j + 1])) {
                    Treasure temp = this->treasures[j];
                    this->treasures[j] = this->treasures[j + 1];
                    this->treasures[j + 1] = temp;
                }   
            }
        }
    }

    Treasure findMostValuable() const {
        Treasure result = this->treasures[0];
        for (size_t i = 1; i < this->countOfTreasures; i++) {
            if (this->treasures[i].treasureValue > result.treasureValue) {
                result = this->treasures[i];
            }
        }
        return result;
    }

    void printTreasures() const {
        for (size_t i = 0; i < this->countOfTreasures; i++) {
            this->treasures[i].print();
        }
        std::cout << std::endl;
    }

    void writeToFile(std::ofstream& ofs) const {
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ofs.write((const char*)&this->countOfTreasures, sizeof(size_t));
        for (size_t i = 0; i < this->countOfTreasures; i++) {
            this->treasures[i].writeToFile(ofs);
        }
    }
    
    void readFromFile(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ifs.read((char*)&this->countOfTreasures, sizeof(size_t));
        for (size_t i = 0; i < this->countOfTreasures; i++) {
            this->treasures[i].readFromFile(ifs);
        }
    }
};  

int main() {
    TreasureMap map;
    Treasure treasure1 = {"GoldChest", 500, 10, 5};
    Treasure treasure2 = {"AncientCoin", 200, -3, 7};
    Treasure treasure3 = {"SilverRing", 150, 22, 1};

    map.addTreasure(treasure1);
    map.addTreasure(treasure2);
    map.addTreasure(treasure3);
    map.printTreasures();
    
    map.sortTreasures([](const Treasure& left, const Treasure& right) {
        return left.treasureValue > right.treasureValue;
    });
    map.printTreasures();
    map.sortTreasures([](const Treasure& left, const Treasure& right){
        return left.point.getDestanceFromZero() > right.point.getDestanceFromZero();
    });
    map.printTreasures();

    Treasure treause = map.findMostValuable();
    std::cout << treause.nameOfTreasure << std::endl << std::endl;

    std::ofstream ofs("test.bin", std::ios::binary);
    map.writeToFile(ofs);
    ofs.close();

    std::ifstream ifs("test.bin", std::ios::binary);
    TreasureMap map2;
    map2.readFromFile(ifs);
    map2.printTreasures();
    ifs.close();

    return 0;
}