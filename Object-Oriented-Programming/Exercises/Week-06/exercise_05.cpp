#include <cstring>
#include <algorithm>

#include "exercise_05.h"

void MultiSet::free() {
    delete[] this->data;
    this->data = nullptr;
    this->bitsPerNumber = 0;
    this->capacity = 0;
    this->maxNumber = 0;
}

void MultiSet::copyFrom(const MultiSet& other) {
    this->capacity = other.capacity;
    this->maxNumber = other.maxNumber;
    this->bitsPerNumber = other.bitsPerNumber;
    this->data = new uint8_t[this->capacity]{};
    std::memcpy(this->data, other.data, this->capacity * sizeof(uint8_t));
}

void MultiSet::moveTo(MultiSet&& other) noexcept {
    this->capacity = other.capacity;
    this->maxNumber = other.maxNumber;
    this->bitsPerNumber = other.bitsPerNumber;
    this->data = other.data;

    other.data = nullptr;
    other.capacity = 0;
    other.maxNumber = 0;
    other.bitsPerNumber = 0;
}

void MultiSet::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    uint8_t* newData = new uint8_t[newCapacity]{};
    std::memcpy(newData, this->data, this->capacity * sizeof(uint8_t));
    delete[] this->data;
    this->data = newData;
    this->capacity = newCapacity;
}

size_t MultiSet::getBitPosition(const size_t number, const size_t k) {
    return number * k;
}

size_t MultiSet::getByteIndex(const size_t number, const size_t k) {
    return MultiSet::getBitPosition(number, k) / 8;
}

size_t MultiSet::getByteOffset(const size_t number, const size_t k) {
    return MultiSet::getBitPosition(number, k) % 8;
}

MultiSet::MultiSet(const size_t n, const size_t k) {
    if (k < 1 || k > 8) {
        throw std::runtime_error("Invalid input");
    }

    this->maxNumber = n;
    this->bitsPerNumber = k;
    this->capacity = ((n + 1) * k + 7) / 8;
    this->data = new uint8_t[this->capacity]{};
}

MultiSet::MultiSet(const MultiSet& other) {
    this->copyFrom(other);
}

MultiSet::MultiSet(MultiSet&& other) noexcept {
    this->moveTo(std::move(other));
}

MultiSet& MultiSet::operator = (const MultiSet& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

MultiSet& MultiSet::operator = (MultiSet&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

MultiSet& MultiSet::operator |= (const MultiSet& other) {
    if (this->maxNumber != other.maxNumber || this->bitsPerNumber != other.bitsPerNumber) {
        throw std::runtime_error("Incompatible multisets");
    }

    for (size_t i = 0; i <= this->maxNumber; i++) {
        size_t maxCount = std::max(this->getCount(i), other.getCount(i));
        this->removeNumber(i);
        for (size_t j = 0; j < maxCount; j++) {
            this->addNumber(i);
        }
    }
    return *this;
}

MultiSet& MultiSet::operator &= (const MultiSet& other) {
    if (this->maxNumber != other.maxNumber || this->bitsPerNumber != other.bitsPerNumber) {
        throw std::runtime_error("Incompatible multisets");
    }

    for (size_t i = 0; i <= this->maxNumber; i++) {
        size_t minCount = std::min(this->getCount(i), other.getCount(i));
        this->removeNumber(i);
        for (size_t j = 0; j < minCount; j++) {
            this->addNumber(i);
        }
    }
    return *this;
}

MultiSet::~MultiSet() {
    this->free();
}

MultiSet operator | (const MultiSet& left, const MultiSet& right) {
    MultiSet result = left;
    result |= right;
    return result;
}

MultiSet operator & (const MultiSet& left, const MultiSet& right) {
    MultiSet result = left;
    result &= right;
    return result;
}

void MultiSet::serialize(const char* fileName) const {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs.write((const char*)&this->maxNumber, sizeof(size_t));
    ofs.write((const char*)&this->bitsPerNumber, sizeof(size_t));
    ofs.write((const char*)&this->capacity, sizeof(size_t));
    ofs.write((const char*)this->data, this->capacity * sizeof(uint8_t));

    ofs.clear();
    ofs.close();
}

void MultiSet::deserialize(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ifs.read((char*)&this->maxNumber, sizeof(size_t));
    ifs.read((char*)&this->bitsPerNumber, sizeof(size_t));
    ifs.read((char*)&this->capacity, sizeof(size_t));
    ifs.read((char*)this->data, this->capacity * sizeof(uint8_t));

    ifs.clear();
    ifs.close();
}

std::ostream& operator << (std::ostream& os, const MultiSet& set) {
    os << "{";
    for (size_t i = 0; i <= set.maxNumber; i++) {
        size_t count = set.getCount(i);
        for (size_t j = 0; j < count; j++) {
            os << i << " ";
        }
    }
    os << "}";
    return os;
}

size_t MultiSet::getCount(const size_t number) const {
    if (number > this->maxNumber) {
        throw std::out_of_range("Number is out of range");
    }

    size_t bitPosition = getBitPosition(number, this->bitsPerNumber);
    size_t result = 0;
    for (size_t i = 0; i < this->bitsPerNumber; i++) {
        size_t currentBit = bitPosition + i;
        if (this->data[currentBit / 8] & (1 << (currentBit % 8))) {
            result |= (1 << i);
        }
    }
    return result;
}

void MultiSet::addNumber(const size_t number) {
    size_t currentCount = this->getCount(number);
    size_t maxCount = (1 << this->bitsPerNumber) - 1;
    if (currentCount == maxCount) {
        return;
    }

    size_t newCount = currentCount + 1;
    size_t bitPosition = getBitPosition(number, this->bitsPerNumber);
    for (size_t i = 0; i < this->bitsPerNumber; i++) {
        size_t currentBit = bitPosition + i;
        if (newCount & (1 << i)) {
            this->data[currentBit / 8] |= (1 << (currentBit % 8));
        } else {
            this->data[currentBit / 8] &= ~(1 << (currentBit % 8));
        }
    }
}

void MultiSet::removeNumber(const size_t number) {
    size_t bitPosition = getBitPosition(number, this->bitsPerNumber);
    for (size_t i = 0; i < this->bitsPerNumber; i++) {
        size_t currentBit = bitPosition + i;
        this->data[currentBit / 8] &= ~(1 << (currentBit % 8));
    }
}

bool MultiSet::hasNumber(const size_t number) const {
    return this->getCount(number) > 0;
}

void MultiSet::complement() {
    size_t maxCount = (1 << this->bitsPerNumber) - 1;
    for (size_t i = 0; i <= this->maxNumber; i++) {
        size_t newCount = maxCount - this->getCount(i);
        this->removeNumber(i);
        for (size_t j = 0; j < newCount; j++) {
            this->addNumber(i);
        }
    }
}

void MultiSet::printMemory() const {
    for (size_t i = 0; i < this->capacity; i++) {
        for (size_t j = 8; j > 0; j--) {
            std::cout << ((this->data[i] >> (j - 1)) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}