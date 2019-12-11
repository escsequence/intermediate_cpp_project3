/*
* Parcel.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/20/2019
*/

/*
* Parcel class definition
*/

#ifndef PARCEL_H
#define PARCEL_H
#include "Contact.h"

enum ParcelType { Ground, Overnight };

class Parcel {
  protected:
    // Parcel information
	ParcelType type;
	int parcelNumber;
    std::string name;
	double weight;

    // Contact information
    Contact senderAddress;
    Contact receiverAddress;

  public:

    // Constructors
    Parcel();
    Parcel(int number, std::string name, double weight, Contact sender, Contact receiver);

    // Destructor
    ~Parcel();

    // Setters
    void setName(std::string);
	  void setWeight(double);
    void setSenderAddress(Contact);
    void setReceiverAddress(Contact);
    void setParcelNumber(int);

    // Getters
    std::string getName();
    double getWeight();
    Contact getSenderAddress();
    Contact getReceiverAddress();
    int getParcelNumber();
	ParcelType getType();

    virtual double calculateCost() = 0;
    virtual void toString() = 0;
};

#endif
