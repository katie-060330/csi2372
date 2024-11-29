#include "Table.h"

Table::Table()
{

    string playerOne;
    string playerTwo;
    // initalizig player one
    cout << "Player one enter name: ";
    getline(cin, playerOne);
    p1 = Player(playerOne);
    // initalizing player two
    cout << "Player two enter name: ";
    getline(cin, playerTwo);
    p2 = Player(playerTwo);
    CardFactory *cardFactory = CardFactory::getCardFactory();
    deck = cardFactory->getDeck();
    dp = DiscardPile();
    ta = TradeArea();
}
bool Table::win(std::string &s)
{
    if (deck->deck.empty())
    {
        if (p1.getName() == s && p1.getNumCoins() > p2.getNumCoins())
        {
            return true;
        }
        else if (p2.getName() == s && p1.getNumCoins() < p2.getNumCoins())
        {
            return true;
        }
    }
    return false;
}

void Table::printHand(bool showFullHand)
{
    if (showFullHand)
    {
        cout << hand;
        // TODO print the full hand to the ostream
    }
    else
    {
        cout << hand->top();
    }
}
std::ostream &operator<<(std::ostream &out, const Table &table)
{
    // printing out the two players
     out << "--------------------- Table ---------------------" << endl;
    out << "Player One: " << table.p1.getName() << endl;
    out << "Player One: " << table.p2.getName() << endl;

    // discard pile outstream operator
    out << "Discard Pile:\t";
    if (table.dp.discardPile.empty())
    {
        out << "Empty" << endl;
    }
    else
    {
        out << table.dp.top()->getName() << endl;
    }

    // trade area outstream
    out << "Trade Area:\t";
    if (table.ta.tradeArea.empty())
    {
        out << "Empty" << endl;
    }
    else
    {
        for (Card *card : table.ta.tradeArea)
        {
            out << card->getName() << " ";
        }
    }

    return out;
}