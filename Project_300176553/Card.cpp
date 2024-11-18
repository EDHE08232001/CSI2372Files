#include "headers/Card.h"
using namespace std;

// Destructor for Card
/**
 * @brief Destructor for the Card class.
 */
Card::~Card() {}

// Blue
/**
 * @class Blue
 * @brief Represents a Blue bean card.
 */

/**
 * @brief Constructs a Blue bean card with an optional name.
 * @param name Name of the bean (default is "Blue").
 */
Blue::Blue(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Blue beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int Blue::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 4;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 10;
        break;
    default:
        cout << "(Blue) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Blue bean.
 * @return Name of the bean.
 */
string Blue::getName()
{
    return this->name;
}

/**
 * @brief Prints the Blue card representation to an output stream.
 * Outputs uppercase 'B' for Blue.
 * @param out Output stream.
 */
void Blue::print(std::ostream &out)
{
    out << 'B'; // Output uppercase 'B' for Blue
}

// Chili
/**
 * @class Chili
 * @brief Represents a Chili bean card.
 */

/**
 * @brief Constructs a Chili bean card with an optional name.
 * @param name Name of the bean (default is "Chili").
 */
Chili::Chili(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Chili beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int Chili::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 6;
        break;
    case 3:
        numCards = 8;
        break;
    case 4:
        numCards = 9;
        break;
    default:
        cout << "(Chili) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Chili bean.
 * @return Name of the bean.
 */
string Chili::getName()
{
    return this->name;
}

/**
 * @brief Prints the Chili card representation to an output stream.
 * Outputs 'C' for Chili.
 * @param out Output stream.
 */
void Chili::print(std::ostream &out)
{
    out << 'C'; // Output 'C' for Chili
}

// Stink
/**
 * @class Stink
 * @brief Represents a Stink bean card.
 */

/**
 * @brief Constructs a Stink bean card with an optional name.
 * @param name Name of the bean (default is "Stink").
 */
Stink::Stink(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Stink beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int Stink::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 7;
        break;
    case 4:
        numCards = 8;
        break;
    default:
        cout << "(Stink) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Stink bean.
 * @return Name of the bean.
 */
string Stink::getName()
{
    return this->name;
}

/**
 * @brief Prints the Stink card representation to an output stream.
 * Outputs uppercase 'S' for Stink.
 * @param out Output stream.
 */
void Stink::print(std::ostream &out)
{
    out << 'S'; // Output uppercase 'S' for Stink
}

// Green
/**
 * @class Green
 * @brief Represents a Green bean card.
 */

/**
 * @brief Constructs a Green bean card with an optional name.
 * @param name Name of the bean (default is "Green").
 */
Green::Green(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Green beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int Green::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 3;
        break;
    case 2:
        numCards = 5;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(Green) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Green bean.
 * @return Name of the bean.
 */
string Green::getName()
{
    return this->name;
}

/**
 * @brief Prints the Green card representation to an output stream.
 * Outputs uppercase 'G' for Green.
 * @param out Output stream.
 */
void Green::print(std::ostream &out)
{
    out << 'G'; // Output uppercase 'G' for Green
}

// soy
/**
 * @class soy
 * @brief Represents a Soy bean card.
 */

/**
 * @brief Constructs a Soy bean card with an optional name.
 * @param name Name of the bean (default is "soy").
 */
soy::soy(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Soy beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int soy::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 6;
        break;
    case 4:
        numCards = 7;
        break;
    default:
        cout << "(soy) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Soy bean.
 * @return Name of the bean.
 */
string soy::getName()
{
    return this->name;
}

/**
 * @brief Prints the Soy card representation to an output stream.
 * Outputs lowercase 's' for soy.
 * @param out Output stream.
 */
void soy::print(std::ostream &out)
{
    out << 's'; // Output lowercase 's' for soy
}

// black
/**
 * @class black
 * @brief Represents a Black bean card.
 */

/**
 * @brief Constructs a Black bean card with an optional name.
 * @param name Name of the bean (default is "black").
 */
black::black(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Black beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int black::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 4;
        break;
    case 3:
        numCards = 5;
        break;
    case 4:
        numCards = 6;
        break;
    default:
        cout << "(black) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Black bean.
 * @return Name of the bean.
 */
string black::getName()
{
    return this->name;
}

/**
 * @brief Prints the Black card representation to an output stream.
 * Outputs lowercase 'b' for black.
 * @param out Output stream.
 */
void black::print(std::ostream &out)
{
    out << 'b'; // Output lowercase 'b' for black
}

// Red
/**
 * @class Red
 * @brief Represents a Red bean card.
 */

/**
 * @brief Constructs a Red bean card with an optional name.
 * @param name Name of the bean (default is "Red").
 */
Red::Red(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Red beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int Red::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 2;
        break;
    case 2:
        numCards = 3;
        break;
    case 3:
        numCards = 4;
        break;
    case 4:
        numCards = 5;
        break;
    default:
        cout << "(Red) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Red bean.
 * @return Name of the bean.
 */
string Red::getName()
{
    return this->name;
}

/**
 * @brief Prints the Red card representation to an output stream.
 * Outputs 'R' for Red.
 * @param out Output stream.
 */
void Red::print(std::ostream &out)
{
    out << 'R'; // Output 'R' for Red
}

// garden
/**
 * @class garden
 * @brief Represents a Garden bean card.
 */

/**
 * @brief Constructs a Garden bean card with an optional name.
 * @param name Name of the bean (default is "garden").
 */
garden::garden(std::string name)
{
    this->name = name;
}

/**
 * @brief Gets the number of cards required for a certain number of coins for Garden beans.
 * @param coins Number of coins.
 * @return Number of cards required, or -1 if invalid.
 */
int garden::getCardsPerCoin(int coins)
{
    int numCards = -1; // Default to -1 indicating invalid input
    switch (coins)
    {
    case 1:
        numCards = 0;
        break;
    case 2:
        numCards = 2;
        break;
    case 3:
        numCards = 3;
        break;
    case 4:
        numCards = 0;
        break;
    default:
        cout << "(garden) - Invalid number of coins passed to getCardsPerCoin. Value received: " << coins << endl;
        break;
    }

    return numCards;
}

/**
 * @brief Gets the name of the Garden bean.
 * @return Name of the bean.
 */
string garden::getName()
{
    return this->name;
}

/**
 * @brief Prints the Garden card representation to an output stream.
 * Outputs lowercase 'g' for garden.
 * @param out Output stream.
 */
void garden::print(std::ostream &out)
{
    out << 'g'; // Output lowercase 'g' for garden
}

/**
 * @brief Overloaded insertion operator to display the card object.
 * Calls the card's print method.
 * @param out Output stream.
 * @param card Card to be printed.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, Card &card)
{
    card.print(out);
    return out;
}

/**
 * @brief Writes the card representation to a file.
 * @param filename Output file stream.
 */
void Card::saveCard(std::ofstream &filename)
{
    filename << *this; // Use the overloaded operator<<
}
