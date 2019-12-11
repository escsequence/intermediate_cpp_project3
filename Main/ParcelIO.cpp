/*
* ParcelIO.cpp
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3 Part 2
* Created on: 12/10/2019
*/

#include "pch.h"
#include "ParcelIO.h"
#include "GroundParcel.h"
#include "OvernightParcel.h"
#include "Contact.h"
#include <typeinfo>
#include <fstream>

// Constructor
ParcelIO::ParcelIO (std::string groundFile, std::string overnightFile, std::string contactFile) {
  // groundParcelFileName = groundFile;
  // overnightParcelFileName = overnightFile;
  // contactFileName = contactFile;
}

ParcelIO::ParcelIO() {
  // Do nothing
}

void ParcelIO::setFileLocation(std::string groundFile, std::string overnightFile, std::string contactFile) {
  groundParcelFileName = groundFile;
  overnightParcelFileName = overnightFile;
  contactFileName = contactFile;
  groundParcelFile = new VectorIO<GroundParcel>(groundFile);
  overnightParcelFile = new VectorIO<OvernightParcel>(overnightFile);
  //contactFile = new VectorIO<OvernightParcel>(contactFile);
}

// This function writes both contacts and parcels
void ParcelIO::write(std::vector<Parcel*> &vector, std::vector<Contact> &contacts) {
  writeContacts(contacts);
  writeParcels(vector);
}

void ParcelIO::writeContacts(std::vector<Contact> &contacts) {

  // Create the stream for the contacts
  std::ofstream coFile(contactFileName, std::ios::binary | std::ios::out);

  // Initally writes the size of the contacts
  unsigned int size = contacts.size();
  // Write it as a "header"
  coFile.write(reinterpret_cast<const char*> (&size), sizeof(size));

  // Loop through contacts and write them now
  for (int index = 0; index < contacts.size(); ++index) {
    coFile.write(reinterpret_cast<char*> (&contacts[index]), sizeof(Contact));
  }

  // Close contact file
  coFile.close();
}

// Writes to file
void ParcelIO::writeParcels(std::vector<Parcel*> &vector) {
  // Create streams for ground and overnight
  std::ofstream gpFile(groundParcelFileName, std::ios::binary | std::ios::out),
                opFile(overnightParcelFileName, std::ios::binary | std::ios::out);

  // We need to get the size of the counts to put in the file header
  unsigned int gpCount = groundParcelCount(vector);
  unsigned int opCount = vector.size() - gpCount;

  // Write the "header" values
  gpFile.write(reinterpret_cast<char*> (&gpCount), sizeof(gpCount));
  opFile.write(reinterpret_cast<char*> (&opCount), sizeof(opCount));


  for (int index = 0; index < vector.size(); ++index) {
    //Parcel *parcel = vector[index];
    if (isGroundParcel(vector[index])) { // Parcel is GroundParcel
      GroundParcel* gp = dynamic_cast<GroundParcel*>(vector[index]);
      gpFile.write(reinterpret_cast<char*> (gp), sizeof(*gp));
    } else { // Otherwise it is Overnight
      OvernightParcel* op = dynamic_cast<OvernightParcel*>(vector[index]);
      opFile.write(reinterpret_cast<char*> (op), sizeof(*op));
    }
  }

  // Close the files
  gpFile.close();
  opFile.close();
}

bool ParcelIO::isGroundParcel(Parcel *p) {
  return (typeid(*p).name() == typeid(GroundParcel).name());
}

int ParcelIO::groundParcelCount(std::vector<Parcel*> &vector) {
  unsigned int sizeOfGp = 0;
  for (int index = 0; index < vector.size(); ++index) {
    if (isGroundParcel(vector[index]))
      sizeOfGp++;
  }
  return sizeOfGp;
}

std::vector<OvernightParcel> ParcelIO::readOvernightParcels() {
  std::vector<OvernightParcel> parcels;
  std::ifstream opFile;
  unsigned int overnightParcelSize = 0;

  opFile.open(overnightParcelFileName, std::ios::binary | std::ios::in);
  opFile.read(reinterpret_cast<char*> (&overnightParcelSize), sizeof(overnightParcelSize));
  for (int opIndex = 0; opIndex < overnightParcelSize; ++opIndex) {
    OvernightParcel tempParcel;
    opFile.read(reinterpret_cast<char*> (&tempParcel), sizeof(tempParcel));
    parcels.push_back(tempParcel);
  }
  opFile.close();
  //std::cout << "Overnight Parcel size: " << overnightParcelSize << std::endl;
  return parcels;
}


std::vector<GroundParcel> ParcelIO::readGroundParcels() {
  std::vector<GroundParcel> parcels;
  std::ifstream gpFile;
  unsigned int groundParcelSize = 0;

  gpFile.open(groundParcelFileName, std::ios::binary | std::ios::in);
  gpFile.read(reinterpret_cast<char*> (&groundParcelSize), sizeof(groundParcelSize));
  for (int gpIndex = 0; gpIndex < groundParcelSize; ++gpIndex) {
    GroundParcel tempParcel;
    gpFile.read(reinterpret_cast<char*> (&tempParcel), sizeof(tempParcel));
    parcels.push_back(tempParcel);
  }
  gpFile.close();
  //std::cout << "Ground Parcel size: " << groundParcelSize << std::endl;
  return parcels;
}


std::vector<Contact> ParcelIO::readContacts() {
  std::vector<Contact> contacts;
  unsigned int contactSize = 0;
  std::ifstream coFile;

  coFile.open(contactFileName, std::ios::binary | std::ios::in);
  coFile.read(reinterpret_cast<char*> (&contactSize), sizeof(int));
  for (int index = 0; index < contactSize; ++index) {
    Contact tempContact;
    coFile.read(reinterpret_cast<char*> (&tempContact), sizeof(Contact));
    contacts.push_back(tempContact);
  }
  coFile.close();
  //std::cout << "Contact size: " << contactSize << std::endl;
  return contacts;
}

// Reads the configuration file
std::vector<double> ParcelIO::readConfig() {

  int hasBeenModified = 0;
  double basicFee, standardWeight, costPerOz;

  std::vector<double> config;
  std::ifstream configFile;
  configFile.open(configFileName, std::ios::binary | std::ios::in);

  configFile.read(reinterpret_cast<char*> (&hasBeenModified), sizeof(hasBeenModified));
  if (hasBeenModified) {
    configFile.read(reinterpret_cast<char*> (&basicFee), sizeof(basicFee));
    config.push_back(basicFee);
    configFile.read(reinterpret_cast<char*> (&standardWeight), sizeof(standardWeight));
    config.push_back(standardWeight);
    configFile.read(reinterpret_cast<char*> (&costPerOz), sizeof(costPerOz));
    config.push_back(costPerOz);
  }
  configFile.close();
  return config;
}

void ParcelIO::writeConfig(double basicFee, double standardWeight, double costPerOz) {
  std::ofstream configFile(configFileName, std::ios::binary | std::ios::out);
  int modified = 1;
  configFile.write(reinterpret_cast<char*> (&modified), sizeof(modified));
  configFile.write(reinterpret_cast<char*> (&basicFee), sizeof(basicFee));
  configFile.write(reinterpret_cast<char*> (&standardWeight), sizeof(standardWeight));
  configFile.write(reinterpret_cast<char*> (&costPerOz), sizeof(costPerOz));
  configFile.close();
}

void ParcelIO::setConfigFile(std::string file) {
  configFileName = file;
}
