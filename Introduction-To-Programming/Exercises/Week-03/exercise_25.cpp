// Да се напише програма, която получава 3 цели числа,
// които символизират дата (ден, месец, година) определя и
// извежда следващата дата.
#include <iostream>

int main() {
    int day, month, year = 0;
    std::cin >> day >> month >> year;
    int days_in_month = 0;

    if (month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month == 10 || month == 12) {
        days_in_month = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else if (month == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    }

    if (day < days_in_month) {
        day += 1;
    } else {
        day = 1;
        if (month < 12) {
            month += 1;
        } else {
            month = 1;
            year += 1;
        }
    }

    std::cout << day << " " << month << " " << year << std::endl;
    return 0;
}