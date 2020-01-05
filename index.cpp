#include <iostream>
#include <ctime>
#include <random>

using namespace std;
int main() {

	default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

    //Human properties
	float humanAttack = 0.6f;
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = humanHealth;

	//Skeleton properties
	float skeletonAttack = 0.2f;
	float skeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeletonHealth = skeletonHealth;

	float attackResult;

	int startHumans;
	int startSkeletons;

	int numSkeletons;
	int numHumans;
	char turn = 'H';
	cout << "========================================================== \n";
	cout << "1-D Combat Simulator 2014 - Made in Kenya. \n";
	cout << "========================================================== \n";
    //Get number of Humans
	cout << "Enter the number of Humans: \n";
	cin >> numHumans;
	startHumans = numHumans;
	//Get number of Skeletons
	cout << "Enter the number of Skeletons: \n";
	cin >> numSkeletons;
	startSkeletons = numSkeletons;
	
	while ((numHumans > 0) && (numSkeletons > 0))
	{
		//check attack result
		attackResult = attack(randomEngine);

		//Human's turn
		if (turn == 'H') {
			
			//check if attack was successful
		if (attackResult <= humanAttack) {
			currentSkeletonHealth -= humanDamage;
			if (currentSkeletonHealth > 0) {
				numSkeletons--;
				currentSkeletonHealth = skeletonHealth;
			}
		}
		turn = 'S';
	}
		else {
			
			if (attackResult <= skeletonAttack) {
				currentHumanHealth -= skeletonDamage;
				if (currentHumanHealth < 0 ) {
					numHumans--;
					currentHumanHealth = humanHealth;
				}
			}
			turn = 'H';
		}
	}
	cout << "The battle is over!! \n";
	if (numHumans > 0) {
		cout << "Humans Won! \n";
		cout << "There are " << numHumans << " humans left. \n";
	}
	else {
		cout << "Skeletons Won! \n";
		cout << "There are " << numSkeletons << " skeletons left. \n";
	}
	cout << startHumans - numHumans << " humans and " << startSkeletons - numSkeletons << " skeletons died. \n";
}