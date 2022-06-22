#include "../Players/Player.h"
#include "Card.h"
#include "../utilities.h"
#include <iostream>

//const int MAX_LENGTH = 15;

Card::Card(const std::string name) : m_cardName(name)
{}

std::ostream& operator<<(std::ostream& os, const Card& r)
{
    printCardDetails(os , r.m_cardName);
    printEndOfCardDetails(os);
    return os;
}