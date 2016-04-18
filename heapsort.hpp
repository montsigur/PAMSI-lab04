#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include "kopiec.hpp"
#include <vector>
using namespace std;

void heapsort(vector<int> &array, unsigned int from, unsigned int to) {

  kopiec K;

  if (from < to) {

    for (unsigned int i=from; i<=to; i++)
      K.dodaj(array[i]);

    for (unsigned int i=from; i<=to; i++)
      array[i] = K.zdejmijMinimalny();
  }
}

#endif
