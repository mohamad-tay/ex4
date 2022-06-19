#include "Rouge.h"
#include "utilities.h"


void Rouge::addCoins(int const coins) //bdekat kelet
{
     if (coins>0)
     {
     m_coins += 2*coins;
     }
}

std::ostream& Rogue::operator<<(std::ostream& os, const Rogue& r)
{
 std::string name= r.m_name;
 std::string job = "Rogue";
 int level =r.m_level;
 int force = r.m_force;
 int HP =r.m_hp;
 int coins = r.m_coins;
 printPlayerDetails(os,name,job,level,force,HP,coins);
}
