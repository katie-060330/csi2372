#ifndef CHAIN_H
#define CHAIN_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "Card.h"

using namespace std;

template <class T>
class Chain
{
    std::vector<T> chain;

public:
    // adding cards to the chian
    Chain<T> &operator+=(Card *card)
    {
        // make sure that they match the chain
        if (typeid(card) != typeid(chain.front()))
        {
            throw std::invalid_argument("Card doesn't match the chain");
        }
        else
        {
            chain.push_back(card);
        }
        return *this;
    }

    void addCard(Card *card)
    {
        *this += card;
    }

    int sell()
    {
        if (chain.empty())
        {
            return 0;
        }
        int size = chain.size();
        Card *topCard = chain.front();
        int coins = topCard->getCoinsPerCard(size);
        chain.clear();
        return coins;
    }

    // for checkign the chain type to add cards
    string getType()
    {
        return chain.empty() ? "Empty" : chain.front()->getName();
    }

    // when the chains are full and they are forced to sell a chain becasue the player needs to sell
    int startFreshChain(Card *card)
    {
        int coins = sell();
        *this += card;
        return coins;
    }

    // similar  to get type but returns the acctual card
    Card *getCardType()
    {
        return chain.empty() ? nullptr : chain.front();
    }

    // printing out the chains
    friend ostream &operator<<(ostream &output, const Chain<T> &c)
    {
        if (c.chain.empty())
        {
            output << "Empty";
        }
        else
        {

            Card *front = c.chain.front();
            string f = front->getName();
            output << f << "\t";

            for (int i = 0; i < c.chain.size(); i++)
            {
                output << f.at(0) << " ";
            }

        }
        return output;
    }
    
    int getSize()
    {
        return chain.size();
    }
};

#endif
