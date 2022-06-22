#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"
class Fighter : public Player {
public:
   Fighter(const std::string& name);
   int getAttackStrength() override;
   friend std::ostream& operator<<(std::ostream& os, const Fighter& r);
   virtual void abstract() override;
   virtual std::string getType() const override;
};


#endif //EX4_FIGHTER_H