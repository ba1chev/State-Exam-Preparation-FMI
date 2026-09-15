// Да се напише клас Programmer, който да описва програмист в дадена фирма. Всеки програмист се описва с:

// Име (най-много 32 символа)
// Възраст (най-малко 18 години)
// Заплата (цяло число в интерала 2500-5000)
// Езици за програмиране, които знае и позлва сред следните C++, Python, Java, C#, Javascript.
// След създаване на програмист единствено заплатата и езиците му може да бъдат променяни. Даден програмист 
// може да научи нов език по всяко време, както и да бъде попитан дали може да работи с конкретен език. 
// Информация за даден програмист може да се извежда на стандартния изход в следния формат: Name | Age | 
// Salary | Programming languages

// Реализирайте клас SoftwareCompany. В една фирма могат да работят най-много 50 на брой програмисти. 
// Класът да поддържа следните функционалности:

// Добавяне на нов програмист, ако има място
// Връщане на броя на назначените програмисти
// Извеждане на информация за всички програмисти
// Извеждане на информация за всички програмисти, работещи да даден език
// Изчисляване на средната заплата
// Изчисляване на средната възраст
// Промяна на заплатата на даден програмист чрез формула. Тази формула да се подава с указател към функция.
// Сортиране по заплата/възраст
#include <iostream>
#include <cstring>

enum class ProgrammingLanguage {
    CPlusPlus = (1 << 0), 
    Python = (1 << 1), 
    Java = (1 << 2), 
    CSharp = (1 << 3), 
    Javascript = (1 << 4)
};

class Programmer {
private:
    char name[31 + 1] = "";
    int age = 18;
    int salary = 2500;
    ProgrammingLanguage language = ProgrammingLanguage::CPlusPlus;
    
public:
    Programmer() = default;

    Programmer(const char* name, const int age, const int salary, ProgrammingLanguage language) {
        if (!name || strlen(name) > 31 || age < 18 ||
            salary < 2500 || salary > 5000) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->name, name, strlen(name));
        this->age = age;
        this->salary = salary;
        this->language = language;
    }

    void print() const {
        std::cout << "|";
        std::cout << this->name << "|";
        std::cout << this->age << "|";
        std::cout << this->salary << "|";

        std::cout << "( ";
        if ((int)this->language & (1 << 0)) {
            std::cout << "C++" << " ";
        }
        if ((int)this->language & (1 << 1)) {
            std::cout << "Python" << " ";
        }
        if ((int)this->language & (1 << 2)) {
            std::cout << "Java" << " ";
        }
        if ((int)this->language & (1 << 3)) {
            std::cout << "C#" << " ";
        }
        if ((int)this->language & (1 << 4)) {
            std::cout << "JavaScript" << " ";
        }
        std::cout << ")" << "|";
        std::cout << std::endl;
    }

    ProgrammingLanguage getLanguage() const {
        return this->language;
    }

    int getSalary() const {
        return this->salary;
    }

    int getAge() const {
        return this->age;
    }

    void setSalary(const int newSalary) {
        this->salary = newSalary;
    }

    void learnLanguage(ProgrammingLanguage newLanguage) {
        this->language = (ProgrammingLanguage)((int)this->language | (int)newLanguage);
    }

    bool canWorkWith(ProgrammingLanguage searchedLanguage) const {
        return (int)this->language & (int)searchedLanguage;
    }
};

class SoftwareCompany {
private:
    Programmer programmers[50]{};
    size_t countOfProgrammers = 0;

public:
    SoftwareCompany() = default;

    void addProggramer(const Programmer& programmer) {
        if (this->countOfProgrammers == 50) {
            throw std::runtime_error("No more space");
        }

        this->programmers[this->countOfProgrammers] = programmer;
        this->countOfProgrammers += 1;
    }

    size_t getProgrammersCount() const {
        return this->countOfProgrammers;
    }

    void printInfo() const {
        for (size_t i = 0; i < this->countOfProgrammers; i++) {
            this->programmers[i].print();
        }
        std::cout << std::endl;
    }

    void printInfoByLanguage(ProgrammingLanguage language) const {
        for (size_t i = 0; i < this->countOfProgrammers; i++) {
            if ((int)this->programmers[i].getLanguage() & (int)language) {
                this->programmers[i].print();
            }
        }
        std::cout << std::endl;
    }

    float calculateAvarageSalary() const {
        float result = 0.0f;
        for (size_t i = 0; i < this->countOfProgrammers; i++) {
            result += this->programmers[i].getSalary();
        }
        
        return (result / this->countOfProgrammers);
    }

    float calculateAvarageAge() const {
        float result = 0.0f;
        for (size_t i = 0; i < this->countOfProgrammers; i++) {
            result += this->programmers[i].getAge();
        }
        
        return (result / this->countOfProgrammers);
    }

    typedef int (*SalaryPredicate)(const int);
    void changeProgrammerSalary(SalaryPredicate predicate, size_t index) {
        if (index >= this->countOfProgrammers) {
            throw std::out_of_range("Index is out of range");
        }

        this->programmers[index].setSalary(
            predicate(this->programmers[index].getSalary())
        );
    }

    typedef bool (*SortingPredicate)(const Programmer&, const Programmer&);
    void sortBy(SortingPredicate predicate) {
        for (size_t i = 0; i < this->countOfProgrammers - 1; i++) {
             for (size_t j = 0; j < this->countOfProgrammers - i - 1; j++) {
                if (predicate(this->programmers[j], this->programmers[j + 1])) {
                    Programmer temp = this->programmers[j];
                    this->programmers[j] = this->programmers[j + 1];
                    this->programmers[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int programmingLangMask1 = (int)ProgrammingLanguage::CPlusPlus | 
        (int)ProgrammingLanguage::Python | (int)ProgrammingLanguage::Javascript;

    int programmingLangMask2 = (int)ProgrammingLanguage::CPlusPlus | 
        (int)ProgrammingLanguage::Python;

    Programmer p1 = {"Yoan Baychev", 22, 2500, (ProgrammingLanguage)programmingLangMask1};
    Programmer p2 = {"Magdalena Dicheva", 19, 3200, (ProgrammingLanguage)programmingLangMask2};
    Programmer p3 = {"Kaloyan Markov", 30, 5000, ProgrammingLanguage::CSharp};
    
    SoftwareCompany company;
    company.addProggramer(p1);
    company.addProggramer(p2);
    company.addProggramer(p3);

    std::cout << company.getProgrammersCount() << std::endl;
    std::cout << company.calculateAvarageAge() << std::endl;
    std::cout << company.calculateAvarageSalary() << std::endl;
    std::cout << std::endl;

    company.printInfo();
    std::cout << std::endl;

    company.changeProgrammerSalary([](const int salary){
        return salary + 1000;
    }, 0);
    company.printInfo();
    std::cout << std::endl;

    company.sortBy([](const Programmer& left, const Programmer& right){
        return left.getSalary() > right.getSalary();
    });
    company.printInfo();
    std::cout << std::endl;

    company.sortBy([](const Programmer& left, const Programmer& right){
        return left.getAge() > right.getAge();
    });
    company.printInfo();
    std::cout << std::endl;

    company.printInfoByLanguage(ProgrammingLanguage::CPlusPlus);
    std::cout << std::endl;

    std::cout << p3.canWorkWith(ProgrammingLanguage::Java) << std::endl;
    p3.learnLanguage(ProgrammingLanguage::Java);
    std::cout << p3.canWorkWith(ProgrammingLanguage::Java) << std::endl;

    return 0;
}
