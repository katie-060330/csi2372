#include "Hand.h"
using namespace std;

Hand &Hand::operator+=(Card *c)
{
    //*adds to the rear of the hand
    hand.push_back(c);
    return *this;
}

Card *Hand::play()
{
    //*returns and removes the card that the player must play, the highest ranking bean
    if (hand.empty())
    {
        return nullptr;
    }
    Card *card = top();

    hand.pop_front();
    return card;
}

Card *Hand::top() const
{
    //*returns but doesnt remove the top of the hand
    if (!hand.empty())
    {
        Card *c = hand.front();
        return c;
    }
    return nullptr;
}

Card *Hand::operator[](int i)
{
    if (i < 0 || i >= hand.size() )
    {
        throw std::invalid_argument("Index out of bounds");
    }
    //*returns the card given at that index i
    auto front = hand.begin();
    std::advance(front, i);
    return *front;
}


std::ostream &operator<<(std::ostream &out, const Hand &h)
{
    if (h.hand.empty())
    {
        out << "Empty" << endl;
    }
    else
    {
        for (auto current = h.hand.begin(); current != h.hand.end(); current++)
        {
            out << (*current)->getName() << " ";
        }
    }

    return out;
}
