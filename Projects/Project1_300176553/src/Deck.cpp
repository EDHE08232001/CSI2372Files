#include "../include/Deck.h"

Deck::Deck(std::istream &in)
{
    // Reconstruct deck from input stream
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
        push_back(new Card(type));
    }
}

Card *Deck::draw()
{
    if (empty())
    {
        return nullptr; // Return nullptr if the deck is empty
    }
    Card *topCard = back();
    pop_back();
    return topCard;
}

std::ostream &operator<<(std::ostream &out, const Deck &deck)
{
    for (const auto &card : deck)
    {
        if (card)
        {
            out << *card << " ";
        }
    }
    return out;
}