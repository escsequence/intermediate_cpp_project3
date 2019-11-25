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
#include "Main.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Create vectors to store the parcels the user makes
vector<GroundParcel> ground;
vector<OvernightParcel> overnight;
vector<Contact> contacts;

int main()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	bool go = true;
	int choice = 0;
	string input = "";

	// Begin the program's main loop to construct parcels
	do {
		// Show the user a list of options
		cout << "What would you like to do now? Enter the corresponding number:\n\t1). Create a new contact\n\t2). Create a ground parcel\n\t3). Create an overnight parcel\n\t4). Display parcel information and quit" << endl;

		// Ask user to make their choice
		getline(cin, input);
		choice = stoi(input);
		switch (choice) {
			case 1:
			{
				// Call the method for handling contacts to allow the user to create a new one
				handleContact();
				break;
			}
			case 2:
			{
				// Call a special method to collect all the data the program needs to make a ground parcel
				createGroundParcel();
				break;
			}
			case 3:
			{
				// Call a special method to collect all the data the program needs to make an overnight parcel
				createOvernightParcel();
				break;
			}
			case 4:
			{
				// Set the variable to false to break the while loop
				cout << "Thank you for using the parcel management program. Look below for details on your parcels:" << endl;
				go = false;
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

string getInputFromuser(string msg) {
	string tmp;
	cout << msg;
	getline(cin, tmp);
	return tmp;
}

Contact getContactFromUser(string msg) {
	cout << msg;
	return handleContact();
}

void createGroundParcel()
{
	// Create variables to gather input
	int val = 0;
	string input = "";

	// Collect information
	cout << "Please input the requested information: " << endl;

	// Parcel Number
	int parcelNumber = stoi(getInputFromuser("Parcel Number: #"));

	// Name of Parcel
	std::string name = getInputFromuser("Name of Parcel: ");

	// Contact information for sender
	Contact senderAddress = getContactFromUser("Who is the sender? ");

	// Contact information for recipient
	Contact receiverAddress = getContactFromUser("Who is the recipient? ");

	// Fee
	double fee = stod(getInputFromuser("Shipping fee: $"));

	// Weight
	double weight = stod(getInputFromuser("Weight (in oz): "));

	// Cost per ounce
	double costPerOz = stod(getInputFromuser("Cost per oz: $"));

	// Assemble a new ground parcel from the inputted information
	GroundParcel g(parcelNumber, name, senderAddress, receiverAddress, fee, weight, costPerOz);

	// Push the ground parcel to the vector
	ground.push_back(g);
	cout << endl << endl << "Thank you! Your ground parcel has been successfully created." << endl;
}

void createOvernightParcel()
{
	// Create variables to gather input
	int val = 0;
	string input = "";

	// Collect information
	cout << "Please input the requested information: " << endl;

	// Parcel Number
	int parcelNumber = stoi(getInputFromuser("Parcel Number: #"));

	// Name of Parcel
	string name = getInputFromuser("Name of Parcel: ");

	// Contact information for sender
	Contact senderAddress = getContactFromUser("Who is the sender? ");

	// Contact information for recipient
	Contact receiverAddress = getContactFromUser("Who is the recipient? ");

	// Fee
	double fee = stod(getInputFromuser("Shipping fee: $"));

	// Weight
	double weight = stod(getInputFromuser("Weight (in oz): "));

	// Cost per ounce
	double costPerOz = stod(getInputFromuser("Cost per oz: $"));

	// Tracking number
	int trackingNumber = stoi(getInputFromuser("Tracking Number: #"));

	// Standard weight
	double standardWeight = stod(getInputFromuser("Standard Weight (in oz): "));

	// Assemble a new ground parcel from the inputted information
	OvernightParcel o(parcelNumber, name, senderAddress, receiverAddress, fee, weight, costPerOz, trackingNumber, standardWeight);

	// Push the ground parcel to the vector
	overnight.push_back(o);
	cout << endl << endl << "Thank you! Your ground parcel has been successfully created." << endl;
}

Contact handleContact()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	bool go = true;
	int choice = 0;
	string input = "";
	Contact userChoice;

	// Loop to ensure operation is completed successfully
	do {
		// Show the user a list of options
		cout << "What would you like to do now? Enter the corresponding number:\n\t1). View existing contacts\n\t2). Create a new contact" << endl;

		// Ask user to make their choice
		getline(cin, input);
		choice = stoi(input);

		// Evaluate choice
		switch (choice) {
		case 1:
		{
			if (contacts.size() == 0) 
			{
				cout << "Sorry, there aren't any existing contacts. You'll have to create a new one." << endl;
				continue;
			}
			else 
			{
				// Issue instructions to user
				cout << "Enter the number that corresponds to the desired contact: " << endl;

				// List all existing contacts
				for (int i = 0; i < contacts.size(); i++)
				{
					cout << i << "). " << contacts[i].toString() << endl;
				}

				// Select the contact that the user chose
				int choice = stoi(getInputFromuser(""));
				userChoice = contacts[choice];
				go = false;
				break;
			}
		}
		case 2:
		{
			// Collect information
			cout << "Please input the requested information: " << endl;

			// Name of Contact
			string name = getInputFromuser("Name of Contact: ");

			// Street Address of Contact
			string addressStreet = getInputFromuser("Street Address: ");

			// City of Contact
			string addressCity = getInputFromuser("City: ");

			// State of Contact
			string addressState = getInputFromuser("State: ");

			// Zip code of Contact
			string addressZip = getInputFromuser("Zip: ");;

			// Create a contact with the given information
			Contact userChoice(name, addressStreet, addressCity, addressState, addressZip);

			// Add the contact to list of created contacts
			contacts.push_back(userChoice);

			// Break loop
			go = false;
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

	// Return the newly created contact or the contact selected by the user.
	return userChoice;
}
