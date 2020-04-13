#include <iostream>

using namespace std;

void CloseWindow()
{
    cout << "Tap twice 'Enter' to exit the window..." << endl;
    cin.clear();
    cin.ignore(32767, '\n');
    cin.get();
}

int main()
{
    CloseWindow();
    return 0;
}
