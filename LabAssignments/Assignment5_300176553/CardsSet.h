#ifndef CARDSSET_H
#define CARDSSET_H

#include "Card.h"    // CardsSet depends on Card
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <cassert>   // for assert()
#include <algorithm> // for std::swap

class CardsSet
{
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no); // no = 1 for the top of the set
    void empty() { number = 0; }

private:
    Card set[52];
    int number;
};

/* Create a new set that corresponds to the 52 cards */
void CardsSet::novSet()
{
    number = 0;
    // Loop through each color/suit
    for (int col = club; col <= spade; col++)
    {
        // Loop through each value from 1 to 13
        for (int val = 1; val <= 13; val++)
        {
            set[number++] = Card(static_cast<color>(col), val);
        }
    }
}

/* Shuffle the cards */
void CardsSet::shuffle()
{
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    for (int i = 0; i < number; i++)
    {
        int randIndex = rand() % number;
        std::swap(set[i], set[randIndex]); // Swap the current card with a random card
    }
}

/* Take a card from the top of the set */
Card CardsSet::take()
{
    assert(number > 0);   // Ensure there is at least one card to take
    return set[--number]; // Decrease the count and return the top card
}

/* Put a card onto the set */
void CardsSet::put(Card k)
{
    assert(number < 52); // Ensure there is room to add a new card
    set[number++] = k;   // Add the card and increase the count
}

/* Look at the card in position no (no = 1 for the top of the set) */
Card CardsSet::lookIn(int no)
{
    assert(no >= 1 && no <= number); // Ensure the index is within bounds
    return set[number - no];         // Return the card at the specified position
}

#endif // CARDSSET_H
