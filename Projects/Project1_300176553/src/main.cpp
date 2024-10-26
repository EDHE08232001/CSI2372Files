// File: ./src/main.cpp

#include "../include/Table.h"
#include <iostream>
#include <fstream>

void loadGame(Table &table)
{
    std::ifstream inFile("saved_game.txt");
    if (inFile.is_open())
    {
        table = Table(inFile);
        inFile.close();
        std::cout << "Game loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "No saved game found. Starting a new game." << std::endl;
    }
}

void saveGame(const Table &table)
{
    std::ofstream outFile("saved_game.txt");
    if (outFile.is_open())
    {
        outFile << table;
        outFile.close();
        std::cout << "Game saved successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to save the game." << std::endl;
    }
}

int main()
{
    std::string player1Name, player2Name;
    std::cout << "Enter Player 1 Name: ";
    std::cin >> player1Name;
    std::cout << "Enter Player 2 Name: ";
    std::cin >> player2Name;

    Table table(player1Name, player2Name);
    char choice;

    std::cout << "Do you want to load a saved game? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        loadGame(table);
    }

    while (true)
    {
        std::string winnerName;
        if (table.win(winnerName))
        {
            std::cout << "Game Over! Winner: " << winnerName << std::endl;
            break;
        }

        std::cout << table << std::endl;

        // Simulate turns (simplified for illustration)
        std::cout << "Press 's' to save the game or any other key to continue: ";
        std::cin >> choice;
        if (choice == 's')
        {
            saveGame(table);
            continue;
        }

        // TODO: Implement player turns (drawing cards, trading, etc.)
        std::cout << "Simulating player turns..." << std::endl;
        // Player actions would be here

        std::cout << "Press 'q' to quit or any other key to continue: ";
        std::cin >> choice;
        if (choice == 'q')
        {
            saveGame(table);
            break;
        }
    }

    return 0;
}
