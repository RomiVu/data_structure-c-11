#include <iostream>
#include "tools.h"

using namespace std;

void CloseWindow()
{
	cout << "Tap twice 'Enter' to exit the window..." << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
}
