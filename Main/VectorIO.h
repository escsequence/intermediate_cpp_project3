/*
* VectorIO.h
* Written by: James Johnston
* Written for: COMPSCI 222 Project 3 Part II
* Created on: 12/11/2019
*
* The purpose of this class is to write/read vectors
* from files easily.
*
* !!! THIS IS IN THE HEADER TO PREVENT LINKER ISSUES !!!
* Linker issues were unavoidable in the creation of this template
*/

#ifndef VECTOR_IO_H
#define VECTOR_IO_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

template <typename T>
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

  // Consutrctor overriden
  VectorIO(std::string file) {
    this->file = file;
    this->isOpen = false;
  }

  // Read the vector values from file
  std::vector<T> read();

  // Write vector values to a file
  void write(std::vector<T> vector);
};

/**
 * This function writes out vector data of the
 * template specified when initializing the class.
 * @param vector<T>,    Data to output to a file
 */
template<typename T>
void VectorIO<T>::write(std::vector<T> vector) {

  // Open the file, so nothing else can be done
  openWrite();

   // Header is used to track the amount of elements
  writeHeader(vector.size());

  // Loop through all of the vector elements
  for (int index = 0; index < vector.size(); ++index) {

    // Write the item to the file
    this->itemWrite(vector[index]);

  }

  // Close the file now
  close();
}

/**
 * This function reads the vector data from the
 * template specified when initializing the class.
 * @return vector<T>,    Organized data from the file
 */
template<typename T>
std::vector<T> VectorIO<T>::read() {

  // Create a temporary element vector
  std::vector<T> elements;

  // Open the file, so nothing else can be done
  openRead();

  // Get the size from the header portion of the file
  unsigned int size = readHeader();

  // Loop through the size we got from the header
  for (int index = 0; index < size; ++index) {

    // read each element
    elements.push_back(itemRead());

  }

  // Close the file now
  close();

  // Return the results from the file
  return elements;
}

/**
 * Read an individual element from the open file
 * @return T,    Single element from the file
 */
template<typename T>
T VectorIO<T>::itemRead() {
  // Create temporary item
  T n;
  if (isOpen) // check if the stream is open
    readStream.read(reinterpret_cast<char*> (&n), sizeof(n)); //if not... read

  // Return the value
  return n;
}

/**
 * Write an individual element to the open file
 * @param T,    Single element to the file
 */
template<typename T>
void VectorIO<T>::itemWrite(T element) {
  // Check if stream is open
  if (isOpen)
    writeStream.write(reinterpret_cast<char*> (&element), sizeof(element));
}

/**
 * Closes the streams and sets the to status "closed"
 */
template<class T>
void VectorIO<T>::close() {
  if (isOpen) {
    writeStream.close();
    readStream.close();
    isOpen = false;
  }
}

/**
 * Opens the file to enable writing
 */
template<typename T>
void VectorIO<T>::openWrite() {
  if (!isOpen) {
    writeStream.open(file, std::ios::out);
    isOpen = true;
  } else {
    std::cout << "!! Unable to open a write to file '" << file;
    std::cout << "'. File is open. !!" << std::endl;
  }
}

/**
 * Opens the file to enable reading
 */
template<typename T>
void VectorIO<T>::openRead() {
  if (!isOpen) {
    readStream.open(file, std::ios::in);
    isOpen = true;
  } else {
    std::cout << "!! Unable to open a read to file '" << file;
    std::cout << "'. File is open. !!" << std::endl;
  }
}

/**
 * Reads the header data (always the first thing)
 * @return unsigned int,    vector size count
 */
template<typename T>
unsigned int VectorIO<T>::readHeader() {
  unsigned int sizeOfVector = 0;
  if (isOpen)
    readStream.read(reinterpret_cast<char*> (&sizeOfVector), sizeof(sizeOfVector));
  return sizeOfVector;
}

/**
 * Writes the header data (always the first thing)
 * @param unsigned int,    vector size count
 */
template<typename T>
void VectorIO<T>::writeHeader(unsigned int sizeOfVector) {
  if (isOpen)
    writeStream.write(reinterpret_cast<char*> (&sizeOfVector), sizeof(sizeOfVector));
}

#endif
