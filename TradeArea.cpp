#include "TradeArea.h"

    TradeArea::TradeArea(istream& in, const CardFactory cardFactory){
        numberOfCards = 0;
        //TODO same as other constructors
    }

    TradeArea& TradeArea::operator+=(Card* c){
        //*adds the card but doesnt verify that it legally can be added ie the bean is already in the trading area
        tradeArea.push_back(c);
        return *this;

    }
    bool TradeArea::legal(Card* c){
        for(Card* card: tradeArea){
        if(c->getName() == card->getName()){
        return true;
        }
        return false;
}
    }

    Card* TradeArea::trade(string s) {
        //using iterator over list to find the 
    Card* cardMatch = nullptr;  
    for (auto it = tradeArea.begin(); it != tradeArea.end(); ++it) {
        if ((*it)->getName() == s) {
            cardMatch = *it;  
            tradeArea.erase(it);  
            return cardMatch; 
            }
    }
    return nullptr;  
    }

    int TradeArea::numCards(){
        return tradeArea.size();
    }

    void TradeArea::displayTradeArea(){
        for(Card* c : tradeArea){
            cout<< c->getName()<< " ";
        }
    }
    void TradeArea::discard(){
        tradeArea.clear();

    }
    std::ostream& operator<<(std::ostream& out, const TradeArea& tA) {
       
        return out;
    }

    //?nd the insertion operator (friend) to insert all the cards of the trade area to an std::ostream.
