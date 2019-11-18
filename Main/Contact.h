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
