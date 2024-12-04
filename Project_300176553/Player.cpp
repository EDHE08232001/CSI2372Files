#include "headers/Player.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>

/**
 * @brief Constructs a new Player object with a given name.
 * @param name The name of the player.
 */
Player::Player(const std::string &name) : MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2)
{
  pName = name;
  pCoins = 0;
  pHand = new Hand();
}

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
Player::Player(std::istream &input, const CardFactory *cf)
    : MAX_NUM_CHAINS(3), ALLOWED_CHAINS(2)
{
  std::string line;
  std::string chainType;
  Card *card = nullptr;
  pHand = new Hand();
  int chain_idx = -1; // Index of the current chain being added
  bool nameInitialized = false;
  bool coinsInitialized = false;
  bool handInitialized = false;
  bool chainsInitialized = false;
  bool chainTypeInitialized = false;

  while (std::getline(input, line))
  {
    std::istringstream iss(line);
    std::string data;
    if (!(iss >> data))
    {
      // Skip empty lines
      continue;
    }
    // Get the name from the first line
    if (!nameInitialized)
    {
      pName = data;
      nameInitialized = true;
      continue;
    }

    // Get the coins from the second line
    if (!coinsInitialized)
    {
      pCoins = std::stoi(data);
      coinsInitialized = true;
      continue;
    }

    // Initialize the hand
    if (!handInitialized)
    {
      if (data == "-chains")
      {
        handInitialized = true; // End of hand initialization
        continue;
      }
      else
      {
        // Create card based on symbol
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
          std::cout << "(Player Constructor) Invalid card symbol: " << data
                    << std::endl;
          exit(1);
        }
        // Add the card to the hand
        if (card != nullptr)
          *pHand += card;
      }
    }
    // Initialize the chains
    else if (!chainsInitialized)
    {
      if (data == "-end-chains")
      {
        chainsInitialized = true;
        continue;
      }
      else
      {
        if (data == "---")
        {
          chainTypeInitialized = false;
          continue;
        }
        else
        {
          if (!chainTypeInitialized)
          {
            // First line is the chain type
            chainType = data;
            chainTypeInitialized = true;

            Chain_Base *new_chain = nullptr;
            // Create a new chain based on the type
            if (chainType == "Blue")
              new_chain = new Chain<Blue>;
            else if (chainType == "Chili")
              new_chain = new Chain<Chili>;
            else if (chainType == "Stink")
              new_chain = new Chain<Stink>;
            else if (chainType == "Green")
              new_chain = new Chain<Green>;
            else if (chainType == "soy")
              new_chain = new Chain<soy>;
            else if (chainType == "black")
              new_chain = new Chain<black>;
            else if (chainType == "Red")
              new_chain = new Chain<Red>;
            else if (chainType == "garden")
              new_chain = new Chain<garden>;
            else
            {
              std::cout << "(Player Constructor) Invalid chain type: "
                        << chainType << std::endl;
              exit(1);
            }
            // Add the new chain to the player's chains
            if (new_chain != nullptr)
            {
              pChains.push_back(new_chain);
              chain_idx++;
            }
          }
          else
          {
            // Add cards to the current chain
            card = nullptr;
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
              std::cout << "(Player Constructor) Invalid card symbol: " << data
                        << std::endl;
              exit(1);
            }
            if (chain_idx != -1 && card != nullptr)
            {
              *(pChains.at(chain_idx)) += card;
            }
            else
            {
              std::cout << "(Player Constructor) No chain has been added yet. "
                           "chain_idx: "
                        << chain_idx << std::endl;
            }
          }
        }
      }
    }
  }

  std::cout << "Player initialized from file properly." << std::endl;
}

/**
 * @brief Destructor for the Player class.
 *
 * Deletes the player's hand and chains to prevent memory leaks.
 */
Player::~Player()
{
  delete pHand;
  // Delete all chains
  for (Chain_Base *chain : pChains)
  {
    delete chain;
  }
  pChains.clear();
}

