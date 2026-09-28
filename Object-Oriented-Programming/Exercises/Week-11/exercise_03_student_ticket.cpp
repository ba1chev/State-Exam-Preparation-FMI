#include "exercise_03_student_ticket.h"

StudentTicket::StudentTicket(const char* name, const float price): 
    Ticket(name, price / 2) {}