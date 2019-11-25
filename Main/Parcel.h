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

class Parcel {
  protected:
    // Parcel #
    int parcelNumber;

    // Name of parcel?
    std::string name;

    // Contact information
    Contact senderAddress;
    Contact receiverAddress;

    // Other attributes of the Parcel object
    double fee;
    double weight;
    double costPerOz;
  public:

    // Constructors
    Parcel();
    Parcel(int number, std::string name, Contact sender, Contact receiver,
      double fee, double weight, double oz);

    // Destructor
    ~Parcel();

    // Setters
    void setName(std::string);
    void setSenderAddress(Contact);
    void setReceiverAddress(Contact);
    void setFee(double);
    void setWeight(double);
    void setCostPerOz(double);

    // Getters
    std::string getName();
    Contact getSenderAddress();
    Contact getReceiverAddress();
    double getFee();
    double getWeight();
    double getCostPerOz();

    virtual double calculateCost() = 0;
    virtual std::string toString() = 0;
};

#endif
