#include "DiscardPile.h"

//adds to the discard pile 
DiscardPile &DiscardPile::operator+=(Card *c)
{
    discardPile.push_back(c);
    return *this;
}

//removes the top from the discard pile and reases it, if it empty then it returns a null ptr 
Card *DiscardPile::pickUp()
{
    if (!discardPile.empty())
    {
        Card *c = top();
        discardPile.pop_back();
        return c;
    }

    return nullptr;
}
// retuns the top card of the discard pile but doenst change anything 
Card *DiscardPile::top() const
{

    if (!discardPile.empty())
    {
        return discardPile.back();
    }
    return nullptr;
}

void DiscardPile::print(std::ostream &out)
{
    // TODO again ask how these inputs and outputs work
    //*print out all the cards taht where just added to the

    for (Card *c : discardPile)
    {
        out << c->getName() + "/n";
    }
}

//does nothing becaseu we overload this in teh table outstream 
std::ostream &operator<<(ostream &os, const DiscardPile &dPile)
{

    return os;
}
