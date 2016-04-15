#include <exception>
using namespace std;

class EmptyHeapException: public exception {

  const char* what() const throw() {

    return "Blad. Kopiec jest pusty.";
    
  }
};
