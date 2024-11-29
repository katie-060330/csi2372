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

    for (int i = 0; i < 5; i++)
    {
        table.p1.hand.operator+=(table.deck->draw());
        table.p2.hand.operator+=(table.deck->draw());
    }

    do
    {
        for (int playerIdx = 0; playerIdx < 2; playerIdx++)
        {
            // able to keep chains from resetting every itteration
            Player &currentPlayer = (playerIdx == 0) ? table.p1 : table.p2;

            // print out table
            cout << table << endl;

            currentPlayer.hand.operator+=(table.deck->draw());

            // Add bean card to chains or discard them
            if (!table.ta.tradeArea.empty())
            {
                for (int i = 0; i < currentPlayer.getMaxChains(); i++)
                {
                    string c = currentPlayer.chains.at(i).getType();
                    Card *returned = table.ta.trade(c);
                    if (returned != nullptr)
                    {
                        currentPlayer.chains.at(i).operator+=(returned);
                    }
                }
            }

            // iscard trade area
            table.ta.discard();

            // player must play thier top card
            input = 'y';
            while ((input == 'y' || input == 'Y') && !currentPlayer.hand.hand.empty())
            {
                cout << currentPlayer.getName() << endl;
                for (int i = 0; i < currentPlayer.getMaxChains(); i++)
                {
                    cout << currentPlayer.chains.at(i) << endl;
                }

                if (input == 'y' || input == 'Y')
                {

                    for (int i = 0; i < currentPlayer.getMaxChains(); i++)
                    {

                        // if all the chains are empty
                        if (currentPlayer.getNonZeroChains() == 0)
                        {
                            currentPlayer.chains.at(0).operator+=(currentPlayer.hand.play());
                            break;
                        }
                        else if (currentPlayer.chains.at(i).getType() == currentPlayer.hand.top()->getName())
                        {
                            // if so add them
                            currentPlayer.chains.at(i).operator+=(currentPlayer.hand.play());
                            break;
                        }
                        else if (currentPlayer.chains.at(i).getSize() == 0)
                        {
                            currentPlayer.chains.at(i).operator+=(currentPlayer.hand.play());
                            break;
                        }
                    }

                    //! debugging help the chains get added
                    cout << currentPlayer.getName() << endl;
                    for (int i = 0; i < currentPlayer.getMaxChains(); i++)
                    {
                        cout << currentPlayer.chains.at(i) << endl;
                    }
                    cout << "Would you like to play you have to play (y): " << currentPlayer.hand.top()->getName() << endl;

                    cin >> input;
                }
                else
                {
                    break;
                }
            }
            cout << "Selling avalible chains" << endl;
            for (int i = 0; i < currentPlayer.getNonZeroChains(); i++)
            {
                Card *c = currentPlayer.chains.at(i).getCardType();
                if (c->getCoinsPerCard(currentPlayer.chains.at(i).getSize()) != -1)
                {
                    // if hte chain can be sold for coins than sell it
                    currentPlayer.chains.at(i).sell();
                    cout << "NUmber of coins " << currentPlayer.getNumCoins() << "for " << currentPlayer.getName() << endl;
                }
            }
            

            input = 'y';
            while ((input == 'y' || input == 'Y') && !currentPlayer.hand.hand.empty())
            {
                cout << "Would you like to discard any of your cards: (y)" << endl;
                cout << currentPlayer.hand << endl;
                cin >> input;
                if (!(input == 'y' || input == 'Y') && !currentPlayer.hand.hand.empty())
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
                    table.dp.operator+=(currentPlayer.hand[number]);
                    auto itterator = currentPlayer.hand.hand.begin();
                    advance(itterator, number);
                    currentPlayer.hand.hand.erase(itterator);
                }
            }
            cout << currentPlayer.hand << endl;

            for (int i = 0; i < 3; i++)
            {
                table.ta.operator+=(table.deck->draw());
            }

            for (int i = 0; i < 2; i++)
            {
                currentPlayer.hand.operator+=(table.deck->draw());
            }
        }
    } while (!table.deck->deck.empty());
}
