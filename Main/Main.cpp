/**
 * Project 3 - Part 2
 * Authors: Alec Ochowski and James Johnston
 */

 /*
 * Main.cpp
 * Written by: Alec Ochowski
 * Written for: COMPSCI 222 Project 3 Part 2
 * Created on: 12/04/2019
 */

 /*
 * New program for testing the Ground Parcel and Overnight Parcel classes (driver)
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

// Create vectors to store the parcels and contacts the user makes
vector<Parcel*> parcels;
vector<Contact> contacts;

/**
 * Initializes the static variables that are shared between all parcels.
 */
void initializeStatic() {
	BasicFee = stod(getInputFromUser("Please enter the basic shipping fee for all parcels: $"));
	StandardWeight = stod(getInputFromUser("Please enter the maximum weight (in oz) before extra charge (standard weight) for all overnight parcels: "));
	CostPerOunce = stod(getInputFromUser("Please enter the cost per ounce for all parcels: $"));
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
	parcels.push_back(&gp);

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

	// Standard initalization for all Parcels
	initParcel(np);

	// Tracking number
	np.setTrackingNumber(stoi(getInputFromUser("Tracking number of this parcel: #")));

	// Push the ground parcel to the vector
	parcels.push_back(&np);

	// Confirm completed adding the parcel
	cout << endl << endl << "Thank you! Your overnight parcel has been successfully created, and it is now IN TRANSITION." << endl;
}

/**
 * This method handles getting contact information
 * @param	Contact* 		Contact pointer
 */
Contact* handleContact()
{
	// Declare an initialize the basic variables that will be required to run the loop and intake user choices
	string input;
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

	// Reset go for the main loop
	go = true;

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

/**
 * Runs the secondary menu, which gives the user the options to make new ground and overnight parcles.
 */
void secondaryMenu() {
	string input;

	// Show the user a list of options
	cout << "\n_____________________________________________\nPlease select parcel type:\n1 - Ground parcel\n2 - Overnight parcel\nOther - Return to main menu\n_____________________________________________" << endl;

	// Ask user to make their choice
	getline(cin, input);
	choice = stoi(input);
	switch (choice) {
	case 1:
		createGroundParcel(); break;
	case 2:
		createOvernightParcel(); break;
	default:
		break; // Write all new parcels to external file
	}
}

/**
 * Runs the primary menu, which gives the user the options to make contacts, process parcels, and update and track overnight parcel statuses.
 */
void primaryMenu() {
	string input;

	// Show the user a list of options
	cout << "\n_____________________________________________\nEnter your service selection:\n0 - Make a new contact.\n1 - Process a parcel request.\n2 - Update the status of an overnight parcel.\n3 - Track the status of an overnight parcel.\nOther - Print parcel info and exit this program.\n_____________________________________________" << endl;

	// Ask user to make their choice
	getline(cin, input);
	choice = stoi(input);
	switch (choice) {
	case 0:
		handleContact(); break;
	case 1:
		secondaryMenu(); break;
	case 2:
		updateStatus(); break;
	case 3:
		trackStatus(); break;
	default:
	{
		cout << "Thank you for using the parcel management program. Look below for details on your parcels:" << endl << endl;
		go = false; break;
	}
	}
}

/**
 * Allows the user to track the status of an Overnight Pacel
 */
int trackStatus() {
	// Have the user input the tracking number of the desired parcel
	int choice = stoi(getInputFromUser("Please enter the tracking number of an Overnight Parcel: #"));

	// Check the array for parcels with the same tracking number
	for (int i = 0; i < parcels.size(); i++) {
		if (/*parcels[i].trackingNumber*/1 == choice) {
			// Print out the information for the first parcel that has a matching tracking number
			cout << parcels[i]->toString() << endl;

			// Target the parcel in case it needs to be updated
			//Target = &parcels[i];

			// Return a variable to tell updateStatus() whether or not there's something to update. When trackStatus() is called directly, it's just a dummy.
			return 1;
		}
	}

	// If there is no matching parcel, inform the user
	cout << "Sorry, there are no overnight parcels with the tracking number #" << choice << "." << endl << endl;
	return 0;
}

/**
 * Allows the user to enter the tracking number of an Overnight Parcel to update its status.
 */
void updateStatus() {
	if (trackStatus() == 1) {
		// Have the user input the tracking number of the desired parcel
		int choice = stoi(getInputFromUser("Please select a new status for this parcel:\n1 - In Transition\n2 - Delivered\nOthers - Return to Menu"));
		switch (choice) {
			case 1: {
				Target->setStatus(InTransition);
				cout << "Success! This parcel is now marked as \"In Transition.\"" << endl << endl;
			}
			case 2: {
				Target->setStatus(Delivered);
				cout << "Success! This parcel is now marked as \"Delivered.\"" << endl << endl;
			}
			default: {
				cout << "Returning to menu...." << endl << endl;
			}
		}
	}
}

/**
 * Calls the toString() function for every parcel the user has created.
 */
void printAllParcels() {
	// Fix the decimal precision of the output stream
	cout << fixed;

	// Print out information on all the parcels the user created
	for (int i = 0; i < parcels.size(); i++)
		cout << setprecision(2) << "Parcel #" << i + 1 << ":\n" << parcels[i]->toString() << endl;
}

/**
 * Main method
 * This is where the program starts.
 * @return int,	Program status
 */
int main()
{
	// Initialize the static variables
	initializeStatic();

	// Begin the program's main loop to construct parcels
	do {
		primaryMenu();
	} while (go == true);

	// Print all of the parcels
	printAllParcels();

	// End program
	return -1;
}
