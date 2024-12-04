#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file Player.h
 * @brief Contains the declaration of the Player class used in the card game.
 */

#include "Chain.h"
#include "Hand.h"
#include <cstdlib>
#include <vector>

class Player
{
  std::string pName; /**< Player's name */
  Hand *pHand;       /**< Pointer to the player's hand */

  // Vector of pointers to the player's chains
  std::vector<Chain_Base *> pChains;

  int pCoins;               /**< Number of coins held by the player */
  const int MAX_NUM_CHAINS; /**< Maximum number of chains allowed */
  const int
      ALLOWED_CHAINS; /**< Number of chains allowed before purchasing more */

public:
  /**
   * @brief Constructs a new Player object with a given name.
   * @param name The name of the player.
   */
  Player(const std::string &name);

  /**
   * @brief Constructs a new Player object from an input stream.
   * Reconstructs the Player from saved data.
   * @param input The input stream to read from.
   * @param cf Pointer to the CardFactory.
   *
   * This constructor reads player data from the input stream, including the
   * player's name, coins, hand, and chains, and initializes the Player object
   * accordingly.
   */
  Player(std::istream &input, const CardFactory *cf);

  /**
   * @brief Destructor for the Player class.
   *
   * Deletes the player's hand and chains to prevent memory leaks.
   */
  ~Player();

  /**
   * @brief Increases the player's coin count by a specified amount.
   * @param coins The number of coins to add.
   * @return Reference to the updated Player object.
   */
  Player &operator+=(int coins);

  /**
   * @brief Returns a reference to the chain at the specified index.
   * @param i The index of the chain.
   * @return Reference to the Chain_Base object.
   *
   * Throws an exception if the index is out of range.
   */
  Chain_Base &operator[](int i);

  /**
   * @brief Adds a card to the player's hand.
   * @param card Pointer to the Card to add.
   */
  void takeCard(Card *card);

  /**
   * @brief Plays a card from the player's hand.
   * Creates or adds to a chain based on the card played.
   * @param input Pointer to a specific Card to play (optional).
   * @param specified_input True if a specific card is provided.
   * @return Pointer to the Card played.
   *
   * If no specific card is provided, the top card of the hand is played.
   */
  Card *playCard(Card *input = nullptr, bool specified_input = false);

  /**
   * @brief Removes a card from the player's hand at the specified position.
   * @param pos The position of the card to remove (default is 0).
   * @return Pointer to the removed Card.
   *
   * Throws an exception if the position is invalid.
   */
  Card *removeCard(int pos = 0);

  /**
   * @brief Gets the player's name.
   * @return The player's name as a string.
   */
  std::string getName();

  /**
   * @brief Gets the number of coins the player has.
   * @return The number of coins.
   */
  int getNumCoins();

  /**
   * @brief Gets the maximum number of chains allowed for the player.
   * @return The maximum number of chains.
   */
  int getMaxNumChains();

  /**
   * @brief Gets the current number of chains the player has.
   * @return The number of chains.
   */
  int getNumChains();

  /**
   * @brief Gets the number of cards in the player's hand.
   * @return The number of cards.
   */
  int getNumCards();

  /**
   * @brief Gets a pointer to the player's hand.
   * @return Pointer to the Hand object.
   */
  Hand *getHand();

  /**
   * @brief Gets a pointer to the player's chains.
   * @return Pointer to the vector of Chain_Base pointers.
   */
  std::vector<Chain_Base *> *getChains();

  /**
   * @brief Allows the player to buy a third chain for three coins.
   *
   * Reduces the player's coins by three. Throws an exception if the player
   * does not have enough coins or has already reached the maximum number of
   * chains.
   */
  void buyThirdChain();

  /**
   * @brief Prints the player's hand to the supplied ostream.
   * @param output The output stream.
   * @param allCards True to print all cards, false to print only the top card.
   *
   * If allCards is false, only the top card is printed.
   */
  void printHand(std::ostream &output, bool allCards);

  /**
   * @brief Overloaded insertion operator to display the player's information.
   * @param output The output stream.
   * @param player The Player object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output, const Player &player);

  /**
   * @brief Saves the player's state to a file.
   * @param p_id The player's ID (used for the filename).
   *
   * Writes the player's name, coins, hand, and chains to a file for later
   * reconstruction.
   */
  void savePlayer(int p_id);

  /**
   * @brief Checks for and removes any empty chains the player may have.
   */
  void checkEndedChains();
};

#endif // PLAYER_H
