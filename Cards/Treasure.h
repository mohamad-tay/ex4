#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"
#include "../Players/Player.h"
class Treasure : public Card
{
    private:
    int m_treasureCoins;

    public:
    Treasure();
    void applyEncounter(Player& player) const override;
};




#endif //EX4_TREASURE_H