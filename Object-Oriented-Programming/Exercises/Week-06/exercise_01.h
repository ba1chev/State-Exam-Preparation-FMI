// Напишете клас, който поддържа множество от числа в интервала [0, n] по
// подадено n в конструктора. Нека класът да бъде оптимален откъм памет.
#pragma once
#include <iostream>
#include <cstdint>

class BitSet {
private:
    size_t capacity = 8;
    uint32_t maxNumber = 0;
    uint8_t* data = nullptr;

    void free();
    void resize(const size_t newCapacity);
    void moveTo(BitSet&& other) noexcept;
    void copyFrom(const BitSet& other);
    void updateMaxNumber();

    static int getBucketIndex(const uint32_t number);
    static int getIndexInBucket(const uint32_t number);

public:
    BitSet(const int n);
    BitSet(const uint8_t* data, size_t capacity);
    BitSet(const BitSet& other);
    BitSet(BitSet&& other) noexcept;
    BitSet& operator = (const BitSet& other);
    BitSet& operator = (BitSet&& other) noexcept;
    ~BitSet();

    void addNumber(const uint32_t number);
    void removeNumber(const uint32_t number);

    void print() const;
    bool hasNumber(const uint32_t number) const;
};