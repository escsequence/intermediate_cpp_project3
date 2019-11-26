/*
* Parcel.cpp
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

Parcel::Parcel(int number, string name, double weight, Contact sender, Contact receiver)
{
  this->parcelNumber = number;
  this->name = name;
  this->weight = weight;
  this->senderAddress = sender;
  this->receiverAddress = receiver;
}

void Parcel::setName(string name) {
  this->name = name;
}

void Parcel::setWeight(double weight) {
	this->weight = weight;
}

void Parcel::setSenderAddress(Contact contact) {
  senderAddress = contact;
}

void Parcel::setReceiverAddress(Contact contact) {
  receiverAddress = contact;
}

string  Parcel::getName() {
  return name;
}

double Parcel::getWeight() {
	return weight;
}

Contact Parcel::getSenderAddress() {
  return senderAddress;
}

Contact Parcel::getReceiverAddress() {
  return receiverAddress;
}