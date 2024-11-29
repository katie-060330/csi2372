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
    Chain<T> &operator+=(Card *card)
    {
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

    string getType()
    {
        return chain.empty() ? "Empty" : chain.front()->getName();
    }

    void startFreshChain(Card *card)
    {
        sell();
        *this += card;
    }

    Card *getCardType()
    {
        return chain.empty() ? nullptr : chain.front();
    }

    friend ostream& operator<<(ostream &output, const Chain<T> &c)
    {
        if (c.chain.empty())
        {
            output << "Empty";
        }
        else
        {

            Card* front = c.chain.front();
            string f = front->getName();
            output<<f<< "\t"; 
            
            for(int i = 0; i < c.chain.size(); i++){
                output<<f.at(0)<<" ";
            }
            
            // output << c.chain.front()->getName() << "\t";
            // for (const T *card : c.chain)
            // {
            //     card->print(output);
            //     output << " ";
            // }
        }
        return output;
    }
    int getSize(){
        return chain.size();
    }
    

};

#endif
