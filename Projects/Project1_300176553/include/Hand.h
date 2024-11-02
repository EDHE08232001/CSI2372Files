#ifndef HAND_H
#define HAND_H

#include <deque>
#include <iostream>
#include "Card.h"
#include "CardFactory.h" // Forward-declaring if not yet implemented

class Hand {
private:
    std::deque<Card*> cards;  // Holds the cards in the hand

public:
    // Constructor to initialize Hand from file
    Hand(std::istream& in, const CardFactory* factory);

    // Adds a card to the rear of the hand
    Hand& operator+=(Card* card);

    // Returns and removes the top card from the hand
    Card* play();

    // Returns but does not remove the top card from the hand
    Card* top() const;

    // Returns and removes the card at the given index
    Card* operator[](int index);

    // Destructor
    ~Hand();

    // Friend function to print all cards in the hand
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
};

#endif // HAND_H
