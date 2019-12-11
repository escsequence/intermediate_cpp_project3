/*
* ParcelIO.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3 Part II
* Created on: 12/20/2019
*/
#ifndef PARCELIO_H
#define PARCELIO_H
#include <iostream>
#include <vector>
#include "Parcel.h"
#include "GroundParcel.h"
#include "OvernightParcel.h"
#include "VectorIO.h"

class ParcelIO {
  private:
    std::string groundParcelFileName;
    std::string overnightParcelFileName;
    std::string contactFileName;
    std::string configFileName;

    VectorIO<GroundParcel>    *groundParcelFile;
    VectorIO<OvernightParcel> *overnightParcelFile;
    VectorIO<Contact>         *contactFile;
    VectorIO<double>          *configFile;
  public:
    // Constructors
    ParcelIO();
    ParcelIO(std::string, std::string, std::string);

    // Setters
    void setFileLocation(std::string, std::string, std::string);

    void setConfigFile(std::string);

    int groundParcelCount(std::vector<Parcel*> &vector);

    bool isGroundParcel(Parcel*);

    // Write will write binary files for contacts & parcels
    void write(std::vector<Parcel*> &vector, std::vector<Contact> &contacts);

    // Write out binary file for parcels only
    void writeParcels(std::vector<Parcel*> &vector);

    // Write out binary file for contacts only
    void writeContacts(std::vector<Contact> &contacts);

    std::vector<GroundParcel> readGroundParcels();
    std::vector<OvernightParcel> readOvernightParcels();

    std::vector<Contact> readContacts();

    std::vector<double> readConfig();
    void writeConfig(double, double, double);
};
#endif
