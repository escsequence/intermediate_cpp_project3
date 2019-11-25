/*
* Contact.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/18/2019
*/

/*
* Struct for contacts
*/

#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

typedef struct Contact {

  // Name
  std::string name;

  // Address
  std::string addressStreet;
  std::string addressCity;
  std::string addressState;
  std::string addressZip;

  Contact(){}

  // Constructor
  Contact(std::string name, std::string street, std::string city,
    std::string state, std::string zip) {
      this->name = name;
      this->addressCity = city;
      this->addressStreet = street;
      this->addressState = state;
      this->addressZip = zip;
  }


  std::string toString() {
    return "Contact " + name + "\nAddress (" + addressStreet + ", " + addressCity + " " + addressState + " " + addressZip + "\n";
  }

};
#endif
