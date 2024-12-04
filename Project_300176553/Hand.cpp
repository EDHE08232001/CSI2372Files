#include "headers/Hand.h"
#include <queue>
#include <list>
#include <iostream>
#include <fstream>

/**
 * @brief Returns and removes the top card from the player's hand.
 *
 * @return Card*
 */
 
Card *Hand::play(){
    if (pHand.empty()) {
        std::cout << "(play) No cards left in hand." << std::endl;
        return nullptr;
    }
    Card *card = pHand.front();
    pHand.pop(); // remove the first element
    return card;
}


/**
 * @brief Returns the top card from the hand without removing it.
 *
 * @return Card*
 */
 
Card *Hand::top(){
    if (pHand.empty()) {
        std::cout << "(top) No cards left in hand." << std::endl;
        return nullptr;
    }
    return pHand.front();
}


/**
 * @brief Returns the number of cards contained in the hand.
 *
 * @return int
 */
 
int Hand::numCards(){
    return pHand.size();
}


/**
 * @brief Returns the card at the specified index.
 *
 * @param pos
 * @return Card*
 */
 
Card *Hand::getCard(int specifiedIndex){
    if (specifiedIndex < 0 || specifiedIndex >= pHand.size()) {
        std::cout << "(getCard) The index " << specifiedIndex << " is out of range. Current size of the hand = " << pHand.size() << std::endl;
        return nullptr;
    }

    std::queue<Card *, std::list<Card *>> temporary;
    Card *targetCard = nullptr;
    int currentIndex = 0;

    while (!pHand.empty()) {
        Card *currentCard = pHand.front();
        pHand.pop();
        if (currentIndex == specifiedIndex) {
            targetCard = currentCard;
        }
        temporary.push(currentCard);
        currentIndex++;
    }

    // Restore original queue without modifying order
    pHand = temporary; 
    return targetCard;
}


/**
 * @brief Insertion operator to display the content of the Hand object.
 *
 * @param output
 * @param hand
 * @return std::ostream&
 */
 
std::ostream &operator<<(std::ostream &output, Hand &hand){
    std::queue<Card *, std::list<Card *>> temporary = hand.pHand;
    while (!temporary.empty()) {
        output << temporary.front() << std::endl;
        temporary.pop();
    }
    return output;
}


/**
 * @brief Write the cards inside the hand to a file.
 *
 */
 
void Hand::saveHand(std::ofstream &filename){
    std::queue<Card *, std::list<Card *>> temp = pHand;
    while (!temp.empty()) {
        Card *currentCard = temp.front();
        currentCard->saveCard(filename);
        filename << std::endl;
        temp.pop();
    }

    std::cout << "Hand saved." << std::endl;
}


/**
 * @brief Get the list of cards inside the hand.
 *
 * @return std::queue<Card *, std::list<Card *>>
 */
 
std::queue<Card *, std::list<Card *>> *Hand::getListOfCards(){
    return &pHand;
}
