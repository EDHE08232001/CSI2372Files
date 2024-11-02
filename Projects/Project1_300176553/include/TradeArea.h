#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"  // Forward-declaring if not yet implemented

class TradeArea {
private:
    std::list<Card*> cards;  // Holds cards in the trade area

public:
    // Constructor to initialize TradeArea from file
    TradeArea(std::istream& in, const CardFactory* factory);

    // Adds a card to the trade area
    TradeArea& operator+=(Card* card);

    // Checks if adding a card of the same bean type is legal
    bool legal(Card* card) const;

    // Removes a card of the specified bean type from the trade area
    Card* trade(const std::string& beanName);

    // Returns the number of cards in the trade area
    int numCards() const;

    // Destructor
    ~TradeArea();

    // Friend function to print all cards in the trade area
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif // TRADEAREA_H
