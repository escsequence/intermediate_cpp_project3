#include "Parcel.h"

Parcel::Parcel() {}
Parcel::~Parcel() {}

Parcel(int number, string name, Contact sender, Contact receiver,
  double fee, double weight, double oz){
  this->parcelNumber = number;
  this->name = name;
  this->senderAddress = sender;
  this->receieverAddress = receiver;
  this->fee = fee;
  this->weight = weight;
  this->costPerOz = oz;
}

void Parcel::setName(string name) {
  this->name = name;
}

void Parcel::setSenderAddress(Contact contact) {
  senderAddress = contact;
}

void Parcel::setReceiverAddress(Contact content) {
  receieverAddress = conact;
}

void Parcel::setFee(double fee) {
  this->fee = fee;
}

void Parcel::setWeight(double weight) {
  this->weight = weight;
}

void Parcel::setCostPerOz(double oz) {
  costPerOz = oz;
}

string  Parcel::getName() {
  return name;
}

Contact Parcel::getSenderAddress() {
  return senderContact;
}

Contact Parcel::getReceiverAddress() {
  return receieverAddress;
}

double Parcel::getFee() {
  return fee;
}

double Parcel::getWeight() {
  return weight;
}

double Parcel::getCostPerOz() {
  return costPerOz;
}
