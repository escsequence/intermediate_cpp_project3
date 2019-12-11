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

enum Status { InTransition, Delivered };

class OvernightParcel : public Parcel
{
protected:
	// The parcel's unique tracking number
	int trackingNumber;

	// The current status of the parcel (whether it is "In Transition" or "Delivered")
	Status state;

public:
	// Constructors
	OvernightParcel();
	OvernightParcel(int number, std::string name, double weight, Contact sender, Contact receiver, int trackingNumber);
	// OvernightParcel(OvernightParcel&);
	// Destructor
	~OvernightParcel();

	//	Getters
	int getTrackingNumber();
	Status getStatus();

	//	Setters
	void setTrackingNumber(int i);
	void setStatus(Status s);

	//	Overrides
	double calculateCost();
	void toString();
};

#endif
