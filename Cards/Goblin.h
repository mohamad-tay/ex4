#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H
#include "Battle.h"
class Goblin : public Battle
{
    public:
    Goblin();
    void battleAbstract() override;
};



#endif //EX4_GOBLIN_H