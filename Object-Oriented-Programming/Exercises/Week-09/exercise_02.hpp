// Да се реализира шаблонен клас Stack<T> със следните функционалности:

// динамичен масив от елементи от тип T
// брой на елементите в стека
// Функции:

// подходящи конструктори и деструктор
// void push(const T& value) — добавя елемент на върха на стека
// void pop() — премахва елемента на върха
// T& top() — връща референция към елемента на върха
// bool isEmpty() — връща дали стекът е празен
// size_t size() — връща броя на елементите
// void clear() — премахва всички елементи
#pragma once
#include <iostream>

template <class T>
class Stack {
private:
    T* data = nullptr;
    size_t currentSize = 0;
    size_t currentCapacity = 0;

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

    void pop();
    void push(const T& value);
    T& top();

    bool isEmpty() const;
    size_t size() const;
    void clear();
};

template <class T>
void Stack<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->currentSize = 0;
    this->currentCapacity = 0;
}

template <class T>
void Stack<T>::resize(const size_t newCapacity) {
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
void Stack<T>::copyFrom(const Stack<T>& other) {
    this->data = new T[other.currentCapacity]{};
    this->currentSize = other.currentSize;
    this->currentCapacity = other.currentCapacity;
    for (size_t i = 0; i < this->currentSize; i++) {
        this->data[i] = other.data[i];
    }
}

template <class T>
void Stack<T>::moveTo(Stack<T>&& other) noexcept {
    this->data = other.data;
    this->currentSize = other.currentSize;
    this->currentCapacity = other.currentCapacity;

    other.data = nullptr;
    other.currentSize = 0;
    other.currentCapacity = 0;
}

template <class T>
Stack<T>::Stack() {
    this->currentSize = 0;
    this->currentCapacity = 8;
    this->data = new T[this->currentCapacity]{};
}

template <class T>
Stack<T>::Stack(const Stack<T>& other) {
    this->copyFrom(other);
}

template <class T>
Stack<T>::Stack(Stack<T>&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
Stack<T>& Stack<T>::operator = (Stack<T>&& other) noexcept {
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
void Stack<T>::pop() {
    if (this->currentSize == 0) {
        throw std::runtime_error("Data is empty");
    }
    this->currentSize -= 1;
}

template <class T>
void Stack<T>::push(const T& value) {
    if (this->currentSize == this->currentCapacity) {
        this->resize(this->currentCapacity * 2);
    }
    this->data[this->currentSize] = value;
    this->currentSize += 1;
}

template <class T>
T& Stack<T>::top() {
    return this->data[this->currentSize - 1];
}

template <class T>
bool Stack<T>::isEmpty() const {
    return this->currentSize == 0;
}

template <class T>
size_t Stack<T>::size() const {
    return this->currentSize;
}

template <class T>
void Stack<T>::clear() {
    this->currentSize = 0;
}