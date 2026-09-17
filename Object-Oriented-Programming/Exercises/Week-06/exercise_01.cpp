#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdint>

#include "exercise_01.h"

int BitSet::getBucketIndex(const uint32_t number) {
    return number / 8;
}

int BitSet::getIndexInBucket(const uint32_t number) {
    return number % 8;
}

void BitSet::free() {
    delete[] this->data;
    this->data = nullptr;
    this->maxNumber = 0;
    this->capacity = 0;
}

void BitSet::updateMaxNumber() {
    this->maxNumber = 0;
    for (size_t i = 0; i < this->capacity; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (this->data[i] & (1 << j)) {
                this->maxNumber = std::max(this->maxNumber, (uint32_t)(8 * i + j));
            }
        }
    }
}

void BitSet::resize(const size_t newCapacity) {
    if (newCapacity < this->capacity) {
        throw std::runtime_error("Invalid input");
    }

    uint8_t* newData = new uint8_t[newCapacity]{};
    std::memcpy(newData, this->data, this->capacity * sizeof(uint8_t));
    this->capacity = newCapacity;
    delete[] this->data;
    this->data = newData;
}

void BitSet::moveTo(BitSet&& other) noexcept {
    this->data = other.data;
    this->maxNumber = other.maxNumber;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.maxNumber = 0;
    other.capacity = 0;
}

void BitSet::copyFrom(const BitSet& other) {
    this->data = new uint8_t[other.capacity]{};
    this->capacity = other.capacity;
    this->maxNumber = other.maxNumber;
    std::memcpy(this->data, other.data, other.capacity * sizeof(uint8_t));
}

BitSet::BitSet(const int n) {
    if (n < 0) {
        throw std::runtime_error("Invalid input");
    }

    this->capacity = BitSet::getBucketIndex(n) + 1;
    this->data = new uint8_t[this->capacity]{0};
    this->maxNumber = 0;
}

BitSet::BitSet(const uint8_t* data, size_t capacity) {
    if (!data) {
        throw std::runtime_error("Nullptr detected");
    }

    this->capacity = capacity;
    this->data = new uint8_t[capacity]{};
    std::memcpy(this->data, data, capacity * sizeof(uint8_t));
    this->updateMaxNumber();
}

BitSet::BitSet(const BitSet& other) {
    this->copyFrom(other);
}

BitSet::BitSet(BitSet&& other) noexcept {
    this->moveTo(std::move(other));
}

BitSet& BitSet::operator = (const BitSet& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

BitSet& BitSet::operator = (BitSet&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

BitSet::~BitSet() {
    this->free();
}

void BitSet::addNumber(const uint32_t number) {
    size_t bucketIndex = getBucketIndex(number);
    size_t indexInBucket = getIndexInBucket(number);
    if (bucketIndex >= capacity) {
        this->resize(bucketIndex + 1);
    }

    this->maxNumber = std::max(this->maxNumber, number);
    this->data[bucketIndex] |= (1 << indexInBucket);
}

void BitSet::removeNumber(const uint32_t number) {
    size_t bucketIndex = getBucketIndex(number);
    size_t indexInBucket = getIndexInBucket(number);
    if (bucketIndex >= capacity) {
        return;
    }

    this->data[bucketIndex] &= ~(1 << indexInBucket);
    this->updateMaxNumber();
}

void BitSet::print() const {
    std::cout << "{";
    for (size_t i = 0; i < this->capacity; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (this->data[i] & (1 << j)) {
                std::cout << 8 * i + j << " ";
            }
        }
    }
    std::cout << "}" << std::endl;
}

bool BitSet::hasNumber(const uint32_t number) const {
    size_t bucketIndex = getBucketIndex(number);
    size_t indexInBucket = getIndexInBucket(number);
    if (bucketIndex >= this->capacity) {
        return false;
    }
    return this->data[bucketIndex] & (1 << indexInBucket);
}