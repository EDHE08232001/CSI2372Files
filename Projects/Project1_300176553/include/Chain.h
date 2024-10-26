#ifndef CHAIN_H
#define CHAIN_H

#include "Card.h"
#include <vector>
#include <iostream>
#include <stdexcept>

// Exception class for illegal card type insertion
class IllegalType : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Attempted to add an illegal card type to the chain.";
    }
};

// Template class Chain
template <typename T>
class Chain
{
public:
    // Constructor that initializes an empty chain
    Chain() = default;

    // Constructor to reconstruct the chain from a file
    Chain(std::istream &in);

    // Adds a card to the Chain
    Chain<T> &operator+=(Card *card);

    // Returns the number of coins earned based on the number of cards in the chain
    int sell() const;

    // Overload the stream insertion operator to print the chain
    friend std::ostream &operator<<(std::ostream &out, const Chain<T> &chain)
    {
        if (!chain.cards.empty())
        {
            out << chain.cards.front()->getName() << " ";
            for (const auto &card : chain.cards)
            {
                out << *card << " ";
            }
        }
        return out;
    }

private:
    std::vector<Card *> cards;
};

#endif // CHAIN_H