#ifndef TESTRESULTS_H_INCLUDED
#define TESTRESULTS_H_INCLUDED

/*
 *  testResults.h
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

class testResults {
public:
	std::string testTopLine;
	double thirty;
	double twentynine;
	double twentyeight;
	double twentyseven;
	double twentysix;
	double twentyfive;
	double twentyfour;
	double twentythree;
	double twentytwo;
	double twentyone;
	double twenty;
	double nineteen;
	double eighteen;
	double seventeen;
	double sixteen;
	double fifteen;
	
	int hit;
	int stay;
	
	void addString(std::string string);
	
	void printResults();
	//~testResults();
	testResults();
};

testResults::testResults() {
	thirty = 0;
	twentynine = 0;
	twentyeight = 0;
	twentyseven = 0;
	twentysix = 0;
	twentyfive = 0;
	twentyfour = 0;
	twentythree = 0;
	twentytwo = 0;
	twentyone = 0;
	twenty = 0;
	nineteen = 0;
	eighteen = 0;
	seventeen = 0;
	sixteen = 0;
	fifteen = 0;
}

void testResults::addString(std::string string) {
	testTopLine = string;
}

void testResults::printResults() {
	int winCount = twentyone + twenty + nineteen + eighteen + seventeen + sixteen + fifteen;
	int bust = thirty + twentynine + twentyeight + twentyseven + twentysix + twentyfive + twentyfour + twentythree + twentytwo;
	std::cout << "10000 games hitting on " << hit << " and staying on " << stay << " concluded with " << winCount << " wins, " << bust << " losses, and " << twentyone << " blackjacks, distributed as:" << std::endl;
	std::cout << "27+: " << thirty + twentynine + twentyeight + twentyseven << std::endl;
	std::cout << "26: " << twentysix << std::endl;
	std::cout << "25: " << twentyfive << std::endl;
	std::cout << "24: " << twentyfour << std::endl;
	std::cout << "23: " << twentythree << std::endl;
	std::cout << "22: " << twentytwo << std::endl;
	std::cout << "21: " << twentyone << std::endl;
	std::cout << "20: " << twenty << std::endl;
	std::cout << "19: " << nineteen << std::endl;
	std::cout << "18: " << eighteen << std::endl;
	std::cout << "17: " << seventeen << std::endl;
	std::cout << "16: " << sixteen << std::endl;
	std::cout << "15: " << fifteen << std::endl;
	double sum = (thirty * 30) + (twentynine * 29) + (twentyeight * 28) + (twentyseven * 27) + (twentysix * 26) + (twentyfive * 25) + (twentyfour * 24) + (twentythree * 23) + (twentytwo * 22) + (twentyone * 21) + (twenty * 20) + (nineteen * 19) + (eighteen * 18) + (seventeen * 17) + (sixteen * 16) + (fifteen * 15);
	double average = sum / 10000;
	std::cout << "Average number is " << average << "." << std::endl;
	
	std::cout << "The mode is ";
	int mode;
	int largestNumber;
	largestNumber = fifteen;
	mode = 15;
	if (sixteen > largestNumber) {
		mode = 16;
		largestNumber = sixteen;
	}
	if (seventeen > largestNumber) {
		mode = 17;
		largestNumber = seventeen;
	}
	if (eighteen > largestNumber) {
		mode = 18;
		largestNumber = eighteen;
	}
	if (nineteen > largestNumber) {
		mode = 19;
		largestNumber = nineteen;
	}
	if (twenty > largestNumber) {
		mode = 20;
		largestNumber = twenty;
	}
	if (twentyone > largestNumber) {
		mode = 21;
		largestNumber = twentyone;
	}
	if (twentytwo > largestNumber) {
		mode = 22;
		largestNumber = twentytwo;
	}
	if (twentythree > largestNumber) {
		mode = 23;
		largestNumber = twentythree;
	}
	if (twentyfour > largestNumber) {
		mode = 24;
		largestNumber = twentyfour;
	}
	if (twentyfive > largestNumber) {
		mode = 25;
		largestNumber = twentyfive;
	}
	if (twentysix > largestNumber) {
		mode = 26;
		largestNumber = twentysix;
	}
	double percent;
	percent = largestNumber / 100.0;
	//percent *= 100;
	std::cout << mode << " with a count of " << largestNumber << ", " << percent << "% of the results." << std::endl;
	
	std::cout << std::endl << "======================================" << std::endl << std::endl;
}

/*testResults::~testResults() {
	printResults();
}*/

#endif // TESTRESULTS_H_INCLUDED