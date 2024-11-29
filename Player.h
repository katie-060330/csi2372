#ifndef PLAYERS_H
#define PLAYERS_H
#include "Chain.h"
#include "Hand.h"
#include "CardFactory.h"
#include "NotEnoughCoins.h"

class Player
{
public:
    string name;
    int totalCoins;
    int numberOfChains;
    bool hasThirdChain;
    int nonZeroChains;
    Hand hand;
    std::vector<Chain<Card *>> chains;

public:
    Player();
    Player(std::string &n);
    int getNonZeroChains();
    Player(istream &in, const CardFactory cardFactory);
    std::string getName() const;
    int getNumCoins();
    Player &operator+=(int coins);
    int getMaxChains();
    Chain<Card *> &operator[](int i);
    void buyThirdChain();
    Hand &getHand();
    void printHand(std::ostream &out, bool showFullHand);
    friend ostream &operator<<(ostream &out, const Player &player);
};
#endif