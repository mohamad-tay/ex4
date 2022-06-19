#include "Vampire.h"

Vampire::Vampire() :
Battle(Vampire, 10, 2, 10)
{}

void Vampire::applyEncounter(Player& player) const //check const 
{
        if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();  //p msh capital
        player.addCoins(m_coins);
        //std::string cardName = m_cardName; //protected check again 
        printWinBattle(player.m_name ,m_cardName); //check access to player.m_name and card , should be ok
    }
    else
    {
        player.damage(m_hpLossOnDefeat);
        player.minusForce();
        printLossBattle(player.m_name ,m_cardName);
    }
}