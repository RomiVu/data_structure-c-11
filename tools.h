#ifndef TOOLS_H
#define TOOLS_H
#include <vector>


void CloseWindow();

int getRandomNumber(int min, int max);

// Chooses k unique random elements from a population sequence from its index [start, end].
std::vector<int> randomSample(int start, int end, int k);

int min(int a, int b);
int max(int a, int b);
int _abs(int a);


#endif