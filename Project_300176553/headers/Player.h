#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <vector>
#include "Hand.h"
#include "Chain.h"

class Player{
	
private:
    std::string pName;                 // player name
    Hand *pHand;                       // player hand
    std::vector<Chain_Base *> pChains; // player chains
    int pCoins;                        // number of coins held by the player
    const int MAX_NUM_CHAINS = 3;
    const int ALLOWED_CHAINS = 2;

public:
    /**
     * @brief Construct a new Player object
     *
     * @param name
     */
    Player(const std::string &name) : pName(name), pCoins(0), pHand(new Hand()) {};

    /**
     * @brief Construct a new Player object from an istream
     *
     * @param input
     * @param cf
     */
    Player(std::istream &input, const CardFactory *cf) : pCoins(0), pHand(new Hand()){
        std::string strLine;
        Card *card = nullptr;
        bool handInitialized = false;
        bool chainsInitialized = false;
        Chain_Base *currentChain = nullptr;

        while (std::getline(input, strLine)) {
        	
            if (!handInitialized) {
                if (line == "-chains") {
                    handInitialized = true;
                    continue;
                }
                card = cf->getCard(line);
                if (card) {
                    *pHand += card;
                }
            } 
			
			else if (!chainsInitialized) {
                if (strLine == "-end-chains") {
                    chainsInitialized = true;
                    continue;
                }
                if (strLine == "---") {
                    currentChain = nullptr;
                    continue;
                }
                if (!currentChain) {
                    currentChain = cf->createChain(line);
                    if (currentChain) {
                        pChains.push_back(currentChain);
                    }
                } 
				
				else {
                    card = cf->getCard(line);
                    if (card) {
                        *currentChain += card;
                    }
                }
            }
        }
    }

    /**
     * @brief Destroy the Player object
     */
    ~Player(){
        delete pHand;
        for (auto chain : pChains) {
            delete chain;
        }
    }

    /**
     * @brief Add coins to the player's total
     *
     * @param coins
     * @return Player&
     */
    Player &operator+=(int playerCoins){
        pCoins += playerCoins;
        return *this;
    }

    /**
     * @brief Access a chain by index
     *
     * @param i
     * @return Chain_Base&
     */
    Chain_Base &operator[](int t){
        return *(pChains.at(t));
    }

    void takeCard(Card *);
    Card *playCard(Card *input = nullptr, bool specified_input = false);
    Card *removeCard(int = 0);
    std::string getName() { return pName; }
    int getNumCoins() { return pCoins; }
    int getMaxNumChains() { return MAX_NUM_CHAINS; }
    int getNumChains() { return pChains.size(); }
    int getNumCards() { return pHand->numCards(); }
    Hand *getHand() { return pHand; }
    std::vector<Chain_Base *> *getChains() { return &pChains; }
    void buyThirdChain();

    /**
     * @brief Prints the player's hand to the supplied ostream
     *
     * @param output
     * @param showAll
     */
    void printHand(std::ostream &output, bool showAll){
        if (!showAll) {
            output << pHand->top()->getName()[0] << std::endl;
        } 
		else {
            for (int t = 0; t < pHand->numCards(); t++) {
                output << pHand->getCard(t)->getName()[0] << " ";
            }
            output << std::endl;
        }
    }

    friend std::ostream &operator<<(std::ostream &, const Player &);
    void savePlayer(int p_id);
    void checkEndedChains();
};

#endif
