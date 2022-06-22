#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player {
public:
 Wizard(const std::string& name);
 void heal(int extraHp) override; 
 friend std::ostream& operator<<(std::ostream& os, const Wizard& r);
 virtual void abstract() override;
 std::string getType() const override;
};



#endif //EX4_WIZARD_H