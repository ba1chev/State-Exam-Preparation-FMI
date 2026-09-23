// Да се реализира шаблонен клас Optional<T> със следните 
// функционалности:

// Функции:

// подходящи конструктори (по подразбиране празен Optional; с параметър 
// Optional със стойност)
// bool hasValue() — връща дали обектът съдържа стойност
// T& value() — връща стойността
// T valueOr(T defaultValue) — връща стойността, ако я има, иначе връща 
// подадената стойност по подразбиране
// void reset() — изчиства стойността
// explicit operator bool() — еквивалентен на hasValue()
// operator*() — еквивалентен на value()
#pragma once
#include <iostream>

template <class T>
class Optional {
private:
    T* data = nullptr;

    void free();
    void moveTo(Optional&& other) noexcept;
    void copyFrom(const Optional& other);

public:
    Optional() = default;
    Optional(const T& value);
    Optional(const Optional& other);
    Optional(Optional&& other) noexcept;
    Optional& operator = (const Optional& other);
    Optional& operator = (Optional&& other) noexcept;
    ~Optional();

    T& value();
    T valueOr(T defaultValue) const;
    
    void reset();
    bool hasValue() const;

    T& operator * ();
    explicit operator bool() const;
};

template <class T>
void Optional<T>::free() {
    delete this->data;
    this->data = nullptr;
}

template <class T>
void Optional<T>::moveTo(Optional&& other) noexcept {
    this->data = other.data;
    other.data = nullptr;
}

template <class T>
void Optional<T>::copyFrom(const Optional& other) {
    if (!other.data) {
        this->data = nullptr;
        return;
    }
    this->data = new T(*(other.data));
}

template <class T>
Optional<T>::Optional(const T& value) {
    this->data = new T(value);
}

template <class T>
T& Optional<T>::value() {
    return *this->data;
}

template <class T>
T Optional<T>::valueOr(T defaultValue) const {
    if (!this->data) {
        return defaultValue;
    }
    return *this->data;
}

template <class T>
void Optional<T>::reset() {
    this->free();
}

template <class T>
bool Optional<T>::hasValue() const {
    return this->data != nullptr;
}

template <class T>
T& Optional<T>::operator * () {
    if (!this->data) {
        throw std::runtime_error("Nullptr detected");
    }
    return *this->data;
}

template <class T>
Optional<T>::operator bool() const {
    return this->data != nullptr;
}

template <class T>
Optional<T>::Optional(const Optional& other) {
    this->copyFrom(other);
}

template <class T>
Optional<T>::Optional(Optional&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
Optional<T>& Optional<T>::operator = (const Optional<T>& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class T>
Optional<T>& Optional<T>::operator = (Optional<T>&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

template <class T>
Optional<T>::~Optional() {
    this->free();
}