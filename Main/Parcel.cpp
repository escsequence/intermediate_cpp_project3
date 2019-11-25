/*
* GroundParcel.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/18/2019
*/

/*
* Parcel class implementation
*/

#include "pch.h"
#include "Parcel.h"

using namespace std;

Parcel::Parcel() {}
Parcel::~Parcel() {}

Parcel::Parcel(int number, string name, Contact sender, Contact receiver, double fee, double weight, double oz)
{
  this->parcelNumber = number;
  this->name = name;
  this->senderAddress = sender;
  this->receiverAddress = receiver;
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

void Parcel::setReceiverAddress(Contact contact) {
  receiverAddress = contact;
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
  return senderAddress;
}

Contact Parcel::getReceiverAddress() {
  return receiverAddress;
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