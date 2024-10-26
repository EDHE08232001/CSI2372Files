#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Chain.h"
#include "Hand.h"
#include <string>
#include <vector>
#include <iostream>

class Player
{
public:
    // Constructor that creates a player with a given name
    Player(const std::string &name);

    // Constructor to reconstruct the player from a file
    Player(std::istream &in);

    // Returns the player's name
    std::string getName() const;

    // Returns the number of coins the player has
    int getNumCoins() const;

    // Adds coins to the player
    Player &operator+=(int coins);

    // Returns the number of chains the player can have
    int getMaxNumChains() const;

    // Returns the number of non-empty chains the player has
    int getNumChains() const;

    // Returns the chain at the specified position
    Chain<Card> &operator[](int i);

    // Buys a third chain for three coins
    void buyThirdChain();

    // Prints the player's hand (top card only or full hand)
    void printHand(std::ostream &out, bool full) const;

    // Overload the stream insertion operator to print the player
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

private:
    std::string name;
    int coins;
    int maxChains;
    std::vector<Chain<Card>> chains;
    Hand hand;
};

#endif // PLAYER_H