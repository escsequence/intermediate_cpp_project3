/*
* OvernightParcel.h
* Written by: Alec Ochowski
* Written for: COMPSCI 222 Project 3
* Created on: 11/20/2019
*/

/*
* Overnight Parcel class definition
*/

#ifndef OVERNIGHT_PARCEL_H
#define OVERNIGHT_PARCEL_H
#include "Parcel.h"

class OvernightParcel : public Parcel
{
protected:
	// The parcel's unique tracking number
	int trackingNumber;

public:
	// Constructors
	OvernightParcel();
	OvernightParcel(int number, std::string name, double weight, Contact sender, Contact receiver, int trackingNumber);

	// Destructor
	~OvernightParcel();

	//	Getters
	int getTrackingNumber();

	//	Setters
	void setTrackingNumber(int i);

	//	Overrides
	double calculateCost();
	std::string toString();
};

#endif
