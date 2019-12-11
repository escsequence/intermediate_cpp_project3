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
#include <iomanip>

using namespace std;

/**
 * Standard conatructor for GroundParcel
 */
GroundParcel::GroundParcel(){
	this->type = Ground;
}

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
	this->type = Ground;
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
void GroundParcel::toString()
{
	cout << setprecision(2);
	cout << "Ground Parcel " << name << " (#" << parcelNumber << ")" << endl;
	cout << "Weight: " << getWeight() << " oz" << endl << endl;
	cout << "FROM:" << endl << senderAddress.toString() << endl << endl;
	cout << "TO:" << endl << receiverAddress.toString() << endl;
	cout << "Sent for $" << calculateCost() << " - ($" << getFee();
	cout << " basic fee and " << getCostPerOz() << " per ounce)." << endl;
	cout << "---------------------------------------------" << endl;
}
