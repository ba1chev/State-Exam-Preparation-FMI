// Създайте клас NumberSeries, който моделира работата с числова редица. В конструктора на класа ще приемате 
// цяло число - начална стойност на редицата (a0)
//  и указател към функция на преход, приемаща цяло число и връщаща цяло число (ai=f(ai−1)).

// Трябва да имате следните функционалности:

// Генериране на i-то число от редицата.
// Проверка дали подадено число е част от редицата.
// Setter-и за нова начална стойност и нова функция на преход.
// Генерирането на стойности трябва да бъде оптимизирано откъм скорост:

// За коректна работа с фунцкионалността за генериране на i-то по ред число, трябва да поддържате динамичен масив в 
// класа, в който да пазите досега генерираните стойности.
// Ако числото вече е било генерирано, трябва да го върнете като резултат без да го генерирате повторно.
// Ако числото го няма в масива, генерирайте и добавете към масива всички числа, които липсват до 
// a
// i
//  в редицата и върнете генерираната стойност.
// Ако в масива няма достатъчно място, за да се съхранят новите стойности, преоразмерете го по подходящ начин.
// При set-ване на нова начална стойност или функция на преход, трябва да изтривате динамичния масив и да започвате 
// процеса на запазване отначало.
// Помислете как трябва да се handle-не коректно копирането на обекти от вашия клас.
#pragma once
#include <iostream>

static constexpr int SERIES_PREDICATE_TOLERANCE = 20;
typedef int (*SeriesPredicate)(const int);

class NumberSeries {
private:
    int firstElement = 0;
    SeriesPredicate predicate = nullptr;

    int* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void clearCache();
    void appendData(const int element);
    void copyFrom(const NumberSeries& other);
    void moveTo(NumberSeries&& other) noexcept;
    void resize(size_t newCapacity);
    int checkInnerData(const int element) const;

public:
    NumberSeries(const int firstElement, SeriesPredicate predicate);
    NumberSeries(const NumberSeries& other);
    NumberSeries(NumberSeries&& other) noexcept;
    NumberSeries& operator = (const NumberSeries& other);
    NumberSeries& operator = (NumberSeries&& other) noexcept;
    ~NumberSeries();

    bool hasElement(const int element) const;
    int generateIElement(const size_t i); 
    void setSeriesPredicate(SeriesPredicate predicate);
    void setFirstElement(const int firstElement);
};