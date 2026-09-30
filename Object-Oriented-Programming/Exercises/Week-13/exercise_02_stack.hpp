#pragma once
#include <iostream>
#include "exercise_02_exception.h"

template <class T>
class Stack {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const Stack& other);
    void moveTo(Stack&& other) noexcept;

public:
    Stack();
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator = (const Stack& other);
    Stack& operator = (Stack&& other) noexcept;
    ~Stack();

    void push(const T& element);
    const T& top() const;
    void pop();

    const T* getData() const;
    size_t getSize() const;
    size_t getCapacity() const;
};

template <class T>
void Stack<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <class T>
void Stack<T>::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater the the old one");
    }

    this->capacity = newCapacity;
    T* newData = new T[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

template <class T>
void Stack<T>::copyFrom(const Stack& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template <class T>
void Stack<T>::moveTo(Stack&& other) noexcept {
    this->data = other.data;
    this->capacity = other.capacity;
    this->size = other.size;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <class T>
Stack<T>::Stack() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity]{};
}

template <class T>
Stack<T>::Stack(const Stack& other) {
    this->copyFrom(other);
}

template <class T>
Stack<T>::Stack(Stack&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
Stack<T>& Stack<T>::operator = (const Stack& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
Stack<T>& Stack<T>::operator = (Stack&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

template <class T>
Stack<T>::~Stack() {
    this->free();
}

template <class T>
void Stack<T>::push(const T& element) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = element;
    this->size += 1;
}

template <class T>
const T& Stack<T>::top() const {
    if (this->size == 0) {
        throw EmptyStackException("The stack is empty");
    }
    return this->data[this->size - 1];
}

template <class T>
void Stack<T>::pop() {
    if (this->size == 0) {
        throw EmptyStackException("The stack is empty");
    }
    this->size -= 1;
}

template <class T>
const T* Stack<T>::getData() const {
    return this->data;
}

template <class T>
size_t Stack<T>::getSize() const {
    return this->size;
}

template <class T>
size_t Stack<T>::getCapacity() const {
    return this->capacity;
}
