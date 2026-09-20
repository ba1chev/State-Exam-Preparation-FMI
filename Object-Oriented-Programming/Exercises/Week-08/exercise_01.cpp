#include "exercise_01.h"
    
void MulString::free() {
    delete[] this->data;
    this->data = nullptr;
}
    
void MulString::copyFrom(const MulString& other) {
    this->data = new char[strlen(other.data) + 1]{};
    strncpy(this->data, other.data, strlen(other.data));
}

void MulString::moveTo(MulString&& other) noexcept {
    this->data = other.data;
    other.data = nullptr;
}

MulString::MulString(const char* data) {
    this->data = new char[strlen(data) + 1]{};
    strncpy(this->data, data, strlen(data));
}

MulString::MulString(const MulString& other) {
    this->copyFrom(other);
}

MulString::MulString(MulString&& other) noexcept {
    this->moveTo(std::move(other));
}

MulString& MulString::operator *= (const int k) {
    if (k < 0) {
        throw std::runtime_error("K must be greater than zero");
    }

    char* newData = new char[k * strlen(this->data) + 1]{};
    char* tempPtr = newData;
    for (size_t i = 0; i < k; i++) {
        strncpy(tempPtr, this->data, strlen(this->data));
        tempPtr += strlen(this->data);
    }
    delete[] this->data;
    this->data = newData;

    return *this;
}

MulString& MulString::operator %= (const MulString& other) {
    bool buffer[255]{};
    for (size_t i = 0; i < 255; i++) {
        buffer[i] = false;
    }
    
    for (size_t i = 0; i < strlen(this->data); i++) {
        buffer[(int)this->data[i]] = true;
    }
    for (size_t i = 0; i < strlen(other.data); i++) {
        buffer[(int)other.data[i]] = true;
    }
    
    size_t newSize = 0;
    for (size_t i = 0; i < 255; i++) {
        if (buffer[i]) {
            newSize += 1;
        }
    }
    char* newData = new char[newSize + 1]{};
    size_t currentIndex = 0;
    for (size_t i = 0; i < 255; i++) {
        if (buffer[i]) {
            newData[currentIndex] = (char)i;
            currentIndex += 1;
        }
    }
    
    delete[] this->data;
    this->data = newData;
    return *this;
}

MulString& MulString::operator = (const MulString& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

MulString& MulString::operator = (MulString&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

bool MulString::operator != (const MulString& other) const {
    size_t leftWeight = 0;
    size_t rightWeight = 0;

    for (size_t i = 0; i < strlen(this->data); i++) {
        leftWeight += (int)this->data[i];
    }
    for (size_t i = 0; i < strlen(other.data); i++) {
        rightWeight += (int)other.data[i];
    }
    
    return leftWeight != rightWeight;
}

MulString::~MulString() {
    this->free();
}

MulString operator * (const MulString& left, const int k) {
    MulString result = left;
    result *= k;
    return result;
}

MulString operator * (const int k, const MulString& right) {
    MulString result = right;
    result *= k;
    return result;
}

MulString operator % (const MulString& left, const MulString& right) {
    MulString result = left;
    result %= right;
    return result;
}

const char* MulString::getData() const {
    return this->data;
}

std::ostream& operator << (std::ostream& os, const MulString& str) {
    os << str.data;
    return os;
}