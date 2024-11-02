#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Hand.h"
#include "Chain.h"
#include "CardFactory.h"

class NotEnoughCoins : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not enough coins to buy a third chain.";
    }
};

class Player {
private:
    std::string name;
    int coins = 0;
    int maxChains = 2;  // Defaults to 2, but can be increased to 3
    std::vector<Chain_Base*> chains;  // Using Chain_Base* to allow polymorphic behavior
    Hand hand;

public:
    // Constructor with player name
    Player(const std::string& playerName);

    // Constructor to reconstruct player from file
    Player(std::istream& in, const CardFactory* factory);

    // Get player's name
    std::string getName() const;

    // Get number of coins
    int getNumCoins() const;

    // Add coins
    Player& operator+=(int coinsToAdd);

    // Get maximum number of chains
    int getMaxNumChains() const;

    // Get current number of chains
    int getNumChains() const;

    // Access chain at a given index
    Chain_Base& operator[](int i);

    // Buy a third chain
    void buyThirdChain();

    // Print the player's hand
    void printHand(std::ostream& out, bool showAll) const;

    // Friend function to print player info
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

    // Destructor to clean up dynamically allocated chains
    ~Player();
};

#endif // PLAYER_H
