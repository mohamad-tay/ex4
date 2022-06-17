#include "Mtmchkin.h"
#include "iostream"
#include <fstream>
#include <string>

Mtmchkin::Mtmchkin(const std::string fileName) 
{
    initializeCards(fileName);
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int numOfPlayer;
    cin >> numOfPlayer;
    while(numOfPlayer<2 && numOfPlayer>6)
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
                nameOfPlayer[j]='\0'
                std::string typeOfPlayer;
                int k = 0;
                for(int j=found+1 ; j<=(length+1) ; j++)
                {
                    typeOfPlayer[k] = tempName[j];
                    k++;
                }
                if(typeOfPlayer = "Rouge")
                {
                    shared_ptr<Player> ptr(new Rouge(nameOfPlayer))
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer = "Fighter")
                {
                    shared_ptr<Player> ptr(new Fighter(nameOfPlayer))
                    m_teamPlayer.push_back(ptr);
                }
                else if(typeOfPlayer = "Rouge")
                {
                    shared_ptr<Player> ptr(new Wizard(nameOfPlayer))
                    m_teamPlayer.push_back(ptr);
                }
                else
                {
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
    i++
}

 
void Mtmchkin::initializeCards(const std::string fileName)
{
    ifstream file(fileName);
    if(!(file.is_open()))
    {
        throw DeckFileNotFound e();
    }
    map<std::string, Object *(*c)()> typeOfCard = {
        {"" , }
    }
    std::string line;
     map<std::string, Object *(*c)()>::iterator itr;
    while (std::getline(file, line))
    {
        for (itr =typeOfCard.begin(); itr != typeOfCard.end() ; ++itr)
        {
            if(itr->first == line)
            {
                shared_ptr<Player> ptr(new itr->second);
                m_groubCard.push_back(ptr);
                break;
            }
            if(itr==typeOfCard.end())
            {
                throw 
            }
        }
    }
}

kkk