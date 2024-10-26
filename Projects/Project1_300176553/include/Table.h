#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include <iostream>

class Table
{
public:
    // Constructor to initialize a new table with two players
    Table(const std::string &player1Name, const std::string &player2Name);

    // Constructor to reconstruct the table from a file
    Table(std::istream &in);

    // Returns true if the game has been won
    bool win(std::string &winnerName) const;

    // Prints the hand of a player (top card only or full hand)
    void printHand(std::ostream &out, bool full, const Player &player) const;

    // Overload the stream insertion operator to print the table
    friend std::ostream &operator<<(std::ostream &out, const Table &table);

private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;
};

#endif // TABLE_H