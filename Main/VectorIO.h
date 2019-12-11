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
  void writeHeader(unsigned int sizeOfVector);

  unsigned int readHeader();

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

  // Read the vector values from file
  std::vector<T> read();

  // Write vector values from file
  void write(std::vector<T> vector);
};

#endif
