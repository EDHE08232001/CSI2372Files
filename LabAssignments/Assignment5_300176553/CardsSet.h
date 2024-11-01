#ifndef CARDSSET_H
#define CARDSSET_H

#include "Card.h"  // CardsSet depends on Card, so it's included here
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cassert> // For assert()

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
    Card set[52]; // Array to hold the cards
    int number;   // Number of cards currently in the set
};

/* novSet() method */
void CardsSet::novSet()
{
    number = 0;                         // Reset the number of cards
    for (int c = club; c <= spade; c++) // Loop through all colors
    {
        color col = static_cast<color>(c);  // Cast int to color enum
        for (int val = 1; val <= 13; val++) // Loop through card values
        {
            set[number++] = Card(col, val); // Create a new card and add it to the set
        }
    }
}

/* shuffle() method */
void CardsSet::shuffle()
{
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    for (int i = 0; i < number; i++)
    {
        int randIndex = rand() % number;   // Generate a random index
        std::swap(set[i], set[randIndex]); // Swap the current card with the card at the random index
    }
}

/* take() method */
Card CardsSet::take()
{
    assert(number > 0);   // Ensure there is at least one card to take
    return set[--number]; // Decrease the count and return the top card
}

/* put() method */
void CardsSet::put(Card k)
{
    assert(number < 52); // Ensure there is room to add a new card
    set[number++] = k;   // Add the card and increase the count
}

/* lookIn() method */
Card CardsSet::lookIn(int no)
{
    assert(no >= 1 && no <= number); // Ensure the index is within bounds
    return set[number - no];         // Return the card at the specified position
}

#endif // CARDSSET_H
