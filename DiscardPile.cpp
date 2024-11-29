#include "DiscardPile.h"
//   DiscardPile::DiscardPile(istream& in, const CardFactory* cardFactory){
// TODO ask what the input for the constuctors are becaseu they are all ahinvg the same inputs but it doesnt make any sense to me
// do a for loop for the amount of lines in in
/*   for(int i =0; in.gcount; i++){
       Card card = in.getline();
       discardPile.insert(card);


   }*/
//}

DiscardPile &DiscardPile::operator+=(Card *c)
{
    // TODO return a refrence the the card just added to the discard pile
    discardPile.push_back(c);
    return *this;
}

//! done i think
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
//! done i think
Card* DiscardPile::top() const 
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

std::ostream& operator<<(ostream& os,const DiscardPile& dPile)
{


    return os;
}
