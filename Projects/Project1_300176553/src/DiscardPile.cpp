#include "../include/DiscardPile.h"

DiscardPile::DiscardPile(std::istream &in)
{
    // Reconstruct discard pile from input stream
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
        // Create cards based on BeanType
        switch (type)
        {
        case BeanType::Blue:
            cards.push_back(new Card(BeanType::Blue));
            break;
        case BeanType::Chili:
            cards.push_back(new Card(BeanType::Chili));
            break;
        case BeanType::Stink:
            cards.push_back(new Card(BeanType::Stink));
            break;
        case BeanType::Green:
            cards.push_back(new Card(BeanType::Green));
            break;
        case BeanType::Soy:
            cards.push_back(new Card(BeanType::Soy));
            break;
        case BeanType::Black:
            cards.push_back(new Card(BeanType::Black));
            break;
        case BeanType::Red:
            cards.push_back(new Card(BeanType::Red));
            break;
        case BeanType::Garden:
            cards.push_back(new Card(BeanType::Garden));
            break;
        }
    }
}

DiscardPile &DiscardPile::operator+=(Card *card)
{
    cards.push_back(card);
    return *this;
}

Card *DiscardPile::pickUp()
{
    if (cards.empty())
    {
        return nullptr; // Return nullptr if the discard pile is empty
    }
    Card *topCard = cards.back();
    cards.pop_back();
    return topCard;
}

Card *DiscardPile::top() const
{
    if (cards.empty())
    {
        return nullptr; // Return nullptr if the discard pile is empty
    }
    return cards.back();
}

void DiscardPile::print(std::ostream &out) const
{
    for (const auto &card : cards)
    {
        if (card)
        {
            out << *card << " ";
        }
    }
}

std::ostream &operator<<(std::ostream &out, const DiscardPile &pile)
{
    if (!pile.cards.empty() && pile.cards.back())
    {
        out << *(pile.cards.back());
    }
    return out;
}