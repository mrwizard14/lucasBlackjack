/*
 To do:
 Linked list solution for "what if I draw multiple aces?"
 */

#include <iostream>

#include "dealer.h"
#include "deck.h"
#include "interfaceHandler.h"
#include "moneyHandler.h"

using namespace std;

int main (int argc, char * const argv[]) {
    dealer mainDealer;
	deck mainDeck;
	interfaceHandler mainInterfaceHandler;
	moneyHandler mainMoneyHandler;
	
	mainDealer.getDeck(&mainDeck);
	mainDealer.getInterfaceHandler(&mainInterfaceHandler);
	mainDealer.getMoneyHandler(&mainMoneyHandler);
	
	mainDealer.takeDifficulty(1);
	
	bool done = 0;
	
	do {
		int choice;
		choice = mainInterfaceHandler.displayMenu();
		//cout << "The option chosen was " << choice << "." << std::endl;
		if (choice == 1) {
			bool playAgain;
			do {
				mainDealer.newGame();
				playAgain = mainInterfaceHandler.playAgain();
			} while (playAgain);
		}
		if (choice == 2) {
			int difficulty;
			difficulty = mainInterfaceHandler.displayDifficulty();
			mainDealer.takeDifficulty(difficulty);
		}
		if (choice == 3) {
			done = 1;
			std::cout << "Goodbye" << std::endl;
		}
	} while (!done);
	
    return 0;
}
