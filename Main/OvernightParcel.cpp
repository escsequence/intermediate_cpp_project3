#include "pch.h"
#include "OvernightParcel.h"
#include <string>

using namespace std;

OvernightParcel::OvernightParcel() {}
OvernightParcel::~OvernightParcel() {}

OvernightParcel::OvernightParcel(int number, string name, Contact sender, Contact receiver, double fee, double weight, double oz, int trackingNumber, double standardWeight) :
	Parcel(number, name, sender, receiver, fee, weight, oz)
{
	this->trackingNumber = number;
	this->standardWeight = standardWeight;
}

int OvernightParcel::getTrackingNumber() 
{
	return trackingNumber;
}

double OvernightParcel::getStandardWeight()
{
	return standardWeight;
}

void OvernightParcel::setTrackingNumber(int trackingNumber)
{
	this->trackingNumber = trackingNumber;
}

void OvernightParcel::setStandardWeight(double standardWeight)
{
	this->standardWeight = standardWeight;
}

/* The cost is:
	(a) Just the basic fee if the weight is below the standard weight 
	(b) The basic fee plus additional charge if it is more than the standard weight.*/
double OvernightParcel::calculateCost()
{
	if (weight <= standardWeight)
		return fee;
	else 
	{
		double extraWeight = weight - standardWeight;
		return fee + extraWeight * costPerOz;
	}
}

// Outputs all information about this parcel
string OvernightParcel::toString()
{	
	string s = "Parcel " + name + " (" + to_string(parcelNumber) + "):\nWeight: " + to_string(weight) + "\nTracking Number: " + to_string(trackingNumber) + "\n\nFROM:\n" + senderAddress.name + "\n" + 
		senderAddress.addressStreet + "\n" + senderAddress.addressCity + ", " + senderAddress.addressState + " " + senderAddress.addressZip + "\n\nTO:\n" + receiverAddress.name + "\n" + receiverAddress.addressStreet 
		+ "\n" + receiverAddress.addressCity + ", " + receiverAddress.addressState + " " + receiverAddress.addressZip + "\nSent for $" + to_string(fee) + " and $" + to_string(costPerOz) + " for each ounce over " + 
		to_string(standardWeight) + " oz.";

	return s;
}