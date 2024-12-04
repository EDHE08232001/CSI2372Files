#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <queue>
#include <list>
#include <sstream>
#include <cstdlib>
#include <memory>

class CardFactory;

class Hand{
	
private:
    std::queue<Card *, std::list<Card *>> pHand; // player hand

public:
    /**
     * @brief Construct a new Hand object
     */
    Hand() = default;

    /**
     * @brief Construct a new Hand object from an istream
     *
     * @param input
     * @param cf
     */
    Hand(std::istream &input, const CardFactory *cf){
        std::string strLine;
        
        while (std::getline(input, strLine)) {
            Card *card = nullptr;
            
            if (strLine == "B"){
				card = new Blue;
			}
			
            else if (strLine == "C"){
				card = new Chili;
			}
			
            else if (strLine == "S"){
				card = new Stink;
			}
			
            else if (strLine == "G"){
				card = new Green;
			}
			
            else if (strLine == "s"){ 
				card = new soy;
			}
			
            else if (strLine == "b"){
				card = new black;
			}
			
            else if (strLine == "R"){
				card = new Red;
			}
			
            else if (strLine == "g"){
				card = new garden;
			}
			
            else {
                std::cerr << "(Hand Constructor) Invalid card type: " << strLine << std::endl;
                std::exit(1);
            }
            pHand.push(card);
        }
    }

    /**
     * @brief Add the card to the hand
     *
     * @param card
     * @return Hand&
     */
    Hand &operator+=(Card *card){
        pHand.push(card);
        return *this;
    }

    /**
     * @brief Returns and removes the Card at a given index
     *
     * @param pos
     * @return Card*
     */
    Card *operator[](int pos){
        if (pos < 0 || pos >= pHand.size()) {
            std::cerr << "(operator[]) Invalid index: " << pos << std::endl;
            return nullptr;
        }

        std::queue<Card *, std::list<Card *>> temp;
        Card *targetCard = nullptr;
        int currentIndex = 0;

        while (!pHand.empty()) {
            Card *currentCard = pHand.front();
            pHand.pop();
            if (currentIndex == pos) {
                targetCard = currentCard;
            } else {
                temp.push(currentCard);
            }
            currentIndex++;
        }

        pHand = temp;
        return targetCard;
    }

    /**
     * @brief Returns and removes the top card from the hand
     *
     * @return Card*
     */
    Card *play();

    /**
     * @brief Returns the top card from the hand without removing it
     *
     * @return Card*
     */
    Card *top();

    /**
     * @brief Returns the card at the specified index
     *
     * @param pos
     * @return Card*
     */
    Card *getCard(int pos);

    /**
     * @brief Returns the number of cards in the hand
     *
     * @return int
     */
    int numCards() { return pHand.size(); }

    /**
     * @brief Get the list of cards in the hand
     *
     * @return std::queue<Card *, std::list<Card *>>*
     */
    std::queue<Card *, std::list<Card *>> *getListOfCards() { return &pHand; }

    /**
     * @brief Insertion operator to display the content of the Hand object
     *
     * @param output
     * @param hand
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &output, Hand &hand);

    /**
     * @brief Saves the cards in the hand to a file
     *
     * @param filename
     */
    void saveHand(std::ofstream &filename);
};

#endif
