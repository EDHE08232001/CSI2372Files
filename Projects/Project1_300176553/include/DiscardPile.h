#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h" // Forward-declaring this if not yet implemented

class DiscardPile {
private:
    std::vector<Card*> cards;  // Holds the discarded cards

public:
    // Constructor to initialize DiscardPile from file
    DiscardPile(std::istream& in, const CardFactory* factory);

    // Adds a card to the DiscardPile
    DiscardPile& operator+=(Card* card);

    // Removes and returns the top card from the discard pile
    Card* pickUp();

    // Returns (without removing) the top card from the discard pile
    Card* top() const;

    // Prints all cards in the discard pile
    void print(std::ostream& out) const;

    // Destructor
    ~DiscardPile()

    // Friend function for the insertion operator to print only the top card
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile);
};

#endif // DISCARDPILE_H
