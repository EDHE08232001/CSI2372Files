#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "Card.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

class Deck;

class CardFactory
{
public:
    // Returns the singleton instance of CardFactory
    static CardFactory *getFactory();

    // Returns a deck with all cards shuffled
    Deck getDeck();

private:
    // Constructor is private to enforce singleton pattern
    CardFactory();

    // Prevent copying
    CardFactory(const CardFactory &) = delete;
    CardFactory &operator=(const CardFactory &) = delete;

    // Holds all cards that can be added to a deck
    std::vector<Card *> allCards;
};

#endif // CARD_FACTORY_H