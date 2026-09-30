#pragma once
#include "exercise_01_manager.h"
#include "exercise_01_engineer.h"

class TechManager: public Engineer, public Manager {    
public:
    TechManager(const char* name, const char* project, const char* techData);
    
    void assignTask(const char* task);
    Employee* clone() const override;
    void printInfo() const override;
};