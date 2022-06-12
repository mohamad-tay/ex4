#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

class Battle : public Card
{
    private:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
    friend class Player;

    public:
    Battle(const char* name, int force, int loot, int hpLossOnDefeat);
    void applyEncounter(Player& player) const ;
    std::ostream& operator<<(std::ostream& os);
}







#endif //EX4_BATTLE_H