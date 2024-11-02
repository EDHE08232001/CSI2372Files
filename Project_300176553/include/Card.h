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

// Abstract base class Card
class Card
{
public:
    virtual ~Card() = default;

    // Pure virtual functions
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual std::string getName() const = 0;
    virtual void print(std::ostream &out) const = 0;

    // Friend global insertion operator using the virtual friend function idiom
    friend std::ostream &operator<<(std::ostream &out, const Card &card)
    {
        card.print(out);
        return out;
    }
};

// Derived classes

class Blue : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Chili : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Stink : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Green : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Soy : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Black : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Red : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

class Garden : public Card
{
public:
    int getCardsPerCoin(int coins) const override;
    std::string getName() const override;
    void print(std::ostream &out) const override;
};

#endif // CARD_H
