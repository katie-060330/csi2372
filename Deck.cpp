#include "Deck.h"

//crawing a cards and deleteing it from the deck 
Card *Deck::draw()
{
   //drawing a card and erasing it from the deck 
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

//printing out the deck
std::ostream &operator<<(std::ostream &out, const Deck &d)
{
    for (auto current = d.deck.begin(); current != d.deck.end(); current++)
    {
        out << (*current)->getName() << " ";
    }
    return out;
}

