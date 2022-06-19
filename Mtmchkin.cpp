#include "Mtmchkin.h"
#include "Exception.h"
#include <iostream>
#include <fstream>
#include <string>

Mtmchkin::Mtmchkin(const std::string fileName) : m_numOfRounds(0)
{
    initializeCards(fileName); //try and catch return in main 
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int numOfPlayer;
    cin >> numOfPlayer;
    while(numOfPlayer<2 || numOfPlayer>6)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        cin >> numOfPlayer;
    }
    printInsertPlayerMessage();

    int i = 0;                               // n70t hay bfonqtsea l7alha
    while(i<numOfPlayer)
    {
        std::string input; 
        cin >> input;
        std::size_t found = input.find(' ');
        if(found != string::npos)
        {
            if(found>15 || found = 0)
            {
                printInvalidName();
                continue;
            }
            else 
            {
                int length = strlen(input);
                std::string nameOfPlayer;         //hktsaa??
                int j=0                  
                for( ; j<found ; j++)
                {
                    nameOfPlayer[j] = input[j];
                }
                nameOfPlayer[j]='\0' //?
                std::string typeOfPlayer;
                int k = 0;
                for(int j=found+1 ; j<=(length+1) ; j++)
                {
                    typeOfPlayer[k] = tempName[j];
                    k++;
                }
                if(typeOfPlayer = "Rouge")
                {
                    shared_ptr<Player> ptr(new Rouge(nameOfPlayer));
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer = "Fighter")
                {
                    shared_ptr<Player> ptr(new Fighter(nameOfPlayer));
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer = "Rouge")
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
            if(strlen(input) > 15)
            {
                printInvalidName();
                continue;
            }
            else
            {
                printInvalidClass();
                continue;
            }
        }
    i++;
}
}

 
void Mtmchkin::initializeCards(const std::string fileName)
{
    ifstream file(fileName);
    if(!(file.is_open()))
    {
        throw DeckFileNotFound e();
    }
    std::string line;
    int numOfLine=0; //0 or 1
    while (std::getline(file, line))
    {
        switch (line)
        {
            case "Goblin" : 
            shared_ptr<Card> ptr(new Goblin(nameOfPlayer));
            m_groubCard.push_back(ptr);
            break;

            case "Vampire" : 
            shared_ptr<Card> ptr(new Vampire(nameOfPlayer));
            m_groubCard.push_back(ptr);
            break;

            case "Dragon" : 
            shared_ptr<Card> ptr(new Dragon(nameOfPlayer));
            m_groubCard.push_back(ptr);
            break;

            case "Merchant" : 
            shared_ptr<Card> ptr(new Merchant(nameOfPlayer));
            m_groubCard.push_back(ptr);
            break;

            case "Treasure" : 
            shared_ptr<Card> ptr(new Treasure(nameOfPlayer))
            m_groubCard.push_back(ptr);
            break;

            case "Pitfall" : 
            shared_ptr<Card> ptr(new Pitfall(nameOfPlayer))
            m_groubCard.push_back(ptr);
            break;

            case "Barfight" : 
            shared_ptr<Card> ptr(new Barfight(nameOfPlayer))
            m_groubCard.push_back(ptr);
            break;

            case "Fairy" : 
            shared_ptr<Card> ptr(new Fairy(nameOfPlayer))
            m_groubCard.push_back(ptr);
            break;

            default :
            throw DeckFileFormatError e(std::to_string(numOfLine)); 
        }
        numOfLine++;
    }
    if(numOfLine<5) //6 or 5 taloy mn kde mnbda
    {
        throw DeckFileInvalidSize e();
    }

}

void Mtmchkin::playRound()
{
    printRoundStartMessage();
    int numOfPlayers = m_teamPlayer.size();
    for( int i=0 ; i<numOfPlayers ; ++i)
    {
        printTurnStartMessage(*(m_teamPlayer.front()).getName());
        (m_groubCard.front())->applyEncounter(*(m_teamPlayer.front()));
        m_groubCard.push_back(m_groubCard.front());
        m_groubCard.pop_front();
        if (*(m_teamPlayer.front()).isKnockedout())
        {
            m_losers.push_front(m_teamPlayer.front());
            m_teamPlayer.pop_front();
        }
        else if (*(m_teamPlayer.front()).getLevel()==10)
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

int getNumberOfRounds() const
{
    return m_numOfRounds;
}

bool isGameOver() const
{
    return !(m_teamPlayer.size());
}

void printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank=1;
    for(int i=0 ; i<m_winners.size(); ++i)
    {
        printPlayerLeaderBoard(rank,*(m_winners[i]));
        rank++;
    }
    for(int i=0 ; i<m_teamPlayer.size(); ++i)
    {
        printPlayerLeaderBoard(rank,*(m_teamPlayer[i]));
        rank++;
    }
    for(int i=0 ; i<m_losers.size(); ++i)
    {
        printPlayerLeaderBoard(rank,*(m_losers[i]));
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