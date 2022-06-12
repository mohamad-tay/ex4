#ifndef EX4_CARD_H
#define EX4_CARD_H
#include <string>       

class Card 
{
    protected:
    std::string m_cardName;
    
    public:
    Card(const char* name);
    Card(const Card&) = default;                                     //a3tked sa7 3shn string btsawe alashe
    ~Card() = default;                                               //check aetha lazm virtual
    Card& operator=(const Card& other) = default;
    virtual void applyEncounter(Player& player) const = 0;
    virtual std::ostream& operator<<(std::ostream& os);
}





#endif //EX4_CARD_H