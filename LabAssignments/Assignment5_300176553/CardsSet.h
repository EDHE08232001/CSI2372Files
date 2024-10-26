#ifndef CARDSSET_H
#define CARDSSET_H

#include "Card.h"  // CardsSet depends on Card, so it's better to include it
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

class CardsSet
{
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }

private:
    Card set[52];
    int number;
};

void CardsSet::novSet()
{
    number = 0;
    for (int col = club; col <= spade; col++)
    {
        for (int val = 1; val <= 13; val++)
        {
            set[number++] = Card(static_cast<color>(col), val);
        }
    }
}

void CardsSet::shuffle()
{
    srand(static_cast<unsigned>(time(0))); // seed the random number generator
    for (int i = 0; i < number; i++)
    {
        int randIndex = rand() % number;
        std::swap(set[i], set[randIndex]); // Swap the current card with the card at the random index
    }
}

Card CardsSet::take()
{
    assert(number > 0);   // Ensure there is at least one card to take
    return set[--number]; // Decrease the count and return the top card
}

void CardsSet::put(Card k)
{
    assert(number < 52); // Ensure there is room to add a new card
    set[number++] = k;   // Add the card and increase the count
}

Card CardsSet::lookIn(int no)
{
    assert(no >= 0 && no < number); // Ensure the index is within bounds
    return set[no];                 // Return the card at the specified position
}

#endif // CARDSSET_H