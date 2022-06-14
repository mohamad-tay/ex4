#include "Fairy.h"
#include "utilities.h"
#include "Player.h"
#include "Wizard.h"


Barfight::Barfight() :
Card("Fairy"),
m_extraHp(10)
{}

void applyEncounter(Player& player) const
{
    Wizard* castPtr = dynamic_cast<Wizard*>(&player);
    if(castPtr != nullptr) 
    {
        player.heal(m_extraHp);
        printFairyMessage(true);
    }
    else
    {
       printFairyMessage(false);
    }
}