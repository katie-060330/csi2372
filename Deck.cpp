#include "Deck.h"


Card *Deck::draw()
{
   
    if (!deck.empty())
    {
        Card *toReturn = deck.front();
        deck.erase(deck.begin());
        return toReturn;
    }
    else
    {
        return nullptr;
    }
}

std::ostream &operator<<(std::ostream &out, const Deck &d)
{
    for (auto current = d.deck.begin(); current != d.deck.end(); current++)
    {
        out << (*current)->getName() << " ";
    }
    return out;
}

