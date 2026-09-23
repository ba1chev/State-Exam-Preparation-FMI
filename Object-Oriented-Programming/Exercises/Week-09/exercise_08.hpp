// Реализирайте шаблонен клас Pipeline<T>, който представлява верига от 
// трансформации върху стойност от тип T и поддържа следните операции:

// Pipeline(const T& initial) — конструктор с начална стойност
// pipe(std::function<T(T)>) — добавя трансформация към веригата и връща 
// референция към обекта, за да се поддържа chaining
// executeOne() - прилага първата трансформация и я премахва от списъка с 
// операции, връща текущия междинен резултат
// execute() — прилага всички трансформации последователно и връща крайния резултат
// *Всяка трансформация се прилага по веднъж, след което се изтрива от 
// списъка с изчакващи трансформации (можете да ползвате опашката, която сте написали за това).
#pragma once
#include "exercise_07.hpp"
#include <iostream>

template <class T>
using FunctionPredicate = T (*)(const T&);

template <class T>
class Pipeline {
private:
    T value = T{};
    Queue<FunctionPredicate<T>> functions;

public:
    Pipeline() = default;
    Pipeline(const T& value);

    Pipeline& pipe(FunctionPredicate<T> function);
    const T& executeOne();
    const T& execute();
};

template <class T>
Pipeline<T>::Pipeline(const T& value) {
    this->value = value;
}

template <class T>
Pipeline<T>& Pipeline<T>::pipe(FunctionPredicate<T> function) {
    this->functions.enqueue(function);
    return *this;
}

template <class T>
const T& Pipeline<T>::executeOne() {
    this->value = this->functions.front()(this->value);
    this->functions.dequeue();
    return this->value;
}

template <class T>
const T& Pipeline<T>::execute() {
    while (!this->functions.isEmpty()) {
        this->executeOne();
    }
    return this->value;
}
