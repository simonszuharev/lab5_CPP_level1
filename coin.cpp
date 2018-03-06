/* Coin class implementation */

#include "coin.h"
#include <random>


// Toss the coin and update member variables
void Coin::tossCoin() {
	if(rand() % 2) {
		sideUp="Heads";
		headsCount++;
	}
	else {
		sideUp="Tails";
		tailsCount++;
	}
}
