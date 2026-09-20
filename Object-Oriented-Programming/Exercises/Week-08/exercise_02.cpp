#include "exercise_02.h"

void Vector::free() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

size_t Vector::getNeededCapacity(size_t size) {
    size_t index = 0;
    while (((size_t)1 << index) <= size && index < 64) {
        index += 1;
    }
    return ((size_t)1 << index);
}

void Vector::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    float* newData = new float[newCapacity]{};
    std::memcpy(newData, this->data, this->size * sizeof(float));
    this->capacity = newCapacity;
    delete[] this->data;
    this->data = newData;
}

void Vector::moveTo(Vector&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void Vector::copyFrom(const Vector& other) {
    this->data = new float[other.capacity]{};
    std::memcpy(this->data, other.data, other.size * sizeof(float));
    this->size = other.size;
    this->capacity = other.capacity;
}

Vector::Vector() {
    this->size = 0;
    this->capacity = 8;
    this->data = new float[this->capacity]{};
}

Vector::Vector(const size_t capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->data = new float[this->capacity]{};
}

Vector::Vector(const float* data, const size_t size) {
    if (!data) {
        throw std::runtime_error("Nullptr detected");
    }

    this->size = size;
    this->capacity = getNeededCapacity(this->size);
    this->data = new float[this->capacity]{};
    std::memcpy(this->data, data, this->size * sizeof(float));
}

Vector::Vector(const Vector& other) {
    this->copyFrom(other);
}

Vector::Vector(Vector&& other) noexcept {
    this->moveTo(std::move(other));
}

Vector& Vector::operator *= (const float scalar) {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] *= scalar;
    }
    return *this;
}

Vector& Vector::operator /= (const float scalar) {
    if (std::abs(scalar - 0.0f) < 0.001) {
        throw std::runtime_error("Cannot devide by zero");
    }

    for (size_t i = 0; i < this->size; i++) {
        this->data[i] /= scalar;
    }
    return *this;
}

Vector& Vector::operator += (const Vector& other) {
    size_t newSize = (this->size + other.size + 
        std::abs((int)(this->size - other.size))) / 2;

    bool isSmaller = this->size < newSize;
    float* newData = new float[newSize]{};
    if (isSmaller) {
        size_t i = 0;
        for (; i < this->size; i++) {
            newData[i] = this->data[i] + other.data[i];
        }
        for (; i < newSize; i++) {
            newData[i] = other.data[i];
        }
    } else {
        size_t i = 0;
        for (; i < other.size; i++) {
            newData[i] = this->data[i] + other.data[i];
        }
        for (; i < newSize; i++) {
            newData[i] = this->data[i];
        }
    }

    delete[] this->data;
    this->data = newData;
    this->size = newSize;
    this->capacity = newSize;
    this->resize(getNeededCapacity(this->size));
    return *this;
}

Vector& Vector::operator -= (const Vector& other) {
    size_t newSize = (this->size + other.size + 
        std::abs((int)(this->size - other.size))) / 2;

    bool isSmaller = this->size < newSize;
    float* newData = new float[newSize]{};
    if (isSmaller) {
        size_t i = 0;
        for (; i < this->size; i++) {
            newData[i] = this->data[i] - other.data[i];
        }
        for (; i < newSize; i++) {
            newData[i] = -other.data[i];
        }
    } else {
        size_t i = 0;
        for (; i < other.size; i++) {
            newData[i] = this->data[i] - other.data[i];
        }
        for (; i < newSize; i++) {
            newData[i] = this->data[i];
        }
    }

    delete[] this->data;
    this->data = newData;
    this->size = newSize;
    this->capacity = newSize;
    this->resize(getNeededCapacity(this->size));
    return *this;
}

Vector& Vector::operator = (const Vector& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Vector& Vector::operator = (Vector&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Vector::~Vector() {
    this->free();
}

void Vector::pop() {
    if (this->size == 0) {
        throw std::runtime_error("There are not any elements left");
    }
    this->size -= 1;
}

void Vector::pushBack(const float number) {
    if (this->size == this->capacity) {
        this->resize(getNeededCapacity(this->size));
    }
    this->data[this->size] = number;
    this->size += 1;
}

float& Vector::operator [](const size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

const float& Vector::operator [](const size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

size_t Vector::getSize() const {
    return this->size;
}

size_t Vector::getCapacity() const {
    return this->capacity;
}

const float* Vector::getData() const {
    return this->data;
}

std::ostream& operator << (std::ostream& os, const Vector& vector) {
    os << vector.capacity << " " << vector.size << " ";
    for (size_t i = 0; i < vector.size; i++) {
        os << vector[i] << " ";
    }
    return os;
}

std::istream& operator >> (std::istream& is, Vector& vector) {
    is >> vector.size;
    is >> vector.capacity;
    delete[] vector.data;
    vector.data = new float[vector.capacity]{};

    for (size_t i = 0; i < vector.size; i++) {
        is >> vector[i];
    }
    
    return is;
}

Vector operator + (const Vector& left, const Vector& right) {
    Vector result = left;
    result += right;
    return result;
}

Vector operator - (const Vector& left, const Vector& right) {
    Vector result = left;
    result -= right;
    return result;
}

Vector operator * (const Vector& left, const float scalar) {
    Vector result = left;
    result *= scalar;
    return result;
}

Vector operator * (const float scalar, const Vector& right) {
    Vector result = right;
    result *= scalar;
    return result;
}

Vector operator / (const Vector& left, const float scalar) {
    Vector result = left;
    result /= scalar;
    return result;
}

Vector operator / (const float scalar, const Vector& right) {
    Vector result = right;
    result /= scalar;
    return result;
}

static float getLength(const Vector& vector) {
    float sum = 0.0f;
    for (size_t i = 0; i < vector.getSize(); i++) {
        sum += vector[i] * vector[i];
    }
    return std::sqrt(sum);
}

bool operator == (const Vector& left, const Vector& right) {
    if (left.getSize() != right.getSize()) {
        return false;
    }
    for (size_t i = 0; i < left.getSize(); i++) {
        if (std::abs(left[i] - right[i]) >= 0.001f) {
            return false;
        }
    }
    return true;
}

bool operator != (const Vector& left, const Vector& right) {
    return !(left == right);
}

bool operator >= (const Vector& left, const Vector& right) {
    return getLength(left) >= getLength(right);
}

bool operator <= (const Vector& left, const Vector& right) {
    return getLength(left) <= getLength(right);
}

bool operator > (const Vector& left, const Vector& right) {
    return getLength(left) > getLength(right);
}

bool operator < (const Vector& left, const Vector& right) {
    return getLength(left) < getLength(right);
}