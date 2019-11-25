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
};
#endif
