/*
* OvernightParcel.cpp
* Written by: Alec Ochowski
* Written for: COMPSCI 222 Project 3
* Created on: 11/21/2019
*/

/*
* Class implementation for OvernightParcel
*/

#include "pch.h"
#include "OvernightParcel.h"
#include "Main.h"
#include <string>

using namespace std;

OvernightParcel::OvernightParcel() {}
OvernightParcel::~OvernightParcel() {}

OvernightParcel::OvernightParcel(int number, string name, double weight, Contact sender, Contact receiver, int trackingNumber) :
	Parcel(number, name, weight, sender, receiver)
{
	this->trackingNumber = number;
}

int OvernightParcel::getTrackingNumber() 
{
	return trackingNumber;
}

void OvernightParcel::setTrackingNumber(int trackingNumber)
{
	this->trackingNumber = trackingNumber;
}

/* The cost is:
	(a) Just the basic fee if the weight is below the standard weight 
	(b) The basic fee plus additional charge if it is more than the standard weight.*/
double OvernightParcel::calculateCost()
{
	if (weight <= getStandardWeight())
		return getFee();
	else 
	{
		double extraWeight = weight - getStandardWeight();
		return getFee() + extraWeight * getCostPerOz();
	}
}

// Outputs all information about this parcel
string OvernightParcel::toString()
{	
	string s = name + " (#" + to_string(parcelNumber) + ")\nWeight: " + to_string(getWeight()) + " oz\nTracking Number: " + to_string(trackingNumber) + "\n\nFROM:\n" + 
		senderAddress.toString() + "\n\nTO:\n" + receiverAddress.toString() + "\nSent for $" + to_string(calculateCost()) + "($" + to_string(getFee()) + " basic fee and $" + 
		to_string(getCostPerOz()) + " for each ounce over " + to_string(getStandardWeight()) + " oz).\n\n";

	return s;
}