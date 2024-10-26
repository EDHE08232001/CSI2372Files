#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "Card.h"
#include <vector>
#include <iostream>

class DiscardPile {
public:
    // Constructor that initializes an empty discard pile
    DiscardPile() = default;

    // Constructor to reconstruct the discard pile from a file
    DiscardPile(std::istream& in);

    // Adds a card to the discard pile
    DiscardPile& operator+=(Card* card);

    // Returns and removes the top card from the discard pile
    Card* pickUp();

    // Returns but does not remove the top card from the discard pile
    Card* top() const;

    // Prints all cards in the discard pile to an output stream
    void print(std::ostream& out) const;

    // Overload the stream insertion operator to print the top card
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& pile);

private:
    std::vector<Card*> cards;
};

#endif // DISCARDPILE_H