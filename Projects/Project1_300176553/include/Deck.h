#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h" // Forward-declaring this if not yet implemented

class Deck : public std::vector<Card *>
{
public:
    // Default constructor
    Deck() = default;

    // Constructor to initialize Deck from file
    Deck(std::istream &in, const CardFactory *factory);

    // Draws the top card from the deck, removing it from the deck
    Card *draw();

    // Destructor
    ~Deck();

    // Friend function for the insertion operator
    friend std::ostream &operator<<(std::ostream &out, const Deck &deck);
};

#endif // DECK_H
