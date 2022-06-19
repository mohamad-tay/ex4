#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

//#include "Mtmchkin.h"
#include "Battle.h"
#include "Merchant.h"
#include <string>
//#include "Mtmchkin.h"

class Player {
protected:
   std::string m_name;   
   int m_level;
   int m_force;
   int m_maxHp;
   int m_hp ;
   int m_coins;
   friend class Mtmchkin;       // check if needded in ex4 
   friend class Battle;  //is include needed ?!!!!!?
   friend class Merchant; //check if Card

public:                                                                 // adding virtual
    Player(const char* name);
    Player(const Player& copiedPlayer)=default;
    virtual ~Player()=default;
    void levelUp();
    int getLevel();
    void buff(int extraForce);
    virtual void heal(int extraHp);
    void damage(int hpDamage);
    bool isKnockedOut();
    virtual void addCoins(int coins) ;
    bool pay(int value);
    virtual int getAttackStrength();
    void minusForce();
    virtual void abstract()=0; //made the class abstract
    std::string getName() const;
};




#endif //EX4_PLAYER_H