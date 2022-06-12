#include "Pitfall.h"
#include "utilities.h"
#include "Player.h"



Pitfall::Pitfall() :
Card("Pitfall"),
m_hpDamage(10)
{}

void applyEncounter(Player& player) const
{
    if(player.m_name != "Rouge")
    {
        player.damage(m_hpDamage);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}