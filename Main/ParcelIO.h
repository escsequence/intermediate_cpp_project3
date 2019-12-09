#ifndef PARCELIO_H
#define PARCELIO_H
#include<iostream>
#include<vector>
#include "Parcel.h"
class ParcelIO {
  private:
    std::string groundParcelFileName;
    std::string overnightParcelFileName;
    std::string contactFileName;
  public:
    ParcelIO(std::string, std::string, std::string);
    void write(std::vector<Parcel*> &vector, std::vector<Contact> contacts);
    std::vector<Parcel*> read();
};
#endif
