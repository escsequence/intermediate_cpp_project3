#include "ParcelIO.h"
#include "GroundParcel.h"
#include "OvernightParcel.h"
#include "Contact.h"
#include <fstream>

// Constructor
ParcelIO::ParcelIO (std::string groundFile, std::string overnightFile, std::string contactFile) {
  groundParcelFileName = groundFile;
  overnightParcelFileName = overnightFile;
  contactFileName = contactFile;
}


// Writes to file
void ParcelIO::write(std::vector<Parcel*> &vector, std::vector<Contact> contacts) {

  // Create streams for ground and overnight
  std::ofstream gpFile(groundParcelFileName, std::ios::binary | std::ios::out),
                opFile(overnightParcelFileName, std::ios::binary | std::ios::out),
                coFile(contactFileName, std::ios::binary | std::ios::out);
  // First write out the contacts
  // Initally writes the size of the contacts
  unsigned int size = contacts.size();
  coFile.write(reinterpret_cast<const char*> (&size), sizeof(int));
  std::cout << "Writing out " << contacts.size() << " contacts" << std::endl;
  // Loop through contacts
  // for (Contact c : contacts) {
  //   coFile.write(reinterpret_cast<char*> (&c), sizeof(Contact));
  // }

  coFile.close();

  // // Loop through parcel items
  // gpFile.write(reinterpret_cast<char*> (groundParcelCount(vector)), sizeof(int));
  // opFile.write(reinterpret_cast<char*> (vector.size() - groundParcelCount(vector)), sizeof(int));
  //
  // for (Parcel* p : vector) {
  //   if (dynamic_cast<GroundParcel*>(p)) { // Parcel is GroundParcel
  //     gpFile.write(reinterpret_cast<char*> (p), sizeof(GroundParcel));
  //   } else { // Otherwise it is Overnight
  //     opFile.write(reinterpret_cast<char*> (p), sizeof(OvernightParcel));
  //   }
  // }
  //
  // // Close the files
  // gpFile.close();
  opFile.close();
}

int ParcelIO::groundParcelCount(std::vector<Parcel*> v) {
  int val;
  for (int index = 0; index < v.size(); ++index)
    if (dynamic_cast<GroundParcel*>(v[index]))
      val++;
  return val;
}

// Reads file
std::vector<Parcel*> ParcelIO::read() {
  std::vector<Parcel*> parcels;
  std::ifstream gpFile, opFile, coFile;

  unsigned int contactSize = 0;
  unsigned int groundParcelSize = 0;
  unsigned int overnightParcelSize = 0;

  // Reading the contacts
  coFile.open(contactFileName, std::ios::binary | std::ios::in);
  coFile.read(reinterpret_cast<char*> (&contactSize), sizeof(int));
  coFile.close();
  std::cout << "Contact size: " << contactSize << std::endl;

  // Reading the ground parcels
  gpFile.open(groundParcelFileName, std::ios::binary | std::ios::in);
  gpFile.read(reinterpret_cast<char*> (&groundParcelSize), sizeof(int));
  gpFile.close();
  std::cout << "Ground Parcel size: " << groundParcelSize << std::endl;

  // Reading the overnight parcels
  opFile.open(overnightParcelFileName, std::ios::binary | std::ios::in);
  opFile.read(reinterpret_cast<char*> (&overnightParcelSize), sizeof(int));
  opFile.close();
  std::cout << "Overnight Parcel size: " << overnightParcelSize << std::endl;

  return parcels;

}
