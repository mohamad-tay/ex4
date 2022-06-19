#include "Battle.h"
#include "utilities.h"
#include "Player.h"
#include <string>

Battle:: Battle(const char* name, int force, int loot, int hpLossOnDefeat) :
Card(name),
m_force(force),
m_loot(loot),
m_hpLossOnDefeat(hpLossOnDefeat)
{}

void Battle::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_coins);
        //std::string cardName = m_cardName; //protected check again 
        printWinBattle(player.m_name ,m_cardName); //check access to player.m_name and card , should be ok
    }
    else
    {
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.m_name ,m_cardName);
    }
}

std::ostream& Battle::operator<<(std::ostream& os, const Battle& r)  //check battle&
{
    os << "Card Details:" << endl;
    os << "Name: " << r.m_cardName << endl;
    bool isDragon = false;
    if(r.m_cardName == "Dragon")    //check == should be ok
    {
        isDragon = true
    }
    printMonsterDetails(os, r.m_force, r.m_hpLossOnDefeat, r.m_coins, isDragon );
    printEndOfCardDetails(os)
    return os;
}