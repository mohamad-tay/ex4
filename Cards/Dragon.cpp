#include "Battle.h"
#include "Dragon.h"

Dragon::Dragon() :
Battle(std::string("Dragon"), 25, 1000, 100)
{}

void Dragon::battleAbstract()
{
    return;
}