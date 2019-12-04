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

/**
 * Standard conatructor for OvernightParcel
 */
OvernightParcel::OvernightParcel() {}

/**
 * Destructor for OvernightParcel
 */
OvernightParcel::~OvernightParcel() {}

/**
 * Overloaded Constructor for OvernightParcel
 * @param int,      ParcelNumber
 * @param string,   Name of Parcel
 * @param double,   Weight of Parcel
 * @param Contact,  Sender of Parcel
 * @param Contact,  Receiever of Parcel
 * @param int,			Tracking number
 * @return Parcel, 	Returns a Parcel object
 */
OvernightParcel::OvernightParcel(int number, string name, double weight, Contact sender, Contact receiver, int trackingNumber) :
	Parcel(number, name, weight, sender, receiver)
{
	this->trackingNumber = number;
	this->state = InTransition;
}

/**
 * Get the tracking number for the overnight object
 * @return int,		Tracking number value
 */
int OvernightParcel::getTrackingNumber()
{
	return trackingNumber;
}

/**
 * Get the status of the overnight object
 * @return Status,		State value
 */
Status OvernightParcel::getStatus()
{
	return state;
}

/**
 * Set the tracking number for the overnight object
 * @param int,		New tracking number
 */
void OvernightParcel::setTrackingNumber(int trackingNumber)
{
	this->trackingNumber = trackingNumber;
}

/**
 * Set the tracking number for the overnight object
 * @param Status,		New state
 */
void OvernightParcel::setStatus(Status state)
{
	this->state = state;
}

/**
 * Calculates the cost for OvernightParcel
 * The cost is:
 *	(a) Just the basic fee if the weight is below the standard weight
 *	(b) The basic fee plus additional charge if it is more than the standard weight.
 * @return double,		Value of calculated cost
 */
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

/**
 * Outputs all information about this OvernightParcel
 * @return string,		String value of concatenated values for this object.
 */
string OvernightParcel::toString()
{
	string s = "Overnight Parcel " + name + " (#" + to_string(parcelNumber) + ")\nWeight: " + to_string(getWeight()) + " oz\nTracking Number: " + to_string(trackingNumber) + 
		"\n\nFROM:\n" + senderAddress.toString() + "\n\nTO:\n" + receiverAddress.toString() + "\nSent for $" + to_string(calculateCost()) + "($" + to_string(getFee()) + 
		" basic fee and $" + to_string(getCostPerOz()) + " for each ounce over " + to_string(getStandardWeight()) + " oz).\n\n";

	switch (state) {
		case Delivered: 
		{
			s += "Parcel Status: DELIVERED\n\n";
		}
		case InTransition:
		{
			s += "Pacel Status: IN TRANSITION\n\n";
		}
		default:
		{
			s += "Parcel Status: UNKNOWN\n\n";
		}
	}

	return s;
}
