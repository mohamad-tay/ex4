// lazm nns5 alkfatseem card.h + utilities.h 
// bs llesh baken 3amlen incloude l card.h wen ast3mlnaha??

#include "../Cards/Card.h"
#include "../utilities.h"
#include <iostream>
#include "Player.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"
#include <string>

const int FIVE = 5;
const int MAX_HEALTH_DEFAULT = 100;
const int INITIAL_COINS = 10;

Player::Player(const std::string& name) :                              // 6/8/2022
     m_name(name),
     m_level(1),
     m_force(FIVE),
     m_maxHp(MAX_HEALTH_DEFAULT),
     m_hp(MAX_HEALTH_DEFAULT),
     m_coins(INITIAL_COINS)
{}




void Player::levelUp()
{
     if(m_level>=0 && m_level<10)
     {
          m_level++;
     }
}


int Player::getLevel()
{
    if(m_level>=0 && m_level<=10)
    {
         return m_level;
     }
     return -1;
}


void Player::buff(int const extraForce)
{
     if (extraForce>0)
     {
     m_force += extraForce;     
     }                          
}


void Player::heal(int const extraHp)
{
     if (extraHp<=0)          //throw exception ?
     {
          return;
     }
     if((m_hp+extraHp)>m_maxHp)                            
     {
          m_hp = m_maxHp;
     }
     else
     {
          m_hp += extraHp;
     }
}


void Player::damage(int const hpDamage)
{
     if (hpDamage<=0)            //added if 
     {
          return;
     }
     if(m_hp-hpDamage<0)
     {
          m_hp = 0;
     }
     else
     {
         m_hp -= hpDamage;
     }
}


  bool Player::isKnockedOut()
  {
     if(m_hp)
     {
          return false;
     }
     return true;
  }


void Player::addCoins(int const coins) //bdekat kelet //throw exception?
{
     if (coins>0)
     {
     m_coins += coins;
     }
}


 bool Player::pay(int const value)
 {
      if (value<0)
      {
          return true;           //true or false
      }
     if(m_coins >= value)
     {
          m_coins = m_coins-value;
          return true;
     }
     return false;
 }


  int Player::getAttackStrength()
  {
     int attackStrength = m_level + m_force;
     return attackStrength;
  }

  void Player::minusForce()
  {
     if (m_force>=1)
     {
          m_force--;
     }
  }

  std::string Player::getName() const
  {
     return m_name;
  }

std::ostream& operator<<(std::ostream& os,const Player& r)
{
 std::string name= r.m_name;
 std::string job= r.getType();
 int level =r.m_level;
 int force = r.m_force;
 int HP =r.m_hp;
 int coins = r.m_coins;
 printPlayerDetails(os,name,job,level,force,HP,coins);
 return os;
}