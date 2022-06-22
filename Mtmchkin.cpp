#include "Mtmchkin.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Card.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Player.h"
#include "Exception.h"
#include "utilities.h"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;


Mtmchkin::Mtmchkin(const std::string fileName) : m_numOfRounds(0)
{
    initializeCards(fileName); //try and catch return in main 
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int numOfPlayer;
    std::cin >> numOfPlayer; //getline?????   std::cin >> numOfPlayer;
    while(numOfPlayer<2 || numOfPlayer>6)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> numOfPlayer; //bka kelta 3adeye
    }
    printInsertPlayerMessage();

    int i = 0;                               // n70t hay bfonqtsea l7alha
    while(i<numOfPlayer)
    {
        std::string input; 
        std::getline(std::cin,input);
        std::size_t found1 = input.find(' ');
        if(found1 != string::npos)
        {
            int found = (int)found1; //check cast 22.6
            if(found>15 || found == 0) //changed to >= 22.6
            {
                printInvalidName();
                continue;
            }
            else 
            {
                int length = (int)(input.size()); //bdlna mn strlen
                std::string nameOfPlayer;         //hktsaa??
                int j=0;                  
                for( ; j<found ; j++)
                {
                    nameOfPlayer.push_back(input[j]);
                }
                //nameOfPlayer[j]='\0' ; //check this and string comparison below
                std::string typeOfPlayer;
                for(int z=found+1 ; z<=(length) ; z++) //removed +! from length 22.6
                {
                    typeOfPlayer.push_back(input[z]);
                }
                if(typeOfPlayer == "Rogue")
                {
                    std::shared_ptr<Player> ptr(new Rogue(nameOfPlayer));
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer == "Fighter")
                {
                    shared_ptr<Player> ptr(new Fighter(nameOfPlayer));
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer == "Wizard")
                {
                    shared_ptr<Player> ptr(new Wizard(nameOfPlayer));
                    m_teamPlayer.push_back(ptr); //check shared ptr what happens
                }
                else
                {
                    printInvalidClass();
                    continue;
                } 
            }
        }
        else
        {
            if(((int)(input.size())) > 15) //changed here 22.6
            {
                printInvalidName();
                continue;
            }
            else //made commented 22.6
            {
                printInvalidClass();
                continue;
            }
        }
        i++;
        if (i<numOfPlayer)
        {
        printInsertPlayerMessage();
        }
}
}


 
void Mtmchkin::initializeCards(const std::string fileName)
{
    std::ifstream file(fileName);
    if(!(file.is_open()))
    {
        throw DeckFileNotFound();
    }
    std::string line;
    int numOfLine=0; //0 or 1
    while (std::getline(file, line))
    {
        
        if (line == std::string("Goblin"))
        {
            shared_ptr<Card> ptr(new Goblin());
            m_groubCard.push_back(ptr);
        }
        else if (line == std::string("Vampire"))
        {
            shared_ptr<Card> ptr(new Vampire());
            m_groubCard.push_back(ptr);
        }

         else if (line == std::string("Dragon"))
        {
            shared_ptr<Card> ptr(new Dragon());
            m_groubCard.push_back(ptr);
        }

        else if (line == std::string("Merchant"))
        {
            shared_ptr<Card> ptr(new Merchant());
            m_groubCard.push_back(ptr);
        }

        else if (line == std::string("Treasure"))
        {
            shared_ptr<Card> ptr(new Treasure());
            m_groubCard.push_back(ptr);
        }

        else if (line == std::string("Pitfall"))
        {
            shared_ptr<Card> ptr(new Pitfall());
            m_groubCard.push_back(ptr);
        }

         else if (line == std::string("Barfight"))
        {
            shared_ptr<Card> ptr(new Barfight());
            m_groubCard.push_back(ptr);
        }

         else if (line ==  std::string("Fairy"))
        {
            shared_ptr<Card> ptr(new Fairy());
            m_groubCard.push_back(ptr);
        }

        else
        {
            throw DeckFileFormatError(std::to_string(numOfLine)); 
        }
        numOfLine++;
    }
    if(numOfLine<5) //6 or 5 taloy mn kde mnbda
    {
        throw DeckFileInvalidSize();
    }

}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_numOfRounds);
    int numOfPlayers = m_teamPlayer.size();
    for( int i=0 ; i<numOfPlayers ; ++i)
    {
        printTurnStartMessage((*(m_teamPlayer.front())).getName());
        (m_groubCard.front())->applyEncounter(*(m_teamPlayer.front()));
        m_groubCard.push_back(m_groubCard.front());
        m_groubCard.pop_front();
        if ((*(m_teamPlayer.front())).isKnockedOut())
        {
            m_losers.push_front(m_teamPlayer.front());
            m_teamPlayer.pop_front();
        }
        else if ((*(m_teamPlayer.front())).getLevel()==10)
        {
            m_winners.push_back(m_teamPlayer.front());
            m_teamPlayer.pop_front();
        }
        else 
        {
            m_teamPlayer.push_back(m_teamPlayer.front());
            m_teamPlayer.pop_front();   
        }
    }
    m_numOfRounds++;
    if(this->isGameOver())
    {
        printGameEndMessage();
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numOfRounds;
}

bool Mtmchkin::isGameOver() const
{
    return !(m_teamPlayer.size());
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank=1;
    for(int i=0 ; i<((int)m_winners.size()); ++i)
    {
        printPlayerLeaderBoard(rank,(*(m_winners[i])));
        rank++;
    }
    for(int i=0 ; i<((int)m_teamPlayer.size()); ++i)
    {
        printPlayerLeaderBoard(rank,(*(m_teamPlayer[i])));
        rank++;
    }
    for(int i=0 ; i<((int)m_losers.size()); ++i)
    {
        printPlayerLeaderBoard(rank,(*(m_losers[i])));
        rank++;
    }
}


/*
void Mtmchkin::initializeCards(const std::string fileName)
{
    ifstream file(fileName);
    if(!(file.is_open()))
    {
        throw DeckFileNotFound e();
    }
    // map<std::string, Object *(*c)()> typeOfCard = {
    //     {"" , }
    // }
    // std::string line;
    // map<std::string, Object *(*c)()>::iterator itr;
    while (std::getline(file, line))
    {
        // for (itr =typeOfCard.begin(); itr != typeOfCard.end() ; ++itr)
        // {
        //     if(itr->first == line)
        //     {
        //         shared_ptr<Player> ptr(new itr->second);
        //         m_groubCard.push_back(ptr);
        //         break;
        //     }
        //     if(itr==typeOfCard.end())
        //     {
        //         throw 
        //     }
        }
    }
}*/