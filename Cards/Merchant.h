#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

class Merchant : public Card 
{
    private:
    int m_extraForce;
    int m_extraHp;

    public:
    Merchant(int extraForce, int extraHp);
    void applyEncounter(Player& player) const;
    std::ostream& operator<<(std::ostream& os);
}


#endif //EX4_MERCHANT_H