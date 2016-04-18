#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& array, int from, int to) {

  unsigned int pivot_index;
  int pivot, i;
  vector<int> left, right;
  
  if (from < to) {
    
    pivot = array[to];

    for (i=from; i < to; i++) {

      if (pivot > array[i])
	left.push_back(array[i]);

      else
	right.push_back(array[i]);	  
      
    }

    i = from;
    
    for (unsigned int j=0; j < left.size(); i++, j++)
      array[i] = left[j];
    
    pivot_index = i++;
    array[pivot_index] = pivot;
    
    for (unsigned int k=0; k < right.size(); i++, k++)
      array[i] = right[k];
    
    quicksort(array, from, pivot_index-1);
    quicksort(array, pivot_index+1, to);
  }
}

#endif
