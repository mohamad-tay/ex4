#include "Barfight.h"
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include "Card.h"


Barfight::Barfight() : Card(std::string("Barfight")),
m_hpDamage(10)
{}

void Barfight::applyEncounter(Player& player) const
{
    Fighter* castPtr = dynamic_cast<Fighter*>(&player);
    if(castPtr == nullptr) 
    {
        player.damage(this->m_hpDamage);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}