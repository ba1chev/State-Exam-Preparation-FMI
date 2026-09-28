#pragma once
#include "exercise_03_ticket.h"

class GroupTicket: public Ticket {
public:
    GroupTicket(const char* name, const float price);
};