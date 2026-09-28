#pragma once
#include "exercise_06_exhibit.h"

class ZooKeeper;

class Section {
protected:
    char* name = nullptr;
    size_t minExpirience = 0;
    Exhibit* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    ZooKeeper* guard = nullptr;

    void free();
    void resize(const size_t newCapacity);
    void moveTo(Section&& other) noexcept;
    void copyFrom(const Section& other);

public:
    Section();
    Section(const char* name, const size_t minExpirience);
    Section(const Section& other);
    Section(Section&& other) noexcept;
    Section& operator = (const Section& other);
    Section& operator = (Section&& other) noexcept;
    virtual ~Section();

    void addExhibit(const Exhibit& exhibit);
    bool assignGuard(ZooKeeper* keeper);
    bool hasActiveGuard() const;
    void releaseGuard(const ZooKeeper* keeper);
    const Animal* search(const char* name) const;

    const char* getName() const;
    size_t getMinExpirience() const;
    const Exhibit* getExhibitData() const;
    size_t getExhibitDataSize() const;

    friend std::ostream& operator << (std::ostream& os, const Section& section);
};
