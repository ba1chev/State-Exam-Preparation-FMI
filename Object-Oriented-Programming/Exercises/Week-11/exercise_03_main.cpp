// Реализирайте клас Ticket, който описва билет за театрална 
// постановка. Всеки билет има име на постановката и цена. 
// Направете подходящи конструктори.

// Реализирайте клас Student Ticket, който е 2 пъти по-евтин. 
// В конструктора си приема име и оригинална цена за постановката. 
// Реализирайте клас Group Ticket, който е с 20% по-евтин от 
// нормалния. Направете подходящи функции за принтиране на 
// информацията за билетите.
#include <iostream>
#include "exercise_03_ticket.h"
#include "exercise_03_student_ticket.h"
#include "exercise_03_group_ticket.h"

int main() {
    Ticket ticket("Hamlet", 40.0f);
    StudentTicket studentTicket("Hamlet", 40.0f);
    GroupTicket groupTicket("Hamlet", 40.0f);

    std::cout << "===== Ticket =====" << std::endl;
    ticket.printData();

    std::cout << "===== StudentTicket =====" << std::endl;
    studentTicket.printData();

    std::cout << "===== GroupTicket =====" << std::endl;
    groupTicket.printData();

    return 0;
}