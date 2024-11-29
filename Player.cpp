#include "Player.h"
//default constuctor 
Player::Player() {}
//constructor used to create the player 
Player::Player(std::string &n)
{

    name = n;
    totalCoins = 0;
    numberOfChains = 2;
    hasThirdChain = false;
    nonZeroChains = 0;
    hand = Hand();
    chains = std::vector<Chain<Card *>>(2);

}
//returns the number of chains that arent empty
int Player::getNonZeroChains()
{
    int k = 0;
    for (int i = 0; i < chains.size(); i++)
    {
        if (chains.at(i).getSize() == 0)
        {
            k++;
        }
    }
    return chains.size() - k;
}

//bonus of one mark.. we didnt chose to do that 
Player::Player(istream &in, const CardFactory cardFactory)
{
    
}
//getters
std::string Player::getName() const
{
    return name;
}
int Player::getNumCoins()
{
    return totalCoins;
}
//adding coins for when we sell the chain 
Player &Player::operator+=(int coins)
{
    totalCoins += coins;
    return *this;

    //*adds coins to the plyers total
}
int Player::getMaxChains()
{
    return numberOfChains;
}
//getting chain at position i
Chain<Card *> &Player::operator[](int i)
{
    return (chains.at(i));
}
void Player::buyThirdChain()
{
    //* if the player has enough money to buy the chain and the payer hasnt bouth the chain already

    if (getNumCoins() >= 3 && !hasThirdChain)
    {
        totalCoins -= 3;
        hasThirdChain = true;
        numberOfChains = 3;
    }
    else
    {
        throw NotEnoughCoins("Player doesnt have enough coins to buy a third chain. ");
    }
}
Hand &Player::getHand()
{
    return hand;
}
void Player::printHand(std::ostream &out, bool showFullHand)
{
    if (showFullHand)
    {
        // uisng insertion opperator
        cout << hand;
        // TODO print the full hand to the ostream
    }
    else
    {
        hand.top()->print(out);
    }
}
std::ostream &operator<<(std::ostream &out, Player &player)
{
    out << player.getName();
    out << player.getNumCoins();

    return out;
}
