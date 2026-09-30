// В една фирма съществуват различни видове служители. Всеки служител има име и 
// служебен номер. Мениджърите ръководят проекти, а инженерите работят по 
// технически задачи. Съществува и служител, наречен технически мениджър – 
// той изпълнява едновременно ролите на инженер и мениджър.

// Създайте клас Employee, който съдържа:

// име на служителя (низ)
// идентификационен номер (цяло число)
// метод printInfo(), който извежда информацията за служителя
// Създайте клас Manager, който:

// наследява Employee
// съдържа име на проект (низ)
// има собствена имплементация на printInfo()
// Създайте клас Engineer, който:

// наследява Employee
// съдържа техническа специализация (низ)
// има собствена имплементация на printInfo()
// Създайте клас TechManager, който:

// наследява едновременно от Manager и Engineer
// съдържа метод assignTask(const MyString& task), който извежда съобщение от вида:
// TechManager [name] assigns task: [task]
// Създайте клас Firm, който:

// съдържа колекция от работници
// съдържа метод, който дава пълна информация за всички работници
// съдържа метод, който добавя работник
// съдържа метод, който премахва работник по идентификационен номер
#include <iostream>
#include "exercise_01_firm.h"
#include "exercise_01_engineer.h"
#include "exercise_01_manager.h"
#include "exercise_01_tech_manager.h"

int main() {
    Firm firm;
    Engineer engineer("Ivan", "C++ Backend");
    Manager manager("Petar", "Apollo");
    TechManager techManager("Georgi", "Gemini", "Embedded Systems");

    firm.addEmployee(&engineer);
    firm.addEmployee(&manager);
    firm.addEmployee(&techManager);

    std::cout << "--- All employees ---" << std::endl;
    firm.printInfo();

    techManager.assignTask("Design the new module");

    std::cout << "--- Removing employee with id " << manager.getId() << " ---" << std::endl;
    firm.removeEmployee(manager.getId());

    std::cout << "--- After removal ---" << std::endl;
    firm.printInfo();

    return 0;
}