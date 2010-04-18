/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

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
