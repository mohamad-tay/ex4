#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

class Vampire : public Battle
{
    public:
    Vampire();
    virtual void applyEncounter(Player& player) const override;
}



#endif //EX4_VAMPIRE_H