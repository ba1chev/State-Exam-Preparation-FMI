// Да се реализира опростена версия на std::unique_ptr
#pragma once
#include <stdexcept>

template <class T>
class UnuquePtr {
private:
    T* data = nullptr;

    void free();
    
public:
    UnuquePtr() = delete;
    UnuquePtr(T* data);
    UnuquePtr(const UnuquePtr& other) = delete;
    UnuquePtr(UnuquePtr&& other) noexcept = delete;
    UnuquePtr& operator = (const UnuquePtr& other) = delete;
    UnuquePtr& operator = (UnuquePtr&& other) noexcept = delete;
    ~UnuquePtr();

    const T* getData() const;
};

template <class T>
void UnuquePtr<T>::free() {
    delete this->data;
    this->data = nullptr;
}

template <class T>
UnuquePtr<T>::UnuquePtr(T* data) {
    if (!data) {
        throw std::runtime_error("Nullptr detected");
    }
    this->data = data;
}

template <class T>
UnuquePtr<T>::~UnuquePtr() {
    this->free();
}

template <class T>
const T* UnuquePtr<T>::getData() const {
    return this->data;
}