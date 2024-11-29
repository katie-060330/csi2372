#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include "Player.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Deck.h"


class Table{
    public:
    Player p1; 
    Player p2; 
    Deck* deck;
    DiscardPile dp; 
    TradeArea ta;
    Hand* hand;


    Table();
    Table(istream& in, const CardFactory* cardFactory);
    bool win(std::string& s);
    void printHand(bool showFullHand);
    friend ostream &operator<<(ostream &out, const Table &table);
};
#endif