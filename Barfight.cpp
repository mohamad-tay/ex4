#include "Barfight.h"
#include "utilities.h"
#include "Player.h"
#include "Fighter.h" //check include maybe just on of the two


Barfight::Barfight() :
Card("Barfight"),
m_hpDamage(10)
{}

void applyEncounter(Player& player) const
{
    Fighter* castPtr = dynamic_cast<Fighter*>(&player);
    if(castPtr == nullptr) 
    {
        player.damage(m_hpDamage);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}