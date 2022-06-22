#include "Goblin.h"

Goblin::Goblin() :
Battle(std::string("Goblin"), 6, 2, 10)        //check sendingn "" as char*
{}

void Goblin::battleAbstract()
{
    return;
}