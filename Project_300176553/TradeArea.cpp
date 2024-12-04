#include "headers/TradeArea.h"

/**
 * @brief Constructs a TradeArea object from an input stream.
 * Reconstructs the TradeArea from saved data.
 * @param input The input stream to read from.
 * @param cf Pointer to the CardFactory (currently unused).
 *
 * This constructor reads card data from the input stream, creates corresponding
 * Card objects, and adds them to the TradeArea.
 */
TradeArea::TradeArea(std::istream &input, const CardFactory *cf)
    : MAX_CARDS(3)
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
      std::cout << "(TradeArea Constructor) Check the card name in the file. "
                   "Value received: "
                << data << std::endl;
      exit(1);
    }
    // Add the card to the TradeArea
    if (card != nullptr)
      tradeAr.push_back(card);
  }

  std::cout << "TradeArea with " << count
            << " cards initialized from file properly." << std::endl;
}

/**
 * @brief Destructor for the TradeArea class.
 * Deletes all Card pointers stored in the trade area.
 */
TradeArea::~TradeArea()
{
  for (Card *card : tradeAr)
  {
    delete card;
  }
  tradeAr.clear();
  std::cout << "TradeArea destroyed." << std::endl;
}

/**
 * @brief Adds a card to the trade area.
 * Does not check if it is legal to place the card.
 * @param card Pointer to the Card to add.
 * @return Reference to the updated TradeArea.
 */
TradeArea &TradeArea::operator+=(Card *card)
{
  if (this->legal(card) || tradeAr.size() < MAX_CARDS)
  {
    tradeAr.push_back(card);
  }
  else
  {
    std::cout << "The card [" << card->getName()
              << "] cannot be added to the Trade Area." << std::endl;
  }
  return *this;
}

/**
 * @brief Checks if the card can be legally added to the TradeArea.
 * A card can be legally added if a card of the same bean is already in the
 * TradeArea.
 * @param card Pointer to the Card to check.
 * @return True if the card can be legally added, false otherwise.
 */
bool TradeArea::legal(Card *card)
{
  for (Card *existingCard : tradeAr)
  {
    if (existingCard->getName() == card->getName())
      return true;
  }
  return false;
}

/**
 * @brief Removes and returns a card of the specified bean name from the trade
 * area.
 * @param cardName The name of the bean to trade.
 * @return Pointer to the Card if found, nullptr otherwise.
 */
Card *TradeArea::trade(const std::string &cardName)
{
  for (auto it = tradeAr.begin(); it != tradeAr.end(); ++it)
  {
    if ((*it)->getName() == cardName)
    {
      Card *cardFound = *it;
      tradeAr.erase(it); // Remove the card from the trade area
      return cardFound;
    }
  }
  return nullptr; // Card not found
}

/**
 * @brief Returns the number of cards currently in the trade area.
 * @return Number of cards in the trade area.
 */
int TradeArea::numCards() { return static_cast<int>(tradeAr.size()); }

/**
 * @brief Overloaded insertion operator to print the trade area.
 * @param output The output stream.
 * @param tr_arr The TradeArea object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const TradeArea &tr_arr)
{
  for (Card *card : tr_arr.tradeAr)
  {
    card->print(output);
    output << " ";
  }
  return output;
}

/**
 * @brief Saves the TradeArea to a file.
 * @param filename The output file stream to write to.
 */
void TradeArea::saveTradeArea(std::ofstream &filename)
{
  for (Card *card : tradeAr)
  {
    card->saveCard(filename);
    filename << std::endl;
  }
  std::cout << "TradeArea saved." << std::endl;
}

/**
 * @brief Returns a copy of the list of cards in the trade area.
 * @return A list of Card pointers.
 */
std::list<Card *> TradeArea::getListOfCards() { return tradeAr; }