/**
 * @brief Increases the player's coin count by a specified amount.
 * @param coins The number of coins to add.
 * @return Reference to the updated Player object.
 */
Player &Player::operator+=(int coins)
{
  pCoins += coins;
  return *this;
}

/**
 * @brief Returns a reference to the chain at the specified index.
 * @param i The index of the chain.
 * @return Reference to the Chain_Base object.
 *
 * Throws an exception if the index is out of range.
 */
Chain_Base &Player::operator[](int i)
{
  if (i < 0 || static_cast<size_t>(i) >= pChains.size())
  {
    throw std::out_of_range("Chain index out of range");
  }
  return *(pChains.at(i));
}

/**
 * @brief Adds a card to the player's hand.
 * @param card Pointer to the Card to add.
 */
void Player::takeCard(Card *card)
{
  *pHand += card; // Add the card to the player's hand
}

/**
 * @brief Plays a card from the player's hand.
 * Creates or adds to a chain based on the card played.
 * @param input Pointer to a specific Card to play (optional).
 * @param specified_input True if a specific card is provided.
 * @return Pointer to the Card played.
 *
 * If no specific card is provided, the top card of the hand is played.
 */
Card *Player::playCard(Card *input, bool specified_input)
{
  Card *card = nullptr;
  if (pHand->numCards() <= 0)
  {
    std::cout << "(playCard) Not enough cards in hand for player: " << pName
              << std::endl;
    return nullptr;
  }

  if (!specified_input)
    card = pHand->top();
  else
    card = input;

  Chain_Base *new_chain = nullptr;
  bool existingChain = false;
  char user_input[2];

  // Check if the chain already exists
  for (Chain_Base *chain : pChains)
  {
    if (chain->getChainType() == card->getName())
    {
      existingChain = true;
      new_chain = chain;
      if (!specified_input)
        card = pHand->play();

      if (card ==
          nullptr) // Take a card from the hand to avoid unexpected behavior
        card = pHand->play();

      *new_chain += card;
      break;
    }
  }

  // If the chain was not found, create a new one
  if (!existingChain)
  {
    // Create a new chain based on the card's name
    if (card->getName() == "Blue")
      new_chain = new Chain<Blue>;
    else if (card->getName() == "Chili")
      new_chain = new Chain<Chili>;
    else if (card->getName() == "Stink")
      new_chain = new Chain<Stink>;
    else if (card->getName() == "Green")
      new_chain = new Chain<Green>;
    else if (card->getName() == "soy")
      new_chain = new Chain<soy>;
    else if (card->getName() == "black")
      new_chain = new Chain<black>;
    else if (card->getName() == "Red")
      new_chain = new Chain<Red>;
    else if (card->getName() == "garden")
      new_chain = new Chain<garden>;
    else
    {
      std::cout << "(playCard) Invalid card name: " << card->getName()
                << std::endl;
      exit(1);
    }

    if (pChains.size() == static_cast<size_t>(MAX_NUM_CHAINS))
    {
      // Maximum number of chains reached; sell the first chain
      std::cout << "Player " << pName
                << " has reached the maximum number of chains ("
                << MAX_NUM_CHAINS << ")." << std::endl;
      std::cout << "> Selling Chain of type: "
                << pChains.front()->getChainType() << std::endl;

      // Sell the chain and add coins
      Chain_Base *chainToSell = pChains.front();
      int coinsEarned = 0;

      // Dynamic casting to the correct chain type to call sell()
      if (chainToSell->getChainType() == "Blue")
        coinsEarned = dynamic_cast<Chain<Blue> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "Chili")
        coinsEarned = dynamic_cast<Chain<Chili> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "Stink")
        coinsEarned = dynamic_cast<Chain<Stink> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "Green")
        coinsEarned = dynamic_cast<Chain<Green> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "soy")
        coinsEarned = dynamic_cast<Chain<soy> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "black")
        coinsEarned = dynamic_cast<Chain<black> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "Red")
        coinsEarned = dynamic_cast<Chain<Red> *>(chainToSell)->sell();
      else if (chainToSell->getChainType() == "garden")
        coinsEarned = dynamic_cast<Chain<garden> *>(chainToSell)->sell();
      else
      {
        std::cout << "(playCard) Invalid chain type: "
                  << chainToSell->getChainType() << std::endl;
        exit(1);
      }

      std::cout << "> Acquiring " << coinsEarned << " coins" << std::endl;
      pCoins += coinsEarned;

      // Delete the sold chain and remove it from the vector
      delete chainToSell;
      pChains.erase(pChains.begin());
    }
    else if (pChains.size() < static_cast<size_t>(ALLOWED_CHAINS))
    {
      // Add the new chain to the player's chains
      pChains.push_back(new_chain);
      if (new_chain->getSize() == 0)
      {
        new_chain->setChainType(card->getName());
      }
      card = pHand->play();
      *new_chain += card;
    }
    else
    {
      // Ask the player if they want to buy a third chain
      std::cout << ">>> Player " << pName
                << " has reached the maximum allowed number of chains ("
                << ALLOWED_CHAINS << ")." << std::endl;
      std::cout << "> Do you want to buy a third chain? (y/n)" << std::endl;
      std::cin >> user_input;
      if (user_input[0] == 'y')
      {
        try
        {
          // Buy a third chain
          buyThirdChain();
          // Add the card to the new chain
          for (Chain_Base *chain : pChains)
          {
            if (chain->getChainType() == card->getName())
            {
              new_chain = chain;
              card = pHand->play();
              *new_chain += card;
              break;
            }
          }
        }
        catch (const std::runtime_error &e)
        {
          std::cout << e.what() << std::endl;
          // Handle exception (e.g., not enough coins)
        }
      }
      else
      {
        // Sell the first chain to make room
        std::cout << "> Selling Chain of type: "
                  << pChains.front()->getChainType() << std::endl;

        Chain_Base *chainToSell = pChains.front();
        int coinsEarned = 0;

        // Dynamic casting to the correct chain type to call sell()
        if (chainToSell->getChainType() == "Blue")
          coinsEarned = dynamic_cast<Chain<Blue> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "Chili")
          coinsEarned = dynamic_cast<Chain<Chili> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "Stink")
          coinsEarned = dynamic_cast<Chain<Stink> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "Green")
          coinsEarned = dynamic_cast<Chain<Green> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "soy")
          coinsEarned = dynamic_cast<Chain<soy> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "black")
          coinsEarned = dynamic_cast<Chain<black> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "Red")
          coinsEarned = dynamic_cast<Chain<Red> *>(chainToSell)->sell();
        else if (chainToSell->getChainType() == "garden")
          coinsEarned = dynamic_cast<Chain<garden> *>(chainToSell)->sell();
        else
        {
          std::cout << "(playCard) Invalid chain type: "
                    << chainToSell->getChainType() << std::endl;
          exit(1);
        }

        std::cout << "> Acquiring " << coinsEarned << " coins" << std::endl;
        pCoins += coinsEarned;

        // Delete the sold chain and remove it from the vector
        delete chainToSell;
        pChains.erase(pChains.begin());

        // Start a new chain
        pChains.push_back(new_chain);
        if (new_chain->getSize() == 0)
        {
          new_chain->setChainType(card->getName());
        }
        card = pHand->play();
        *new_chain += card;
      }
    }
  }
  return card;
}

