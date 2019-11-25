/*
* GroundParcel.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/24/2019
*/

/*
* Ground Parcel class definition
*/

#ifndef GROUND_PARCEL_H
#define GROUND_PARCEL_H
#include "Parcel.h"

class GroundParcel : public Parcel
{
public:
	// Constructors
	GroundParcel();
	GroundParcel(int number, std::string name, Contact sender, Contact receiver,
		double fee, double weight, double oz);

	// Destructors
	~GroundParcel();

	//	Overrides
	double calculateCost();
	std::string toString();
};

#endif
