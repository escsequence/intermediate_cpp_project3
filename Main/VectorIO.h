#ifndef VECTOR_IO_H
#define VECTOR_IO_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>

template <class T>
class VectorIO {
private:

  // streams
  std::ofstream writeStream;
  std::ifstream readStream;

  // File path location
  std::string file;

  // If file is open
  bool isOpen;

  // Header private functions
  void writeHeader(unsigned int sizeOfVector) {
    if (isOpen)
      writeStream.write(reinterpret_cast<char*> (&sizeOfVector), sizeof(sizeOfVector));
  }

  unsigned int readHeader() {
    unsigned int sizeOfVector = 0;
    if (isOpen)
      readStream.read(reinterpret_cast<char*> (&sizeOfVector), sizeof(sizeOfVector));
    return sizeOfVector;
  }

  void openRead();

  void openWrite();

  void close();

  void itemWrite(T element);

  T itemRead();

public:

  // Constructor
  VectorIO() {
    this->isOpen = false;
  }

  VectorIO(std::string file) {
    this->file = file;
    this->isOpen = false;
  }

  ~VectorIO() {
    // close stream if still open
    this->close();
  }

  // Read the vector values from file
  std::vector<T> read();

  // Write vector values from file
  void write(std::vector<T> vector);
};

#endif
