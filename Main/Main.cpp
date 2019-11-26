/**
 * Project 3 - Part 1
 * Authors: Alec Ochowski and James Johnston
 */

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
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Create vectors to store the parcels the user makes
vector<GroundParcel> ground;
vector<OvernightParcel> overnight;
vector<Contact> contacts;

/**
 * Main method
 * This is where the program starts.
 * @return int,	Program status
 */
int main()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	bool go = true;
	int choice = 0;
	string input = "";

	// Initialize the static variables
	BasicFee = stod(getInputFromUser("Please enter the basic shipping fee for all parcels: $"));
	StandardWeight = stod(getInputFromUser("Please enter the maximum weight (in oz) before extra charge (standard weight) for all overnight parcels: "));
	CostPerOunce = stod(getInputFromUser("Please enter the cost per ounce for all parcels: $"));

	// Begin the program's main loop to construct parcels
	do {
		// Show the user a list of options
		cout << "\nWhat would you like to do now? Enter the corresponding number:\n\t1). Create a new contact\n\t2). Create a ground parcel\n\t3). Create an overnight parcel\n\t4). Display parcel information and quit" << endl;

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
				cout << "Thank you for using the parcel management program. Look below for details on your parcels:" << endl << endl;
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

	// Fix the decimal precision of the output stream
	cout << fixed;

	// Print out information on all the ground parcels the user created
	for (int i = 0; i < ground.size(); i++) {
		cout << setprecision(2) << "Ground Parcel #" << i + 1 << ":\n" << ground[i].toString() << endl;
	}

	// Print out information on all the overnight parcels the user created
	for (int j = 0; j < overnight.size(); j++) {
		cout << setprecision(2) << "Overnight Parcel #" << j + 1 << ":\n" << overnight[j].toString() << endl;
	}

	// End program
	return -1;
}

/**
 * Reutrns a string value entered by the user.
 * @return string,	Value entered by user
 */
string getInputFromUser(string msg) {
	string tmp;
	cout << msg;
	getline(cin, tmp);
	return tmp;
}

/**
 * Returns a Contact pointer - all this does is display a message and
 * relies on handleContact to return a value.
 * @param string,			Message to display before getting values
 * @return Conact*,		Contact pointer
 */
Contact* getContactFromUser(string msg) {
	cout << msg;
	return handleContact();
}

/**
 * Initalizes a generic Parcel object with values
 * @param Parcel,		Reference of a Parcel object
 */
void initParcel(Parcel &p) {

		// Parcel Number
		p.setParcelNumber(stoi(getInputFromUser("Parcel Number: #")));

		// Name of Parcel
		p.setName(getInputFromUser("Name of Parcel: "));

		// Contact information for sender
		p.setSenderAddress(*getContactFromUser("Who is the sender? "));

		// Contact information for recipient
		p.setReceiverAddress(*getContactFromUser("Who is the recipient? "));

		// Weight
		p.setWeight(stod(getInputFromUser("Weight (in oz): ")));

}

/**
 * Gets information from the user for a Ground Parcel and inserts into
 * the vector of GroundParcels (ground)
 * @param	none
 * @return none
 */
void createGroundParcel() {

	// Create a parcel object
	GroundParcel gp;

	// Collect information
	cout << "Please input the requested information: " << endl;

	// Standard initalization for all Parcels
	initParcel(gp);

	// Push the ground parcel to the vector
	ground.push_back(gp);

	// Confirm completed adding the parcel
	cout << endl << endl << "Thank you! Your ground parcel has been successfully created." << endl;
}

/**
 * Similiarly with createGroundParcel, this function gets information for an
 * OvernightParcel and inserts into the vector of OvernightParcels (overnight)
 * @param	none
 * @return none
 */
void createOvernightParcel() {

	// Create a parcel object
	OvernightParcel np;

	// Collect information
	cout << "Please input the requested information: " << endl;

	initParcel(np);

	// Tracking number
	np.setTrackingNumber(stoi(getInputFromUser("Tracking number of this parcel: #")));

	// Push the ground parcel to the vector
	overnight.push_back(np);


	cout << endl << endl << "Thank you! Your overnight parcel has been successfully created." << endl;
}

/**
 * This method handles getting contact information
 * @param	Contact* 		Contact pointer
 */
Contact* handleContact()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	bool go = true;
	int choice = 0;
	string input = "";
	Contact dummy;
	Contact *userChoice = &dummy;

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
				int choice = stoi(getInputFromUser(""));
				userChoice = &contacts[choice];
				go = false;
				break;
			}
		}
		case 2:
		{
			// Collect information
			cout << "Please input the requested information: " << endl;

			// Name of Contact
			string name = getInputFromUser("Name of Contact: ");

			// Street Address of Contact
			string addressStreet = getInputFromUser("Street Address: ");

			// City of Contact
			string addressCity = getInputFromUser("City: ");

			// State of Contact
			string addressState = getInputFromUser("State: ");

			// Zip code of Contact
			string addressZip = getInputFromUser("Zip: ");;

			// Create a contact with the given information
			Contact c(name, addressStreet, addressCity, addressState, addressZip);

			// Add the contact to list of created contacts
			contacts.push_back(c);
			userChoice = &contacts.back();

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

/**
 * Sets static variable for fee
 * @param double,  Fee for specific Parcels
 */
void setFee(double fee) {
	BasicFee = fee;
}

/**
 * Sets static variable for standard weight
 * @param double,  Standard weight
 */
void setStandardWeight(double weight) {
	StandardWeight = weight;
}

/**
 * Sets static variable for cost per ounce
 * @param double,  Cost per ounce
 */
void setCostPerOz(double oz) {
	CostPerOunce = oz;
}

/**
 * Gets the basic fee
 * @return double,  Fee for specific Parcels
 */
double getFee() {
	return BasicFee;
}

/**
 * Gets the standard weight
 * @return double,  standard weight for parcels
 */
double getStandardWeight() {
	return StandardWeight;
}

/**
 * Gets the cost per ounce
 * @return double,  cost per ounce
 */
double getCostPerOz() {
	return CostPerOunce;
}
