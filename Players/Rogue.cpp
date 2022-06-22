#include "Rogue.h"
#include "../utilities.h"

Rogue::Rogue(const std::string& name) : Player(name)
{}


void Rogue::addCoins(int const coins) //bdekat kelet
{
     if (coins>0)
     {
     m_coins += 2*coins;
     }
}

std::ostream& operator<<(std::ostream& os, const Rogue& r)
{
 std::string name= r.m_name;
 std::string job = "Rogue";
 int level =r.m_level;
 int force = r.m_force;
 int HP =r.m_hp;
 int coins = r.m_coins;
 printPlayerDetails(os,name,job,level,force,HP,coins);
 return os;
}

 void Rogue::abstract()
 {
     return;
 }

 std::string Rogue::getType() const
 {
    return std::string("Rogue");
 }