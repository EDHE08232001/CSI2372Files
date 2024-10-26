#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "Card.h"
#include <list>
#include <iostream>

class TradeArea
{
public:
    // Constructor that initializes an empty trade area
    TradeArea() = default;

    // Constructor to reconstruct the trade area from a file
    TradeArea(std::istream &in);

    // Adds a card to the trade area
    TradeArea &operator+=(Card *card);

    // Checks if the card can be legally added to the TradeArea
    bool legal(Card *card) const;

    // Removes a card of the corresponding bean type from the trade area
    Card *trade(const std::string &beanName);

    // Returns the number of cards currently in the trade area
    int numCards() const;

    // Overload the stream insertion operator to print the trade area
    friend std::ostream &operator<<(std::ostream &out, const TradeArea &tradeArea);

private:
    std::list<Card *> cards;
};

#endif // TRADEAREA_H