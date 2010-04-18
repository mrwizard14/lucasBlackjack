#ifndef INTERFACEHANDLER_H_INCLUDED
#define INTERFACEHANDLER_H_INCLUDED

/*
 *  interfaceHandler.h
 *  Blackjack
 *
 *  Created by Lucas Kjaero on 3/29/10.
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

#include "dealer.h"

class interfaceHandler {
public:
	std::string upperCase(std::string input);
	
	int displayMenu();
	int displayDifficulty();
	int displayHitOrStay();
	bool playAgain();
	
	void draw(int card);
	
	void win();
	void lose();
	void tie(bool getMoney);
	void blackJack();
	
	void printFinalValues(int dealer, int player);
};

std::string interfaceHandler::upperCase(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
	}
	return input;
}

int interfaceHandler::displayMenu() {
	std::cout << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "#                      #" << std::endl;
	std::cout << "# 1) New Game          #" << std::endl;
	std::cout << "# 2) Change Difficulty #" << std::endl;
	std::cout << "# 3) Quit              #" << std::endl;
	std::cout << "#                      #" << std::endl;
	std::cout << "########################" << std::endl << std::endl;
	
	std::cout << "Select an option: ";
	
	std::string answer;
	std::cin >> answer;
	
	if (answer == "1" || upperCase(answer) == "NEW" || upperCase(answer) == "N") {
		return 1;
	}
	else if (answer == "2" || upperCase(answer) == "CHANGE" || upperCase(answer) == "DIFFICULTY") {
		return 2;
	}
	else if (answer == "3" || upperCase(answer) == "QUIT" || upperCase(answer) == "Q") {
		return 3;
	}
	else {
		return this->displayMenu();
	}
}
int interfaceHandler::displayDifficulty() {
	std::cout << "################" << std::endl;
	std::cout << "#              #" << std::endl;
	std::cout << "# 1) Very Easy #" << std::endl;
	std::cout << "# 2) Easy      #" << std::endl;
	std::cout << "# 3) Medium    #" << std::endl;
	std::cout << "# 4) Hard      #" << std::endl;
	std::cout << "#              #" << std::endl;
	std::cout << "################" << std::endl << std::endl;
	
	std::cout << "Select an option";
	
	std::string difficulty;
	std::cin >> difficulty;
	
	if (difficulty == "1" || upperCase(difficulty) == "VERY" || upperCase(difficulty) == "V") {
		return 1;
	}
	else if (difficulty == "2" || upperCase(difficulty) == "EASY" || upperCase(difficulty) == "E") {
		return 2;
	}
	else if (difficulty == "3" || upperCase(difficulty) == "MEDIUM" || upperCase(difficulty) == "M") {
		return 3;
	}
	else if (difficulty == "4" || upperCase(difficulty) == "HARD" || upperCase(difficulty) == "H") {
		return 4;
	}
	else {
		return this->displayDifficulty();
	}
}
int interfaceHandler::displayHitOrStay() {
	std::cout << "###########" << std::endl;
	std::cout << "#         #" << std::endl;
	std::cout << "# 1) Hit  #" << std::endl;
	std::cout << "# 2) Stay #" << std::endl;
	std::cout << "#         #" << std::endl;
	std::cout << "###########" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Select an option, please: ";
	std::string result;
	std::cin >> result;
	
	if (result == "1" || upperCase(result) == "HIT") {
		return 1;
	}
	else if (result == "2" || upperCase(result) == "STAY") {
		return 2;
	}
	else {
		return this->displayHitOrStay();
	}
}
bool interfaceHandler::playAgain() {
	std::cout << "###############" << std::endl;
	std::cout << "#             #" << std::endl;
	std::cout << "# Play Again? #" << std::endl;
	std::cout << "#             #" << std::endl;
	std::cout << "# 1) Yes      #" << std::endl;
	std::cout << "# 2) No       #" << std::endl;
	std::cout << "#             #" << std::endl;
	std::cout << "###############" << std::endl;
	
	std::cout << "Select an option, please: ";
	std::string result;
	std::cin >> result;
	
	if (result == "1" || upperCase(result) == "YES") {
		return 1;
	}
	if (result == "2" || upperCase(result) == "NO") {
		return 0;
	}
	else {
		return this->playAgain();
	}
}

void interfaceHandler::draw(int card) {
	std::cout << "You drew a";
	if (card == 1) {
		std::cout << "n ace. This means that it can be valued at 1 or 11." << std::endl;
	}
	if (card > 1 && 11 > card) {
		std::cout << " " << card << "." << std::endl;
	}
	if (card == 11) {
		std::cout << " Jack. This means that it is valued at 10." << std::endl;
	}
	if (card == 12) {
		std::cout << " Queen. This means that it is valued at 10." << std::endl;
	}
	if (card == 13) {
		std::cout << " King. This means that it is valued at 10." << std::endl;
	}
}

void interfaceHandler::win() {
	std::cout << "You won." << std::endl;
}
void interfaceHandler::lose() {
	std::cout << "You lost." << std::endl;
}
void interfaceHandler::tie(bool getMoney) {
	if (getMoney == 0) {
		std::cout << "You both busted, the game was a tie." << std::endl;
	}
	if (getMoney == 1) {
		std::cout << "You tied, so you get your bet money won." << std::endl;
	}
}
void interfaceHandler::blackJack() {
	std::cout << "BLACKJACK!" << std::endl;
}

void printFinalValues(int dealerValue, int player) {
	std::cout << "Dealer Value: " << dealerValue << std::endl;
	std::cout << "Player Value: " << player << std::endl;
}

#endif // INTERFACEHANDLER_H_INCLUDED