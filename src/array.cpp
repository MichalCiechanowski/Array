#include <iostream>
#include <cstdarg>

#include "array.h"

Array::Array() {
  this->array = 0;
  this->size = 0;
}

int Array::getSize() {
  return this->size;
}

int Array::at(int position) {
  if (position >= size) {
    std::cout << "Position out of range!\nSize of array is: " << this->size << " and you called " << position + 1 << " element.\n";
    exit(-1);
  }
  return *(this->array + position);
}

int* Array::begin() {
  return this->array;
}


int* Array::end() {
  return this->array + this->size - 1;
}

void Array::append(int value) {
  *(&this->array + this->size * sizeof(int)) = new int;
  *(this->array + this->size) = value;
  this->size++;
}

void Array::pop() {
  if (this->size == 0) {
    std::cout << "Can't pop from empty array.\n";
    return;
  }
  delete *(&this->array + (this->size - 1) * sizeof(int));
  this->size--;
}

void Array::print() {
  if (this->size == 0) {
    std::cout << "Array is empty\n";
    return;
  }
  std::cout << "[";
  for (int i = 0; i < this->size; i++) {
    if (i + 1 == this->size) {
      std::cout << *(this->array + i) << "]\n";
    } else {
      std::cout << *(this->array + i) << ", ";
    }
  }
}

void Array::printMore() {
  if (this->size == 0) {
    std::cout << "Array is empty\n";
    return;
  }
  for (int i = 0; i < this->size; i++) {
    if (i + 1 == this->size) {
      std::cout << "Adress: " << this->array + i << " Value: "<< *(this->array + i) << "\n";
    } else {
      std::cout << "Adress: " << this->array + i << " Value: "<< *(this->array + i) << "\n";
    }
  }
}

void Array::fill(std::initializer_list<int> valuse) {
  for (int i = 0; i < valuse.size(); i++) {
    append(*(valuse.begin() + i));
  }
}

void Array::clear() {
  this->size = 0;
  delete array;
}

Array::~Array() {
  delete array;
}
