# Lab Assignments of CSI 2372

## Group Members
1. Student 1
    * Name:
        - Edward He
    * Student Number:
        - 300176553
2. Student 2
    * Name:
        - Teodora Vukojevic
    * Student Number:
        - 300199584

-----

## Program Overview

This project is a card game implemented in C++ as part of the lab assignments for CSI 2372. The game simulates a simplified version of a trading card game where two players compete to collect coins by creating chains of cards. Players draw cards, manage their hands, form chains, and strategically decide when to sell chains to maximize their coin count.

## Execution Instructions

To compile the program, navigate to the project directory and use the following command:

```bash
clang++ -std=c++11 -Wall -Wextra ./*.cpp -o ./game
```

- `-std=c++11`: Compile using the C++11 standard.
- `-Wall -Wextra`: Enable all compiler warnings for better code quality.

To run the game, execute:

```bash
./game
```

## Program Description

### Game Flow

1. **Initialization**:
   - The game initializes the deck using the `CardFactory` and shuffles it.
   - Each player is created and initialized with an empty hand and zero coins.
   - Each player is dealt five cards from the deck to start.

2. **Gameplay Loop**:
   - The game proceeds in turns, alternating between the two players.
   - **Player's Turn**:
     - The player draws a card from the deck and adds it to their hand.
     - The player plays the top card from their hand to their chains:
       - If they have a matching chain, the card is added to it.
       - If they don't have a matching chain, they can start a new chain or must sell an existing chain if they've reached the maximum number of chains.
     - The player decides whether to play another card or discard a card from their hand to the discard pile.
     - Three cards are drawn from the deck into the trade area.
     - The player can add any matching cards from the trade area to their chains.
     - The top card of the discard pile is added to the trade area if it matches any cards in the trade area.
     - The player draws two additional cards from the deck to their hand.

3. **End of Game**:
   - The game ends when the deck is empty.
   - Players sell all their remaining chains for coins.
   - The player with the most coins wins the game.

### Saving and Loading Game State

- **Saving**:
  - At any point during the game, players can choose to save the game state.
  - The state of all game components (players, deck, discard pile, trade area) is saved to files.
- **Loading**:
  - When starting the game, players can choose to load a saved game.
  - The game reconstructs all components from the saved files and resumes from where it was left off.

## Requirements Satisfied

The following requirements from the project instructions have been satisfied:

1. **Class Implementations**:
   - Implemented all required classes (`Card`, `Deck`, `Hand`, `Chain`, `Player`, `Table`, `DiscardPile`, `TradeArea`, `CardFactory`) with appropriate methods and member variables.
   - Used inheritance for different card types derived from the `Card` base class.

2. **Singleton Pattern**:
   - The `CardFactory` class is implemented as a singleton to ensure only one instance exists.

3. **Operator Overloading**:
   - Overloaded operators such as `operator+=` for adding cards to hands, chains, etc.
   - Overloaded `operator<<` for printing objects like `Player`, `Hand`, `Chain`, etc.
   - Overloaded `operator[]` for accessing elements in collections.

4. **File I/O for Saving and Loading**:
   - Implemented save and load functionality for all game components.
   - Game state can be saved to and loaded from files, allowing players to pause and resume the game.

5. **Exception Handling**:
   - Used exceptions to handle error conditions, such as attempting to buy a third chain without enough coins.
   - Exception messages provide clear information about the error.

6. **Memory Management**:
   - Properly managed dynamic memory allocation and deallocation.
   - Destructors are implemented for classes that allocate memory to prevent memory leaks.

7. **Standard Template Library (STL) Usage**:
   - Utilized STL containers such as `std::vector`, `std::list`, `std::queue` for managing collections.
   - Chose appropriate containers based on the required functionality (e.g., `std::queue` for hands).

8. **User Interaction and Input Validation**:
   - The game provides prompts and messages to guide the player through their turn.
   - Input is read from the console, and basic validation is performed.

9. **Code Documentation**:
   - Added comprehensive comments and documentation throughout the code.
   - Used Doxygen-style comments for classes and methods for better maintainability.

10. **Compilation and Warnings**:
    - The code compiles without errors using the provided compilation command.
    - Warnings are addressed, and the `-Wall -Wextra` flags are used to ensure code quality.

## Known Issues and Limitations

- **Input Validation**:
  - While basic input validation is implemented, there may be cases where unexpected input could cause issues. Further input sanitization is recommended.

- **Game Scalability**:
  - The game is currently designed for two players. Extending it to support more players would require modifications to the game loop and player management.

- **Exception Messages**:
  - Some exception messages could be more user-friendly. Improving exception handling can enhance the user experience.

- **Unused Parameters**:
  - There are warnings about unused parameters in some constructors (e.g., `CardFactory *cf`) which were parts of the ealy satge of the program design. These can be addressed by removing or utilizing these parameters.

---

We hope you enjoy playing the game!