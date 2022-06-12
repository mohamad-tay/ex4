#include "Fairy.h"
#include "utilities.h"
#include "Player.h"


Barfight::Barfight() :
Card("Fairy"),
m_extraHp(10)
{}

void applyEncounter(Player& player) const
{
    if(player.m_name == "Wizard")
    {
        player.heal(m_extraHp);
        printFairyMessage(true);
    }
    else
    {
       printFairyMessage(false);
    }
}