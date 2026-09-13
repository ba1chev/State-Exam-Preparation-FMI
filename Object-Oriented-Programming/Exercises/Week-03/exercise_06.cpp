// Да се напише структура Vector, която да представлява вектор в 
// тримерното евклидово пространство. Да се напише структура VectorSpace, 
// която да съдържа в себе си най-много 50 вектора и техния брой. 
// Да се реализират следните функции:

// Vector makeVector(int x, int y, int z)
// void addToVectorSpace(VectorSpace& vectorSpace, const Vector& vector)
// void serializeVector(std::ofstream& ofs, const Vector& vector)
// Vector deserializeVector(std::ifstream& ifs)
// void serializeVectorSpace(const char* fileName, const VectorSpace& vectorSpace)
// VectorSpace deserializeVectorSpace(const char* fileName)
// Записаните вектори в текстов файл трябва да изглеждат по следния начин:

// size <x0, y0, z0> <x1, y1, z1> ... <xn, yn, zn>
#include <iostream>
#include <fstream>
#include <limits>

struct Vector {
public:
    int x = 0;
    int y = 0;
    int z = 0;

    Vector() = default;

    Vector(const int x, const int y, const int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct VectorSpace {
public:
    Vector data[50]{};
    size_t countOfVectors = 0;
};

Vector makeVector(int x, int y, int z) {
    return Vector(x, y, z);
}

void addToVectorSpace(VectorSpace& vectorSpace, const Vector& vector) {
    if (vectorSpace.countOfVectors >= 50) {
        throw std::runtime_error("Vector space is full");
    }

    vectorSpace.data[vectorSpace.countOfVectors] = vector;
    vectorSpace.countOfVectors += 1;
}

void serializeVector(std::ofstream& ofs, const Vector& vector) {
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs << "<" << vector.x << ", " << vector.y << ", " << vector.z << "> ";
    ofs.clear();
}

Vector deserializeVector(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    Vector result;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '<');
    ifs >> result.x;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    ifs >> result.y;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    ifs >> result.z;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '>');
    ifs.clear();

    return result;
}

void serializeVectorSpace(const char* fileName, const VectorSpace& vectorSpace) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs << vectorSpace.countOfVectors << " ";
    for (size_t i = 0; i < vectorSpace.countOfVectors; i++) {
        serializeVector(ofs, vectorSpace.data[i]);
    }
    
    ofs.clear();
    ofs.close();
}

VectorSpace deserializeVectorSpace(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    VectorSpace result;
    ifs >> result.countOfVectors;

    for (size_t i = 0; i < result.countOfVectors; i++) {
        result.data[i] = deserializeVector(ifs);
    }

    ifs.clear();
    ifs.close();
    return result;
}
int main() {
    VectorSpace vectorSpace;
    addToVectorSpace(vectorSpace, makeVector(1, 2, 3));
    addToVectorSpace(vectorSpace, makeVector(4, 5, 6));
    addToVectorSpace(vectorSpace, makeVector(-7, 8, -9));

    serializeVectorSpace("vectors.txt", vectorSpace);

    VectorSpace loaded = deserializeVectorSpace("vectors.txt");
    for (size_t i = 0; i < loaded.countOfVectors; i++) {
        std::cout << "<" << loaded.data[i].x << ", " << loaded.data[i].y
            << ", " << loaded.data[i].z << ">" << std::endl;
    }

    return 0;
}