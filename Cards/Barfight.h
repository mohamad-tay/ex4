#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

class Barfight : public Card
{
    private:
    int m_hpDamage;
    //friend class player;

    public:
    Barfight();
    void applyEncounter(Player& player) const override;
}




#endif //EX4_BARFIGHT_H

