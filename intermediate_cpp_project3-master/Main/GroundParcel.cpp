/*
* GroundParcel.cpp
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/24/2019
*/

/*
* Ground Parcel class implementation
*/

#include "pch.h"
#include "GroundParcel.h"
#include "Main.h"
#include <string>

using namespace std;

GroundParcel::GroundParcel(){
}

GroundParcel::GroundParcel(int number, std::string name, double weight, Contact sender, Contact receiver) 
	: Parcel(number, name, weight, sender, receiver) {

}


GroundParcel::~GroundParcel(){
}

/**
 * The cost is:
 * weight times cost per ounce + additional fee
 */
double GroundParcel::calculateCost() {
  return (weight * getCostPerOz()) + getFee();
}

// Outputs all information about this parcel
string GroundParcel::toString()
{
	string s = name + " (#" + to_string(parcelNumber) + ")\nWeight: " + to_string(getWeight()) + " oz\n\nFROM:\n" + senderAddress.toString() + "\n\nTO:\n" + receiverAddress.toString() + 
		"\nSent for $" + to_string(calculateCost()) + "($" + to_string(getFee()) + " basic fee and " + to_string(getCostPerOz()) + " per ounce).\n\n";

	return s;
}
