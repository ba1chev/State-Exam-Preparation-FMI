// Да се реализира клас MachineProcess, който моделира процес в операционна система. 
// Всеки процес се характеризира с цяло число pid, име на процеса, както и цяло число, описващо 
// използваната памет (в мегабайти).

// Класът трябва да съхранява броя на съществуващите процеси в даден момент, както и функция за 
// достъп до тази стойност. При създаване на обект броячът трябва да се увеличава, а при унищожаване – 
// да се намалява.

// Да се реализират следните функции за класа:

// промяна на използваната памет;
// извеждане на информация за процеса;
// извеждане на текущия брой на всички създадени процеси.
// сравнение на два процеса по използвана памет.
#include <iostream>
#include <cstring>
#include <stdexcept>

class MachineProcess {
private:
    int pid = 0;
    char* name = nullptr;
    int usedGBs = 0;
    static int countOfProcesses;

    void free() {
        delete[] this->name;
        this->name = nullptr;
        this->pid = 0;
        this->usedGBs = 0;
    }

    void copyFrom(const MachineProcess& other) {
        this->name = new char[strlen(other.name) + 1]{};
        strncpy(this->name, other.name, strlen(other.name));
        this->pid = other.pid;
        this->usedGBs = other.usedGBs;
    }

    void moveTo(MachineProcess&& other) noexcept {
        this->name = other.name;
        this->pid = other.pid;
        this->usedGBs = other.usedGBs;

        other.name = nullptr;
        other.pid = 0;
        other.usedGBs = 0;
    }

public:
    MachineProcess(const int pid, const char* name, const int usedGBs) {
        if (pid < 0 || !name || usedGBs < 0) {
            throw std::runtime_error("Invalid input");
        }
        this->pid = pid;
        this->usedGBs = usedGBs;
        this->name = new char[strlen(name) + 1]{};
        strncpy(this->name, name, strlen(name));
        MachineProcess::countOfProcesses += 1;
    }

    MachineProcess(const MachineProcess& other) {
        this->copyFrom(other);
        MachineProcess::countOfProcesses += 1;
    }

    MachineProcess(MachineProcess&& other) noexcept {
        this->moveTo(std::move(other));
        MachineProcess::countOfProcesses += 1;
    }

    MachineProcess& operator = (const MachineProcess& other) {
        if (this != &other) {
            this->free();
            this->copyFrom(other);
        }
        return *this;
    }

    MachineProcess& operator = (MachineProcess&& other) noexcept {
        if (this != &other) {
            this->free();
            this->moveTo(std::move(other));
        }
        return *this;
    }

    ~MachineProcess() {
        this->free();
        MachineProcess::countOfProcesses -= 1;
    }

    void print() const {
        std::cout << this->name << " ";
        std::cout << this->pid << " ";
        std::cout << this->usedGBs << std::endl;
    }

    void setMemory(const int newUsedMemory) {
        if (newUsedMemory < 0) {
            throw std::runtime_error("Invalid input");
        }
        this->usedGBs = newUsedMemory;
    }

    static int getProcessesCount() {
        return countOfProcesses;
    }

    bool hasMoreMemoryThan(const MachineProcess& other) const {
        return this->usedGBs > other.usedGBs;
    }
};
int MachineProcess::countOfProcesses = 0;

int main() {
    MachineProcess process1(1, "Chrome", 200);
    MachineProcess process2(2, "", 50);
    process1.print();
    process2.print();

    std::cout << "Processes: " << MachineProcess::getProcessesCount() << std::endl;
    process2.setMemory(300);

    if (process2.hasMoreMemoryThan(process1)) {
        std::cout << "process2 uses more memory" << std::endl;
    }

    MachineProcess process3 = process1;
    std::cout << "Processes: " << MachineProcess::getProcessesCount() << std::endl;
    return 0;
}