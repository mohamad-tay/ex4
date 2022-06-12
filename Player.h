#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
//#include "Mtmchkin.h"

class Player {
protected:
   std::string m_name;   //may be probmlematic in advance copy c'tor
   int m_level;
   int m_force;
   int m_maxHp;
   int m_hp ;
   int m_coins;
   friend class Mtmchkin;

public:                                                                 // adding virtual
    Player(const char* name);
    Player(const Player& copiedPlayer)=default;
    ~Player()=default;
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int extraForce);
    virtual void heal(int extraHp);
    void damage(int hpDamage);
    bool isKnockedOut();
    virtual void addCoins(int coins);
    bool pay(int value);
    virtual int getAttackStrength();
    
};




#endif //EX4_PLAYER_H