/**
 * @brief Removes a card from the player's hand at the specified position.
 * @param pos The position of the card to remove (default is 0).
 * @return Pointer to the removed Card.
 *
 * Throws an exception if the position is invalid.
 */
Card *Player::removeCard(int pos)
{
  if (pos < 0 || pos >= pHand->numCards())
  {
    throw std::out_of_range("Invalid position for removeCard");
  }
  return (*pHand)[pos];
}

/**
 * @brief Gets the player's name.
 * @return The player's name as a string.
 */
std::string Player::getName() { return pName; }

/**
 * @brief Gets the number of coins the player has.
 * @return The number of coins.
 */
int Player::getNumCoins() { return pCoins; }

/**
 * @brief Gets the maximum number of chains allowed for the player.
 * @return The maximum number of chains.
 */
int Player::getMaxNumChains() { return MAX_NUM_CHAINS; }

/**
 * @brief Gets the current number of chains the player has.
 * @return The number of chains.
 */
int Player::getNumChains()
{
  int counter = 0;
  for (Chain_Base *chain : pChains)
  {
    if (chain->getSize() > 0)
      counter++;
  }
  return counter;
}

/**
 * @brief Gets the number of cards in the player's hand.
 * @return The number of cards.
 */
int Player::getNumCards() { return pHand->numCards(); }

