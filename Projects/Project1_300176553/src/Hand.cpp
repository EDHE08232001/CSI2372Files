#include "../include/Hand.h"

Hand::Hand(std::istream &in)
{
    // Reconstruct hand from input stream
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
        cards.push_back(new Card(type));
    }
}

Hand &Hand::operator+=(Card *card)
{
    cards.push_back(card);
    return *this;
}

Card *Hand::play()
{
    if (cards.empty())
    {
        return nullptr; // Return nullptr if the hand is empty
    }
    Card *topCard = cards.front();
    cards.pop_front();
    return topCard;
}

Card *Hand::top() const
{
    if (cards.empty())
    {
        return nullptr; // Return nullptr if the hand is empty
    }
    return cards.front();
}

Card *Hand::operator[](int index)
{
    if (index < 0 || index >= static_cast<int>(cards.size()))
    {
        return nullptr; // Return nullptr if index is out of bounds
    }
    auto it = cards.begin();
    std::advance(it, index);
    Card *card = *it;
    cards.erase(it);
    return card;
}

std::ostream &operator<<(std::ostream &out, const Hand &hand)
{
    for (const auto &card : hand.cards)
    {
        if (card)
        {
            out << *card << " ";
        }
    }
    return out;
}