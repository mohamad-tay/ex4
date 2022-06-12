#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

class Pitfall : public Card
{
    private:
    int m_hpDamage;
    friend class player;

    public:
    Pitfall();
    void applyEncounter(Player& player) const
}




#endif //EX4_PITFALL_H