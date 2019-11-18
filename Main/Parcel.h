#ifndef PARCEL_H
#define PARCEL_H
#include "Contact.h"

class Parcel {
  protected:
    // Parcel #
    int parcelNumber;

    // Name of parcel?
    string name;

    // Contact information
    Contact senderAddress;
    Contact receieverAddress;

    // Other attributes of the Parcel object
    double fee;
    double weight;
    double costPerOz;
  public:

    // Constructors
    Parcel();
    Parcel(int number, string name, Contact sender, Contact receiver,
      double fee, double weight, double oz);

    // Destructor
    ~Parcel();

    // Setters
    void setName(string);
    void setSenderAddress(Contact);
    void setReceiverAddress(Contact);
    void setFee(double);
    void setWeight(double);
    void setCostPerOz(double);

    // Getters
    string getName();
    Contact getSenderAddress();
    Contact getReceiverAddress();
    double getFee();
    double getWeight();
    double getCostPerOz();

    virtual double calculateCost() = 0;
    virtual string toString() = 0;
};

#endif
