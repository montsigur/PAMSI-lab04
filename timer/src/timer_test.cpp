#include <iostream>
#include "Timer.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

  Timer timer;
  int val = 0;
  double intrmed;
  srand(time(NULL));

  timer.start();

  while (val < 2140000000) val = rand();

  timer.stop();

  intrmed = timer.getElapsedTimeInMicroSec();

  cout << intrmed << " us" << endl;

  timer.start();

  val = 0;
  
  while (val < 2140000000) val = rand();

  timer.stop();

  intrmed = timer.getElapsedTimeInMicroSec();

  cout << intrmed << " us" << endl;
    
  return 0;
}
