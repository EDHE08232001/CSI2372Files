// main.cpp
#include <iostream>
#include <fstream>
#include "../include/Table.h"
#include "../include/CardFactory.h"

int main() {
    CardFactory* factory = CardFactory::getFactory();
    Table* table = nullptr;
    std::string choice;

    std::cout << "Do you want to load a saved game? (yes/no): ";
    std::cin >> choice;

    if (choice == "yes") {
        // Load game from file
        std::ifstream file("saved_game.txt");
        if (!file) {
            std::cerr << "No saved game found.\n";
            return 1;
        }
        table = new Table(file, factory);
        file.close();
    } else {
        // Start a new game
        std::string player1Name, player2Name;
        std::cout << "Enter name for Player 1: ";
        std::cin >> player1Name;
        std::cout << "Enter name for Player 2: ";
        std::cin >> player2Name;

        table = new Table(player1Name, player2Name, factory);
    }

    bool gamePaused = false;

    while (!gamePaused && !table->win()) {
        for (int i = 0; i < 2; ++i) {
            Player& currentPlayer = table->getPlayer(i);

            // Display Table
            std::cout << *table << std::endl;

            // Player draws top card from Deck
            Card* drawnCard = table->getDeck().draw();
            if (drawnCard) {
                currentPlayer.hand += drawnCard;
            } else {
                // Deck is empty
                break;
            }

            // If TradeArea is not empty
            if (table->getTradeArea().numCards() > 0) {
                // Add bean cards from TradeArea to chains or discard them
                // Implement logic for adding to chains or discarding
            }

            // Play topmost card from Hand
            Card* topCard = currentPlayer.hand.play();
            if (topCard) {
                // Implement logic to add card to chain or create a new chain
                // If chain is ended, remove cards and give coins to player
            }

            // If player decides to play another card
            std::cout << "Do you want to play another card? (yes/no): ";
            std::cin >> choice;
            if (choice == "yes") {
                Card* nextCard = currentPlayer.hand.play();
                if (nextCard) {
                    // Implement logic to add card to chain or create a new chain
                    // If chain is ended, remove cards and give coins to player
                }
            }

            // If player decides to discard a card
            std::cout << "Do you want to discard a card from your hand? (yes/no): ";
            std::cin >> choice;
            if (choice == "yes") {
                // Show player's hand
                currentPlayer.printHand(std::cout, true);
                std::cout << "Enter the index of the card to discard: ";
                int index;
                std::cin >> index;
                Card* discardedCard = currentPlayer.hand[index];
                if (discardedCard) {
                    table->getDiscardPile() += discardedCard;
                }
            }

            // Draw three cards from the deck and place in TradeArea
            for (int j = 0; j < 3; ++j) {
                Card* tradeCard = table->getDeck().draw();
                if (tradeCard) {
                    table->getTradeArea() += tradeCard;
                } else {
                    break;
                }
            }

            // While top card of discard pile matches a card in TradeArea
            while (true) {
                Card* discardTop = table->getDiscardPile().top();
                if (discardTop && table->getTradeArea().legal(discardTop)) {
                    table->getTradeArea() += table->getDiscardPile().pickUp();
                } else {
                    break;
                }
            }

            // For all cards in TradeArea
            // Implement logic for player to chain or leave cards

            // Draw two cards from Deck and add to player's hand
            for (int j = 0; j < 2; ++j) {
                Card* newCard = table->getDeck().draw();
                if (newCard) {
                    currentPlayer.hand += newCard;
                } else {
                    break;
                }
            }

            // Check if player wants to pause the game
            std::cout << "Do you want to pause and save the game? (yes/no): ";
            std::cin >> choice;
            if (choice == "yes") {
                std::ofstream file("saved_game.txt");
                file << *table;
                file.close();
                gamePaused = true;
                break;
            }
        }
    }

    // Determine the winner if the game ended
    if (!gamePaused) {
        std::string winnerName;
        if (table->win(winnerName)) {
            std::cout << "Game over! Winner: " << winnerName << std::endl;
        } else {
            std::cout << "Game over! It's a tie." << std::endl;
        }
    }

    // Clean up
    delete table;

    return 0;
}
