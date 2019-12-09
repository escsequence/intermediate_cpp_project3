#include "ParcelIO.h"
#include "GroundParcel.h"
#include "OvernightParcel.h"
#include "Contact.h"
#include <fstream>

// Constructor
ParcelIO::ParcelIO (std::string groundFile, std::string overnightFile, std::string contactFile) {
  groundParcelFileName = groundFile;
  overnightParcelFileName = overnightFile;
}


// Writes to file
void ParcelIO::write(std::vector<Parcel*> &vector, std::vector<Contact> contacts) {

  // Create streams for ground and overnight
  std::ofstream gpFile(groundParcelFileName, std::ios::binary | std::ios::out),
                opFile(overnightParcelFileName, std::ios::binary | std::ios::out),
                coFile(contactFileName, std::ios::binary | std::ios::out);

  // First write out the contacts
  for (Contact c : contacts) {
    coFile.write(reinterpret_cast<char*> (&c), sizeof(Contact));
  }

  // Loop through parcel items
  for (Parcel* p : vector) {
    if (dynamic_cast<GroundParcel*>(p)) { // Parcel is GroundParcel
      gpFile.write(reinterpret_cast<char*> (p), sizeof(GroundParcel));
    } else { // Otherwise it is Overnight
      opFile.write(reinterpret_cast<char*> (p), sizeof(GroundParcel));

    }
  }

  // Close the files
  gpFile.close();
  opFile.close();
}

// Reads file
std::vector<Parcel*> ParcelIO::read() {

}
