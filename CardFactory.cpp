

#include "CardFactory.h"

// have to initialize static stuff here
CardFactory *CardFactory::instance = nullptr;
// static initalization of the array deck to be
std::vector<Card *> CardFactory::deckToBe(CardFactory::deckSize);

// constructor creating all of hte cards
CardFactory::CardFactory()
{

    for (int i = 0; i < deckSize; i++)
    {
        if (i < 20)
        {
            deckToBe[i] = new Blue();
        }
        else if (i < 38)
        {
            deckToBe[i] = new Chili();
        }
        else if (i < 54)
        {
            deckToBe[i] = new Stink();
        }
        else if (i < 68)
        {
            deckToBe[i] = new Green();
        }
        else if (i < 80)
        {
            deckToBe[i] = new Soy();
        }
        else if (i < 90)
        {
            deckToBe[i] = new Black();
        }
        else if (i < 98)
        {
            deckToBe[i] = new Red();
        }
        else
        {
            deckToBe[i] = new Garden();
        }
    }
}
// destructor removing all of hte cards
CardFactory::~CardFactory()
{
    for (Card *card : deckToBe)
    {
        delete card;
    }
}

CardFactory *CardFactory::getCardFactory()
{
    if (instance == nullptr)
    {
        instance = new CardFactory();
    }
    return instance;
}

// creating the deck and suffling it
Deck *CardFactory::getDeck()
{
    Deck *cardDeck = new Deck();
    for (int i = 0; i < deckSize; i++)
    {
        cardDeck->deck.push_back(deckToBe[i]);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cardDeck->deck.begin(), cardDeck->deck.end(), std::default_random_engine(seed));

    return cardDeck;
}
