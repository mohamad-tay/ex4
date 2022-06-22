#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H
#include "Battle.h"
#include "../Players/Player.h"

class Vampire : public Battle
{
    public:
    Vampire();
    void applyEncounter(Player& player) const override;
    void battleAbstract() override;
};



#endif //EX4_VAMPIRE_H