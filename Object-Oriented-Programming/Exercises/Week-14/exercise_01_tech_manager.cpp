#include "exercise_01_tech_manager.h"

TechManager::TechManager(const char* name, const char* project, const char* techData):
    Employee(name), Engineer(name, techData), Manager(name, project) {
    if (!name || !project || !techData) {
        throw std::runtime_error("Nullptr detected");
    }
}

void TechManager::assignTask(const char* task) {
    if (!task) {
        throw std::runtime_error("Nullptr detected");
    }
    std::cout << "TechManager " << this->name << " assigns task: ";
    std::cout << task << std::endl;
}

void TechManager::printInfo() const {
    Engineer::printInfo();
    Manager::printInfo();
}

Employee* TechManager::clone() const {
    return new TechManager(*this);
}