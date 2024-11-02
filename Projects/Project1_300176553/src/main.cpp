#include <iostream>
#include "../include/Card.h"

void testCard(Card* card) {
    // Test getName()
    std::cout << "Testing card: " << card->getName() << "\n";
    
    // Test getCardsPerCoin() with different coin values
    std::cout << "Cards required for 1 coin: " << card->getCardsPerCoin(1) << "\n";
    std::cout << "Cards required for 2 coins: " << card->getCardsPerCoin(2) << "\n";
    std::cout << "Cards required for 3 coins: " << card->getCardsPerCoin(3) << "\n";
    std::cout << "Cards required for 4 coins: " << card->getCardsPerCoin(4) << "\n";

    // Test print() and operator<<
    std::cout << "Card print symbol: ";
    card->print(std::cout);  // Directly calling print method
    std::cout << "\n";
    
    std::cout << "Card using << operator: " << *card << "\n\n";
}

int main() {
    // Instantiate each derived class and test
    Blue blueCard;
    Chili chiliCard;
    Stink stinkCard;
    Green greenCard;
    Soy soyCard;
    Black blackCard;
    Red redCard;
    Garden gardenCard;

    // Run tests for each card type
    testCard(&blueCard);
    testCard(&chiliCard);
    testCard(&stinkCard);
    testCard(&greenCard);
    testCard(&soyCard);
    testCard(&blackCard);
    testCard(&redCard);
    testCard(&gardenCard);

    return 0;
}
