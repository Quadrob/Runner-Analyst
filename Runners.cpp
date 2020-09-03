//============================================================================
// Name        : Runners.cpp
// Author      : Robert Zeelie
// Version     : 1.00.00
// Copyright   : Your copyright notice
/* Description : A program that asks the user to enter the number of kilometers
 * 				 run by 10 different people.The program will analyze the data
 * 				 and output which person ran the most, average, and the least
 * 				 kilometers. It also outputs a list with the order of kilometers
 * 				 run by all 10 people (person with most kilometers first).
 */
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//a function to calculate the max
void maxCalculation(double distance[], int runnersNum[], int sizeOfArray) {
	double max = distance[0];
	int maxRunner = runnersNum[0];
	for (int i = 0; i < sizeOfArray; i++) {
		if (distance[i] > max) {
			max = distance[i];
			maxRunner = runnersNum[i];
		}
	}
	cout << "\nThe maximum distance run is by Runner " << maxRunner << " with : "
		 << max << "km" << endl;
}

//a function to calculate the min
void minCalculation(double distance[], int runnersNum[], int sizeOfArray) {
	double min = distance[0];
	int minRunner = runnersNum[0];
	for (int i = 0; i < sizeOfArray; i++) {
		if (distance[i] < min) {
			min = distance[i];
			minRunner = runnersNum[i];
		}
	}
	cout << "\nThe minimum distance run is by Runner " << minRunner << " with : "
		 << min << "km" << endl;
}

//a function to calculate the average
void averageCalculation(double distance[], int sizeOfArray) {
	double average = 0;
	for (int j = 0; j < sizeOfArray; j++) {
		average += distance[j];
	}
	average = (average / sizeOfArray);
	cout << "\nThe average distance run is : " << average << "km" << endl;
}

//a function to sort the array from largest to smallest
void bubbleSortArray(double distance[], int runnersNum[], int sizeOfArray) {
	double tempPlace;
	int tempRunner;
	for (int i = 0; i < sizeOfArray; i++) {
		for (int z = (sizeOfArray - 1); z >= i; z--) {
			if (distance[z - 1] < distance[z]) {
				//exchange elements of distance
				tempPlace = distance[z - 1];
				distance[z - 1] = distance[z];
				distance[z] = tempPlace;
				//exchange elements of runnersNum
				tempRunner = runnersNum[z - 1];
				runnersNum[z - 1] = runnersNum[z];
				runnersNum[z] = tempRunner;
			}
		}
	}
	for (int a = 0; a < sizeOfArray; a++) {
		cout << "\tRunner " << runnersNum[a] << " ran : " << distance[a] << "km" << endl;
	}
}


//main method
int main() {

	//Tell the user what the program is
	cout << "Runners Distance Analyzer (kilometers) :" << endl;
	cout << setfill('-') << setw(100) << "-" << endl;

	//declare variables
	int sizeOfArray = 10;/*I could get the user to input how many runners to
	enter but for this problem it is required to be set to 10 */
	double distance[sizeOfArray];
	int runnersNum[sizeOfArray];

	//get input from user
	for (int i = 0; i < sizeOfArray; i++) {
		cout << "\nPlease enter the distance of runner " << (i + 1) << " in km : ";
		cin >> distance[i];//store input dist in array
		runnersNum[i] = (i + 1);//store runners number in array
	}

	//print out original array
	cout << "\n" << setfill('-') << setw(100) << "-" << endl;
	cout << "The Original List of Runners:" << endl;
	for (int x = 0; x < sizeOfArray; x++) {
		cout << "\tRunner " << runnersNum[x] << " ran : " << distance[x] << "km" << endl;
	}
	cout << setfill('-') << setw(100) << "-" << endl;

	//Information about the runners
	cout << "\nInformation about runners : " << endl;
	//compute the max distance run in km
	maxCalculation(distance, runnersNum, sizeOfArray);
	//compute the mix distance run in km
	minCalculation(distance, runnersNum, sizeOfArray);
	//compute the average distance run in km
	averageCalculation(distance, sizeOfArray);
	cout << "\n" << setfill('-') << setw(100) << "-" << endl;

	//Sort the array
	cout << "The sorted list from highest to lowest : " << endl;
	bubbleSortArray(distance, runnersNum, sizeOfArray);
	cout << setfill('-') << setw(100) << "-" << endl;

	return 0;
}























