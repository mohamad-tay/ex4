#include "Treasure.h"
#include "../utilities.h"
#include "../Players/Player.h"

Treasure::Treasure() : 
Card(std::string("Treasure")),
m_treasureCoins(10)
{}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(m_treasureCoins);
    printTreasureMessage();
}