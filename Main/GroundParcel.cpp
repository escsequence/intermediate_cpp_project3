/*
* GroundParcel.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/24/2019
*/

/*
* Ground Parcel class implementation
*/

#include "pch.h"
#include "GroundParcel.h"
#include <string>

using namespace std;

GroundParcel::GroundParcel(){
}

GroundParcel::GroundParcel(int number, std::string name, Contact sender, Contact receiver,
  double fee, double weight, double oz) : Parcel(number, name, sender, receiver,
  fee, weight, oz) {

}


GroundParcel::~GroundParcel(){
}

/**
 * The cost is:
 * weight times cost per ounce + additional fee
 */
double GroundParcel::calculateCost() {
  return (weight * oz) + fee;
}

// Outputs all information about this parcel
string GroundParcel::toString()
{
	string s = "Ground Parcel " + name + " (" + to_string(parcelNumber) + "):\nWeight: " + to_string(weight) + "\n\nFROM:\n" + senderAddress.name + "\n" +
		senderAddress.addressStreet + "\n" + senderAddress.addressCity + ", " + senderAddress.addressState + " " + senderAddress.addressZip + "\n\nTO:\n" + receiverAddress.name + "\n" + receiverAddress.addressStreet
		+ "\n" + receiverAddress.addressCity + ", " + receiverAddress.addressState + " " + receiverAddress.addressZip + "\nSent for $" + to_string(fee) + " and $" + to_string(costPerOz) + " for each ounce over " +
		to_string(standardWeight) + " oz.";

	return s;
}
