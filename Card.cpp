
#include "Card.h"
#include <stdexcept>
#include <iostream>


std::ostream& operator<<(std::ostream& out, const Card& card)
{
    card.print(out);
    return out;
}

int Blue::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 4;
    }
    else if (coins == 2)
    {
        return 6;
    }
    else if (coins == 3)
    {
        return 8;
    }
    else if (coins == 4)
    {
        return 10;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1, 2, 3, 4");
    }
}

int Blue::getCoinsPerCard(int cards)
{
    //when the chain doesnt make any coins
    if (cards < 4 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 4 || cards == 5)
    {
        return 1;
    }
    else if (cards <= 7 && cards > 5)
    {
        return 2;
    }
    else if (cards > 7 && cards <= 9)
    {
        return 3;
    }
    else if (cards > 9 && cards <= 20)
    {
        return 4;
    }
 
}

string Blue::getName()
{
    return "Blue";
}

void Blue::print(ostream &out) const
{
    out << "B";
}

int Chili::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 3;
    }
    else if (coins == 2)
    {
        return 6;
    }
    else if (coins == 3)
    {
        return 8;
    }
    else if (coins == 4)
    {
        return 9;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Chili::getCoinsPerCard(int cards)
{
    if (cards < 3 && cards >= 0)
    {
        return 0;
    }
    else if (cards <= 5 && cards >= 3)
    {
        return 1;
    }
    else if (cards <= 7 && cards > 5)
    {
        return 2;
    }
    else if (cards == 8)
    {
        return 3;
    }
    else if (cards >= 9 && cards <= 18)
    {
        return 4;
    }
 
}

string Chili::getName()
{
    return "Chili";
}

void Chili::print(ostream &out) const
{
    out << "C";
}

int Stink::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 3;
    }
    else if (coins == 2)
    {
        return 5;
    }
    else if (coins == 3)
    {
        return 7;
    }
    else if (coins == 4)
    {
        return 8;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Stink::getCoinsPerCard(int cards)
{
    if (cards < 3 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 4 || cards == 3)
    {
        return 1;
    }
    else if (cards <= 7 && cards > 5)
    {
        return 2;
    }
    else if (cards == 8)
    {
        return 3;
    }
    else if (cards >= 9 && cards <= 16)
    {
        return 4;
    }

    else
    {
       return -1; 
    }
}

string Stink::getName()
{
    return "Stink";
}

void Stink::print(ostream &out) const
{
    out << "S";
}

int Green::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 3;
    }
    else if (coins == 2)
    {
        return 5;
    }
    else if (coins == 3)
    {
        return 6;
    }
    else if (coins == 4)
    {
        return 7;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}

int Green::getCoinsPerCard(int cards)
{
    if (cards < 3 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 4 || cards == 3)
    {
        return 1;
    }
    else if (cards == 5)
    {
        return 2;
    }
    else if (cards == 6)
    {
        return 3;
    }
    else if (cards >= 7 && cards <= 14)
    {
        return 4;
    }

 
}

string Green::getName()
{
    return "Green";
}

void Green::print(ostream &out) const
{
    out << "G";
}

int Soy::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 2;
    }
    else if (coins == 2)
    {
        return 4;
    }
    else if (coins == 3)
    {
        return 6;
    }
    else if (coins == 4)
    {
        return 7;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Soy::getCoinsPerCard(int cards)
{
    if (cards < 2 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 2 || cards == 3)
    {
        return 1;
    }
    else if (cards == 5 || cards == 4)
    {
        return 2;
    }
    else if (cards == 6)
    {
        return 3;
    }
    else if (cards >= 7 && cards <= 12)
    {
        return 4;
    }
    // not enought cards in teh deck to make a chain
 
}

string Soy::getName()
{
    return "soy";
}

void Soy::print(ostream &out) const
{ //?
    out << "s";
}

int Black::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 2;
    }
    else if (coins == 2)
    {
        return 4;
    }
    else if (coins == 3)
    {
        return 5;
    }
    else if (coins == 4)
    {
        return 6;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Black::getCoinsPerCard(int cards)
{
    if (cards < 2 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 2 || cards == 3)
    {
        return 1;
    }
    else if (cards == 4)
    {
        return 2;
    }
    else if (cards == 5)
    {
        return 3;
    }
    else if (cards >= 6 && cards <= 10)
    {
        return 4;
    }

    else
    {
       return -1; 
    }
}

string Black::getName()
{
    return "black";
}

void Black::print(ostream &out) const
{
    out << "b";
}

int Red::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 2;
    }
    else if (coins == 2)
    {
        return 3;
    }
    else if (coins == 3)
    {
        return 4;
    }
    else if (coins == 4)
    {
        return 5;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Red::getCoinsPerCard(int cards)
{
    if (cards < 2 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 2)
    {
        return 1;
    }
    else if (cards == 3)
    {
        return 2;
    }
    else if (cards == 4)
    {
        return 3;
    }
    else if (cards == 5 && cards <= 8)
    {
        return 4;
    }

    else
    {
       return -1; 
    }
}

string Red::getName()
{
    return "Red";
}

void Red::print(ostream &out) const
{
    out << "R";
}

int Garden::getCardsPerCoin(int coins)
{
    if (coins == 1)
    {
        return 0;
    }
    else if (coins == 2)
    {
        return 2;
    }
    else if (coins == 3)
    {
        return 3;
    }
    else if (coins == 4)
    {
        return 0;
    }
    else
    {
        throw std::invalid_argument("Coins cannot have values other than 1,2,3,4");
    }
}
int Garden::getCoinsPerCard(int cards)
{
    // not enougth cards to get coins
    if (cards < 2 && cards >= 0)
    {
        return 0;
    }
    else if (cards == 2)
    {
        return 2;
    }
    else if (cards == 3)
    {
        return 3;
    }
    // not enought cards in teh deck to make a chain
    else
    {
        return -1;
    }
}

string Garden::getName()
{
    return "garden";
}

void Garden::print(ostream &out) const
{
    out << "g";
}
