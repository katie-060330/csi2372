#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <iostream>
#include <list>
#include "CardFactory.h"


class TradeArea{
    public:

    int numberOfCards; 
    std::list<Card*> tradeArea;

    TradeArea(istream& in, const CardFactory cardFactory);
    TradeArea(){};
    ~TradeArea() { numberOfCards=0;};
    TradeArea& operator+=(Card* c);
    bool legal(Card* c);
    Card* trade(string s);
    int numCards();
    void displayTradeArea(); 
    void discard(); 
    friend ostream& operator<<(ostream& out, const TradeArea& tA);

};
#endif