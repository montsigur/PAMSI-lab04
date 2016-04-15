#include "kopiec.hpp"
#include <vector>
using namespace std;

void add_numbers_to(vector<int>& v) {

  int num;

  while (true) {
    
    cin >> num;
    
    if (!cin.fail())
      v.push_back(num);
    
    else {
      
      cin.clear();
      cin.sync();
      break;

    }
  }
}

void heapsort(vector<int> &array, unsigned int from, unsigned int to) {

  kopiec K;

  if (from < to) {

    for (unsigned int i=from; i<=to; i++)
      K.dodaj(array[i]);

    for (unsigned int i=from; i<=to; i++)
      array[i] = K.zdejmijMinimalny();
  }
}

int main() {

  vector<int> A;

  add_numbers_to(A);
  
  heapsort(A, 0, array.size()-1);

  for (unsigned int i=0; i<A.size(); i++) {

    cout << A[i] << endl;

  }
  
  return 0;
  
}
