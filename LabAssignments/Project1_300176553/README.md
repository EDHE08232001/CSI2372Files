# Lab Assignments of CSI 2372

## Group Members
1. Student 1 (EX1, Ex2)
    * Name:
        - Edward He
    * Student Number:
        - 300176553
2. Student 2 (Ex3)
    * Name:
        - Teodora Vukojevic
    * Student Number:
        - 300199584

-----

# Project Structure Guide for Card Game (CSI2372A)

This document explains the structure of the C++ card game project for CSI2372A, detailing the organization of the files and how the different components fit together to form the complete program.

## **Project Directory Overview**

The project is structured in the following way:

```
Project_ID/
│
├── src/                    # Source code files
│   ├── main.cpp            # Main driver program
│   ├── Card.cpp            # Implementations for the Card class and its derived classes
│   ├── Deck.cpp            # Implementations for Deck class
│   ├── DiscardPile.cpp     # Implementations for DiscardPile class
│   ├── Hand.cpp            # Implementations for Hand class
│   ├── Chain.cpp           # Implementations for Chain class
│   ├── TradeArea.cpp       # Implementations for TradeArea class
│   ├── Player.cpp          # Implementations for Player class
│   ├── Table.cpp           # Implementations for Table class
│   └── CardFactory.cpp     # Implementation for CardFactory
│
├── include/                # Header files
│   ├── Card.h              # Header for Card class and derived classes
│   ├── Deck.h              # Header for Deck class
│   ├── DiscardPile.h       # Header for DiscardPile class
│   ├── Hand.h              # Header for Hand class
│   ├── Chain.h             # Header for Chain class
│   ├── TradeArea.h         # Header for TradeArea class
│   ├── Player.h            # Header for Player class
│   ├── Table.h             # Header for Table class
│   └── CardFactory.h       # Header for CardFactory
│
├── data/                   # Data files for saving game state
│   ├── savegame.txt        # File for saving and loading paused game
│
├── README.txt              # Project description, team names, student numbers, etc.
└── Makefile                # Makefile to compile and link the project
```

## **1. Source Files (`src/`)**
The `src/` folder contains all the C++ source files for your project. Each class is implemented in its respective `.cpp` file:

- **`main.cpp`**: The main driver of the program. It contains the game loop, handles player inputs, and coordinates the flow of the game.
- **`Card.cpp`**: Implements the `Card` class and its derived classes (`Blue`, `Chili`, `Stink`, etc.). Handles the basic functionality for each type of bean card.
- **`Deck.cpp`**: Manages the deck of cards, including shuffling, dealing, and drawing.
- **`DiscardPile.cpp`**: Handles the discard pile functionality, adding and removing cards.
- **`Hand.cpp`**: Manages the player's hand of cards, supporting operations like playing, discarding, and accessing cards.
- **`Chain.cpp`**: Implements the `Chain` template class, which represents a chain of bean cards of the same type.
- **`TradeArea.cpp`**: Manages the trade area, where players can place cards and trade them.
- **`Player.cpp`**: Represents the player, managing their coins, chains, and other player-related functionality.
- **`Table.cpp`**: Represents the game table, managing players, the deck, discard pile, and trade area.
- **`CardFactory.cpp`**: Implements the `CardFactory` singleton class to generate cards and provide a shuffled deck.

## **2. Header Files (`include/`)**
The `include/` folder contains all the header files, which declare the classes, their members, and their function prototypes:

- **`Card.h`**: Declares the abstract `Card` class and its derived classes (`Blue`, `Chili`, etc.).
- **`Deck.h`**: Declares the `Deck` class that inherits from `std::vector<Card*>` and provides shuffling and drawing methods.
- **`DiscardPile.h`**: Declares the `DiscardPile` class for managing discarded cards.
- **`Hand.h`**: Declares the `Hand` class for managing cards held by the player.
- **`Chain.h`**: Declares the `Chain` template class for managing chains of the same bean card.
- **`TradeArea.h`**: Declares the `TradeArea` class for holding cards available for trade.
- **`Player.h`**: Declares the `Player` class, including player attributes such as chains, coins, and hand.
- **`Table.h`**: Declares the `Table` class that represents the current state of the game, including all components.
- **`CardFactory.h`**: Declares the `CardFactory` singleton class, which ensures only one instance is responsible for card creation.

## **3. Data Files (`data/`)**
- **`savegame.txt`**: Used for saving and loading the game state. This file stores information about the current state of the deck, players' hands, and other game components.

## **4. README.txt**
The `README.txt` file should include:
- **Project Title**: Card Game for CSI2372A
- **Student Names and Numbers**: Both team members' names and student numbers.
- **Course Code**: CSI2372A
- **Brief Description**: An overview of the game, instructions on how to run the code, and any additional notes.

## **5. Makefile**
The `Makefile` is used for compiling and linking your project efficiently. It includes:
- **Compilation Rules**: To compile the individual `.cpp` files into object files (`.o`).
- **Linking Rules**: To link the object files into a single executable.
- **Targets**: `all`, `clean`, etc., to facilitate building and cleaning the project.

**Example Commands:**
- `make` - Compile the program.
- `make clean` - Remove all compiled files.

## **Code Documentation and Comments**
- **Use of Comments**: Ensure that each class, function, and complex logic is well-documented using comments.
- **Header Comments**: Provide a brief description of each file's purpose at the top of each header and source file.
- **Doxygen Style**: Where applicable, use Doxygen-style comments for better documentation generation.

## **Game State and Save/Load Functionality**
- **Stream Insertion/Extraction Operators**: Implement `<<` and `>>` operators for each class to support game saving and loading.
- **Save/Load Logic**: Each class should have a constructor accepting an `istream` to reconstruct an object from a saved state.

## **Summary of Key Concepts**
- **Classes**: The game uses multiple classes to represent different components, each with its clear purpose and role.
- **Polymorphism**: The `Card` class and its derived classes showcase polymorphism, allowing for different types of bean cards with specific behaviors.
- **Templates**: The `Chain` class is implemented as a template to allow chaining of any type of bean card.
- **Factory Pattern**: The `CardFactory` class is used to create cards and ensure only one factory is responsible for managing all cards in the game.

This structure ensures that the project is modular, maintainable, and easy to extend or debug as you progress with its implementation. Following this guide will help you stay organized and deliver a well-structured, functional card game.
