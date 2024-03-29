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
#include <iomanip>

using namespace std;

/**
 * Standard conatructor for OvernightParcel
 */
OvernightParcel::OvernightParcel() {
	this->state = InTransition;
	this->type = Overnight;
}

// OvernightParcel::OvernightParcel(OvernightParcel &op) {
// 	this->parcelNumber = op.getParcelNumber();
// 	this->trackingNumber = op.getTrackingNumber();
// 	this->name = op.getName();
// 	this->weight = op.getWeight();
// 	this->senderAddress = op.getSenderAddress();
// 	this->receiverAddress = op.getReceiverAddress();
// }
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
	this->trackingNumber = trackingNumber;
	this->state = InTransition;
	this->type = Overnight;
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
void OvernightParcel::toString()
{
	cout << setprecision(2);
	cout << "Overnight Parcel " << name << " (#" << parcelNumber << ")" << endl;
	cout << "Weight: " << getWeight() << " oz" << endl;
	cout << "Tracking Number: #" << trackingNumber << endl << endl;
	cout << "FROM:" << endl << senderAddress.toString() << endl << endl;
	cout << "TO:" << endl << receiverAddress.toString() << endl;
	cout << "Sent for $" << calculateCost() << "($" << getFee();
	cout << " basic fee and $" << getCostPerOz() << " for each ounce over ";
	cout << getStandardWeight() << " oz.)." << endl << endl;

	switch (state) {
		case Delivered:
		{
			cout << "Parcel Status: DELIVERED" << endl << endl;
			break;
		}
		case InTransition:
		{
			cout << "Parcel Status: IN TRANSITION" << endl << endl;
			break;
		}
		default:
		{
			cout << "Parcel Status: UNKNOWN" << endl << endl;
		}
	}
	cout << "---------------------------------------------" << endl;
}
