#include "header/Player.h"
#include <string>
#include <iomanip>
#include <stdexcept>

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Player::getName(){
	return this->pName;
}


/**
 * @brief Get the number of cards in the hand of the player
 *
 * @return int
 */

int Player::getNumCards(){
    return pHand->numCards();
}


/**
 * @brief Create or add to a chain when a card is played and return the card
 *
 * @return Card*
 */
Card *Player::playCard(Card *input, bool specifiedInput){
	if (pHand -> numCard() <= 0) {
		std::cout << "(PlayCard) Not enough cards in hand for player: " << pName << std::endl;
		return nullptr;
	}
	
	Card *card = specifiedInput ? input : pHand -> top();
	Chain_Base *targetChain = nullptr;
	
	// Checking if the chain already exists
	for (Chain_Base *chain : pChains){
		if (chain -> getChainType() == card -> getName()){
			targetChain = chain;
			card = specifiedInput ? card : pHand -> play();
			*targetChain += card;
			return card;
		}
	}
	
	// If there is no existing chain, we create a new one
	targetChain = createChain(card -> getName());
	if (!targetChain){
		std::cout << "(playCard) Check the card name. Value received: " << card -> getName() << std:: endl;
		exit (1);
	}
	
	if (pChains.size() >= MAX_NUM_CHAINS){
		sellChain(pChains.front());
		pChains.erase(pChains.begin());	
	}
	
	pChains.push_back(targetChain);
	card = pHand -> play();
	*targetChain += card;
	
	return card;
}

/**
 * @brief Create a chain based on the card type
 *
 * @return Chain_Base*
 */
Chain_Base* Player::createChain(const std::string &cardType){
    if (cardType == "Blue"){ 
		return new Chain<Blue>;
	}
	
    if (cardType == "Chili"){
		return new Chain<Chili>;
	}
	
    if (cardType == "Stink"){
		return new Chain<Stink>;
	}
	
    if (cardType == "Green"){
		return new Chain<Green>;
	}
	
    if (cardType == "soy"){
		return new Chain<soy>;
	}
	
    if (cardType == "black"){
		return new Chain<black>;
	}
	
    if (cardType == "Red"){
		return new Chain<Red>;
	}
	
    if (cardType == "garden"){
		return new Chain<garden>;
	}
	
    return nullptr;
}

/**
 * @brief Sell a chain and add coins to the player
 *
 */
void Player::sellChain(Chain_Base *chain){
    if (!chain) return;

    std::cout << "Player " << pName << " has reached the maximum value of chains." << std::endl;
    std::cout << "> Selling Chain of type: " << chain->getChainType() << std::endl;

    if (chain->getChainType() == "Blue"){
		pCoins += dynamic_cast<Chain<Blue> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "Chili"){
		pCoins += dynamic_cast<Chain<Chili> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "Stink"){
		pCoins += dynamic_cast<Chain<Stink> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "Green"){
		pCoins += dynamic_cast<Chain<Green> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "soy"){
		pCoins += dynamic_cast<Chain<soy> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "black"){
		pCoins += dynamic_cast<Chain<black> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "Red"){
		pCoins += dynamic_cast<Chain<Red> *>(chain)->sell();
	}
	
    else if (chain->getChainType() == "garden"){
		pCoins += dynamic_cast<Chain<garden> *>(chain)->sell();
	}
	
    else {
        std::cout << "(sellChain) Check the chain type. Value received: " << chain->getChainType() << std::endl;
        exit(1);
    }
}

/**
 * @brief Get the maximum number of chains allowed for the player
 *
 * @return int
 */
int Player::getMaxNumChains(){
    return MAX_NUM_CHAINS;
}

/**
 * @brief Get the number of non-empty chains the player possesses
 *
 * @return int
 */
int Player::getNumChains(){
    int counterInt = 0;
    for (Chain_Base *chain : pChains) {
        if (chain->getSize() > 0) counterInt++;
    }
    return counterInt;
}

/**
 * @brief Add a card to the player's hand
 *
 * @param card
 */
void Player::takeCard(Card *card){
    *pHand += card;
}

/**
 * @brief Remove the top card from the hand at the specified position
 *
 * @return Card*
 */
Card *Player::removeCard(int specifiedPosition){
    if (specifiedPosition >= pHand->numCards()) {
        std::cout << "Please specify the proper index to remove from the pHand. Entered idx: " << specifiedPosition << std::endl;
        return nullptr;
    }
    return (*pHand)[specifiedPosition];
}

/**
 * @brief Get the number of coins the player has
 *
 * @return int
 */
int Player::getNumCoins(){
    return pCoins;
}

/**
 * @brief Save player information to a text file
 *
 * @param player_id Player ID during the game
 */
void Player::savePlayer(int player_id){
    std::ofstream file;
    file.open("Saved-P" + std::to_string(player_id) + ".txt", std::ios::trunc);

    // Saving the player details
    file << pName << std::endl;
    file << pCoins << std::endl;

    // Saving the hand
    pHand->saveHand(file);

    file << "\n-chains" << std::endl;
    for (Chain_Base *chain : pChains) {
        file << "\n---" << std::endl;
        chain->saveChain(file);
    }
    file << "\n-end-chains" << std::endl;
    file.close();

    std::cout << "Player-" << player_id << " saved." << std::endl;
}

/**
 * @brief Get the hand of the player
 *
 * @return Hand*
 */
Hand *Player::getHand(){
    return pHand;
}

/**
 * @brief Get the chains of the player
 *
 * @return std::vector<Chain_Base *>*
 */
std::vector<Chain_Base *> *Player::getChains(){
    return &pChains;
}
