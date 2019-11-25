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

// This function asks the user for all the input needed to make a GroundParcel object
void createGroundParcel();

// This function asks the user for all the input needed to make an OvernightParcel object
void createOvernightParcel();

// Prompts the user for a contact and returns it
Contact getContactFromUser(std::string msg);

// This function allows the user to select a pre-existing Contact... or create a new one
Contact handleContact();

// Prompts the user for a value and returns it
std::string getInputFromuser(std::string msg);

#endif
