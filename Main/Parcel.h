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

    double fee;
    double weight;
    double costPerOz;
  public:

    // Constructors
    Parcel() {}
    Parcel(int number, string name, Contact sender, Contact receiver, double fee, double weight, double oz) {
      this->parcelNumber = number;
      this->name = name;
      this->senderAddress = sender;
      this->receieverAddress = receiver;
      this->fee = fee;
      this->weight = weight;
      this->costPerOz = oz;
    }

    // Destructor
    ~Parcel() {}

    // Setters
    void setName(string name){this->name = name;}
    void setSenderAddress(Contact contact) {senderAddress = contact;}
    void setReceiverAddress(Contact content) {receieverAddress = conact;}
    void setFee(double fee) {this->fee = fee;}
    void setWeight(double weight) {this->weight = weight;}
    void setCostPerOz(double oz) {costPerOz = oz;}

    // Getters
    string getName() {return name;}
    Contact getSenderAddress() {return senderContact;}
    Contact getReceiverAddress() {return receieverAddress;}
    double getFee() {return fee;}
    double getWeight() {return weight;}
    double getCostPerOz() {return costPerOz;}

    double calculateCost();

    virtual string toString() = 0;
};

#endif
