include "Player.h"
include "Card.h"
include "utilities.h"

const int MAX_LENGTH = 15

Card::Card(const char* name) :
m_cardName(name)
{
    // if((string::strlen(name)>MAX_LENGTH) || (m_cardName.find(' ') != string::npos ))
    // {
    //     delete[] m_cardName;
    //     throw ??;
    // } 
}

 std::ostream& Card::operator<<(std::ostream& os, const Card& r)
{
    printCardDetails(os , r.m_cardName);
    printEndOfCardDetails(os)
    return os;
}