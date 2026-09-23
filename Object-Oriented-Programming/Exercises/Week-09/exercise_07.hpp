// Реализирайте шаблонен клас Queue, който представлява циклична опашка, която поддържа същите операции 
// като Stack(LIFO - last in, first out), но предоставя достъп само до първия добавен елемент(FIFO - first in, first out).

// Циклична означава, че при премахване на първия елемент не искаме да shift-ваме всички останали наляво, а 
// само да продължим да добавяме вдясно от тях. Например:

// Имаме опашка с размер 5: 1 2 3 4 -
// Махаме елемент: - 2 3 4 - (не мърдаме 2, 3 и 4 наляво и оставяме мястото празно)
// Добавяме елементите 5 и 6: - 2 3 4 5 (добавяме 5) -> 6 2 3 4 5 (добавяме 6)
// Числата са записани в паметта сякаш първият елемент в опашката е 6, но реално е 2.

// При запълване на опашката искаме тя да се преоразмерява с коефициент 2 и елементите ѝ да се записват от началото на 
// новия контейнер, т.е. ако преоразмерим горния пример:
// 6 2 3 4 5 ще стане -> 2 3 4 5 6 - - - - -

// Функции:

// подходящи конструктори и деструктор (спазвайки правилото от три)
// void enqueue(const T& value) — добавя елемент на края на опашката
// void dequeue() — премахва първия елемент; ако опашката е празна, хвърля 
// std::runtime_error
// T& front() — връща референция към първия елемент; ако опашката е празна, хвърля std::runtime_error
// bool isEmpty() — връща дали опашката е празна
// size_t size() — връща броя на елементите
// void clear() — премахва всички елементи
// Насока: Използвайте два индекса — left (първи елемент) и right (следващо свободно място). 
// За да преместите индекс напред без да излизате извън масива, може да ползвате index = (index + 1) % capacity. 
// При преоразмеряване копирайте елементите в реда им, като започнете от left и вървите напред, не от началото на самия масив.
#pragma once
#include <iostream>

template <class T>
class Queue {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    size_t leftPtr = 0;
    size_t rightPtr = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const Queue& other);
    void moveTo(Queue&& other) noexcept;

public:
    Queue();
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator = (const Queue& other);
    Queue& operator = (Queue&& other) noexcept;
    ~Queue();

    T& front();
    void clear();
    void dequeue();
    void enqueue(const T& value);
    
    bool isEmpty() const;
    size_t getLeftPtr() const;
    size_t getRightPtr() const;
    size_t getSize() const;
    size_t getCapacity() const;
};

template <class T>
void Queue<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->leftPtr = 0;
    this->rightPtr = 0;
    this->size = 0;
    this->capacity = 0;
}

template <class T>
void Queue<T>::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    T* newData = new T[newCapacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[(this->leftPtr + i) % this->capacity];
    }

    delete[] this->data;
    this->data = newData;
    this->capacity = newCapacity;
    this->leftPtr = 0;
    this->rightPtr = this->size;
}

template <class T>
void Queue<T>::copyFrom(const Queue<T>& other) {
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = new T[this->capacity]{};

    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[(other.leftPtr + i) % other.capacity];
    }

    this->leftPtr = 0;
    this->rightPtr = this->size;
}

template <class T>
void Queue<T>::moveTo(Queue<T>&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;
    this->leftPtr = other.leftPtr;
    this->rightPtr = other.rightPtr;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    other.leftPtr = 0;
    other.rightPtr = 0;
}

template <class T>
Queue<T>::Queue() {
    this->size = 0;
    this->capacity = 8;
    this->leftPtr = 0;
    this->rightPtr = 0;
    this->data = new T[this->capacity]{};
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {
    this->copyFrom(other);
}

template <class T>
Queue<T>::Queue(Queue<T>&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
Queue<T>& Queue<T>::operator = (const Queue<T>& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
Queue<T>& Queue<T>::operator = (Queue<T>&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

template <class T>
Queue<T>::~Queue() {
    this->free();
}

template <class T>
bool Queue<T>::isEmpty() const {
    return this->size == 0;
}

template <class T>
size_t Queue<T>::getLeftPtr() const {
    return this->leftPtr;
}

template <class T>
size_t Queue<T>::getRightPtr() const {
    return this->rightPtr;
}

template <class T>
size_t Queue<T>::getSize() const {
    return this->size;
}

template <class T>
size_t Queue<T>::getCapacity() const {
    return this->capacity;
}

template <class T>
T& Queue<T>::front() {
    if (this->size == 0) {
        throw std::runtime_error("The queue is empty");
    }
    return this->data[this->leftPtr];
}

template <class T>
void Queue<T>::clear() {
    this->size = 0;
    this->leftPtr = 0;
    this->rightPtr = 0;
}

template <class T>
void Queue<T>::dequeue() {
    if (this->size == 0) {
        throw std::runtime_error("The queue is empty");
    }

    this->leftPtr += 1;
    this->leftPtr %= this->capacity;
    this->size -= 1;
}

template <class T>
void Queue<T>::enqueue(const T& value) {
    if (this->size == this->capacity) {
        this->resize(this->capacity * 2);
    }

    this->data[this->rightPtr] = value;
    this->rightPtr += 1;
    this->rightPtr %= this->capacity;
    this->size += 1;
}