#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H
#include "Card.h"
class Fairy : public Card
{
    private:
    int m_extraHp;
    //friend class player;

    public:
    Fairy();
    void applyEncounter(Player& player) const override;
};




#endif //EX4_FAIRY_H