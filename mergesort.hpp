#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int>& array, unsigned int from, unsigned int to) {

  unsigned int i, j, k, middle;
  vector<int> left, right;

  i = j = 0;
  k = from;

  if (from < to) {

    middle = (from + to) / 2;
    mergesort(array, from, middle);
    mergesort(array, middle+1, to);

    for (k = from; k <= middle; k++)
      left.push_back(array[k]);

    for (k = middle+1; k <= to; k++)
      right.push_back(array[k]);

    k = from;

    while (i < left.size() or j < right.size()) {

      if (i == left.size() or (j < right.size() and left[i] > right[j]))
	array[k++] = right[j++];

      else if (j == right.size() or (i < left.size() and left[i] <= right[j]))
	array[k++] = left[i++];
    }
  }
}

#endif
