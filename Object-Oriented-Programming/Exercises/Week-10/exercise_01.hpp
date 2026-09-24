// Да се реализира опростена версия на std::shared_ptr
#pragma once
#include <iostream>

template <class T>
class SharedPtr {
private:
    T* ptr = nullptr;
    size_t* counter = nullptr;

    void free();
    void copyFrom(const SharedPtr& other);

public:
    SharedPtr() = delete;
    SharedPtr(T* object);
    SharedPtr(const SharedPtr& other);
    SharedPtr& operator = (const SharedPtr& other);
    ~SharedPtr();

    size_t getCounter() const;
    const T* getData() const;
};

template <class T>
SharedPtr<T>::SharedPtr(T* object) {
    this->ptr = object;
    this->counter = new size_t(1);
}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) {
    this->copyFrom(other);
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator = (const SharedPtr& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
SharedPtr<T>::~SharedPtr() {
    this->free();
}

template <class T>
void SharedPtr<T>::copyFrom(const SharedPtr& other) {
    this->ptr = other.ptr;
    this->counter = other.counter;
    *this->counter += 1;
}

template <class T>
void SharedPtr<T>::free() {
    *this->counter -= 1;
    if (*this->counter == 0) {
        delete this->ptr;
        delete this->counter;
    }
    this->ptr = nullptr;
    this->counter = nullptr;
}

template <class T>
size_t SharedPtr<T>::getCounter() const {
    return *this->counter;
}

template <class T>
const T* SharedPtr<T>::getData() const {
    return this->ptr;
}
