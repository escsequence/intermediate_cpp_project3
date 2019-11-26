/*
* Contact.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3
* Created on: 11/18/2019
*/

/*
* Struct for contacts, includes defintion and implementation
*/

#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

struct Contact {

  // Name
  std::string name;

  // Address
  std::string addressStreet;
  std::string addressCity;
  std::string addressState;
  std::string addressZip;

  // Base constructor
  Contact(){}

  // Overloaded constructor
  Contact(std::string name, std::string street, std::string city,
    std::string state, std::string zip) {
      this->name = name;
      this->addressCity = city;
      this->addressStreet = street;
      this->addressState = state;
      this->addressZip = zip;
  }

  /**
   * Returns a concatenated string of all of variable values.
   * @return string,    concatenated value of all the values.
   */
  std::string toString() {
    return name + "\n" + addressStreet + "\n" + addressCity + ", " + addressState + " " + addressZip + "\n";
  }

};
// A fix for Visual Studio
typedef struct Contact Contact;

#endif
