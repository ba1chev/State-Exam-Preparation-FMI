// Да се реализира клас MyVector, който имитира основната функционалност на стандартния контейнер 
// std::vector. Класът трябва да работи с произволен тип данни. Класът трябва да позволява следните операции:

// push_back(value) – добавя елемент чрез копиране
// push_back(value) – добавя елемент чрез преместване (move)
// pop_back() – премахва последния елемент
// достъп до елемент чрез конкретен индекс
// front() – връща първия елемент
// back() – връща последния елемент
// size() – брой елементи
// capacity() – заделена памет
// empty() – дали е празен
// clear() – изтрива всички елементи
#pragma once
#include <iostream>

template <class T>
class MyVector {
private:
    T* data = nullptr;
    size_t currentSize = 0;
    size_t currentCapacity = 0;

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

    void pop_back();
    void push_back(const T& element);
    void push_back(T&& element) noexcept;
    const T& front() const;
    const T& back() const;
    T& operator [] (const size_t index);
    const T& operator [] (const size_t index) const;

    void clear();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
};

template <class T>
void MyVector<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->currentSize = 0;
    this->currentCapacity = 0;
}

template <class T>
void MyVector<T>::resize(const size_t newCapacity) {
    if (newCapacity <= this->currentCapacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    T* newData = new T[newCapacity]{};
    for (size_t i = 0; i < this->currentSize; i++) {
        newData[i] = std::move(this->data[i]);
    }
    delete[] this->data;
    this->data = newData;
    this->currentCapacity = newCapacity;
}

template <class T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
    this->data = new T[other.currentCapacity]{};
    this->currentSize = other.currentSize;
    this->currentCapacity = other.currentCapacity;
    for (size_t i = 0; i < this->currentSize; i++) {
        this->data[i] = other.data[i];
    }
}

template <class T>
void MyVector<T>::moveTo(MyVector<T>&& other) noexcept {
    this->data = other.data;
    this->currentSize = other.currentSize;
    this->currentCapacity = other.currentCapacity;

    other.data = nullptr;
    other.currentSize = 0;
    other.currentCapacity = 0;
}

template <class T>
MyVector<T>::MyVector() {
    this->currentSize = 0;
    this->currentCapacity = 8;
    this->data = new T[this->currentCapacity]{};
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
void MyVector<T>::pop_back() {
    if (this->currentSize == 0) {
        throw std::runtime_error("Data is empty");
    }
    this->currentSize -= 1;
}

template <class T>
void MyVector<T>::push_back(const T& element) {
    if (this->currentSize == this->currentCapacity) {
        this->resize(this->currentCapacity * 2);
    }
    this->data[this->currentSize] = element;
    this->currentSize += 1;
}

template <class T>
void MyVector<T>::push_back(T&& element) noexcept {
    if (this->currentSize == this->currentCapacity) {
        this->resize(this->currentCapacity * 2);
    }
    this->data[this->currentSize] = std::move(element);
    this->currentSize += 1;
}

template <class T>
const T& MyVector<T>::front() const {
    return this->data[0];
}

template <class T>
const T& MyVector<T>::back() const {
    return this->data[this->currentSize - 1];
}

template <class T>
T& MyVector<T>::operator [] (const size_t index) {
    if (index >= this->currentSize) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

template <class T>
const T& MyVector<T>::operator [] (const size_t index) const {
    if (index >= this->currentSize) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

template <class T>
void MyVector<T>::clear() {
    this->currentSize = 0;
}

template <class T>
size_t MyVector<T>::size() const {
    return this->currentSize;
}

template <class T>
size_t MyVector<T>::capacity() const {
    return this->currentCapacity;
}

template <class T>
bool MyVector<T>::empty() const {
    return this->currentSize == 0;
}