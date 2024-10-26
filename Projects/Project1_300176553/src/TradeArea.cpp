#include "../include/TradeArea.h"

TradeArea::TradeArea(std::istream &in)
{
    // Reconstruct trade area from input stream
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

TradeArea &TradeArea::operator+=(Card *card)
{
    cards.push_back(card);
    return *this;
}

bool TradeArea::legal(Card *card) const
{
    for (const auto &c : cards)
    {
        if (c->getBeanType() == card->getBeanType())
        {
            return true;
        }
    }
    return false;
}

Card *TradeArea::trade(const std::string &beanName)
{
    for (auto it = cards.begin(); it != cards.end(); ++it)
    {
        if ((*it)->getName() == beanName)
        {
            Card *card = *it;
            cards.erase(it);
            return card;
        }
    }
    return nullptr; // Return nullptr if no card of the specified type is found
}

int TradeArea::numCards() const
{
    return cards.size();
}

std::ostream &operator<<(std::ostream &out, const TradeArea &tradeArea)
{
    for (const auto &card : tradeArea.cards)
    {
        if (card)
        {
            out << *card << " ";
        }
    }
    return out;
}