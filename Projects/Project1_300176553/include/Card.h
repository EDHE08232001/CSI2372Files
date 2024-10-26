#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

enum class BeanType
{
    Blue,
    Chili,
    Stink,
    Green,
    Soy,
    Black,
    Red,
    Garden
};

class Card
{
public:
    // Constructor
    Card(BeanType type);

    // Virtual destructor to allow derived class cleanup
    virtual ~Card() = default;

    // Returns the number of cards needed to earn a certain number of coins
    virtual int getCardsPerCoin(int coins) const;

    // Returns the name of the bean type
    std::string getName() const;

    // Prints the first character of the bean type to the output stream
    virtual void print(std::ostream &out) const;

    // Overloading the stream insertion operator
    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    // Returns the bean type of the card
    BeanType getBeanType() const;

private:
    BeanType type;
};

#endif // CARD_H