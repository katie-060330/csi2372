#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include <iostream>
#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <random>
#include <chrono>

using namespace std;


class Deck;
class CardFactory{

    public:
       static const int deckSize = 104;
       static vector<Card*> deckToBe;
       static CardFactory* instance;
       CardFactory();

    
    Deck* cardDeck;
    ~CardFactory();
    static CardFactory* getCardFactory();
    Deck* getDeck();
    Card* getCard(string cardType) const;
};


#endif
