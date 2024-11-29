#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

class Deck
{

public:
    std::vector<Card *> deck;
    Card *draw();
    friend ostream &operator<<(ostream &out, const Deck &d);
    
};
#endif