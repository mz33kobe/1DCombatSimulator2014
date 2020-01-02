#include <iostream>
#include <string>

using namespace std;
int main() {
	cout << "========================================================== \n";
	cout << "1-D Combat Simulator 2014 - Made in Kenya. \n";
	cout << "========================================================== \n";
    //Simple 1Dimension game
	cout << "Enter the number of Humans: \n";
	int humans;
	cin >> humans;
	cout << "Enter the number of Aliens: \n";
	int aliens;
	cin >> aliens;
	int winners;
	winners = humans - aliens;
	while (true)
	{
		cout << "The " << winners << " won this match! \n";
	}
}