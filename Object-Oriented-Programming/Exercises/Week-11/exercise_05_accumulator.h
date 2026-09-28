#pragma once
#include "exercise_05_car_part.h"

class Accumulator: public CarPart {
private:
    float witdh = 0.0f;
    char* bateryId = nullptr;

    void free();
    void moveTo(Accumulator&& other) noexcept;
    void copyFrom(const Accumulator& other);

public:
    Accumulator(const char* creatorName, const char* description, 
        const float width, const char* bateryId);
    Accumulator(const Accumulator& other);
    Accumulator(Accumulator&& other) noexcept;
    Accumulator& operator = (const Accumulator& other);
    Accumulator& operator = (Accumulator&& other) noexcept;
    ~Accumulator();

    const char* getBateryId() const;
    float getWidth() const;
    friend std::ostream& operator << (std::ostream& os, const Accumulator& wheel);
};
