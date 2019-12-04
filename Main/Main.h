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
#include "Contact.h"
#include "OvernightParcel.h"

// Variables used to run the loops and switches
static bool go = true;
static int choice = 0;

// Variables used to create parcels
static double BasicFee;
static double StandardWeight;
static double CostPerOunce;
static OvernightParcel *Target;

// This funciton asks the user for all the values needed for the program's static variables
void initializeStatic();

// This function asks the user for all the input needed to make a GroundParcel object
void createGroundParcel();

// This function asks the user for all the input needed to make an OvernightParcel object
void createOvernightParcel();

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

// Prompts the user for a value and returns it
std::string getInputFromUser(std::string msg);

// Getters
double getFee();
double getStandardWeight();
double getCostPerOz();

// Setters
void setFee(double fee);
void setStandardWeight(double weight);
void setCostPerOz(double oz);

#endif
