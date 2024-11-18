#include "headers/Deck.h"
using namespace std;

/**
 * @brief Constructs a Deck object from an input stream.
 * Reconstructs the Deck from saved data.
 * @param input The input stream to read from.
 * @param cf Pointer to the CardFactory (currently unused).
 *
 * This constructor reads card data from the input stream, creates corresponding
 * Card objects, and adds them to the Deck.
 */
Deck::Deck(std::istream &input, const CardFactory *cf) : std::vector<Card *>()
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
            std::cout << "(Deck Constructor) Check the card name in the file. Value received: " << data << std::endl;
            exit(1);
        }
        // Add the card to the Deck
        if (card != nullptr)
            this->push_back(card);

        count++;
    }

    std::cout << "Deck with " << count << " cards initialized from file properly." << std::endl;
}

/**
 * @brief Copy constructor for the Deck class.
 * Creates a copy of the Deck.
 * @param d The Deck object to copy from.
 *
 * Note: This performs a shallow copy of the Card pointers. Be cautious as multiple
 * Decks may point to the same Card objects, leading to potential issues on deletion.
 */
Deck::Deck(const Deck &d)
{
    // Clear the items from the current Deck
    this->clear();
    // Copy the items from d into this Deck
    for (size_t i = 0; i < 104 && i < d.size(); i++)
    {
        // Shallow copy of pointers
        this->push_back(d.at(i));
    }
    std::cout << "Deck of size(" << d.size() << ") copied." << std::endl;
}

/**
 * @brief Destructor for the Deck class.
 * Deletes all Card pointers stored in the Deck.
 *
 * Note: Deleting the cards here assumes that the Deck owns the Card objects.
 * If CardFactory manages the lifetime of the cards, this could lead to double deletion.
 */
Deck::~Deck()
{
    for (size_t i = 0; i < this->size(); i++)
    {
        // Delete each Card object
        delete this->at(i);
    }
    std::cout << "Deck of size(" << this->size() << ") destroyed." << std::endl;
}

/**
 * @brief Draws and removes the top card from the Deck.
 * @return Pointer to the drawn Card.
 */
Card *Deck::draw()
{
    Card *card = this->back(); // Get the last added card
    this->pop_back();          // Remove the last element from the Deck
    return card;
}

/**
 * @brief Assignment operator for the Deck class.
 * Copies the contents of one Deck to another.
 * @param d The Deck object to assign from.
 * @return Reference to the assigned Deck.
 *
 * Performs a shallow copy of the Card pointers.
 */
Deck &Deck::operator=(const Deck &d)
{
    // Clear the current Deck
    this->clear();
    // Copy the items from d into this Deck
    for (size_t i = 0; i < d.size() && i < 104; i++)
    {
        // Shallow copy of pointers
        this->push_back(d[i]);
    }
    return *this;
}

/**
 * @brief Overloaded insertion operator to display the Deck.
 * Prints all cards in the Deck to the output stream.
 * @param output The output stream.
 * @param d The Deck object to print.
 * @return Reference to the output stream.
 */
ostream &operator<<(ostream &output, const Deck &d)
{
    for (size_t i = 0; i < d.size(); i++)
    {
        output << d.at(i)->getName()[0] << endl;
    }
    return output;
}

/**
 * @brief Saves the Deck to a file.
 * @param filename The output file stream to write to.
 */
void Deck::saveDeck(std::ofstream &filename)
{
    for (size_t i = 0; i < this->size(); i++)
    {
        this->at(i)->saveCard(filename);
        filename << std::endl;
    }
    std::cout << "Deck saved." << std::endl;
}
