#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

/*
 *  dealer.h
 *  Blackjack
 *
 *  Created by Lucas Kjaero on 3/28/10. 
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

#include <sstream> // istringstream, ostringstream

#include "deck.h"
#include "interfaceHandler.h"
#include "moneyHandler.h"
#include "testResults.h"

class dealer {
private:
	deck * ptrDeck;
	interfaceHandler * ptrInterfaceHandler;
	moneyHandler * ptrMoneyHandler;
	testResults * caseTestResults;
	
	int difficulty;
	int hit;
	int stay;
	
	int firstPlayerValue;
	int secondPlayerValue;
	
	int firstDealerValue;
	int secondDealerValue;
	
	int checkIfBusted(int firstValue, int secondValue);
	
	std::string numberToString(int input);
public:
	dealer();
	void getDeck(deck * dealerDeck);
	void getInterfaceHandler(interfaceHandler * dealerInterfaceHandler);
	void getMoneyHandler(moneyHandler * dealerMoneyHandler);
	
	void takeDifficulty(int difficultyLevel);
	
	void newRound();
	void addPlayerCard(int value);
	void addDealerCard(int value);
	
	void newGame();
	
	void checkValues(int hit, int stay, testResults * caseTestResults);
};

dealer::dealer() {
	newRound();
	this->hit = 18;
	this->stay = 19;
	this->difficulty = 1;
}
void dealer::getDeck(deck * dealerDeck) {
	ptrDeck = dealerDeck;
}
void dealer::getInterfaceHandler(interfaceHandler * dealerInterfaceHandler) {
	ptrInterfaceHandler = dealerInterfaceHandler;
}
void dealer::getMoneyHandler(moneyHandler * dealerMoneyHandler) {
	ptrMoneyHandler = dealerMoneyHandler;
}

void dealer::takeDifficulty(int difficultyLevel) {
	if (difficultyLevel == 1) {
		this->hit = 18;
		this->stay = 19;
		std::cout << "Difficulty set to Very Easy." << std::endl;
	}
	else if (difficultyLevel == 2) {
		this->hit = 17;
		this->stay = 18;
		std::cout << "Difficulty set to Easy." << std::endl;
	}
	else if (difficultyLevel == 3) {
		this->hit = 16;
		this->stay = 17;
		std::cout << "Difficulty set to Medium." << std::endl;
	}
	else if (difficultyLevel == 4) {
		this->hit = 15;
		this->stay = 16;
		std::cout << "Difficulty set to Hard." << std::endl;
	}
	else {
		std::cout << "Difficulty level not understood. Setting to Very Easy." << std::endl;
		this->hit = 18;
		this->stay = 19;
		difficultyLevel = 1;
	}
	this->difficulty = difficultyLevel;
}

void dealer::newRound() {
	firstPlayerValue = 0;
	secondPlayerValue = 0;
	firstDealerValue = 0;
	secondDealerValue = 0;
}
void dealer::addPlayerCard(int value) {
	// If it's a face card.
	if (value == 11 || value == 12 || value == 13) {
		firstPlayerValue += 10;
		secondPlayerValue += 10;
	}
	// Aces can be at a value of 1 or 11
	else if (value == 1) {
		firstPlayerValue += 11;
		secondPlayerValue += 1;
	}
	else {
		firstPlayerValue += value;
		secondPlayerValue += value;
	}
}
void dealer::addDealerCard(int value) {
	// If it's a face card.
	if (value == 11 || value == 12 || value == 13) {
		firstDealerValue += 10;
		secondDealerValue += 10;
	}
	// Aces can be at a value of 1 or 11
	else if (value == 1) {
		firstDealerValue += 11;
		secondDealerValue += 1;
	}
	else {
		firstDealerValue += value;
		secondDealerValue += value;
	}
	checkIfBusted(firstDealerValue, secondDealerValue);
}

int dealer::checkIfBusted(int firstValue, int secondValue) {
	if (firstValue > 21) {
		if (secondValue > 21) {
			// Busted
			ptrMoneyHandler->lose();
			return 1;
		}
	}
	// Not Busted
	return 0;
}

void dealer::newGame() {
	newRound();
	
	int cardValue = 0;
	
	// Dealer goes first
	do {
		cardValue = ptrDeck->draw();
		
		// If it's a face card.
		if (cardValue == 11 || cardValue == 12 || cardValue == 13) {
			firstDealerValue += 10;
			secondDealerValue += 10;
		}
		// Aces can be at a value of 1 or 11
		else if (cardValue == 1) {
			firstDealerValue += 11;
			secondDealerValue += 1;
		}
		else {
			firstDealerValue += cardValue;
			secondDealerValue += cardValue;
		}
		
		if (secondDealerValue >= stay) {
			// Stay
			break;
		}
		if (firstDealerValue >= stay && secondDealerValue > hit) {
			// Stay
			break;
		}
		
		std::cout << "First Dealer Value: " << firstDealerValue << std::endl;
		std::cout << "Second Dealer Value: " << secondDealerValue << std::endl;
	} while (!checkIfBusted(this->firstDealerValue, this->secondDealerValue));
	
	// Player's turn
	do {
		cardValue = ptrDeck->draw();
		ptrInterfaceHandler->draw(cardValue);
		
		if (cardValue == 1) {
			firstPlayerValue += 11;
			secondPlayerValue += 1;
		}
		if (cardValue > 1 && 11 > cardValue) {
			firstPlayerValue += cardValue;
			secondPlayerValue += cardValue;
		}
		if (cardValue == 11) {
			firstPlayerValue += 10;
			secondPlayerValue += 10;
		}
		if (cardValue == 12) {
			firstPlayerValue += 10;
			secondPlayerValue += 10;
		}
		if (cardValue == 13) {
			firstPlayerValue += 10;
			secondPlayerValue += 10;
		}
		
		std::cout << "Current value";
		if (firstPlayerValue != secondPlayerValue) {
			std::cout << "s are " << firstPlayerValue << " and " << secondPlayerValue << "." << std::endl << std::endl;
		}
		else {
			std::cout << " is " << firstPlayerValue << "." << std::endl << std::endl;
		}
		
		if (checkIfBusted(this->firstPlayerValue, this->secondPlayerValue)) {
			break;
		}
		
		int hitOrStay = ptrInterfaceHandler->displayHitOrStay();
		
		if (hitOrStay == 1) {
			// it hit
		}
		else if (hitOrStay == 2) {
			break;
		}

	} while (1);
	
	int finalDealerValue;
	int finalPlayerValue;
	
	if (this->firstDealerValue == this->secondDealerValue) {
		finalDealerValue = this->firstDealerValue;
	}
	else if (this->firstDealerValue > 21 && this->secondDealerValue > 21) {
		finalDealerValue = this->firstDealerValue;
	}
	else if (this->firstDealerValue > 21) {
		finalDealerValue = this->secondDealerValue;
	}
	else if (this->secondDealerValue > 21) {
		finalDealerValue = this->firstDealerValue;
	}
	else if (this->firstDealerValue > this->secondDealerValue) {
		finalDealerValue = this->firstDealerValue;
	}
	else if (this->firstDealerValue < this->secondDealerValue) {
		finalDealerValue = this->secondDealerValue;
	}
	
	if (this->firstPlayerValue == this->firstPlayerValue) {
		finalPlayerValue = this->firstPlayerValue;
	}
	else if (this->firstPlayerValue > 21 && this->secondPlayerValue > 21) {
		finalPlayerValue = this->firstPlayerValue;
	}
	else if (this->firstPlayerValue > 21) {
		finalPlayerValue = this->secondPlayerValue;
	}
	else if (this->secondPlayerValue > 21) {
		finalPlayerValue = this->firstPlayerValue;
	}
	else if (this->firstPlayerValue > this->secondPlayerValue) {
		finalPlayerValue = this->firstPlayerValue;
	}
	else if (this->firstPlayerValue < this->secondPlayerValue) {
		finalPlayerValue = this->secondPlayerValue;
	}
	
	//ptrInterfaceHandler->printFinalValues(finalDealerValue, finalPlayerValue);
	std::cout << "Dealer Value: " << finalDealerValue << std::endl;
	std::cout << "Player Value: " << finalPlayerValue << std::endl;
	
	/*
	if (finalDealerValue > 21 && finalPlayerValue > 21) {
		ptrInterfaceHandler->tie(0);
		ptrMoneyHandler->tie(0);
	}
	else if (finalDealerValue == finalPlayerValue) {
		ptrInterfaceHandler->tie(1);
		ptrMoneyHandler->tie(1);
	}
	else if (finalDealerValue > finalPlayerValue) {
		ptrInterfaceHandler->lose();
		ptrMoneyHandler->lose();
	}
	else if (finalDealerValue < finalPlayerValue) {
		ptrInterfaceHandler->win();
		ptrMoneyHandler->win();
		
		if (finalPlayerValue == 21) {
			ptrInterfaceHandler->blackJack();
		}
		
	}
	*/
	// If you both busted
	// If only the dealer busted
	// If only you busted
	
	
}

