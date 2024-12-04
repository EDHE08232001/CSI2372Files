#ifndef CARD_H
#define CARD_H

#include <fstream>
#include <iostream>

/**
 * @brief Abstract base class representing a generic bean card.
 */
class Card
{
public:
  /**
   * @brief Pure virtual function to get the number of cards required for a
   * certain number of coins.
   * @param coins Number of coins.
   * @return Number of cards required.
   */
  virtual int getCardsPerCoin(int coins) = 0;

  /**
   * @brief Pure virtual function to get the name of the bean.
   * @return Name of the bean.
   */
  virtual std::string getName() = 0;

  /**
   * @brief Pure virtual function to print the card representation to an output
   * stream.
   * @param out Output stream.
   */
  virtual void print(std::ostream &out) = 0;

  /**
   * @brief Virtual destructor for Card.
   */
  virtual ~Card();

  /**
   * @brief Saves the card to a file.
   * @param filename Output file stream.
   */
  void saveCard(std::ofstream &filename);

  /**
   * @brief Insertion operator to display the first character of the card name.
   * @param output Output stream.
   * @return Reference to the output stream.
   * @note This operator is defined as a member function, but it's generally
   * better to overload operator<< as a non-member function.
   */
  std::ostream &operator<<(std::ostream &output)
  {
    output << getName()[0] << std::endl;
    return output;
  }
};

/**
 * @brief Class representing a Blue bean card.
 */
class Blue : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Blue bean card with an optional name.
   * @param name Name of the bean (default is "Blue").
   */
  Blue(std::string name = "Blue");

  /**
   * @brief Gets the number of cards required for a certain number of coins.
   * @param coins Number of coins.
   * @return Number of cards required.
   */
  int getCardsPerCoin(int coins);

  /**
   * @brief Gets the name of the bean.
   * @return Name of the bean.
   */
  std::string getName();

  /**
   * @brief Prints the card representation to an output stream.
   * @param out Output stream.
   */
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Chili bean card.
 */
class Chili : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Chili bean card with an optional name.
   * @param name Name of the bean (default is "Chili").
   */
  Chili(std::string name = "Chili");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Stink bean card.
 */
class Stink : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Stink bean card with an optional name.
   * @param name Name of the bean (default is "Stink").
   */
  Stink(std::string name = "Stink");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Green bean card.
 */
class Green : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Green bean card with an optional name.
   * @param name Name of the bean (default is "Green").
   */
  Green(std::string name = "Green");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Soy bean card.
 */
class soy : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Soy bean card with an optional name.
   * @param name Name of the bean (default is "soy").
   */
  soy(std::string name = "soy");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Black bean card.
 */
class black : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Black bean card with an optional name.
   * @param name Name of the bean (default is "black").
   */
  black(std::string name = "black");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Red bean card.
 */
class Red : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Red bean card with an optional name.
   * @param name Name of the bean (default is "Red").
   */
  Red(std::string name = "Red");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

/**
 * @brief Class representing a Garden bean card.
 */
class garden : public virtual Card
{
  std::string name; /**< Name of the bean */

public:
  /**
   * @brief Constructs a Garden bean card with an optional name.
   * @param name Name of the bean (default is "garden").
   */
  garden(std::string name = "garden");

  int getCardsPerCoin(int coins);
  std::string getName();
  void print(std::ostream &out);
};

#endif // CARD_H
