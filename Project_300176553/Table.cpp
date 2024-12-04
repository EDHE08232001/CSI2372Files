#include "headers/Table.h"
#include <fstream>
#include <iostream>

/**
 * @brief Returns true if a player has won. The name of the player is returned by reference.
 *
 * @param pName
 * @return true if there is a winner, otherwise false
 */
 
bool Table::win(std::string &pName){
    if (deck->size() == 0) {
    	
        if (p1->getNumCoins() > p2->getNumCoins()) {
            pName = p1->getName();
            
        } 
		
		else if (p1->getNumCoins() < p2->getNumCoins()) {
            pName = p2->getName();
            
        } 
		
		else {
            pName = "Equality";
            
        }
        
        return true;
    }
    return false;
}


/**
 * @brief Prints the top card of the player's hand (if argument is false) or all of the player's hand (if argument is true).
 *
 * @param in
 */
 
void Table::printHand(bool allIn){
    Player *current = currentPlayer == 0 ? p1 : p2;
    current->printHand(std::cout, allIn);
}


/**
 * @brief Returns player p1 if id is 0, otherwise returns player p2.
 *
 * @param id
 * @return Player*
 */
 
Player *Table::getPlayer(int pID){
    currentPlayer = pID;
    return (pID == 0) ? p1 : p2;
}


/**
 * @brief Insertion operator to display the table information.
 *
 * @param output
 * @param tb
 * @return std::ostream&
 */
 
std::ostream &operator<<(std::ostream &output, const Table &tb){
    output << "> Player 1 : \n\n" << *(tb.p1) << "\n"
           << "> Player 2 : \n\n" << *(tb.p2) << "\n"
           << "> Discard Pile (Top) : " << *tb.dp << "\n\n"
           << "> Trade Area : " << *tb.tradeAr << "\n"
           << "_______________________\n";
           
    return output;
}


/**
 * @brief Writes the game state to related files.
 */
 
void Table::saveTable(){
    deck->saveDeck(std::ofstream("Saved-Deck.txt", std::ios::trunc));
    dp->saveDiscardPile(std::ofstream("Saved-DiscardPile.txt", std::ios::trunc));
    tradeAr->saveTradeArea(std::ofstream("Saved-TradeArea.txt", std::ios::trunc));
    p1->savePlayer(1);
    p2->savePlayer(2);
}


/**
 * @brief Reloads player information from the saved file.
 *
 * @param p_id
 */
 
void Table::reloadPlayer(int player_id){
    std::ifstream file("Saved-P" + std::to_string(player_id) + ".txt");
    if (file.is_open()) {
        if (player_id == 1) {
            p1 = new Player(file, cf);
        } 
		
		else {
            p2 = new Player(file, cf);
        }
    }
    
    file.close();
}


/**
 * @brief Reloads the saved deck from a file.
 */
 
void Table::reloadDeck(){
    std::ifstream deckFile("Saved-Deck.txt");
    if (deckFile.is_open()) {
        deck = new Deck(deckFile, cf);
    } 
	
	else {
        deck = cf->getDeck();
        std::cout << "Saved-Deck.txt not found. The deck has been generated from the CardFactory." << std::endl;
    }
}


/**
 * @brief Reloads the discard pile from the saved file.
 */
 
void Table::reloadDiscardPile(){
    std::ifstream dpFile("Saved-DiscardPile.txt");
    if (dpFile.is_open()) {
        dp = new DiscardPile(dpFile, cf);
    } 
	
	else {
        dp = new DiscardPile;
        std::cout << "Saved-DiscardPile.txt not found. Using empty discard pile." << std::endl;
    }
}


/**
 * @brief Reloads the trade area from the saved file.
 */
 
void Table::reloadTradeArea(){
    std::ifstream trArFile("Saved-TradeArea.txt");
    if (trArFile.is_open()) {
        tradeAr = new TradeArea(trArFile, cf);
    } 
	
	else {
        tradeAr = new TradeArea;
        std::cout << "Saved-TradeArea.txt not found. Using empty trade area." << std::endl;
    }
}


/**
 * @brief Returns the deck initialized in the table object.
 *
 * @return Deck*
 */
 
Deck *Table::getDeck(){
    if (!deck) {
        deck = cf->getDeck();
    }
    
    return deck;
}


/**
 * @brief Returns the discard pile of the table.
 *
 * @return DiscardPile*
 */
 
DiscardPile *Table::getDiscardPile(){
    return dp;
}


/**
 * @brief Returns the trade area of the table.
 *
 * @return TradeArea*
 */
 
TradeArea *Table::getTradeArea(){
    return tradeAr;
}
