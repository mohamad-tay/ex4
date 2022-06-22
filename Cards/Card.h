#ifndef EX4_CARD_H
#define EX4_CARD_H
#include <string>       
#include "../Players/Player.h"
class Card 
{
    protected:
    std::string m_cardName;
    
    public:
    Card(const std::string name);
    Card(const Card&) = default;                                     //a3tked sa7 3shn string btsawe alashe
    virtual ~Card() = default;                                               //check aetha lazm virtual
    Card& operator=(const Card& other) = default;
    virtual void applyEncounter(Player& player) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Card& r);  //check if needed and Card&
};





#endif //EX4_CARD_H