#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <iostream>

class Deck : public std::vector<Card *>
{
public:
    // Constructor that initializes an empty deck
    Deck() = default;

    // Constructor to reconstruct the deck from a file
    Deck(std::istream &in);

    // Draws the top card from the deck and returns it
    Card *draw();

    // Overload the stream insertion operator to output all cards in the deck
    friend std::ostream &operator<<(std::ostream &out, const Deck &deck);
};

#endif // DECK_H