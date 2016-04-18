#ifndef INTROSORT_HPP
#define INTROSORT_HPP
#include "kopiec.hpp"
#include <vector>
#include <cmath>
using namespace std;

void introsort(vector<int> &array,
	       int from,
	       int to,
	       int max_depth) {

  unsigned int pivot_index;
  int pivot, i;
  vector<int> left, right;
  
  if (from < to) {

    if (max_depth > 0) {
      
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
      
      introsort(array, from, pivot_index-1, max_depth-1);
      introsort(array, pivot_index+1, to, max_depth-1);

    }
    
    else {
      
      kopiec K;

      for (i=from; i<=to; i++)
	K.dodaj(array[i]);

      for (i=from; i<=to; i++)
	array[i] = K.zdejmijMinimalny();
      
    }  
  }
}

#endif
