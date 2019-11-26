/*
* Parcel.cpp
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/18/2019
*/

/*
* Class implementation for Parcel
*/

#include "pch.h"
#include "Parcel.h"

using namespace std;

/**
 * Standard conatructor for Parcel
 */
Parcel::Parcel() {}

/**
 * Destructor for Parcel
 */
Parcel::~Parcel() {}

/**
 * Overloaded Constructor for Parcel
 * @param int,      ParcelNumber
 * @param string,   Name of Parcel
 * @param double,   Weight of Parcel
 * @param Contact,  Sender of Parcel
 * @param Contact,  Receiever of Parcel
 * @return Parcel,  zReturns a Parcel object
 */
Parcel::Parcel(int number, string name, double weight, Contact sender, Contact receiver)
{
  this->parcelNumber = number;
  this->name = name;
  this->weight = weight;
  this->senderAddress = sender;
  this->receiverAddress = receiver;
}

/**
 * Set Parcel name
 * @param string,   New Parcel name
 */
void Parcel::setName(string name) {
  this->name = name;
}

/**
 * Set Parcel weight
 * @param double,   New Parcel weight
 */
void Parcel::setWeight(double weight) {
	this->weight = weight;
}

/**
 * Set Parcel sender address
 * @param Contact,   Sender Contact object
 */
void Parcel::setSenderAddress(Contact contact) {
  senderAddress = contact;
}

/**
 * Set Parcel receiever address
 * @param Contact,   Receiever contact object
 */
void Parcel::setReceiverAddress(Contact contact) {
  receiverAddress = contact;
}

/**
 * Set Parcel number
 * @param int,   New parcel number
 */
void Parcel::setParcelNumber(int parcelNo) {
  parcelNumber = parcelNo;
}

/**
 * Returns current parcel number
 * @return int,   Parcel number
 */
int Parcel::getParcelNumber() {
  return parcelNumber;
}

/**
 * Returns current name for parcel
 * @return string,  Parcel name
 */
string  Parcel::getName() {
  return name;
}

/**
 * Returns current weight for parcel
 * @return double,  Parcel weight
 */
double Parcel::getWeight() {
	return weight;
}

/**
 * Returns current sender address for parcel object
 * @return Contact,  Contact object that is the sender address
 */
Contact Parcel::getSenderAddress() {
  return senderAddress;
}

/**
 * Returns current receiever address for parcel object
 * @return Contact,  Contact object that is the receiver address
 */
Contact Parcel::getReceiverAddress() {
  return receiverAddress;
}
