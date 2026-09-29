#pragma once
#include <iostream>

template <class T>
class MyVector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const MyVector& other);
    void moveTo(MyVector&& other) noexcept;

public:
    MyVector();
    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;
    MyVector& operator = (const MyVector& other);
    MyVector& operator = (MyVector&& other) noexcept;
    ~MyVector();

    void pushBack(const T& element);
    void pop();

    const T& operator [] (const size_t index) const;
    T& operator [] (const size_t index);

    const T* getData() const;
    size_t getSize() const;
    size_t getCapacity() const;

    template <class U>
    friend std::ostream& operator << (std::ostream& os, const MyVector<U>& vector);
    template <class U>
    friend std::istream& operator >> (std::istream& is, MyVector<U>& vector);
};

template <class T>
void MyVector<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <class T>
void MyVector<T>::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    T* newData = new T[newCapacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = std::move(this->data[i]);
    }
    delete[] this->data;
    this->data = newData;
    this->capacity = newCapacity;
}

template <class T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
    this->data = new T[other.capacity]{};
    this->size = other.size;
    this->capacity = other.capacity;
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template <class T>
void MyVector<T>::moveTo(MyVector<T>&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <class T>
MyVector<T>::MyVector() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity]{};
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& other) {
    this->copyFrom(other);
}

template <class T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector<T>& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::operator = (MyVector<T>&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

template <class T>
MyVector<T>::~MyVector() {
    this->free();
}

template <class T>
void MyVector<T>::pushBack(const T& element) {
    if (this->size == this->capacity) {
        this->resize(this->capacity * 2);
    }
    this->data[this->size] = element;
    this->size += 1;
}

template <class T>
void MyVector<T>::pop() {
    if (this->size == 0) {
        throw std::runtime_error("Data is empty");
    }
    this->size -= 1;
}

template <class T>
const T& MyVector<T>::operator [] (const size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

template <class T>
T& MyVector<T>::operator [] (const size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

template <class T>
const T* MyVector<T>::getData() const {
    return this->data;
}

template <class T>
size_t MyVector<T>::getSize() const {
    return this->size;
}

template <class T>
size_t MyVector<T>::getCapacity() const {
    return this->capacity;
}

template <class U>
std::ostream& operator << (std::ostream& os, const MyVector<U>& vector) {
    for (size_t i = 0; i < vector.size; i++) {
        os << vector.data[i] << " ";
    }
    return os;
}

template <class U>
std::istream& operator >> (std::istream& is, MyVector<U>& vector) {
    U element;
    while (is >> element) {
        vector.pushBack(element);
    }
    return is;
}