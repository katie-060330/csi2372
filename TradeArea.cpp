#include "TradeArea.h"

TradeArea::TradeArea(istream &in, const CardFactory cardFactory)
{

}

TradeArea &TradeArea::operator+=(Card *c)
{
    //*adds the card but doesnt verify that it legally can be added ie the bean is already in the trading area
    tradeArea.push_back(c);
    return *this;
}
//checks to see if this card is in the trade area
bool TradeArea::legal(Card *c)
{
    for (Card *card : tradeArea)
    {
        if (c->getName() == card->getName())
        {
            return true;
        }
       
    }
     return false;
}

//check to see if this card can be traded and if it can, remove it from the trade block and return it, if the trade block is empty then return nill
Card *TradeArea::trade(string s)
{
    // using iterator over list to find the
    Card *cardMatch = nullptr;
    for (auto it = tradeArea.begin(); it != tradeArea.end(); ++it)
    {
        if ((*it)->getName() == s)
        {
            cardMatch = *it;
            tradeArea.erase(it);
            return cardMatch;
        }
    }
    return nullptr;
}
//getter
int TradeArea::numCards()
{
    return tradeArea.size();
}

void TradeArea::displayTradeArea()
{
    for (Card *c : tradeArea)
    {
        cout << c->getName() << " ";
    }
}
//remove the trade area
void TradeArea::discard()
{
    tradeArea.clear();
}
//overloaded in the table class
std::ostream &operator<<(std::ostream &out, const TradeArea &tA)
{

    return out;
}
