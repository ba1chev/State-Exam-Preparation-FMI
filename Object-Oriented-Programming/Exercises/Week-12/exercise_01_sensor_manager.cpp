#include "exercise_01_sensor_manager.h"
#include "exercise_01_file_exception.h"
#include <fstream>
#include <sstream>

void SensorManager::free() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

void SensorManager::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    this->capacity = newCapacity;
    Sensor* newData = new Sensor[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

void SensorManager::copyFrom(const SensorManager& other) {
    this->data = new Sensor[other.capacity]{};
    this->capacity = other.capacity;
    this->size = other.size;
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

void SensorManager::moveTo(SensorManager&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void SensorManager::add(const Sensor& sensor) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = sensor;
    this->size += 1;
}

SensorManager::SensorManager() {
    this->size = 0;
    this->capacity = 8;
    this->data = new Sensor[this->capacity]{};
}

SensorManager::SensorManager(const SensorManager& other) {
    this->copyFrom(other);
}

SensorManager::SensorManager(SensorManager&& other) noexcept {
    this->moveTo(std::move(other));
}

SensorManager& SensorManager::operator = (const SensorManager& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

SensorManager& SensorManager::operator = (SensorManager&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

SensorManager::~SensorManager() {
    this->free();
}

void SensorManager::process(const char* inputFile, const char* validFile,
    const char* invalidFile) {
    std::ifstream in(inputFile);
    if (!in.is_open()) {
        throw FileOpenException("Could not open input file");
    }

    std::ofstream valid(validFile);
    if (!valid.is_open()) {
        throw FileOpenException("Could not open processed file");
    }

    std::ofstream invalid(invalidFile);
    if (!invalid.is_open()) {
        throw FileOpenException("Could not open invalid log file");
    }

    char line[256]{};
    while (in.getline(line, 256)) {
        if (strlen(line) == 0) {
            continue;
        }

        try {
            Sensor sensor;
            std::stringstream ss(line);
            ss >> sensor;

            this->add(sensor);
            valid << sensor << std::endl;
        }
        catch (const SensorException& e) {
            invalid << line << " -> " << e.what() << std::endl;
        }
    }
}

void SensorManager::display() const {
    for (size_t i = 0; i < this->size; i++) {
        std::cout << this->data[i] << std::endl;
    }
}
