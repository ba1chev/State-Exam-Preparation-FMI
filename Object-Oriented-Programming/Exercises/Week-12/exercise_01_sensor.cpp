#include "exercise_01_sensor.h"
#include "exercise_01_id_exception.h"
#include "exercise_01_timestamp_exception.h"
#include "exercise_01_temperature_exception.h"
#include "exercise_01_humidity_exception.h"

void Sensor::free() {
    delete[] this->id;
    delete[] this->timestamp;
    this->id = nullptr;
    this->timestamp = nullptr;
    this->humidity = 0;
    this->temperature = 0;
}

void Sensor::copyFrom(const Sensor& other) {
    this->id = new char[strlen(other.id) + 1]{};
    this->timestamp = new char[strlen(other.timestamp) + 1]{};
    strncpy(this->id, other.id, strlen(other.id));
    strncpy(this->timestamp, other.timestamp, strlen(other.timestamp));
    this->temperature = other.temperature;
    this->humidity = other.humidity;
}

void Sensor::moveTo(Sensor&& other) noexcept {
    this->id = other.id;
    this->timestamp = other.timestamp;
    this->temperature = other.temperature;
    this->humidity = other.humidity;

    other.id = nullptr;
    other.timestamp = nullptr;
    other.temperature = 0;
    other.humidity = 0;
}   

bool Sensor::validateTimestamp(const char* timestamp) {
    if (!timestamp) {
        throw std::runtime_error("Nullptr detected");
    }
    if (strlen(timestamp) != strlen("YYYY-MM-DD HH:MM:SS")) {
        return false;
    }
    if (timestamp[4] != '-' || timestamp[7] != '-' || 
        timestamp[10] != ' ' || timestamp[13] != ':' || timestamp[16] != ':') {
        return false;
    }

    for (size_t i = 0; i < strlen(timestamp); i++) {
        if (i == 4 || i == 7 || i == 10 ||
            i == 13 || i == 16) {
            continue;
        }
        if (!UTILS::isDigit(timestamp[i])) {
            return false;
        }
    }

    return true;
}

bool Sensor::validateId(const char* id) {
    if (!id) {
        throw std::runtime_error("Nullptr detected");
    }

    if (strlen(id) < 4 || strlen(id) > 8) {
        return false;
    }
    for (size_t i = 0; i < strlen(id); i++) {
        if (!UTILS::isDigit(id[i]) && !UTILS::isLetter(id[i])) {
            return false;
        }
    }
    return true;
}

bool Sensor::validateTemperature(const float temperature) {
    return temperature >= -50.0f && temperature < 100.0f;
}

bool Sensor::validateHumidity(const uint8_t humidity) {
    return humidity <= 100;
}

Sensor::Sensor(const char* id, const char* timestamp,
    const float temperature, const uint8_t humidity) {
    if (!validateId(id)) {
        throw InvalidSensorIdException("Invalid sensor id");
    }
    if (!validateTimestamp(timestamp)) {
        throw InvalidTimestampException("Invalid timestamp");
    }
    if (!validateTemperature(temperature)) {
        throw InvalidTemperatureException("Invalid temperature");
    }
    if (!validateHumidity(humidity)) {
        throw InvalidHumidityException("Invalid humidity");
    }

    this->id = new char[strlen(id) + 1]{};
    this->timestamp = new char[strlen(timestamp) + 1]{};
    strncpy(this->id, id, strlen(id));
    strncpy(this->timestamp, timestamp, strlen(timestamp));
    this->temperature = temperature;
    this->humidity = humidity;
}

Sensor::Sensor(const Sensor& other) {
    this->copyFrom(other);
}

Sensor::Sensor(Sensor&& other) noexcept {
    this->moveTo(std::move(other));
}

Sensor& Sensor::operator = (const Sensor& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Sensor& Sensor::operator = (Sensor&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Sensor::~Sensor() {
    this->free();
}

const char* Sensor::getId() const {
    return this->id;
}

const char* Sensor::getTimestamp() const {
    return this->timestamp;
}

float Sensor::getTemperature() const {
    return this->temperature;
}

uint8_t Sensor::getHumidity() const {
    return this->humidity;
}

bool UTILS::isDigit(const char ch) {
    return (int)ch >= (int)'0' && (int)ch <= (int)'9';
}

bool UTILS::isLetter(const char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

std::istream& operator >> (std::istream& is, Sensor& sensor) {
    char id[16]{};
    char timestamp[32]{};
    float temperature = 0.0f;
    int humidity = 0;

    is.get(id, 16, ';');
    is.ignore();
    is.get(timestamp, 32, ';');
    is.ignore();
    is >> temperature;
    is.ignore();
    is >> humidity;

    sensor = Sensor(id, timestamp, temperature, (uint8_t)humidity);
    return is;
}

std::ostream& operator << (std::ostream& os, const Sensor& sensor) {
    os << sensor.id << ';' << sensor.timestamp << ';'
        << sensor.temperature << ';' << (int)sensor.humidity;
    return os;
}