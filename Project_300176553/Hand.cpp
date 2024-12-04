#include "headers/Hand.h"
#include <fstream>

/**
 * @brief Constructs a Hand object from an input stream.
 * Reconstructs the Hand from saved data.
 * @param input The input stream to read from.
 * @param cf Pointer to the CardFactory (currently unused).
 *
 * This constructor reads card data from the input stream, creates corresponding
 * Card objects, and adds them to the hand.
 */
Hand::Hand(std::istream &input, const CardFactory *cf)
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
    // Create the appropriate Card object based on the data
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
      std::cout << "(Hand Constructor) Invalid card symbol: " << data
                << std::endl;
      exit(1);
    }
    // Add the card to the hand
    if (card != nullptr)
      pHand.push(card);
  }

  std::cout << "Hand with " << count << " cards initialized from file properly."
            << std::endl;
}

/**
 * @brief Destructor for the Hand class.
 *
 * Deletes all Card pointers stored in the hand to prevent memory leaks.
 */
Hand::~Hand() { clearHand(); }

/**
 * @brief Adds a card to the player's hand.
 * @param card Pointer to the Card to add.
 * @return Reference to the updated Hand object.
 */
Hand &Hand::operator+=(Card *card)
{
  pHand.push(card);
  return *this;
}

/**
 * @brief Returns and removes the top card from the player's hand.
 * @return Pointer to the Card played.
 */
Card *Hand::play()
{
  if (pHand.empty())
  {
    std::cout << "Hand is empty. Cannot play." << std::endl;
    return nullptr;
  }

  Card *card = pHand.front();
  pHand.pop(); // Remove the first element
  return card;
}

/**
 * @brief Returns but does not remove the top card from the player's hand.
 * @return Pointer to the top Card.
 */
Card *Hand::top()
{
  if (pHand.empty())
  {
    std::cout << "Hand is empty. Cannot top." << std::endl;
    return nullptr;
  }

  return pHand.front();
}

/**
 * @brief Returns the Card at a given index without removing it.
 * @param pos The position of the Card in the hand.
 * @return Pointer to the Card at the specified position.
 *
 * Throws an exception if the position is invalid.
 */
Card *Hand::getCard(int pos)
{
  if (pos < 0 || pos >= static_cast<int>(pHand.size()))
  {
    throw std::out_of_range("Invalid position in getCard");
  }

  std::queue<Card *, std::list<Card *>> temp = pHand; // Copy the queue
  Card *card = nullptr;
  for (int i = 0; i <= pos; ++i)
  {
    card = temp.front();
    temp.pop();
  }
  return card;
}

/**
 * @brief Returns and removes the Card at a given index.
 * @param pos The position of the Card to remove.
 * @return Pointer to the removed Card.
 *
 * Throws an exception if the position is invalid.
 */
Card *Hand::operator[](int pos)
{
  if (pos < 0 || pos >= static_cast<int>(pHand.size()))
  {
    throw std::out_of_range("Invalid position in operator[]");
  }

  Card *card = nullptr;                       // Removed card to return
  std::queue<Card *, std::list<Card *>> temp; // Temporary queue
  int find_idx = 0;
  while (!pHand.empty())
  {
    if (find_idx == pos)
    {
      // Remove the card at the specified position
      card = pHand.front();
      pHand.pop();
    }
    else
    {
      // Keep other cards in the temporary queue
      temp.push(pHand.front());
      pHand.pop();
    }
    find_idx++;
  }

  // Restore the original queue without the removed card
  pHand = temp;
  return card;
}

/**
 * @brief Returns the number of cards in the player's hand.
 * @return The number of cards.
 */
int Hand::numCards() { return static_cast<int>(pHand.size()); }

/**
 * @brief Overloaded insertion operator to display the hand.
 * @param output The output stream.
 * @param hand The Hand object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, Hand &hand)
{
  std::queue<Card *, std::list<Card *>> temp =
      *(hand.getListOfCards()); // Copy the queue
  while (!temp.empty())
  {
    Card *card = temp.front();
    card->print(output);
    output << " ";
    temp.pop();
  }
  return output;
}

/**
 * @brief Saves the hand to a file.
 * @param filename The output file stream to write to.
 */
void Hand::saveHand(std::ofstream &filename)
{
  std::queue<Card *, std::list<Card *>> temp = pHand; // Copy the queue
  while (!temp.empty())
  {
    Card *card = temp.front();
    card->saveCard(filename);
    filename << std::endl;
    temp.pop();
  }
  std::cout << "Hand saved." << std::endl;
}

/**
 * @brief Returns a pointer to the internal queue of cards.
 * @return Pointer to the queue of Card pointers.
 */
std::queue<Card *, std::list<Card *>> *Hand::getListOfCards() { return &pHand; }
