#include "Treasure.h"
#include "utilities.h"
#include "Player.h"

Treasue::Treasure() : 
Card("Treasure"),
m_treasureCoins(10)
{}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(m_treasureCoins);
    printTreasureMessage();
}