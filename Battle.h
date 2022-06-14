#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

class Battle : public Card
{
    private:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
    //friend class Player;

    public:
    Battle(const char* name, int force, int loot, int hpLossOnDefeat);
    virtual void applyEncounter(Player& player) const ; //made virtual
    friend std::ostream& operator<<(std::ostream& os, const Battle& r ); //check battle&
    virtual void battleAbstract()=0; //made abstract
}


#endif //EX4_BATTLE_H