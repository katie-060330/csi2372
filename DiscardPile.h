#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include "Card.h"
#include "CardFactory.h"
#include <vector>
#include <vector>


class DiscardPile{
    public:
   std::vector<Card *> discardPile;

    //TODO
    DiscardPile(){}
   //DiscardPile(istream& in, const CardFactory* cardFactory);
   DiscardPile& operator+=(Card* c);
   Card* pickUp();
    Card* top() const;


   void print(std::ostream& out);
//TODO insertion operator??
    friend ostream& operator<<(ostream& os,const DiscardPile& dPile);


};
#endif