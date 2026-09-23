// Напишете клас Color, който моделира RGBA цвят с четири канала: червен, зелен, син и алфа (прозрачност). 
// Всеки канал е цяло число в диапазона [0, 255]. При всяка операция стойностите се ограничават (clamp) 
// до този диапазон.

// За класа реализирайте:

// Конструктор по подразбиране — създава непрозрачен черен цвят (0, 0, 0, 255)
// Конструктор с параметри (r, g, b, a = 255)
// Да се предефинират оператори за:

// Събиране на цветове (+, +=) — събира каналите, clamp до 255
// Изваждане на цветове (-, -=) — изважда каналите, clamp до 0
// Умножение с реално число (*, *=) — мащабира RGB каналите, алфа се запазва
// Смесване на два цвята — * между два Color обекта (channel-wise умножение, нормализирано: r = r1*r2 / 255)
// Унарен ~ — инвертира RGB каналите (255 - стойност), алфа се запазва
// Индексация [] — достъп до канал по индекс (0=R, 1=G, 2=B, 3=A), за константен и неконстантен достъп
// Сравнение (==, !=)
// operator bool — връща false ако цветът е напълно прозрачен (alpha == 0)
// След семинара тази седмица допълнете с:

// Изход от поток << — извежда във вид #RRGGBB (hex) или rgba(r, g, b, a)

#pragma once
#include <iostream>

class Color {
private:
    int red = 0;
    int green = 0;
    int blue = 0;
    int alfa = 255;

    static int clamp(const int value);

public:
    Color() = default;
    Color(const int red, const int green, const int blue, const int alfa = 255);
    Color& operator += (const Color& other);
    Color& operator -= (const Color& other);
    Color& operator *= (const Color& other);
    Color& operator *= (const float scalar);
    Color operator ~ () const;

    int& operator [] (const size_t index);
    const int& operator [] (const size_t index) const;
    explicit operator bool () const;

    friend std::ostream& operator << (std::ostream& os, const Color& color);
    friend std::istream& operator >> (std::istream& is, Color& color);
};

Color operator + (const Color& left, const Color& right);
Color operator - (const Color& left, const Color& right);
Color operator * (const Color& left, const Color& right);
Color operator * (const Color& left, const float scalar);
Color operator * (const float scalar, const Color& right);

bool operator != (const Color& left, const Color& right);
bool operator == (const Color& left, const Color& right);