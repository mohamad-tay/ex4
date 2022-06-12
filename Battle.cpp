#include "Battle.h"
#include "utilities.h"
#include "Player.h"

Battle:: Battle(const char* name, int force, int loot, int hpLossOnDefeat) :
Card(name),
m_force(force),
m_loot(loot),
m_hpLossOnDefeat(hpLossOnDefeat)
{}

void Battle::applyEncounter(Player& player) const
{
    if(Player::player.getAttackStrength() >= m_force)
    {
        Player::player.levelUp();
        Player::Player.addCoins(m_coins);
        printWinBattle(player.m_name ,m_cardName);
    }
    else
    {
        Player::Player.damage(m_hpLossOnDefeat);
        printLossBattle(player.m_name ,m_cardName);
    }
}

std::ostream& Battle::operator<<(std::ostream& os)
{
    os << "Card Details:" << endl;
    os << "Name: " << m_cardName << endl;
    bool isDragon = false;
    if(m_cardName == "Dragon")
    {
        isDragon = true
    }
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, int m_coins, isDragon );
    printEndOfCardDetails(os)
    return os;
}