#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

class Wizard : public Player {
public:
    void heal(int extraHp) override; 
    friend std::ostream& operator<<(std::ostream& os, const Wizard& r);
}





#endif //EX4_WIZARD_H