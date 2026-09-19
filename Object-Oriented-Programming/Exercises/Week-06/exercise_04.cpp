#include <cstring>

#include "exercise_04.h"

void NumberSeries::free() {
    delete[] this->data;
    this->data = nullptr;
    this->predicate = nullptr;
    this->size = 0;
    this->firstElement = 0;
    this->capacity = 0;
}

void NumberSeries::clearCache() {
    delete[] this->data;
    this->capacity = 8;
    this->data = new int[this->capacity]{};
    this->size = 0;
}

void NumberSeries::appendData(const int element) {
    if (this->size == this->capacity) {
        this->resize(this->capacity * 2);
    }
    this->data[this->size] = element;
    this->size += 1;
}

void NumberSeries::copyFrom(const NumberSeries& other) {
    this->data = new int[other.capacity]{};
    this->size = other.size;
    this->capacity = other.capacity;
    this->predicate = other.predicate;
    this->firstElement = other.firstElement;
    std::memcpy(this->data, other.data, other.size * sizeof(int));
}

int NumberSeries::checkInnerData(const int element) const {
    for (size_t i = 0; i < this->size; i++) {
        if (this->data[i] == element) {
            return i;
        }
    }
    return -1;
}

void NumberSeries::moveTo(NumberSeries&& other) noexcept {
    this->data = other.data;
    this->predicate = other.predicate;
    this->firstElement = other.firstElement;
    this->capacity = other.capacity;
    this->size = other.size;

    other.data = nullptr;
    other.predicate = nullptr;
    other.firstElement = 0;
    other.capacity = 0;
    other.size = 0;
}

void NumberSeries::resize(size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    this->capacity = newCapacity;
    int* newData = new int[this->capacity]{};
    std::memcpy(newData, this->data, this->size * sizeof(int));
    delete[] this->data;
    this->data = newData;
}

NumberSeries::NumberSeries(const int firstElement, SeriesPredicate predicate) {
    if (!predicate) {
        throw std::runtime_error("Nullptr detected");
    }

    this->firstElement = firstElement;
    this->predicate = predicate;
    this->capacity = 8;
    this->data = new int[this->capacity]{};
    this->size = 0;
}

NumberSeries::NumberSeries(const NumberSeries& other) {
    this->copyFrom(other);
}

NumberSeries::NumberSeries(NumberSeries&& other) noexcept {
    this->moveTo(std::move(other));
}

NumberSeries& NumberSeries::operator = (const NumberSeries& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

NumberSeries& NumberSeries::operator = (NumberSeries&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

NumberSeries::~NumberSeries() {
    this->free();
}

bool NumberSeries::hasElement(const int element) const {
    if (this->checkInnerData(element) != -1) {
        return true;
    }

    size_t counter = 0;
    int currentElement = this->firstElement;
    while (counter < SERIES_PREDICATE_TOLERANCE) {
        if (currentElement == element) {
            return true;
        }
        currentElement = this->predicate(currentElement);
        counter += 1;
    }
    return false;
}

int NumberSeries::generateIElement(const size_t i) {
    if (i < this->size) {
        return this->data[i];
    }

    if (this->size == 0) {
        this->appendData(this->firstElement);
    }

    while (this->size <= i) {
        this->appendData(this->predicate(this->data[this->size - 1]));
    }

    return this->data[i];
}

void NumberSeries::setSeriesPredicate(SeriesPredicate predicate) {
    if (!predicate) {
        throw std::runtime_error("Nullptr detected");
    }
    this->predicate = predicate;
    this->clearCache();
}

void NumberSeries::setFirstElement(const int firstElement) {
    this->firstElement = firstElement;
    this->clearCache();
}