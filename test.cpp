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

    do
    {
        // for each player

        // display table
        cout << table << endl;
        // player draws a card
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
        while ((input == 'y' || input == 'Y') && !table.p1.hand.hand.empty())
        {
            cout << table.p1.getName() << " Chains before they HAVE to play " << endl;
            for (int i = 0; i < table.p1.getMaxChains(); i++)
            {
                cout << table.p1.chains.at(i) << endl;
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
                        break;
                    }
                    else if (table.p1.chains.at(i).getType() == table.p1.hand.top()->getName())
                    {
                        // if so add them
                        table.p1.chains.at(i).operator+=(table.p1.hand.play());
                        break;
                    }
                    else if (table.p1.chains.at(i).getSize() == 0)
                    {
                        table.p1.chains.at(i).operator+=(table.p1.hand.play());
                        break;
                    }
                }

                //! debugging help the chains get added
                cout << table.p1.getName() << " Chaing after they played " << endl;
                for (int i = 0; i < table.p1.getMaxChains(); i++)
                {
                    cout << table.p1.chains.at(i) << endl;
                }
                cout << "Would you like to play you have to play (y): " << table.p1.hand.top()->getName() << endl;

                cin >> input;
            }
            else
            {
                break;
            }
        }

        // if chains are ended the sell them
        cout << "Selling avalible chains" << endl;
        for (int i = 0; i < table.p1.getMaxChains(); i++)
        {
            Card *c = table.p1.chains.at(i).getCardType();
            //if c is null ptr then dont try and sell that chain 
            if (c)
            {
                if (c->getCoinsPerCard(table.p1.chains.at(i).getSize()) != 0)
                {
                    // if hte chain can be sold for coins than sell it
                    cout << "selling chian " << table.p1.chains.at(i) << endl;
                    table.p1.chains.at(i).sell();
                }
            }

            else
            {
                continue;
            }
        }
        cout << "NUmber of coins " << table.p1.getNumCoins() << "for " << table.p1.getName() << endl;

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
        cout << table.p1.hand << endl;

        for (int i = 0; i < 3; i++)
        {
            table.ta.operator+=(table.deck->draw());
        }
        // while the top most card matches the chain chain it up
        //  vector<Card*> cardsInChain;
        //  for( int i = 0; i < table.p1.chains.size(); i++){
        //      cardsInChain.push_back(table.p1.chains.at(i).getCardType());
        //  }
        //  //while the top card of the dp matches any o fhte chain chain them up
        //  for( int i = 0; i < table.p1.chains.size(); i++){
        //      while(table.dp.top()->getName() == cardsInChain.at(i)->getName()){
        //          table.p1.chains.at(i).operator+=(table.dp.pickUp());
        //      }
        //  }

        // //add cards from the ta to the chians
        // for (Card* c : table.ta.tradeArea){
        //     for(int i = 0; i <cardsInChain.size();i++  ){
        //         if(c->getName() == table.p1.chains.at(i).getType()){
        //             table.p1.chains.at(i).operator+=(c);

        //         }
        //     }

        // }

        for (int i = 0; i < 2; i++)
        {
            table.p1.hand.operator+=(table.deck->draw());
        }
        //! PLAYER 2 TURN
        cout << "----------------------------- other players turn -----------------------------------" << endl;
        cout << table << endl;
        // player draws a card
        table.p1.hand.operator+=(table.deck->draw());
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
        while ((input == 'y' || input == 'Y') && !table.p2.hand.hand.empty())
        {
            cout << table.p2.getName() << endl;
            for (int i = 0; i < table.p2.getMaxChains(); i++)
            {
                cout << table.p2.chains.at(i) << endl;
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
                        break;
                    }
                    else if (table.p2.chains.at(i).getType() == table.p2.hand.top()->getName())
                    {
                        // if so add them
                        table.p2.chains.at(i).operator+=(table.p2.hand.play());
                        break;
                    }
                    else if (table.p2.chains.at(i).getSize() == 0)
                    {
                        table.p2.chains.at(i).operator+=(table.p2.hand.play());
                        break;
                    }
                }

                //! debugging help the chains get added
                cout << table.p2.getName() << endl;
                for (int i = 0; i < table.p2.getMaxChains(); i++)
                {
                    cout << table.p2.chains.at(i) << endl;
                }
                cout << "Would you like to play you have to play (y): " << table.p2.hand.top()->getName() << endl;

                cin >> input;
            }
            else
            {
                break;
            }
        }

        // if chains are ended the sell them
        // cout<<"Selling avalible chains"<<endl;
        // for (int i = 0; i < table.p2.getNonZeroChaons(); i++)
        // {
        //     Card *c = table.p2.chains.at(i).getCardType();
        //     if (c->getCoinsPerCard(table.p2.chains.at(i).getSize()) != -1)
        //     {
        //         // if hte chain can be sold for coins than sell it
        //         table.p2.chains.at(i).sell();
        //     }
        // }
        // cout<<"NUmber of coins "<<table.p2.getNumCoins()<<"for "<<table.p2.getName()<<endl;

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
        cout << table.p2.hand << endl;

        for (int i = 0; i < 3; i++)
        {
            table.ta.operator+=(table.deck->draw());
        }
        // while the top most card matches the chain chain it up
        //  vector<Card*> cardsInChain;
        //  for( int i = 0; i < table.p2.chains.size(); i++){
        //      cardsInChain.push_back(table.p2.chains.at(i).getCardType());
        //  }
        //  //while the top card of the dp matches any o fhte chain chain them up
        //  for( int i = 0; i < table.p2.chains.size(); i++){
        //      while(table.dp.top()->getName() == cardsInChain.at(i)->getName()){
        //          table.p2.chains.at(i).operator+=(table.dp.pickUp());
        //      }
        //  }

        // //add cards from the ta to the chians
        // for (Card* c : table.ta.tradeArea){
        //     for(int i = 0; i <cardsInChain.size();i++  ){
        //         if(c->getName() == table.p2.chains.at(i).getType()){
        //             table.p2.chains.at(i).operator+=(c);

        //         }
        //     }

        // }

        for (int i = 0; i < 2; i++)
        {
            table.p2.hand.operator+=(table.deck->draw());
        }

    } while (!table.deck->deck.empty());
}
