#pragma once
#include "exercise_03_ticket.h"

class StudentTicket: public Ticket {
public:
    StudentTicket(const char* name, const float price);
};