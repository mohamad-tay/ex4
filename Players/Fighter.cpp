#include "Fighter.h"
#include "../utilities.h"

Fighter::Fighter(const std::string& name) : Player(name)
{}

int Fighter::getAttackStrength()
  {
     int attackStrength = m_level + 2*m_force;
     return attackStrength;
  }

std::ostream& operator<<(std::ostream& os, const Fighter& r)
{
 std::string name= r.m_name;
 std::string job = "Fighter";
 int level =r.m_level;
 int force = r.m_force;
 int HP =r.m_hp;
 int coins = r.m_coins;
 printPlayerDetails(os,name,job,level,force,HP,coins);
 return os;
}

 void Fighter::abstract()
 {
  return;
 }

 std::string Fighter::getType() const
 {
  return std::string("Fighter");
 }