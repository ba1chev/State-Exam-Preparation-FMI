#include "exercise_06_zoo.h"

Zoo::~Zoo() {
    for (size_t i = 0; i < this->sections.size(); i++) {
        delete this->sections[i];
    }
}

void Zoo::addSection(Section* section) {
    if (!section) {
        throw std::runtime_error("Nullptr detected");
    }
    this->sections.push_back(section);
}

std::shared_ptr<ZooKeeper> Zoo::addKeeper(const char* name,
    const size_t employeeID, const size_t experience) {
    std::shared_ptr<ZooKeeper> keeper =
        std::make_shared<ZooKeeper>(name, employeeID, experience);
    this->keepers.push_back(keeper);
    return keeper;
}

void Zoo::removeKeeper(const size_t employeeID) {
    for (size_t i = 0; i < this->keepers.size(); i++) {
        if (this->keepers[i]->getEmployeeID() == employeeID) {
            for (size_t j = 0; j < this->sections.size(); j++) {
                this->sections[j]->releaseGuard(this->keepers[i].get());
            }
            this->keepers.erase(this->keepers.begin() + i);
            return;
        }
    }
}

void Zoo::printAll() const {
    for (size_t i = 0; i < this->sections.size(); i++) {
        std::cout << *this->sections[i];
    }
}

const Animal* Zoo::search(const char* name) const {
    for (size_t i = 0; i < this->sections.size(); i++) {
        const Animal* found = this->sections[i]->search(name);
        if (found) {
            return found;
        }
    }
    return nullptr;
}
