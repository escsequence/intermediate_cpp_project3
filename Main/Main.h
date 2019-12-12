/*
* Main.h
* Written by: Alec Ochowski
* Written for: COMPSCI 222 Project 3
* Created on: 11/25/2019
*/

/*
* Method definitions for the extra methods in the driver (Main.cpp)
*/

#ifndef MAIN_H
#define MAIN_H
#include "VectorIO.h"
#include "Contact.h"
#include "OvernightParcel.h"
#include "Parcel.h"
#include "OvernightParcel.h"
#include "GroundParcel.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


// Variables used to run the loops and switches
static bool go = true;
static int choice = 0;
static int ContactsSize = 0;

// Variables used to create parcels
static bool creation = false;
static double BasicFee;
static double StandardWeight;
static double CostPerOunce;
static OvernightParcel *Target;

// This funciton asks the user for all the values needed for the program's static variables
void initializeStatic(bool override = false);

// This function sets up the location for reading the input and outputs
void initializeFileIO();

// This is the menu to get whether the user wants to modify the config or contacts
void modifyConfigOrContact();

// This function asks the user for all the input needed to make a GroundParcel object
void createGroundParcel();

// This function asks the user for all the input needed to make an OvernightParcel object
void createOvernightParcel();

//Keeps prompting the user for input until they return something valid
int validateInputI(std::string instructions, bool choice = false);

//Keeps prompting the user for input until they return something valid
double validateInputD(std::string instructions);

// The standard initalization of a base Parcel object
void initParcel(Parcel &p);

// Allows the user to track the status of an Overnight Pacel
int trackStatus();

// Allows the user to enter the tracking number of an Overnight Parcel to update its status.
void updateStatus();

// Prompts the user for a contact and returns it
Contact* getContactFromUser(std::string msg);

// This function allows the user to select a pre-existing Contact... or create a new one
Contact* handleContact();

// Creates a new Contact with user input
Contact MakeNewContact();

// Prompts the user for a value and returns it
std::string getInputFromUser(std::string msg);

// Loads in data from the file binary
void readFileData();

void writeFileData();

// Getters
double getFee();
double getStandardWeight();
double getCostPerOz();

// Setters
void setFee(double fee);
void setStandardWeight(double weight);
void setCostPerOz(double oz);

#endif
