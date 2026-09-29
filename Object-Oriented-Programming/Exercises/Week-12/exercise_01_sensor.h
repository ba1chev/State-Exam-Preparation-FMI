#pragma once
#include <iostream>
#include <cstring>

namespace UTILS {
    bool isDigit(const char ch);
    bool isLetter(const char ch);
}

class Sensor {
private:
    char* id = nullptr;
    char* timestamp = nullptr;
    float temperature = 0.0f;
    uint8_t humidity = 0;

    void free();
    void copyFrom(const Sensor& other);
    void moveTo(Sensor&& other) noexcept;

    static bool validateTimestamp(const char* timestamp);
    static bool validateId(const char* id);
    static bool validateTemperature(const float temperature);
    static bool validateHumidity(const uint8_t humidity);

public:
    Sensor() = default;
    Sensor(const char* id, const char* timestamp, 
        const float temperature, const uint8_t humidity);
    Sensor(const Sensor& other);
    Sensor(Sensor&& other) noexcept;
    Sensor& operator = (const Sensor& other);
    Sensor& operator = (Sensor&& other) noexcept;
    ~Sensor();

    const char* getId() const;
    const char* getTimestamp() const;
    float getTemperature() const;
    uint8_t getHumidity() const;

    friend std::istream& operator >> (std::istream& is, Sensor& sensor);
    friend std::ostream& operator << (std::ostream& os, const Sensor& sensor);
};