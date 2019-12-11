#include "pch.h"
#include "VectorIO.h"

template<class T>
void VectorIO<T>::write(std::vector<T> vector) {
  this->openWrite();
  this->writeHeader(vector.size());
  for (int index = 0; index < vector.size(); ++index) {
    this->write(vector[index]);
  }
  this->close();
}

template<class T>
std::vector<T> VectorIO<T>::read() {
  std::vector<T> elements;
  this->openRead();
  unsigned int size = this->readHeader();

  for (int index = 0; index < size; ++index)
    elements.push_back(this->readItem());

  this->close();
}

template<class T>
T VectorIO<T>::itemRead() {
  T n;
  if (isOpen)
    readStream.read(reinterpret_cast<char*> (&n), sizeof(n));
  return n;
}

template<class T>
void VectorIO<T>::itemWrite(T element) {
  if (isOpen)
    writeStream.write(reinterpret_cast<char*> (&element), sizeof(element));
}

template<class T>
void VectorIO<T>::close() {
  if (isOpen) {
    writeStream.close();
    readStream.close();
  }
}

template<class T>
void VectorIO<T>::openWrite() {
  writeStream.open(this->file, std::ios::binary | std::ios::out);
  this->isOpen = true;
}

template<class T>
void VectorIO<T>::openRead() {
  readStream.open(this->file, std::ios::binary | std::ios::in);
  this->isOpen = true;
}

template<class T>
unsigned int VectorIO<T>::readHeader() {
  unsigned int sizeOfVector = 0;
  if (isOpen)
    readStream.read(reinterpret_cast<char*> (&sizeOfVector), sizeof(sizeOfVector));
  return sizeOfVector;
}
