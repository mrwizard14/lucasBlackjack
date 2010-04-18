#ifndef MONEY_H_INCLUDED
#define MONEY_H_INCLUDED

/*
 *  moneyHandler.h
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

class moneyHandler {
private:
	int winCount;
	int loseCount;
	int tieCount;
	
	int betAmount;
	int moneyCount;
public:
	moneyHandler();
	
	void win();
	void lose();
	void tie(bool getMoney);
};

moneyHandler::moneyHandler() {
	winCount = 0;
	loseCount = 0;
	tieCount = 0;
	betAmount = 5;
}

void moneyHandler::win() {
	winCount++;
}
void moneyHandler::lose() {
	loseCount++;
	std::cout << "The dealer has beaten you." << std::endl;
	std::cout << "" << std::endl;
}
void moneyHandler::tie(bool getMoney) {
	tieCount++;
	
	if (getMoney) {
		std::cout << "You got the bet" << std::endl;
	}
}

#endif //  MONEY_H_INCLUDED