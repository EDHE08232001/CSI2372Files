#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <list>
#include <iostream>

class Hand
{
public:
    // Constructor that initializes an empty hand
    Hand() = default;

    // Constructor to reconstruct the hand from a file
    Hand(std::istream &in);

    // Adds a card to the rear of the hand
    Hand &operator+=(Card *card);

    // Returns and removes the top card from the player's hand
    Card *play();

    // Returns but does not remove the top card from the player's hand
    Card *top() const;

    // Returns and removes the card at a given index
    Card *operator[](int index);

    // Overload the stream insertion operator to print the hand
    friend std::ostream &operator<<(std::ostream &out, const Hand &hand);

private:
    std::list<Card *> cards;
};

#endif // HAND_H