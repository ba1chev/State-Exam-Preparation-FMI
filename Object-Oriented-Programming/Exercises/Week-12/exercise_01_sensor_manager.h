#pragma once
#include "exercise_01_sensor.h"

class SensorManager {
private:
    Sensor* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const SensorManager& other);
    void moveTo(SensorManager&& other) noexcept;

    void add(const Sensor& sensor);

public:
    SensorManager();
    SensorManager(const SensorManager& other);
    SensorManager(SensorManager&& other) noexcept;
    SensorManager& operator = (const SensorManager& other);
    SensorManager& operator = (SensorManager&& other) noexcept;
    ~SensorManager();

    void process(const char* inputFile, const char* validFile,
        const char* invalidFile);
    void display() const;
};
