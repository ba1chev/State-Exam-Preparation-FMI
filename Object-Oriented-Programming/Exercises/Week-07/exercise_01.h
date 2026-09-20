// Да се реализира клас SpecialCustomFunction. Класът да съдържа указател към функция, която връща и 
// приема цели числа, както и редица от "специални" стойности. Обектите от този клас да се държат като функции.

// За тази цел да се предефинира оператор (), който приема стойност. Ако подадената стойност е специална, 
// обектът трябва да връща нейния квадрат, в противен случай – резултата от function pointer-а.
// Да се предефинират постфиксните и префиксните оператори ++ и --, които да увеличават и намаляват 
// специалните стойности с единица.
// Да се предефинира оператор !, който връща нов обект, в който всяка специална стойност е заменена с 
// противоположната ѝ по стойност.
#pragma once
#include <iostream>

namespace UTILS {
    inline int getPower2(const int number) {
        return number * number;
    }
}

typedef int (*FunctionPredicate)(int);

class SpecialCustomFunction {
private:
    FunctionPredicate function = nullptr;
    int* data = nullptr;
    size_t size = 0;

    void free();
    void copyFrom(const SpecialCustomFunction& other);
    void moveTo(SpecialCustomFunction&& other) noexcept;
    int findSpecialNumberIndex(const int number) const;
    void increaseBy(int offset);

public:
    SpecialCustomFunction(const int* data, const size_t size, FunctionPredicate function);
    SpecialCustomFunction(const SpecialCustomFunction& other);
    SpecialCustomFunction(SpecialCustomFunction&& other) noexcept;
    SpecialCustomFunction& operator = (const SpecialCustomFunction& other);
    SpecialCustomFunction& operator = (SpecialCustomFunction&& other) noexcept;
    ~SpecialCustomFunction();

    int operator ()(const int number) const;
    SpecialCustomFunction operator ! () const;
    SpecialCustomFunction& operator ++ ();
    SpecialCustomFunction operator ++ (int dummy);
    SpecialCustomFunction& operator -- ();
    SpecialCustomFunction operator -- (int dummy);
};