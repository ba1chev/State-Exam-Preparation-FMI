// Напишете клас МultiSet, който съдържа мултимножество от числа в диапазона от 0 до n, където n е подадено в конструктора. 
// В конструктора се подават 2 числа: n (най-голямото число в множеството) и k - колко най-много бита са необходими за 
// запазването на броя срещания на едно число (1 <= k <= 8). Това означава, че всяко число може да се среща в множеството 
// най-много 2^k-1 пъти.
// Класът ви трябва да е максимално оптимален откъм памет.

// Трябва да поддържате следните функционалности:

// Добавяне на число.
// Проверка колко пъти се съдържа число.
// Принтиране на всички числа, които се съдържат в мултимножеството.
// Принтиране на това как мултимножеството е представено в паметта.
// Сериализация/десериализация в/от двоичен файл.
// Сечение/Разлика на две мултимножества.
// Допълнение на мултимножество (ако x се е срещал p пъти, то в допълнението се среща 2^k - 1 - p пъти).
#pragma once
#include <iostream>
#include <fstream>

class MultiSet {
private:
    size_t maxNumber = 0;
    size_t bitsPerNumber = 0;
    
    uint8_t* data = nullptr;
    size_t capacity = 0;

    void free();
    void copyFrom(const MultiSet& other);
    void moveTo(MultiSet&& other) noexcept;
    void resize(const size_t newCapacity);

    static size_t getByteIndex(const size_t number, const size_t k);
    static size_t getByteOffset(const size_t number, const size_t k);
    static size_t getBitPosition(const size_t number, const size_t k);

public:
    MultiSet(const size_t n, const size_t k);
    MultiSet(const MultiSet& other);
    MultiSet(MultiSet&& other) noexcept;
    MultiSet& operator = (const MultiSet& other);
    MultiSet& operator = (MultiSet&& other) noexcept;
    MultiSet& operator |= (const MultiSet& other);
    MultiSet& operator &= (const MultiSet& other);
    ~MultiSet();

    void addNumber(const size_t number);
    void removeNumber(const size_t number);
    bool hasNumber(const size_t number) const;
    size_t getCount(const size_t number) const;
    void complement();

    void serialize(const char* fileName) const;
    void deserialize(const char* fileName);
    void printMemory() const;

    friend std::ostream& operator << (std::ostream& os, const MultiSet& set);
};

MultiSet operator | (const MultiSet& left, const MultiSet& right);
MultiSet operator & (const MultiSet& left, const MultiSet& right);