#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

/*
 *  deck.h
 *  Blackjack
 *
 *  Created by Lucas Kjaero on 3/28/10.
 *
 *  This file is part of lucasBlackjack.
 *
 *  lucasBlackjack is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  lucasBlackjack is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with lucasBlackjack.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <cstdlib>
#include <ctime>

class deck {
private:
	int diamonds[13];
	int spades[13];
	int hearts[13];
	int clubs[13];
	
	void newDeck();
	
	int removeOne(int number);
	
public:
	deck();
	
	int draw();
};

deck::deck() {
	// Seeds the random number generator
	srand((unsigned)time(0));
	
	// Gets you started with a full deck
	newDeck();
}
void deck::newDeck() {
	for (int i = 0; i <= 13; i++) {
		diamonds[i] = 8;
		spades[i] = 8;
		hearts[i] = 8;
		clubs[i] = 8;
	}
	std::cout << "Deck is empty, reshuffling." << std::endl;
}

int deck::draw() {
	int numberChoice;
	int failcount = 0;
	bool done = 0;
	
	while (!done) {
		numberChoice = rand();
		numberChoice = numberChoice % 13;
		numberChoice++;
		
		bool returnStatus;
		returnStatus = removeOne(numberChoice);
		
		if (returnStatus == 0) {
			done = 1;
		}
		else {
			failcount++;
		}
		
		if (failcount >= 5) {
			for (int i = 13; i >= 1; i--) {
				returnStatus = removeOne(i);
				if (returnStatus == 0) {
					done = 1;
					break;
				}
				if (i == 1) {
					newDeck();
				}
			}
		}
	}
	return numberChoice;
}
int deck::removeOne(int number) {
    int faceChoice;
	//std::cout << "Entering RemoveOne" << std::endl;
	
	for (int i = 1; i <= 4; i++) {
		faceChoice = rand();
		faceChoice = (faceChoice % 4) + 1;
		
		switch (faceChoice) {
			case 1:
				// diamonds
				if (diamonds[number] > 0) {
					diamonds[number] -= 1;
					//std::cout << "Exiting RemoveOne" << std::endl;
					//std::cout << "The face chosen was a diamond." << std::endl;
					return 0;
				}
				else {
					faceChoice = 4;
					continue;
				}
				break;
			case 2:
				// spades
				if (spades[number] > 0) {
					spades[number] -= 1;
					//std::cout << "Exiting RemoveOne" << std::endl;
					//std::cout << "The face chosen was a spade." << std::endl;
					return 0;
				}
				else {
					faceChoice--;
					continue;
				}
				break;
			case 3:
				// hearts
				if (hearts[number] > 0) {
					hearts[number] -= 1;
					//std::cout << "Exiting RemoveOne" << std::endl;
					//std::cout << "The face chosen was a heart." << std::endl;
					return 0;
				}
				else {
					faceChoice--;
					continue;
				}
				break;
			case 4:
				// clubs
				if (clubs[number] > 0) {
					clubs[number] -= 1;
					//std::cout << "Exiting RemoveOne" << std::endl;
					//std::cout << "The face chosen was a club." << std::endl;
					return 0;
				}
				else {
					faceChoice--;
					continue;
				}
				break;
				
			default:
				break;
		}
	}
	
	// If we've gotten this far, the cardnumber has none left. So, we return 1 to indicate a failure.
	//std::cout << "Cardnumber " << number << " has no cards left." << std::endl << "Exiting DrawOne." << std::endl;
	return 1;
}

#endif // DECK_H_INCLUDED