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

# Project Structure for Card Game (C++)

This project is implemented in C++ using separate source (`.cpp`) and header (`.h`) files to ensure modularity, maintainability, and scalability. Below is the recommended file structure and explanation for organizing the card game project.

## Directory Structure
The project directory is organized as follows:

```
Project_ID/
  |-- include/                  # Contains header files (.h) for declarations
  |    |-- Card.h
  |    |-- Deck.h
  |    |-- DiscardPile.h
  |    |-- Chain.h
  |    |-- TradeArea.h
  |    |-- Hand.h
  |    |-- Player.h
  |    |-- Table.h
  |    |-- CardFactory.h
  |
  |-- src/                      # Contains source files (.cpp) for implementations
  |    |-- Card.cpp
  |    |-- Deck.cpp
  |    |-- DiscardPile.cpp
  |    |-- Chain.cpp
  |    |-- TradeArea.cpp
  |    |-- Hand.cpp
  |    |-- Player.cpp
  |    |-- Table.cpp
  |    |-- CardFactory.cpp
  |
  |-- main.cpp                  # Entry point of the application
  |-- README.md                 # Project overview and setup instructions
  |-- CODE_REPORT.md            # Explanation and documentation for the code
```

### **Folder Details**
- **include/**: This folder contains all the header files that declare the classes, methods, and interfaces. Each `.h` file is named after the corresponding class it declares, ensuring clear correspondence between the declarations and implementations.
- **src/**: This folder contains the source files with the definitions of the methods and functionalities for the respective classes.
- **main.cpp**: This file serves as the entry point for the program. It will contain the `main()` function that drives the game loop and integrates the game components.
- **README.md**: A general overview of the project, including requirements, installation, usage, and other information useful for anyone getting started.
- **CODE_REPORT.md**: A detailed explanation of the design, implementation details, and approach used to solve the problem. This serves as technical documentation for understanding the code.

## File Descriptions

### Header Files (`include/`)
1. **Card.h**:
   - Declares the `Card` base class and the derived classes (`Blue`, `Chili`, `Stink`, etc.).
   - Defines the abstract methods `getCardsPerCoin()`, `getName()`, and `print()`. It also includes the global stream insertion operator.

2. **Deck.h**:
   - Declares the `Deck` class that extends `std::vector`.
   - Includes methods for drawing cards (`draw()`) and constructing the deck from a saved file.

3. **DiscardPile.h**:
   - Declares the `DiscardPile` class for managing discarded cards.
   - Includes methods for adding cards (`operator+=()`), picking up cards (`pickUp()`), and accessing the top card (`top()`).

4. **Chain.h**:
   - Declares the `Chain` template class.
   - Includes functionality for adding cards to a chain (`operator+=()`), selling chains (`sell()`), and printing the chain.

5. **TradeArea.h**:
   - Declares the `TradeArea` class, which holds the cards available for trading.
   - Includes methods for adding cards, checking legality, and trading specific cards.

6. **Hand.h**:
   - Declares the `Hand` class for representing a player's hand of cards.
   - Includes methods for adding cards (`operator+=()`), playing cards (`play()`), and accessing cards by index (`operator[]`).

7. **Player.h**:
   - Declares the `Player` class for representing each player in the game.
   - Defines methods for managing coins, chains, and interacting with cards.

8. **Table.h**:
   - Declares the `Table` class that holds the game components, including players, deck, and discard pile.
   - Includes functionality for printing the current state and checking winning conditions.

9. **CardFactory.h**:
   - Declares the `CardFactory` class responsible for creating card instances.
   - Uses the singleton pattern to ensure there is only one `CardFactory` instance.

### Source Files (`src/`)
1. **Card.cpp**:
   - Implements the methods declared in `Card.h` for all card types, including the `print()`, `getCardsPerCoin()`, and `getName()` methods.

2. **Deck.cpp**:
   - Implements the `Deck` class, including methods for shuffling and drawing cards.

3. **DiscardPile.cpp**:
   - Implements the `DiscardPile` class, including adding to and removing from the discard pile.

4. **Chain.cpp**:
   - Implements the `Chain` template class, focusing on adding cards, selling chains, and ensuring type safety using exceptions.

5. **TradeArea.cpp**:
   - Implements the `TradeArea` class, providing methods for trading cards and adding cards to the trading area.

6. **Hand.cpp**:
   - Implements the `Hand` class, including adding, playing, and displaying cards.

7. **Player.cpp**:
   - Implements the `Player` class, providing functionalities for managing chains, coins, and hands.

8. **Table.cpp**:
   - Implements the `Table` class, managing the game components, displaying the current state, and determining the winning player.

9. **CardFactory.cpp**:
   - Implements the `CardFactory` singleton, including creating cards and shuffling them into the deck.

### **main.cpp**
- Implements the main game loop.
- Controls the flow of the game, interacts with the `Player` and `Table` objects, and handles user input/output.
- Responsible for setting up the game (initializing deck, players, and table) and orchestrating each player's turn.

## CODE_REPORT.md Content
This file serves as the main code report for the project, documenting the design decisions and providing an overview of the implementation.

### **1. Introduction**
The `Card Game` project was implemented using object-oriented programming concepts. The goal was to create a modular and maintainable C++ program that leverages good software engineering practices.

### **2. Class Design Overview**
- **Card Hierarchy**: The abstract `Card` class represents a generic card, with derived classes for specific types of bean cards.
- **Deck, Hand, Chain, DiscardPile**: These classes extend standard data structures, providing specific game functionalities.
- **Player and Table**: Represent game participants and the central game state, respectively.

### **3. Key Features**
- **Factory Pattern**: The `CardFactory` class ensures consistent card creation throughout the game.
- **Exception Handling**: Proper exception handling is implemented in cases like adding cards to incompatible chains.
- **Polymorphism**: Cards are stored using pointers to the abstract `Card` type, allowing for runtime polymorphism.

### **4. Implementation Decisions**
- **Use of Containers**: Standard containers (`std::vector`, `std::list`, `std::queue`) were chosen for ease of use and efficiency.
- **Stream Insertion/Extraction**: Implemented for each class to facilitate game save/load functionality and easy debugging.

### **5. Compilation and Execution**
- **Compilation**: The project can be compiled using a `Makefile` that compiles each `.cpp` file separately, allowing for easy debugging and modular compilation.
- **Execution**: The executable generated will start the game by asking for player names or loading a saved state.

### **6. Conclusion**
The project demonstrates a robust application of object-oriented programming concepts, focusing on maintainability, scalability, and efficiency. The use of design patterns and exception handling showcases good software engineering practices.


## How to Use this Project Structure
- **Header Files (`include/`)**: Declare all the interfaces and data members of the classes here. Keep function declarations and implementation separate to ensure a clear and organized codebase.
- **Source Files (`src/`)**: Define the actual functionalities of the methods and classes here.
- **main.cpp**: Drive the logic of the game by integrating the components defined in the header and source files.
- **CODE_REPORT.md**: Use this as documentation to explain how each part of your code functions, which is useful for grading and future reference.