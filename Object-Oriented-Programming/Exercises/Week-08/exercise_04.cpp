#include "exercise_04.h"

void Matrix::free() {
    for (size_t i = 0; i < this->countOfRows; i++) {
        delete[] this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = nullptr;
    this->countOfRows = 0;
    this->countOfCols = 0;
}

void Matrix::copyFrom(const Matrix& other) {
    this->countOfRows = other.countOfRows;
    this->countOfCols = other.countOfCols;
    this->data = new float* [this->countOfRows]{nullptr};
    for (size_t i = 0; i < this->countOfRows; i++) {
        this->data[i] = new float[this->countOfCols]{};
    }

    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < this->countOfCols; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }
}
    
void Matrix::moveTo(Matrix&& other) noexcept {
    this->countOfRows = other.countOfRows;
    this->countOfCols = other.countOfCols;
    this->data = other.data;

    other.data = nullptr;
    other.countOfRows = 0;
    other.countOfCols = 0;
}

void Matrix::setCountOfRows(const size_t countOfRows) {
    this->countOfRows = countOfRows;
}

void Matrix::setCountOfCols(const size_t countOfCols) {
    this->countOfCols = countOfCols;
}

Matrix::Matrix() {
    this->setCountOfRows(2);
    this->setCountOfCols(2);
    this->data = new float* [this->countOfRows]{nullptr};
    for (size_t i = 0; i < this->countOfRows; i++) {
        this->data[i] = new float[this->countOfCols]{};
    }
}

Matrix::Matrix(const size_t countOfRows, const size_t countOfCols) {
    this->setCountOfRows(countOfRows);
    this->setCountOfCols(countOfCols);
    this->data = new float* [this->countOfRows]{nullptr};
    for (size_t i = 0; i < this->countOfRows; i++) {
        this->data[i] = new float[this->countOfCols]{};
    }
}

Matrix::Matrix(const Matrix& other) {
    this->copyFrom(other);
}

Matrix::Matrix(Matrix&& other) noexcept {
    this->moveTo(std::move(other));
}

Matrix& Matrix::operator = (const Matrix& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Matrix& Matrix::operator = (Matrix&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Matrix& Matrix::operator += (const Matrix& other) {
    if (this->countOfRows != other.getCountOfRows() ||
        this->countOfCols != other.getCountOfCols()) {
        throw std::runtime_error("Input error");
    }

    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < this->countOfCols; j++) {
            this->data[i][j] += other.data[i][j];   
        }
    }
    return *this;
}

Matrix& Matrix::operator -= (const Matrix& other) {
    if (this->countOfRows != other.getCountOfRows() ||
        this->countOfCols != other.getCountOfCols()) {
        throw std::runtime_error("Input error");
    }

    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < this->countOfCols; j++) {
            this->data[i][j] -= other.data[i][j];   
        }
    }
    return *this;
}

Matrix& Matrix::operator *= (const Matrix& other) {
    if (this->countOfCols != other.countOfRows) {
        throw std::runtime_error("Cannot multiply");
    }

    Matrix result(this->countOfRows, other.countOfCols);
    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < other.countOfCols; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < this->countOfCols; k++) {
                result[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }

    *this = result;
    return *this;
}

Matrix& Matrix::operator *= (const float& scalar) {
    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < this->countOfCols; j++) {
            this->data[i][j] *= scalar;
        }
    }
    return *this;
}

Matrix::~Matrix() {
    this->free();
}

size_t Matrix::getCountOfRows() const {
    return this->countOfRows;
}
 
size_t Matrix::getCountOfCols() const {
    return this->countOfCols;
}

Matrix::operator bool() const {
    for (size_t i = 0; i < this->countOfRows; i++) {
        for (size_t j = 0; j < this->countOfCols; j++) {
            if (this->data[i][j] != 0) {
                return true;
            }
        }
    }
    return false;
}

float* Matrix::operator [] (const size_t index) {
    if (index >= this->countOfRows) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

const float* Matrix::operator [] (const size_t index) const {
    if (index >= this->countOfRows) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

Matrix operator + (const Matrix& left, const Matrix& right) {
    Matrix result = left;
    result += right;
    return result;
}

Matrix operator - (const Matrix& left, const Matrix& right) {
    Matrix result = left;
    result -= right;
    return result;
}

Matrix operator * (const Matrix& left, const Matrix& right) {
    Matrix result = left;
    result *= right;
    return result;
}

Matrix operator * (const Matrix& left, const float& scalar) {
    Matrix result = left;
    result *= scalar;
    return result;
}

Matrix operator * (const float& scalar, const Matrix& right) {
    Matrix result = right;
    result *= scalar;
    return result;
}

bool operator == (const Matrix& left, const Matrix& right) {
    if (left.getCountOfRows() != right.getCountOfRows() ||
        left.getCountOfCols() != right.getCountOfCols()) {
        return false;
    }

    for (size_t i = 0; i < left.getCountOfRows(); i++) {
        for (size_t j = 0; j < left.getCountOfCols(); j++) {
            if (left[i][j] != right[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator != (const Matrix& left, const Matrix& right) {
    return !(left == right);
}