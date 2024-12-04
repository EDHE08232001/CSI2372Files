#include "headers/Table.h"
#include <fstream>

/**
 * @brief Checks if a player has won the game.
 * @param pName Reference to a string where the winner's name will be stored.
 * @return True if a player has won, false otherwise.
 *
 * Determines the winner based on the number of coins when the deck is empty.
 */
bool Table::win(std::string &pName)
{
  if (deck->empty())
  {
    int p1Coins = p1->getNumCoins();
    int p2Coins = p2->getNumCoins();

    if (p1Coins > p2Coins)
    {
      pName = p1->getName();
    }
    else if (p1Coins < p2Coins)
    {
      pName = p2->getName();
    }
    else
    { // Equality
      pName = "Equality";
    }

    return true;
  }
  return false;
}

/**
 * @brief Prints the hand of the current player.
 * @param allCards True to print all cards, false to print only the top card.
 */
void Table::printHand(bool allCards)
{
  Player *current = currentPlayer == 0 ? p1 : p2; // Get the current player
  current->printHand(std::cout, allCards);
}

/**
 * @brief Returns a pointer to a player based on ID.
 * @param id Player ID (0 for Player 1, 1 for Player 2).
 * @return Pointer to the Player.
 */
Player *Table::getPlayer(int id)
{
  currentPlayer = id;
  if (id == 0)
    return p1;
  else
    return p2;
}

/**
 * @brief Overloaded insertion operator to print the table's state.
 * @param output The output stream.
 * @param tb The Table object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const Table &tb)
{
  output << "> Player 1: " << std::endl
         << *(tb.p1) << std::endl;
  output << "> Player 2: " << std::endl
         << *(tb.p2) << std::endl;
  output << "> Discard Pile (Top): " << *(tb.dp) << std::endl;
  output << "> Trade Area: " << *(tb.tradeAr) << std::endl;
  output << "_______________________" << std::endl;
  return output;
}

/**
 * @brief Saves the current game state to files.
 *
 * Writes the deck, discard pile, trade area, and players to their respective
 * files.
 */
void Table::saveTable()
{
  std::ofstream file;

  // Save Deck
  file.open("Saved-Deck.txt", std::ios::trunc);
  if (file.is_open())
  {
    deck->saveDeck(file);
    file.close();
  }

  // Save Discard Pile
  file.open("Saved-DiscardPile.txt", std::ios::trunc);
  if (file.is_open())
  {
    dp->saveDiscardPile(file);
    file.close();
  }

  // Save Trade Area
  file.open("Saved-TradeArea.txt", std::ios::trunc);
  if (file.is_open())
  {
    tradeAr->saveTradeArea(file);
    file.close();
  }

  // Save Players
  p1->savePlayer(1);
  p2->savePlayer(2);
}

/**
 * @brief Reloads a player from a saved file based on player ID.
 * @param p_id Player ID (1 or 2).
 */
void Table::reloadPlayer(int p_id)
{
  std::ifstream file;
  std::string filename = "Saved-P" + std::to_string(p_id) + ".txt";
  file.open(filename);
  if (file.is_open())
  {
    if (p_id == 1)
    {
      p1 = new Player(file, cf);
    }
    else if (p_id == 2)
    {
      p2 = new Player(file, cf);
    }
    file.close();
  }
  else
  {
    std::cout << filename << " not found. Using default player." << std::endl;
    if (p_id == 1)
      p1 = new Player("Player1");
    else if (p_id == 2)
      p2 = new Player("Player2");
  }
}

/**
 * @brief Reloads the deck from the saved file.
 */
void Table::reloadDeck()
{
  std::ifstream deckFile("Saved-Deck.txt");
  if (deckFile.is_open())
  {
    deck = new Deck(deckFile, cf);
    deckFile.close();
  }
  else
  {
    // File not found; generate deck from CardFactory
    deck = cf->getDeck();
    std::cout << "Saved-Deck.txt not found. The deck has been generated from "
                 "the CardFactory."
              << std::endl;
  }
}

/**
 * @brief Reloads the discard pile from the saved file.
 */
void Table::reloadDiscardPile()
{
  std::ifstream dpFile("Saved-DiscardPile.txt");
  if (dpFile.is_open())
  {
    dp = new DiscardPile(dpFile, cf);
    dpFile.close();
  }
  else
  {
    // File not found; use empty discard pile
    dp = new DiscardPile();
    std::cout << "Saved-DiscardPile.txt not found. Using empty discard pile."
              << std::endl;
  }
}

/**
 * @brief Reloads the trade area from the saved file.
 */
void Table::reloadTradeArea()
{
  std::ifstream trArFile("Saved-TradeArea.txt");
  if (trArFile.is_open())
  {
    tradeAr = new TradeArea(trArFile, cf);
    trArFile.close();
  }
  else
  {
    // File not found; use empty trade area
    tradeAr = new TradeArea();
    std::cout << "Saved-TradeArea.txt not found. Using empty trade area."
              << std::endl;
  }
}

/**
 * @brief Returns a pointer to the deck.
 * @return Pointer to the Deck.
 */
Deck *Table::getDeck()
{
  if (deck == nullptr)
  {
    deck = cf->getDeck();
  }
  return deck;
}

/**
 * @brief Returns a pointer to the discard pile.
 * @return Pointer to the DiscardPile.
 */
DiscardPile *Table::getDiscardPile() { return dp; }

/**
 * @brief Returns a pointer to the trade area.
 * @return Pointer to the TradeArea.
 */
TradeArea *Table::getTradeArea() { return tradeAr; }
