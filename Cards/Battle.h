#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include <string>
#include <iostream>
#include "../Players/Player.h"
#include "Card.h" 
class Battle : public Card
{
    private:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
    //int m_coins; //added 21.6
    //friend class Player;

    public:
    Battle(const std::string name, int force, int loot, int hpLossOnDefeat);
    virtual void applyEncounter(Player& player) const ; //made virtual
    friend std::ostream& operator<<(std::ostream& os, const Battle& r ); //check battle&
    virtual void battleAbstract()=0; //made abstract //hay brdo
    int getForce() const;
    int getLoot() const;
    int getHpLossOnDefeat() const;
};


#endif //EX4_BATTLE_H