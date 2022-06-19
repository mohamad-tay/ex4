#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

class Treasure : public Card
{
    private:
    int m_treasureCoins;

    public:
    Treasure();
    void applyEncounter(Player& player) const override;
}




#endif //EX4_TREASURE_H