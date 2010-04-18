#ifndef MONEY_H_INCLUDED
#define MONEY_H_INCLUDED

/*
 *  moneyHandler.h
 *  Blackjack
 *
 *  Created by Lucas Kjaero on 3/28/10.
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