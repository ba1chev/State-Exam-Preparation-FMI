#include "exercise_05_librarian.h"

Librarian::Librarian(const std::string& name, const size_t employeeNumber) {
    this->name = name;
    this->employeeNumber = employeeNumber;
}

void Librarian::watchArchive(Archive* archive) {
    this->watchedArchives.push_back(archive);
}

void Librarian::printWatchedArchives() const {
    std::cout << "[Librarian]:   " << this->name << std::endl;
    std::cout << "[EmployeeNum]: " << this->employeeNumber << std::endl;
    for (size_t i = 0; i < this->watchedArchives.size(); i++) {
        std::cout << "[Archive]:     "
            << this->watchedArchives[i]->getName() << std::endl;
    }
    std::cout << std::endl;
}

bool Librarian::archiveExists(const std::string& name) const {
    for (size_t i = 0; i < this->watchedArchives.size(); i++) {
        if (this->watchedArchives[i]->getName() == name) {
            return true;
        }
    }

    return false;
}

size_t Librarian::getEmployeeNumber() const {
    return this->employeeNumber;
}

const std::string& Librarian::getName() const {
    return this->name;
}
