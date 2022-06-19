include "Merchant.h"
#include "utilities.h"
#include "Player.h"

const int EXTRA_FORCE =1;
const int FORCE_VALUE=10;
const int EXTRA_HP=1;
const int HP_VALUE=5;

Merchant::Merchant() :
Card("Merchant"),
m_extraForce(EXTRA_FORCE),
m_forceValue(FORCE_VALUE),
m_extraHp(EXTRA_HP),
m_hpValue(HP_VALUE);
{}

void applyEncounter(Player& player) const
{
    //ostream os; //??
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.m_name, player.m_coins);
    std::string input;
    std::getline (std::cin,input); 
    while(input != "0" && input != "1" && input != "2")
    {
        printInvalidInput();
        std::getline (std::cin,input);
    } 
    
    if(input == "0")
    {
        printMerchantSummary(std::cout,player.m_name, 0, 0);
    }
    else if(input == "1" && player.m_coins >= HP_VALUE)
    {
        player.heal(EXTRA_HP);
        player.pay(HP_VALUE);
        printMerchantSummary(os,player.m_name, 1, HP_VALUE);

    }
    else if(input == "2" && player.m_coins >= FORCE_VALUE)
    {
        player.buff(EXTRA_FORCE);
        player.pay(FORCE_VALUE);
        printMerchantSummary(os,player.m_name, 2, FORCE_VALUE);
    }
    else
    {
        printMerchantInsufficientCoins(std::cout);
    }

}
