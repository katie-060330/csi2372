#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
    // destructor
    virtual ~Card() = default;
    // adding = 0 to make the functions of type card purely virtual
    virtual int getCardsPerCoin(int coins) = 0;
    // added function to get thte number of coins per length of chain
    virtual int getCoinsPerCard(int cards) = 0;
    virtual string getName() = 0;
    virtual void print(ostream &out) const = 0;
    friend std::ostream &operator<<(std::ostream &out, const Card &card);
};

class Blue : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Chili : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Stink : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Green : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Soy : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Black : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};

class Red : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName() override;
    void print(ostream &out) const override;
};

class Garden : public Card
{

public:
    int getCardsPerCoin(int coins);
    int getCoinsPerCard(int cards);
    string getName();
    void print(ostream &out) const override;
};
