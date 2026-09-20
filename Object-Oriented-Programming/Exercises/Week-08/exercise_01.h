// Реализирайте клас MulString, предвиден за работа със символни низове, 
// който да поддържа следните оператори:

// оператор *= , който по подадено цяло число k мултиплицира съдържанието 
// на даден стринг k пъти
// оператор * , който по подадени стринг и число връща стринг, чието 
// съдържание е мултиплицираното k пъти съдържание на поддадения стринг
// оператор за записване в поток <<
// оператор != , сравнява два стринга по тежест, връща true <=> двата 
// стринга са с различна тежест
// оператор %= , който като резултат дава обеднинението без повторения 
// на даден стринг с друг
// оператор % , който като резултат дават обеднинението без повторения 
// на два стринга
// Упътване: Обединение без повторения на два стринга дефинираме като: 
// Всички символи , които се съдържат в първия и втория стринг, записани 
// еднократно. Наредбата в резултата не е от значение. Пример : ABCDEFABJ % BCDGHJ -> ABCDEFJGH

// Тежест на стринг : сумата от ASCII кодовете на символите на стринга.

// Демонстрирайте използването на операторите в кратка main функцияx
#pragma once
#include <iostream>
#include <cstring>

class MulString {
private:
    char* data = nullptr;

    void free();
    void copyFrom(const MulString& other);
    void moveTo(MulString&& other) noexcept;

public:
    MulString() = default;
    MulString(const char* data);
    MulString(const MulString& other);
    MulString(MulString&& other) noexcept;
    MulString& operator *= (const int k);
    MulString& operator %= (const MulString& other);
    MulString& operator = (const MulString& other);
    MulString& operator = (MulString&& other) noexcept;
    bool operator != (const MulString& other) const;
    ~MulString();

    const char* getData() const;
    friend std::ostream& operator << (std::ostream& os, const MulString& str);
};

MulString operator * (const MulString& left, const int k);
MulString operator * (const int k, const MulString& right);
MulString operator % (const MulString& left, const MulString& right);