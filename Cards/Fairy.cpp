#include "Card.h"
#include "Fairy.h"
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Wizard.h"


Fairy::Fairy() :
Card(std::string("Fairy")),
m_extraHp(10)
{}

void Fairy::applyEncounter(Player& player) const
{
    Wizard* castPtr = dynamic_cast<Wizard*>(&player);
    if(castPtr != nullptr) 
    {
        player.heal(this->m_extraHp);
        printFairyMessage(true);
    }
    else
    {
       printFairyMessage(false);
    }
}