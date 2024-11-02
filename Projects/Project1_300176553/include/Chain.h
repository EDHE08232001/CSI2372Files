#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include "Card.h"

// Abstract base class for Chains
class Chain_Base {
public:
    virtual ~Chain_Base() = default;
    virtual int sell() const = 0; // Returns the number of coins based on chain length
    virtual void print(std::ostream& out) const = 0; // Pure virtual print function for chaining
};

// Template Chain class
template <typename T>
class Chain : public Chain_Base {
private:
    std::vector<T*> cards; // a vector to hold pointers to cards of type T

public:
    // Constructor to initialize Chain from file
    Chain(std::istream& in, const CardFactory* factory);

    // Default constructor
    Chain() = default;

    // Adds a card to the Chain, checks if it's of the correct type
    Chain<T>& operator+=(Card* card);

    // Calculates the value of the chain and returns the #coins
    int sell() const override;

    // Prints the Chain's content
    void print(std::ostream& out) const override;

    // Destructor
    ~Chain();

    // Friend function to allow `<<` operator for printing
    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& chain) {
        chain.print(out);
        return out;
    }
};

// Implementation of template functions...

// Implement operator+=
template <typename T>
Chain<T>& Chain<T>::operator+=(Card* card) {
    // Check if card is of the correct type using dynamic_cast
    if (T* specificCard = dynamic_cast<T*>(card)) {
        cards.push_back(specificCard);
    } else {
        throw std::runtime_error("IllegalType: Cannot add different card type to chain.");
    }
    return *this;
}

// Implement sell()
template <typename T>
int Chain<T>::sell() const {
    if (cards.empty()) return 0;
    int numCards = cards.size();
    int coins = 0;

    // Check from highest coin value to lowest
    for (int coinValue = 4; coinValue >= 1; --coinValue) {
        int cardsNeeded = cards.front()->getCardsPerCoin(coinValue);
        if (cardsNeeded > 0 && numCards >= cardsNeeded) {
            coins = coinValue;
            break;
        }
    }
    return coins;
}

// Implement print()
template <typename T>
void Chain<T>::print(std::ostream& out) const {
    if (!cards.empty()) {
        out << cards.front()->getName() << " ";
        for (const auto& card : cards) {
            card->print(out);
            out << " ";
        }
    }
}

// Destructor
template <typename T>
Chain<T>::~Chain() {
    for (T* card : cards) {
        delete card;
    }
    cards.clear();
}


#endif // CHAIN_H
