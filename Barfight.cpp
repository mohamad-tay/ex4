#include "Barfight.h"
#include "utilities.h"
#include "Player.h"


Barfight::Barfight() :
Card("Barfight"),
m_hpDamage(10)
{}

void applyEncounter(Player& player) const
{
    if(player.m_name != "Fighter")
    {
        player.damage(m_hpDamage);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}