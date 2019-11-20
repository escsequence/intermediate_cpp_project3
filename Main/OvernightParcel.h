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
	
	// The maximum weight of a parcel before an extra cost per ounce is charged
	double standardWeight;
public:
	// Constructors
	OvernightParcel();
	OvernightParcel(int number, std::string name, Contact sender, Contact receiver, double fee, double weight, double oz, int trackingNumber, double standardWeight);

	// Destructor
	~OvernightParcel();

	//	Getters
	int getTrackingNumber();
	double getStandardWeight();

	//	Setters
	void setTrackingNumber(int i);
	void setStandardWeight(double d);

	//	Overrides
	double calculateCost() override;
	std::string toString() override;
};

#endif