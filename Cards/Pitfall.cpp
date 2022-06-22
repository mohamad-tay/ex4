#include "Pitfall.h"
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include <iostream>

Pitfall::Pitfall() :
Card(std::string("Pitfall")),
m_hpDamage(10)
{}

void Pitfall::applyEncounter(Player& player) const
{

    //Player* playerPtr = &player;
    Rogue* castPtr = dynamic_cast<Rogue*>(&player);
    if(castPtr == nullptr)     //fix 
    {
        player.damage(this->m_hpDamage);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}