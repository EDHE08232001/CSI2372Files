#include "../include/Table.h"
#include <iostream>
#include <fstream>

int main() {
    std::string player1Name, player2Name;
    char choice;
    Table* gameTable = nullptr;

    std::cout << "Welcome to the Card Game!" << std::endl;
    std::cout << "Do you want to load a saved game? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::ifstream inputFile("savegame.txt");
        if (inputFile.is_open()) {
            gameTable = new Table(inputFile);
            inputFile.close();
            std::cout << "Game loaded successfully!" << std::endl;
        } else {
            std::cerr << "Failed to load the game. Starting a new game instead." << std::endl;
        }
    }

    if (!gameTable) {
        std::cout << "Enter Player 1's name: ";
        std::cin >> player1Name;
        std::cout << "Enter Player 2's name: ";
        std::cin >> player2Name;
        gameTable = new Table(player1Name, player2Name);
    }

    bool gameOver = false;
    while (!gameOver) {
        std::cout << "Current Table Status:" << std::endl;
        std::cout << *gameTable << std::endl;

        for (int i = 0; i < 2; ++i) {
            Player& currentPlayer = (i == 0) ? gameTable->player1 : gameTable->player2;
            std::cout << currentPlayer.getName() << "'s turn." << std::endl;

            // Play top card from hand
            Card* playedCard = currentPlayer.play();
            if (playedCard) {
                gameTable->tradeArea += playedCard;
                std::cout << "Played card: " << *playedCard << std::endl;
            } else {
                std::cout << "No card to play." << std::endl;
            }

            // Handle trade area and chains
            // (Add logic here for chaining and using trade area)

            // Draw new cards
            currentPlayer += gameTable->deck.draw();
            currentPlayer += gameTable->deck.draw();
        }

        std::string winnerName;
        if (gameTable->win(winnerName)) {
            gameOver = true;
            std::cout << "The game is over! Winner: " << winnerName << std::endl;
        }

        // Ask if player wants to save the game
        std::cout << "Do you want to save the game? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            std::ofstream outputFile("savegame.txt");
            if (outputFile.is_open()) {
                outputFile << *gameTable;
                outputFile.close();
                std::cout << "Game saved successfully!" << std::endl;
            } else {
                std::cerr << "Failed to save the game." << std::endl;
            }
        }
    }

    delete gameTable;
    return 0;
}