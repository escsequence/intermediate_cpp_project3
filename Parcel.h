#ifndef PARCEL_H
#define PARCEL_H
#include "Contact.h"

class Parcel {
  private:
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

};

#endif
