// Дефинирайте клас Матрица с произволни размери. Реализирайте:

// конструктор с параметри - 2 числа, които да определят размера на матрицата
// конструктор по подразбиране (по default размерите са 2х2)
// Сетър и гетър за елемент от матрицата
// Оператори:

// оператор+= - за събиране на матрици
// оператор+
// оператор-= - за изваждане на матрици
// оператор-
// оператор*= - за умножаване на матрици (стига да е възможно)
// оператор*
// оператор*= - за умножаване на матрица с число
// оператор*
// оператор== - 2 матрици са равни, ако всичките им елементи са равни
// оператор!=
// оператор[] - връща реда от матрицата на съответния индекс (за константен и неконстантен достъп)
// operator bool - връща false, ако матрицата е нулевата. В противен случай връща true.
#pragma once
#include <iostream>

class Matrix {
private:
    float** data = nullptr;
    size_t countOfRows = 0;
    size_t countOfCols = 0;

    void free();
    void copyFrom(const Matrix& other);
    void moveTo(Matrix&& other) noexcept;

    void setCountOfRows(const size_t countOfRows);
    void setCountOfCols(const size_t countOfCols);

public:
    Matrix();
    Matrix(const size_t countOfRows, const size_t countOfCols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator = (const Matrix& other);
    Matrix& operator = (Matrix&& other) noexcept;
    Matrix& operator += (const Matrix& other);
    Matrix& operator -= (const Matrix& other);
    Matrix& operator *= (const Matrix& other);
    Matrix& operator *= (const float& scalar);
    ~Matrix();

    size_t getCountOfRows() const;
    size_t getCountOfCols() const;

    explicit operator bool () const;
    float* operator [] (const size_t index);
    const float* operator [] (const size_t index) const;
};

Matrix operator + (const Matrix& left, const Matrix& right);
Matrix operator - (const Matrix& left, const Matrix& right);
Matrix operator * (const Matrix& left, const Matrix& right);
Matrix operator * (const Matrix& left, const float& scalar);
Matrix operator * (const float& scalar, const Matrix& right);

bool operator == (const Matrix& left, const Matrix& right);
bool operator != (const Matrix& left, const Matrix& right);