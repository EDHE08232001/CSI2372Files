#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Deck.h"

class CardFactory {
private:
    static CardFactory* instance; // Singleton instance
    CardFactory() = default;      // Private constructor

public:
    CardFactory(const CardFactory&) = delete;
    CardFactory& operator=(const CardFactory&) = delete;

    static CardFactory* getFactory();

    Deck getDeck();

    Card* createCard(const std::string& cardName) const;
};

#endif // CARDFACTORY_H
