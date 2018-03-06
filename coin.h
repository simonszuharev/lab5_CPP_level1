#ifndef COIN_H
#define COIN_H

#include <string>

using namespace std;

/* Coin class declaration */

class Coin {
	private:
		int headsCount;
		int tailsCount;
		string sideUp;
	public:
		// Constructor
		Coin() {
			headsCount = 0;
			tailsCount = 0;
			sideUp = "";
		}
		// Getters
		int getHeadsCount() {
			return headsCount;
		}
		int getTailsCount() {
			return tailsCount;
		}
		int getTossCount() {
			return headsCount + tailsCount;
		}
		string getSideUp() {
			return sideUp;
		}
		// Toss the coin and update member variables
		void tossCoin();
};
#endif

