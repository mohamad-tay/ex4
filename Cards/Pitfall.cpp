#include "Pitfall.h"
#include "utilities.h"
#include "Player.h"
#include "Rouge.h"


Pitfall::Pitfall() :
Card("Pitfall"),
m_hpDamage(10)
{}

void applyEncounter(Player& player) const
{

    //Player* playerPtr = &player;
    Rogue* castPtr = dynamic_cast<Rogue*>(&player);
    if(castPtr == nullptr)     //fix 
    {
        player.damage(m_hpDamage);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}