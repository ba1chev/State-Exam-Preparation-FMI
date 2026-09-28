#include "exercise_03_group_ticket.h"

GroupTicket::GroupTicket(const char* name, const float price): 
    Ticket(name, 0.8f * price) {}