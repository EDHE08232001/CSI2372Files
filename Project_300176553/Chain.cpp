#include "headers/Chain.h"
#include <iomanip>

/**
 * @brief Returns the number of cards in the chain.
 * @return Number of cards in the chain.
 */
int Chain_Base::getSize()
{
    return static_cast<int>(chain.size());
}

/**
 * @brief Sets the type of the chain.
 * @param chainType The chain type to set.
 */
void Chain_Base::setChainType(std::string chainType)
{
    this->chainType = chainType;
}

/**
 * @brief Gets the type of the chain.
 * @return The chain type as a string.
 */
std::string Chain_Base::getChainType()
{
    return chainType;
}

/**
 * @brief Saves the chain to a file.
 * @param filename The output file stream to write to.
 */
void Chain_Base::saveChain(std::ofstream &filename)
{
    filename << chainType << std::endl;
    for (size_t i = 0; i < chain.size(); i++)
    {
        chain.at(i)->saveCard(filename);
    }
    std::cout << "Chain saved." << std::endl;
}

/**
 * @brief Overloaded insertion operator to display the chain information.
 * @param output The output stream.
 * @param d The Chain_Base object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const Chain_Base &d)
{
    output << d.chainType << " ";
    for (size_t i = 0; i < d.chain.size(); i++)
    {
        d.chain.at(i)->print(output);
        output << " ";
    }
    return output;
}
