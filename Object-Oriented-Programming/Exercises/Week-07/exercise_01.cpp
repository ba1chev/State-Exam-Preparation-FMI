#include "exercise_01.h"
#include <cstring>

SpecialCustomFunction::SpecialCustomFunction(const int* data, const size_t size, FunctionPredicate function) {
    if (!data || !function) {
        throw std::runtime_error("Nullptr detected");
    }

    this->size = size;
    this->function = function;
    this->data = new int[this->size]{};
    std::memcpy(this->data, data, this->size * sizeof(int));
}

SpecialCustomFunction::SpecialCustomFunction(const SpecialCustomFunction& other) {
    this->copyFrom(other);
}

SpecialCustomFunction::SpecialCustomFunction(SpecialCustomFunction&& other) noexcept {
    this->moveTo(std::move(other));
}

SpecialCustomFunction& SpecialCustomFunction::operator = (const SpecialCustomFunction& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

SpecialCustomFunction& SpecialCustomFunction::operator = (SpecialCustomFunction&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

SpecialCustomFunction::~SpecialCustomFunction() {
    this->free();
}

void SpecialCustomFunction::free() {
    delete[] this->data;
    this->data = nullptr;
    this->function = nullptr;
    this->size = 0;
}

void SpecialCustomFunction::copyFrom(const SpecialCustomFunction& other) {
    this->data = new int[other.size]{};
    this->size = other.size;
    this->function = other.function;
    std::memcpy(this->data, other.data, sizeof(int) * other.size);
}

void SpecialCustomFunction::moveTo(SpecialCustomFunction&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->function = other.function;

    other.data = nullptr;
    other.size = 0;
    other.function = nullptr;
}

void SpecialCustomFunction::increaseBy(int offset) {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] += offset;
    }
}

int SpecialCustomFunction::findSpecialNumberIndex(const int number) const {
    for (size_t i = 0; i < this->size; i++) {
        if (this->data[i] == number) {
            return i;
        }
    }
    return -1;
}

int SpecialCustomFunction::operator ()(const int number) const {
    int index = this->findSpecialNumberIndex(number);
    if (index != -1) {
        return UTILS::getPower2(number);
    }
    return this->function(number);
}
    
SpecialCustomFunction& SpecialCustomFunction::operator ++ () {
    this->increaseBy(1);
    return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator ++ (int dummy) {
    SpecialCustomFunction result = *this;
    this->increaseBy(1);
    return result;
}

SpecialCustomFunction& SpecialCustomFunction::operator -- () {
    this->increaseBy(-1);
    return *this;
}
    
SpecialCustomFunction SpecialCustomFunction::operator -- (int dummy) {
    SpecialCustomFunction result = *this;
    this->increaseBy(-1);
    return result;
}

SpecialCustomFunction SpecialCustomFunction::operator ! () const {
    SpecialCustomFunction result = *this;
    for (size_t i = 0; i < result.size; i++) {
        result.data[i] *= -1;
    }
    return result;
}