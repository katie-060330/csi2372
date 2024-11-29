#include <iostream>
#include <string>
#include <cctype>
#include "Table.h"
using namespace std;
void playCard(Player currentPlayer);
char input;

// Checks user input to see if they have inputed a number
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}
int main()
{
    Table table;

    // inintlaizing the hands of the two players
    for (int i = 0; i < 5; i++)
    {
        table.p1.hand.operator+=(table.deck->draw());
        table.p2.hand.operator+=(table.deck->draw());
    }
    while (!table.deck->deck.empty())
    {
        // for each player
        for (int k = 0; k < 2; k++)
        {
            Player &p = table.p1;
            if (k == 0)
            {
                p = table.p1;
            }
            else
            {
                p = table.p2;
            }

            // display table
            cout << table << endl;
            // player draws a card
            p.hand.operator+=(table.deck->draw());
            // if ta is not empty add a bean card to chains or discard them
            if (!table.ta.tradeArea.empty())
            {
                for (int i = 0; i < p.getMaxChains(); i++)
                {
                    string c = p.chains.at(i).getType();

                    Card *returned = table.ta.trade(c);
                    if (returned != nullptr)
                    {
                        p.chains.at(i).operator+=(returned);
                    }
                }
            }
            // discard trade area
            table.ta.discard();
            // player has to play thier first card
            input = 'y';
            while ((input == 'y' || input == 'Y') && !p.hand.hand.empty())
            {
                cout << p.getName() << endl;
                for (int i = 0; i < p.getMaxChains(); i++)
                {
                    cout << p.chains.at(i) << endl;
                }

                if (input == 'y' || input == 'Y')
                {

                    for (int i = 0; i < p.getMaxChains(); i++)
                    {

                        // if all the chains are empty
                        if (p.getNonZeroChains() == 0)
                        {
                            p.chains.at(0).operator+=(p.hand.play());
                            break;
                        }
                        else if (p.chains.at(i).getType() == p.hand.top()->getName())
                        {
                            // if so add them
                            p.chains.at(i).operator+=(p.hand.play());
                            break;
                        }
                        else if (p.chains.at(i).getSize() == 0)
                        {
                            p.chains.at(i).operator+=(p.hand.play());
                            break;
                        }
                    }

                    //! debugging help the chains get added
                    cout << p.getName() << endl;
                    for (int i = 0; i < p.getMaxChains(); i++)
                    {
                        cout << p.chains.at(i) << endl;
                    }
                    cout << "Would you like to play you have to play (y): " << p.hand.top()->getName() << endl;

                    cin >> input;
                }
                else
                {
                    break;
                }
            }
            cout << "End of playing from hand" << endl;

            // if chains are ended the sell them
            cout << "Selling avalible chains" << endl;
            for (int i = 0; i < p.getNonZeroChains(); i++)
            {
                Card *c = p.chains.at(i).getCardType();
                if (c->getCoinsPerCard(p.chains.at(i).getSize()) != -1)
                {
                    // if hte chain can be sold for coins than sell it
                    p.chains.at(i).sell();
                }
            }
            cout << "NUmber of coins " << p.getNumCoins() << "for " << p.getName() << endl;

            // if hte player decides to show thier hand, and discard an arbitrary value in

            input = 'y';
            while ((input == 'y' || input == 'Y') && !p.hand.hand.empty())
            {
                cout << "Would you like to discard any of your cards: (y)" << endl;
                cout << p.hand << endl;
                cin >> input;
                if (!(input == 'y' || input == 'Y') && !p.hand.hand.empty())
                {
                    break;
                }
                // player has the option to discard an arbitrary card
                cout << "what card would you like to discard starting at 0? " << endl;
                string h;
                cin >> h;
                if (isNumber(h))
                {
                    int number = stoi(h);
                    table.dp.operator+=(p.hand[number]);
                    auto itterator = p.hand.hand.begin();
                    advance(itterator, number);
                    p.hand.hand.erase(itterator);
                }
            }
            cout << p.hand << endl;

            for (int i = 0; i < 3; i++)
            {
                table.ta.operator+=(table.deck->draw());
            }
            // while the top most card matches the chain chain it up
            //   vector<Card*> cardsInChain;
            //   for( int i = 0; i < p.chains.size(); i++){
            //       cardsInChain.push_back(p.chains.at(i).getCardType());
            //   }
            //   //while the top card of the dp matches any o fhte chain chain them up
            //   for( int i = 0; i < p.chains.size(); i++){
            //       while(table.dp.top()->getName() == cardsInChain.at(i)->getName()){
            //           p.chains.at(i).operator+=(table.dp.pickUp());
            //       }
            //   }

            // //add cards from the ta to the chians
            // for (Card* c : table.ta.tradeArea){
            //     for(int i = 0; i <cardsInChain.size();i++  ){
            //         if(c->getName() == p.chains.at(i).getType()){
            //             p.chains.at(i).operator+=(c);

            //         }
            //     }

            // }

            for (int i = 0; i < 2; i++)
            {
                p.hand.operator+=(table.deck->draw());
            }
            cout << "other player" << endl;
        }
    }
}
