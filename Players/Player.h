#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <string>
#include <iostream>
//#include "Mtmchkin.h"
//#include "../Cards/Battle.h"
//#include "../Cards/Vampire.h"
//#include "../Cards/Merchant.h"
#include <string>
//#include "Mtmchkin.h"

class Player {

friend class Mtmchkin;       // check if needded in ex4 
friend class Vampire;  //is include needed ?!!!!!?
friend class Battle;
friend class Merchant;

protected:
   std::string m_name;   
   int m_level;
   int m_force;
   int m_maxHp;
   int m_hp ;
   int m_coins;

public:                                                                 // adding virtual
    Player(const std::string& name);
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
    friend std::ostream& operator<<(std::ostream& os, const Player& r);
};




#endif //EX4_PLAYER_H