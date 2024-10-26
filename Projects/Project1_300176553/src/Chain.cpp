#ifndef CHAIN_CPP
#define CHAIN_CPP

#include "../include/Chain.h"

template <typename T>
Chain<T>::Chain(std::istream &in)
{
    // Reconstruct chain from input stream
    while (!in.eof())
    {
        char typeChar;
        in >> typeChar;
        BeanType type;
        switch (typeChar)
        {
        case 'B':
            type = BeanType::Blue;
            break;
        case 'C':
            type = BeanType::Chili;
            break;
        case 'S':
            type = BeanType::Stink;
            break;
        case 'G':
            type = BeanType::Green;
            break;
        case 'Y':
            type = BeanType::Soy;
            break;
        case 'b':
            type = BeanType::Black;
            break;
        case 'R':
            type = BeanType::Red;
            break;
        case 'g':
            type = BeanType::Garden;
            break;
        default:
            continue; // Skip invalid characters
        }
        if (type == T().getBeanType())
        {
            cards.push_back(new Card(type));
        }
        else
        {
            throw IllegalType();
        }
    }
}

template <typename T>
Chain<T> &Chain<T>::operator+=(Card *card)
{
    if (card->getBeanType() == T().getBeanType())
    {
        cards.push_back(card);
    }
    else
    {
        throw IllegalType();
    }
    return *this;
}

template <typename T>
int Chain<T>::sell() const
{
    if (cards.empty())
    {
        return 0;
    }
    int numCards = cards.size();
    return cards.front()->getCardsPerCoin(numCards);
}

#endif // CHAIN_CPP