#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <deque>
#include "utilities.h"
#include "Card.h"
#include "Player.h"

class Mtmchkin{

private:
int m_numOfRounds;
std::deque<shared_ptr<Player>> m_teamPlayer;
std::deque<shared_ptr<Card>> m_groubCard;
std::deque<shaared_ptr<Player>> m_winners;
std::deque<shaared_ptr<Player>> m_losers;
void initializeCards(const std::string fileName);


public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */