/*
* GroundParcel.cpp
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/24/2019
*/

/*
* Class implementation for GroundParcel
*/

#include "pch.h"
#include "GroundParcel.h"
#include "Main.h"
#include <string>

using namespace std;

/**
 * Standard conatructor for GroundParcel
 */
GroundParcel::GroundParcel(){}

/**
 * Destructor for GroundParcel
 */
GroundParcel::~GroundParcel(){}

/**
 * Overloaded Constructor for GroundParcel
 * @param int,      ParcelNumber
 * @param string,   Name of Parcel
 * @param double,   Weight of Parcel
 * @param Contact,  Sender of Parcel
 * @param Contact,  Receiever of Parcel
 * @return Parcel, 	Returns a Parcel object
 */
GroundParcel::GroundParcel(int number, std::string name, double weight, Contact sender, Contact receiver)
	: Parcel(number, name, weight, sender, receiver) {
}

/**
 * Calculates the cost for GroundParcel
 * The cost is:
 * weight times cost per ounce + additional fee
 * @return double,		Value of calculated cost
 */
double GroundParcel::calculateCost() {
  return (weight * getCostPerOz()) + getFee();
}

/**
 * Outputs all information about this GroundParcel
 * @return string,		String value of concatenated values for this object.
 */
string GroundParcel::toString()
{
	string s = "Ground Parcel " + name + " (#" + to_string(parcelNumber) + ")\nWeight: " + to_string(getWeight()) + " oz\n\nFROM:\n" + senderAddress.toString() + "\n\nTO:\n" 
		+ receiverAddress.toString() + "\nSent for $" + to_string(calculateCost()) + "($" + to_string(getFee()) + " basic fee and " + to_string(getCostPerOz()) + " per ounce).\n\n";

	return s;
}
