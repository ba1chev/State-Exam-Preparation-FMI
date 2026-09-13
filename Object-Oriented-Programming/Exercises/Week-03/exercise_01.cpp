// Реализирайте клас Time, който ще се използва за работа с часове (13:05:45). 
// Вашият клас трябва да има следния интерфейс:

// Подразбиращ се контруктор, който създава часа на 00:00:00.
// Конструктор, който приема три параметъра - час, минути и секунди.
// Член-функция, която връща оставащото време до полунощ.
// Член-функция, която увеличава часа с 1 секунда.
// Член-функция, която връща дали е време за вечеря. В рамките на задачата време за 
// вечеря е между 20:30 и 22:00.
// Член-функция, която връща дали е време за парти. В рамките на задачата време за 
// парти е между 23:00 и 06:00.
// Член-функция, която приема друг обект от тип Time и връща обект от тип Time, 
// което е разликата между двете времена.
// Член-функция, която която приема друг обект от тип Time и сравнява двата 
// обекта (по-къснен/по-ранен)
// Член-функция за принтиране на часа.
// Да се направи масив от 10 времена и да се сортира с някоя от изучаваните сортировки.
#include <iostream>

class Time {
private:
    int hours = 0;
    int minutes = 0;
    float seconds = 0.0f;

public:
    Time() = default;

    Time(const int hours, const int minutes, const float seconds) {
        if (hours < 0 || hours >= 24 || minutes < 0 || 
            minutes >= 60 || seconds < 0 || seconds >= 60) {
            throw std::runtime_error("Invalid input");
        }

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void addOneSecond() {
        if (this->seconds == 59) {
            this->seconds = 0;

            if (this->minutes == 59) {
                this->minutes = 0;

                if (this->hours == 23) {
                    this->hours = 0;
                    this->minutes = 0;
                } else {
                    this->hours += 1;
                }
            } else {
                this->minutes += 1;
            }
        } else {
            this->seconds += 1;
        }
    }
    
    Time timeLeftTillMidnight() const {
        Time midnight(0, 0, 0);
        return midnight.diffTime(*this);
    }

    bool isDinerTime() const {
        if (this->hours == 20) {
            return this->minutes >= 30;
        }
        if (this->hours == 22) {
            return this->minutes == 0 && this->seconds == 0;
        }
        return this->hours == 21;
    }

    bool isPartyTime() const {
        if (this->hours >= 23 || this->hours < 6) {
            return true;
        }
        return this->hours == 6 && this->minutes == 0 && this->seconds == 0;
    }

    Time diffTime(const Time& other) const {
        Time result = *this;
        if (result.seconds - other.seconds < 0) {
            result.seconds = 60 + result.seconds - other.seconds;

            if (result.minutes - 1 < 0) {
                result.minutes = 59;

                if (result.hours - 1 < 0) {
                    result.hours = 23;
                } else {
                    result.hours -= 1;
                }
            } else {
                result.minutes -= 1;
            }
        } else {
            result.seconds -= other.seconds;
        }

        if (result.minutes - other.minutes < 0) {
            result.minutes = 60 + result.minutes - other.minutes;

            if (result.hours - 1 < 0) {
                result.hours = 23;
            } else {
                result.hours -= 1;
            }
        } else {
            result.minutes -= other.minutes;
        }

        if (result.hours - other.hours < 0) {
            result.hours = 24 + result.hours - other.hours;
        } else {
            result.hours -= other.hours;
        }

        return result;
    }

    bool isEarlier(const Time& other) const {
        if (this->hours == other.hours) {
            if (this->minutes == other.minutes) {
                return this->seconds < other.seconds;
            }
            return this->minutes < other.minutes;
        }
        return this->hours < other.hours;
    }

    void print() const {
        std::cout << this->hours << ":" << 
            this->minutes << ":" << this->seconds << std::endl;
    }
};

int main() {
    Time times[10] = {
        Time(13, 5, 45), Time(6, 30, 0),   Time(23, 59, 59),
        Time(0, 0, 0),   Time(20, 45, 10),  Time(9, 15, 30),
        Time(18, 0, 0),  Time(21, 10, 5),   Time(3, 20, 40),
        Time(12, 0, 0)
    };

    for (size_t i = 0; i + 1 < 10; i++) {
        for (size_t j = 0; j + 1 < 10 - i; j++) {
            if (times[j + 1].isEarlier(times[j])) {
                Time temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }

    for (size_t i = 0; i < 10; i++) {
        times[i].print();
    }

    return 0;
}