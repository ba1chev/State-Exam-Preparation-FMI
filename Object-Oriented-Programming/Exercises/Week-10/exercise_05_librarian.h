#pragma once
#include <vector>
#include <string>
#include "exercise_05_archive.h"

class Librarian {
private:
    std::string name = "";
    size_t employeeNumber = 0;
    std::vector<Archive*> watchedArchives;

public:
    Librarian() = default;
    Librarian(const std::string& name, const size_t employeeNumber);

    void watchArchive(Archive* archive);
    void printWatchedArchives() const;
    bool archiveExists(const std::string& name) const;

    size_t getEmployeeNumber() const;
    const std::string& getName() const;
};
