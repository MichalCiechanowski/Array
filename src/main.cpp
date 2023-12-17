#include <iostream>

#include "array.h"


int main() {
  Array arr;

  int tab[4] = {1, 2, 3, 4};

  arr.fill({1});

  arr.printMore();

  return 0;
}
