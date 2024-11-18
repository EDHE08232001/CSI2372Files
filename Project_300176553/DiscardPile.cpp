#include "headers/DiscardPile.h"

/**
 * @brief Constructs a DiscardPile object from an input stream.
 * Reconstructs the DiscardPile from saved data.
 * @param input The input stream to read from.
 * @param cf Pointer to the CardFactory (currently unused).
 *
 * This constructor reads card data from the input stream, creates corresponding
 * Card objects, and adds them to the DiscardPile.
 */
DiscardPile::DiscardPile(std::istream &input, const CardFactory *cf) : std::vector<Card *>()
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
            std::cout << "(DiscardPile Constructor) Check the card name in the file. Value received: " << data << std::endl;
            exit(1);
        }
        // Add the card to the DiscardPile
        if (card != nullptr)
            this->push_back(card);
    }

    std::cout << "DiscardPile with " << count << " cards initialized from file properly." << std::endl;
}

/**
 * @brief Destructor for the DiscardPile class.
 * Deletes all Card pointers stored in the DiscardPile.
 */
DiscardPile::~DiscardPile()
{
    for (size_t i = 0; i < this->size(); i++)
    {
        delete this->at(i);
    }
    std::cout << "DiscardPile of size(" << this->size() << ") destroyed." << std::endl;
}

/**
 * @brief Adds a card to the discard pile using the operator +=.
 * @param c Pointer to the Card to add.
 * @return Reference to the updated DiscardPile.
 */
DiscardPile &DiscardPile::operator+=(Card *c)
{
    this->push_back(c);
    return *this;
}

/**
 * @brief Returns and removes the top card from the discard pile.
 * @return Pointer to the top Card.
 */
Card *DiscardPile::pickUp()
{
    if (this->empty())
        return nullptr;

    Card *card = this->back(); // Get the last card
    this->pop_back();          // Remove the last card
    return card;
}

/**
 * @brief Returns but does not remove the top card from the discard pile.
 * @return Pointer to the top Card.
 */
Card *DiscardPile::top()
{
    if (this->empty())
        return nullptr;

    return this->back();
}

/**
 * @brief Inserts all the cards in the DiscardPile to the output stream.
 * @param os The output stream to write to.
 *
 * This method prints all the cards in the DiscardPile in order.
 */
void DiscardPile::print(std::ostream &os)
{
    for (size_t i = 0; i < this->size(); i++)
    {
        this->at(i)->print(os);
        os << " ";
    }
}

/**
 * @brief Overloaded insertion operator to display the top card of the discard pile.
 * @param output The output stream.
 * @param dp The DiscardPile object to print.
 * @return Reference to the output stream.
 *
 * This operator prints only the top card of the discard pile.
 */
std::ostream &operator<<(std::ostream &output, const DiscardPile &dp)
{
    if (!dp.empty())
        dp.back()->print(output);
    else
        output << "";

    return output;
}

/**
 * @brief Saves the DiscardPile to a file.
 * @param filename The output file stream to write to.
 */
void DiscardPile::saveDiscardPile(std::ofstream &filename)
{
    for (size_t i = 0; i < this->size(); i++)
    {
        this->at(i)->saveCard(filename);
        filename << std::endl;
    }
    std::cout << "Discard Pile saved." << std::endl;
}