void dealer::checkValues(int hit, int stay, testResults * newCaseTestResults) {
	int bust = 0;
	int shortNumber = 0;
	
	caseTestResults = newCaseTestResults;
	
	caseTestResults->hit = hit;
	caseTestResults->stay = stay;
	
	for (int i = 1; i <= 10000; i++) {
		int firstValue = 0;
		int secondValue = 0;
		
		int cardValue = 0;
		do {
			cardValue = ptrDeck->draw();
			// If it's a face card.
			if (cardValue == 11 || cardValue == 12 || cardValue == 13) {
				firstValue += 10;
				secondValue += 10;
			}
			// Aces can be at a value of 1 or 11
			else if (cardValue == 1) {
				firstValue += 11;
				secondValue += 1;
			}
			else {
				firstValue += cardValue;
				secondValue += cardValue;
			}
			
			if (secondValue >= stay) {
				break;
			}
			if (firstValue >= stay && secondValue > hit) {
				break;
			}
			
		} while (!checkIfBusted(firstValue, secondValue));
		
		std::cout << "[" << i << "] " << secondValue << std::endl;
		
		if (secondValue > 21) {
			bust++;
		}
		
		switch (secondValue) {
			case 30:
				caseTestResults->thirty += 1;
				break;
			case 29:
				caseTestResults->twentynine += 1;
				break;
			case 28:
				caseTestResults->twentyeight += 1;
				break;
			case 27:
				caseTestResults->twentyseven += 1;
				break;
			case 26:
				caseTestResults->twentysix += 1;
				break;
			case 25:
				caseTestResults->twentyfive += 1;
				break;
			case 24:
				caseTestResults->twentyfour += 1;
				break;
			case 23:
				caseTestResults->twentythree += 1;
				break;
			case 22:
				caseTestResults->twentytwo += 1;
				break;
			case 21:
				caseTestResults->twentyone += 1;
				break;
			case 20:
				caseTestResults->twenty += 1;
				break;
			case 19:
				caseTestResults->nineteen += 1;
				break;
			case 18:
				caseTestResults->eighteen += 1;
				break;
			case 17:
				caseTestResults->seventeen += 1;
				break;
			case 16:
				caseTestResults->sixteen += 1;
				break;
			case 15:
				caseTestResults->fifteen += 1;
				break;
			default:
				shortNumber++;
				break;
		}
	}
	
	std::cout << std::endl;
	caseTestResults->printResults();
	
	caseTestResults = NULL;
}

std::string dealer::numberToString(int input) {
	std::ostringstream converter;
	
	converter << input;
	return converter.str();
}

#endif // DEALER_H_INCLUDED