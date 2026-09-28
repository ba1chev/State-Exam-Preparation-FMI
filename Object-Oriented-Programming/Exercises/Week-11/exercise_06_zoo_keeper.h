#pragma once
#include <cstring>
#include <iostream>

class ZooKeeper {
private:
    char* name = nullptr;
    size_t employeeID = 0;
    size_t experience = 0;

    void free();
    void copyFrom(const ZooKeeper& other);
    void moveTo(ZooKeeper&& other) noexcept;

public:
    ZooKeeper(const char* name, const size_t employeeID, const size_t experience);
    ZooKeeper(const ZooKeeper& other);
    ZooKeeper(ZooKeeper&& other) noexcept;
    ZooKeeper& operator = (const ZooKeeper& other);
    ZooKeeper& operator = (ZooKeeper&& other) noexcept;
    ~ZooKeeper();

    const char* getName() const;
    size_t getEmployeeID() const;
    size_t getExperience() const;

    friend std::ostream& operator << (std::ostream& os, const ZooKeeper& keeper);
};
