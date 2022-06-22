#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"

class Merchant : public Card 
{
    private:
    int m_extraForce;  //added members here 21.6
    int m_forceValue;
    int m_extraHp;
    int m_hpValue;

    public:
    Merchant(); //removed parameters here merchant always has same things ? 21.6
    void applyEncounter(Player& player) const override;
    //friend std::ostream& operator<<(std::ostream& os, const Merchant& r);
};


#endif //EX4_MERCHANT_H