/**
 * @brief Allows the player to buy a third chain for three coins.
 *
 * Reduces the player's coins by three. Throws an exception if the player
 * does not have enough coins or has already reached the maximum number of
 * chains.
 */
void Player::buyThirdChain()
{
  if (pCoins >= 3)
  {
    if (pChains.size() < static_cast<size_t>(MAX_NUM_CHAINS))
    {
      pCoins -= 3;
      std::cout << "> Bought a third chain for 3 coins." << std::endl;
    }
    else
    {
      std::cout << "Cannot buy a new chain. Maximum number of chains ("
                << MAX_NUM_CHAINS << ") already reached." << std::endl;
    }
  }
  else
  {
    throw std::runtime_error("NotEnoughCoins");
  }
}

/**
 * @brief Prints the player's hand to the supplied ostream.
 * @param output The output stream.
 * @param allCards True to print all cards, false to print only the top card.
 *
 * If allCards is false, only the top card is printed.
 */
void Player::printHand(std::ostream &output, bool allCards)
{
  if (!allCards)
  {
    if (pHand->numCards() > 0)
      output << pHand->top()->getName()[0] << std::endl;
  }
  else
  {
    for (int i = 0; i < pHand->numCards(); i++)
    {
      output << pHand->getCard(i)->getName()[0] << " ";
    }
    output << std::endl;
  }
}

/**
 * @brief Overloaded insertion operator to display the player's information.
 * @param output The output stream.
 * @param player The Player object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const Player &player)
{
  output << player.pName << std::setw(5) << player.pCoins << " coins "
         << std::endl;
  for (Chain_Base *chain : player.pChains)
  {
    output << *chain;
    output << std::endl;
  }
  return output;
}

/**
 * @brief Saves the player's state to a file.
 * @param p_id The player's ID (used for the filename).
 *
 * Writes the player's name, coins, hand, and chains to a file for later
 * reconstruction.
 */
void Player::savePlayer(int p_id)
{
  std::ofstream file;
  std::string filename = "Saved-P" + std::to_string(p_id) + ".txt";

  file.open(filename, std::ios::trunc);
  if (!file.is_open())
  {
    std::cout << "Unable to open file " << filename << " for saving."
              << std::endl;
    return;
  }

  // Save player name
  file << pName << std::endl;

  // Save player coins
  file << pCoins << std::endl;

  // Save hand
  pHand->saveHand(file);

  file << std::endl
       << "-chains" << std::endl;

  // Save chains
  for (Chain_Base *chain : pChains)
  {
    file << std::endl
         << "---" << std::endl;
    chain->saveChain(file);
  }

  file << std::endl
       << "-end-chains" << std::endl;

  file.close();

  std::cout << "Player-" << p_id << " saved." << std::endl;
}

/**
 * @brief Gets a pointer to the player's hand.
 * @return Pointer to the Hand object.
 */
Hand *Player::getHand() { return pHand; }

/**
 * @brief Gets a pointer to the player's chains.
 * @return Pointer to the vector of Chain_Base pointers.
 */
std::vector<Chain_Base *> *Player::getChains() { return &pChains; }

/**
 * @brief Checks for and removes any empty chains the player may have.
 */
void Player::checkEndedChains()
{
  for (auto it = pChains.begin(); it != pChains.end(); it++)
  {
    if ((*it)->getSize() == 0)
    {
      delete *it;
      it = pChains.erase(it);
    }
  }
}
