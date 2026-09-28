#pragma once
#include <iostream>

class CarPart {
protected:
    char* creatorName = nullptr;
    char* description = nullptr;

    size_t id = 0;
    static size_t idMask;

    void free();
    void copyFrom(const CarPart& other);
    void moveTo(CarPart&& other) noexcept;

public:
    CarPart(const char* creatorName, const char* description);
    CarPart(const CarPart& other);
    CarPart(CarPart&& other) noexcept;
    CarPart& operator = (const CarPart& other);
    CarPart& operator = (CarPart&& other) noexcept;
    ~CarPart();

    const char* getCreatorName() const;
    const char* getDescription() const;
    size_t getId() const;

    friend std::ostream& operator << (std::ostream& os, const CarPart& carPart);
};