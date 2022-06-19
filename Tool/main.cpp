#include "Mtmchkin.h"

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try
    {
        Mtmchkin game("deck.txt");
    }
    catch(DeckFileNotFound& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(DeckFileFormatError& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(DeckFileInvalidSize& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
    {
        game.playRound();
        game.printLeaderBoard();
    }
 
}
