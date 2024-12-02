#include <iostream>
#include <string>
#include <cctype>
#include "Table.h"
#include <stdlib.h>
using namespace std;
void checkWhoWon(Table t);
bool match(Player p);
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
    cout << "---------------------START GAME---------------------" << endl;

    // inintlaizing the hands of the two players
    for (int i = 0; i < 5; i++)
    {
        table.p1.hand.operator+=(table.deck->draw());
        table.p2.hand.operator+=(table.deck->draw());
    }

    do
    {
        cout << "--------------------- Player " << table.p1.getName() << " turn ---------------------" << endl;
        cout << table.p1.getName() << "'s Chains.. \n"
             << endl;
        for (int i = 0; i < table.p1.getMaxChains(); i++)
        {

            cout << table.p1.chains.at(i) << endl;
        }


        cout << "\n"<< table.p1.getName() <<"s \n" << " Coins: " << table.p1.getNumCoins() <<"\n"<< "Hand... "<< table.p1.hand << endl;

        // display table
        cout << "---------------------Table ---------------------" << endl;
        cout << table << endl;
        // player draws a card
        if (table.deck->deck.empty())
        {
            checkWhoWon(table);
            exit(-1);
        }
        table.p1.hand.operator+=(table.deck->draw());
        // if ta is not empty add a bean card to chains or discard them
        if (!table.ta.tradeArea.empty())
        {
            for (int i = 0; i < table.p1.getMaxChains(); i++)
            {
                string c = table.p1.chains.at(i).getType();

                Card *returned = table.ta.trade(c);
                if (returned != nullptr)
                {
                    table.p1.chains.at(i).operator+=(returned);
                }
            }
        }
        // discard trade area
        table.ta.discard();

        input = 'y';
        // for when the player has to play but all of their chains are full
        bool autoplay = true;
        while ((input == 'y' || input == 'Y') && !table.p1.hand.hand.empty())
        {
            // displays the chains before the player has to play
            cout << table.p1.getName() << " Chains before " << table.p1.getName() << " plays " << endl;
            for (int i = 0; i < table.p1.getMaxChains(); i++)
            {
                cout << table.p1.chains.at(i) << endl;
            }
            // replace chain 1 to empty and start fresh chain
            if (autoplay && table.p1.getMaxChains() == table.p1.getNonZeroChains() && !match(table.p1))
            {
                table.p1.operator+=(table.p1.chains.at(0).startFreshChain(table.p1.hand.play()));

                autoplay = false;
            }

            // if player wants to play their cards
            if (input == 'y' || input == 'Y')
            {

                for (int i = 0; i < table.p1.getMaxChains(); i++)
                {

                    // if all the chains are empty
                    if (table.p1.getNonZeroChains() == 0)
                    {
                        table.p1.chains.at(0).operator+=(table.p1.hand.play());
                        autoplay = false;
                        break;
                    }
                    // when the cards match add them
                    else if (table.p1.chains.at(i).getType() == table.p1.hand.top()->getName())
                    {
                        // if so add them
                        table.p1.chains.at(i).operator+=(table.p1.hand.play());
                        autoplay = false;
                        break;
                    }
                    // if the chainis empty we can add any card to the chain if it is empty
                    else if (table.p1.chains.at(i).getSize() == 0)
                    {
                        table.p1.chains.at(i).operator+=(table.p1.hand.play());
                        autoplay = false;
                        break;
                    }
                }

                cout << table.p1.getName() << " Chains after " << table.p1.getName() << " plays " << endl;
                for (int i = 0; i < table.p1.getMaxChains(); i++)
                {
                    cout << table.p1.chains.at(i) << endl;
                }
                if (!table.p1.hand.hand.empty() || !table.p1.getNonZeroChains() == table.p1.getMaxChains())
                {
                    cout << "Would you like to play you have to play (y): " << table.p1.hand.top()->getName() << endl;

                    cin >> input;
                }
                else
                {
                    input = 'n';
                }
            }

            else
            {
                break;
            }
        }

        // if chains are ended the sell them

        cout << "---------------------SELLING AVALIBLE CHAINS ---------------------" << endl;
        for (int i = 0; i < table.p1.getMaxChains(); i++)
        {
            Card *c = table.p1.chains.at(i).getCardType();
            // if c is null ptr then dont try and sell that chain
            if (c)
            {
                if (c->getCoinsPerCard(table.p1.chains.at(i).getSize()) != 0)
                {
                    // if hte chain can be sold for coins than sell it and add the coins to the current players
                    cout << "selling chian " << table.p1.chains.at(i) << endl;
                    table.p1.operator+=(table.p1.chains.at(i).sell());
                }
            }
        }
        cout << "Number of coins " << table.p1.getNumCoins() << " for " << table.p1.getName() << endl;

        // if hte player decides to show thier hand, and discard an arbitrary value in
        input = 'y';
        while ((input == 'y' || input == 'Y') && !table.p1.hand.hand.empty())
        {
            cout << "Would you like to discard any of your cards: (y)" << endl;
            cout << table.p1.hand << endl;
            cin >> input;
            if (!(input == 'y' || input == 'Y') && !table.p1.hand.hand.empty())
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
                table.dp.operator+=(table.p1.hand[number]);
                auto itterator = table.p1.hand.hand.begin();
                advance(itterator, number);
                table.p1.hand.hand.erase(itterator);
            }
        }

        cout << "---------------------drawing 3 cards to the trade area---------------------" << endl;

        for (int i = 0; i < 3; i++)
        {
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                exit(-1);
            }
            table.ta.operator+=(table.deck->draw());
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                exit(-1);
            }
        }

        //*while teh top card of the discard matches any in the discad pile

        while (true)
        {

            Card *topCard = table.dp.top();

            if (topCard == nullptr || !table.ta.legal(topCard))
            {
                break;
            }

            Card *pickedCard = table.dp.pickUp();
            table.ta.operator+=(pickedCard);
        }

        // adds the cards to the back of the players chains if they match
        if (!table.ta.tradeArea.empty())
        {
            for (Card *c : table.ta.tradeArea)
            {
                if (c)
                {
                }
                for (int i = 0; i < table.p1.chains.size(); i++)
                {
                    if (c->getName() == table.p1.chains.at(i).getType())
                    {
                        table.p1.chains.at(i).operator+=(c);
                    }
                }
            }
        }

        cout << "---------------------End player turn   ---------------------" << endl;
        for (int i = 0; i < 2; i++)
        {
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                exit(-1);
            }

            table.p1.hand.operator+=(table.deck->draw());
        }
        cout << table.p1.getName() << "'s Chains.. \n"
             << endl;
        for (int i = 0; i < table.p1.getMaxChains(); i++)
        {
            cout << table.p1.chains.at(i) << endl;
        }

        cout << "\n"
             << table.p1.getName() << "'s Hand ..\n"
             << table.p1.hand << endl;

        //! PLAYER 2 TURN
        if (table.deck->deck.empty())
        {
            checkWhoWon(table);
            break;
        }
        cout << "----------------------------- other players turn -----------------------------------" << endl;
        cout << "--------------------- Player " << table.p2.getName() << " turn ---------------------" << endl;

        cout << table.p2.getName() << "'s Chains.. \n"<< endl;
        for (int i = 0; i < table.p2.getMaxChains(); i++)
        {
            cout << table.p2.chains.at(i) << endl;
        }

        cout << "\n"
             << table.p2.getName() <<"s \n" << " Coins: " << table.p2.getNumCoins() <<"\n"<< "Hand... "<< table.p2.hand << endl;

        // display table
        cout << "---------------------Table ---------------------" << endl;
        cout << table << endl;
        // player draws a card
        if (table.deck->deck.empty())
        {
            checkWhoWon(table);
            break;
        }
        table.p2.hand.operator+=(table.deck->draw());
        // if ta is not empty add a bean card to chains or discard them
        if (!table.ta.tradeArea.empty())
        {
            for (int i = 0; i < table.p2.getMaxChains(); i++)
            {
                string c = table.p2.chains.at(i).getType();

                Card *returned = table.ta.trade(c);
                if (returned != nullptr)
                {
                    table.p2.chains.at(i).operator+=(returned);
                }
            }
        }
        // discard trade area
        table.ta.discard();

        input = 'y';
        // for when the player has to play but all of their chains are full
        autoplay = true;
        while ((input == 'y' || input == 'Y') && !table.p2.hand.hand.empty())
        {
            // displays the chains before the player has to play
            cout << table.p2.getName() << " Chains before " << table.p2.getName() << " plays " << endl;
            for (int i = 0; i < table.p2.getMaxChains(); i++)
            {
                cout << table.p2.chains.at(i) << endl;
            }
            // replace chain 1 to empty and start fresh chain
            if (autoplay && table.p2.getMaxChains() == table.p2.getNonZeroChains() && !match(table.p2))
            {
                table.p2.operator+=(table.p2.chains.at(0).startFreshChain(table.p2.hand.play()));

                autoplay = false;
            }

            // if player wants to play their cards
            if (input == 'y' || input == 'Y')
            {

                for (int i = 0; i < table.p2.getMaxChains(); i++)
                {

                    // if all the chains are empty
                    if (table.p2.getNonZeroChains() == 0)
                    {
                        table.p2.chains.at(0).operator+=(table.p2.hand.play());
                        autoplay = false;
                        break;
                    }
                    // when the cards match add them
                    else if (table.p2.chains.at(i).getType() == table.p2.hand.top()->getName())
                    {
                        // if so add them
                        table.p2.chains.at(i).operator+=(table.p2.hand.play());
                        autoplay = false;
                        break;
                    }
                    // if the chainis empty we can add any card to the chain if it is empty
                    else if (table.p2.chains.at(i).getSize() == 0)
                    {
                        table.p2.chains.at(i).operator+=(table.p2.hand.play());
                        autoplay = false;
                        break;
                    }
                }

                cout << table.p2.getName() << " Chains after " << table.p2.getName() << " plays " << endl;
                for (int i = 0; i < table.p2.getMaxChains(); i++)
                {
                    cout << table.p2.chains.at(i) << endl;
                }
                if (!table.p2.hand.hand.empty() || !table.p2.getNonZeroChains() == table.p2.getMaxChains())
                {
                    cout << "Would you like to play you have to play (y): " << table.p2.hand.top()->getName() << endl;

                    cin >> input;
                }
                else
                {
                    input = 'n';
                }
            }

            else
            {
                break;
            }
        }

        // if chains are ended the sell them

        cout << "---------------------SELLING AVALIBLE CHAINS ---------------------" << endl;
        for (int i = 0; i < table.p2.getMaxChains(); i++)
        {
            Card *c = table.p2.chains.at(i).getCardType();
            // if c is null ptr then dont try and sell that chain
            if (c)
            {
                if (c->getCoinsPerCard(table.p2.chains.at(i).getSize()) != 0)
                {
                    // if hte chain can be sold for coins than sell it and add the coins to the current players
                    cout << "selling chian " << table.p2.chains.at(i) << endl;
                    table.p2.operator+=(table.p2.chains.at(i).sell());
                }
            }
        }
        cout << "Number of coins " << table.p2.getNumCoins() << " for " << table.p2.getName() << endl;

        // if hte player decides to show thier hand, and discard an arbitrary value in
        input = 'y';
        while ((input == 'y' || input == 'Y') && !table.p2.hand.hand.empty())
        {
            cout << "Would you like to discard any of your cards: (y)" << endl;
            cout << table.p2.hand << endl;
            cin >> input;
            if (!(input == 'y' || input == 'Y') && !table.p2.hand.hand.empty())
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
                table.dp.operator+=(table.p2.hand[number]);
                auto itterator = table.p2.hand.hand.begin();
                advance(itterator, number);
                table.p2.hand.hand.erase(itterator);
            }
        }

        cout << "---------------------drawing 3 cards to the trade area---------------------" << endl;

        for (int i = 0; i < 3; i++)
        {
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                exit(-1);
            }
            table.ta.operator+=(table.deck->draw());
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                exit(-1);
            }
        }
        // while the top most card matches the chain chain it up

        // while the top card of the dp matches any o fhte chain chain them up

        //*while teh top card of the discard matches any in the discad pile
        while (true)
        {

            Card *topCard = table.dp.top();

            if (topCard == nullptr || !table.ta.legal(topCard))
            {
                break;
            }

            Card *pickedCard = table.dp.pickUp();
            table.ta.operator+=(pickedCard);
        }

        // adds the cards to the back of the players chains if they match
        if (!table.ta.tradeArea.empty())
        {
            for (Card *c : table.ta.tradeArea)
            {
                for (int i = 0; i < table.p2.chains.size(); i++)
                {
                    if (c->getName() == table.p2.chains.at(i).getType())
                    {
                        table.p2.chains.at(i).operator+=(c);
                    }
                }
            }
        }

        cout << "---------------------End player turn   ---------------------" << endl;
        for (int i = 0; i < 2; i++)
        {
            if (table.deck->deck.empty())
            {
                checkWhoWon(table);
                break;
            }

            table.p2.hand.operator+=(table.deck->draw());
        }
        cout << table.p2.getName() << "'s Chains.. \n"
             << endl;
        for (int i = 0; i < table.p2.getMaxChains(); i++)
        {
            cout << table.p2.chains.at(i) << endl;
        }

        cout << "\n"
             << table.p2.getName() << "'s Hand ..\n"
             << table.p2.hand << endl;

        if (table.deck->deck.empty())
        {
            checkWhoWon(table);
            break;
        }
    } while (!table.deck->deck.empty());
}

void checkWhoWon(Table t)
{
    cout << "--------------------------------END OF GAME-------------------------------- \nDeck out of cards" << endl;
    string p1 = t.p1.getName();
    if (t.win(p1))
    {
        cout << p1 << " WINS!!!!" << endl;
    }
    else
    {
        cout << t.p2.getName() << " WINS!!!!" << endl;
    }
}

bool match(Player p)
{
    Card *top = p.hand.top();
    bool toReturn = false;
    for (int i = 0; i < p.getMaxChains(); i++)
    {
        if (top->getName() == p.chains.at(i).getType())
        {
            toReturn = true;
        }
    }
    return toReturn;
}

