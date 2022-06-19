#include "Wizard.h"
#include "utilities.h"


void Wizard::heal(int const extraHp)
{
     if (extraHp<=0)                   // ??
     {
        return;
     }
     if((m_hp+2*extraHp)>m_maxHp)                            
     {
        m_hp = m_maxHp;
     }
     else
     {
        m_hp += 2*extraHp;
     }
}


std::ostream& Wizard::operator<<(std::ostream& os, const Wizard& r)
{
 std::string name= r.m_name;
 std::string job = "Wizard";
 int level =r.m_level;
 int force = r.m_force;
 int HP =r.m_hp;
 int coins = r.m_coins;
 printPlayerDetails(os,name,job,level,force,HP,coins);
}
