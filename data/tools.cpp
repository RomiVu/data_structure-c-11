#include "tools.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

void CloseWindow()
{
	std::cout << "Tap twice 'Enter' to exit the window..." << std::endl;
    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cin.get();
}


namespace MyRandom
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution<> die(min, max); // we can create a distribution in any function that needs it
	return die(MyRandom::mersenne); // and then generate a random number from our global generator
}