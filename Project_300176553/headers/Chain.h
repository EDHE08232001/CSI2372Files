#ifndef CHAIN_H
#define CHAIN_H

/**
 * @file Chain.h
 * @brief Contains the declarations of the Chain classes used in the card game.
 */

#include "Card.h"
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <vector>

class CardFactory;

/**
 * @class Chain_Base
 * @brief Abstract base class representing a generic chain of cards.
 *        Provides common functionalities for chains.
 */
class Chain_Base
{
protected:
  /**< Vector holding pointers to cards in the chain */
  std::vector<Card *> chain;

  std::string chainType; /**< The type of the chain (bean type) */

public:
  /**
   * @brief Returns the number of cards in the chain.
   * @return Number of cards in the chain.
   */
  int getSize();

  /**
   * @brief Gets the type of the chain.
   * @return The chain type as a string.
   */
  std::string getChainType();

  /**
   * @brief Sets the type of the chain.
   * @param chainType The chain type to set.
   */
  void setChainType(std::string chainType);

  /**
   * @brief Saves the chain to a file.
   * @param filename The output file stream to write to.
   */
  void saveChain(std::ofstream &filename);

  /**
   * @brief Adds a card to the chain.
   * @param card Pointer to the card to add.
   * @return Reference to the updated Chain_Base object.
   */
  Chain_Base &operator+=(Card *card)
  {
    // Add the card to the chain
    chain.push_back(card);
    return *this;
  };

  /**
   * @brief Virtual destructor for Chain_Base.
   */
  virtual ~Chain_Base() {};

  /**
   * @brief Overloaded insertion operator to print the chain.
   * @param output The output stream.
   * @param d The Chain_Base object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output, const Chain_Base &d);
};

/**
 * @class Chain
 * @brief Template class representing a chain of cards of a specific bean type.
 * @tparam T The type of bean card.
 */
template <typename T = Card>
class Chain : public virtual Chain_Base
{
public:
  /**
   * @brief Default constructor for Chain.
   *        Initializes the chainType based on the template type T.
   */
  Chain()
  {
    chainType = typeid(T).name();
    if (std::isdigit(chainType.at(0)))
    {
      // Remove the first unexpected digit in the type name
      chainType = chainType.substr(1, chainType.size());
    }
  };

  /**
   * @brief Constructor to initialize Chain from an input stream.
   *        Reconstructs the chain from saved data.
   * @param input The input stream.
   * @param cf Pointer to the CardFactory.
   */
  Chain(std::istream &input, const CardFactory *cf)
  {
    std::string line;
    Card *card = nullptr;
    int count = 0;
    while (std::getline(input, line))
    {
      std::istringstream iss(line);
      std::string data;
      if (!(iss >> data))
      {
        // Skip empty lines
        continue;
      }
      count++;
      // Create card based on the character read
      if (data == "B")
        card = new Blue;
      else if (data == "C")
        card = new Chili;
      else if (data == "S")
        card = new Stink;
      else if (data == "G")
        card = new Green;
      else if (data == "s")
        card = new soy;
      else if (data == "b")
        card = new black;
      else if (data == "R")
        card = new Red;
      else if (data == "g")
        card = new garden;
      else
      {
        std::cout << "(Chain Constructor) Check the card name in the file. "
                     "Value received: "
                  << data << std::endl;
        exit(1);
      }
      // Add the card to the chain
      if (card != nullptr)
        (*this) += card;
    }

    std::cout << "Chain with " << count
              << " cards initialized from file properly." << std::endl;
  };

  /**
   * @brief Adds a card to the chain.
   *        Throws an exception if the card type does not match the chain's bean
   * type.
   * @param card Pointer to the card to add.
   * @return Reference to the updated Chain object.
   * @throws std::runtime_error if the card type does not match.
   */
  Chain<T> &operator+=(Card *card)
  {
    if (getSize() == 0)
      chainType =
          typeid(*card).name(); // Update the chain type based on the first card

    // Check if the card type matches the chain's bean type
    if (typeid(T) == typeid(*card))
    {
      chain.push_back(card);
      return *this;
    }
    else
      throw std::runtime_error("IllegalType");
  };

  /**
   * @brief Calculates the number of coins earned by selling the chain.
   *        Uses Card::getCardsPerCoin to determine the coin value.
   * @return The number of coins earned.
   */
  int sell()
  {
    if (chain.empty())
      return 0;

    T elem; // Create an instance of the bean to access getCardsPerCoin
    int totalCards = static_cast<int>(chain.size());
    int coins = 0;
    int coinsNeeded = 0;

    // Determine the maximum number of coins that can be earned
    for (int coinValue = 4; coinValue >= 1; --coinValue)
    {
      coinsNeeded = elem.getCardsPerCoin(coinValue);
      if (totalCards >= coinsNeeded)
      {
        coins = coinValue;
        break;
      }
    }

    return coins;
  };

  /**
   * @brief Overloaded insertion operator to print the chain.
   * @param output The output stream.
   * @param d The Chain object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output, const Chain<T> &d)
  {
    output << d.chainType << " ";
    for (size_t i = 0; i < d.chain.size(); i++)
    {
      d.chain.at(i)->print(output);
      output << " ";
    }
    return output;
  }
};

#endif // CHAIN_H
