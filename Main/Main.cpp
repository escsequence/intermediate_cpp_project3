/*
* Main.cpp
* Written by: Alec Ochowski
* Written for: COMPSCI 222 Project 3
* Created on: 11/18/2019
*/

/*
* Program for testing the Ground Parcel and Overnight Parcel classes (driver)
*/

#include "pch.h"
#include "Parcel.h"
#include "OvernightParcel.h"
#include "GroundParcel.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	bool go = true;
	int choice = 0;
	string input = "";

	// Create vectors to store the parcels the user makes
	vector<GroundParcel> ground;
	vector<OvernightParcel> overnight;

	// Begin the program's main loop to construct parcels
	do {
		// Show the user a list of options
		cout << "What would you like to do now? Enter the corresponding number:\n\t1). Create a ground parcel\n\t2). Create an overnight parcel\n\t4). Display paystubs and quit." << endl;

		// Ask user to make their choice
		getline(cin, input);
		choice = stoi(input);

		switch (choice) {
			case 1:
			{
				// Assemble a new ground parcel from the inputted information
				GroundParcel g();
				vector<GroundParcel>::iterator i;
				i = ground.begin();
				ground.insert(i, g);
				break;
			}
			case 2:
			{
				// Assemble a new overnight parcel from the inputted information
				OvernightParcel o();
				vector<OvernightParcel>::iterator j;
				j = overnight.begin();
				overnight.insert(j, o);
				break;
			}
			case 3: 
			{
				// Set the variable to false to break the while loop
				cout << "Thank you for using the parcel management program. Look below for details on your parcels:" << endl;
				bool go = false;
				break;
			}
			default:
			{
				// Inform the user that their input is invalid
				cout << "Sorry, that's not a valid choice. Please try again." << endl;
				break;
			}
		}
	} while (go == true);

	// Print out information on all the ground parcels the user created
	for (int i = 0; i < ground.size(); i++) {
		cout << "Ground Parcel #" << i << ":\n" << ground[i].toString() << endl;
	}

	// Print out information on all the overnight parcels the user created
	for (int j = 0; j < overnight.size(); j++) {
		cout << "Overnight Parcel #" << j << ":\n" << overnight[j].toString() << endl;
	}

	// End program
	return -1;
}
