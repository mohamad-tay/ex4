#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

class Fairy : public Card
{
    private:
    int m_extraHp;
    friend class player;

    public:
    Fairy();
    void applyEncounter(Player& player) const
}




#endif //EX4_FAIRY_H