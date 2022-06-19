#include "Gang.h"
#include <iostream>


Gang::Gang() : Battle("Gang",0,0,0)
{}

void Gang::addMember(const std::string& member, int* lineNumPtr)
{
    switch (member)
    {
        case "Goblin" : 
        shared_ptr<Card> ptr(new Goblin(nameOfPlayer));
        m_gang.push_back(ptr);
        break;

        case "Vampire" : 
        shared_ptr<Card> ptr(new Vampire(nameOfPlayer));
        m_gang.push_back(ptr);
        break;

        case "Dragon" : 
        shared_ptr<Card> ptr(new Dragon(nameOfPlayer));
        m_gang.push_back(ptr);
        break;

        case "EndGang" :
        return;

        default :
        throw DeckFileFormatError e(std::to_string(*numOfLine)); 
    }
    *(lineNumPtr)++;
}


void applyEncounter(Player& player) const 
{
    if(player.getAttackStrength() >= m_gang.front->m_force)
    {
        player.addCoins(m_gang.front->m_coins);
        if(m_gang.size()==1) //b3rfsh etha lazm hay elhdpsa
        {
            player.levelUp();
            printWinBattle(player.m_name ,m_cardName); //check access to player.m_name and card , should be ok
        }
        m_gang.pop_front(); //memory leak?? check check 
    }
    else
    {
        while(m_gang.size()>=1)
        {
            m_gang.front->applyEncounter(player);
            //printLossBattle(player.m_name ,m_cardName); //hdpsa?
            m_gang.pop_front();
        }
    }
}

