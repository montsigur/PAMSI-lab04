#include "mergesort.hpp"
#include "quicksort.hpp"
#include "introsort.hpp"
#include "timer/src/Timer.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

double wspolczynnik(int rozmiar) {

  return (2 * pow(rozmiar, 2) * log2(rozmiar) - pow(rozmiar, 2) / log(2) + 1 / log(2))
       / (4 * rozmiar * pow(log2(rozmiar), 2) - 8 / log(2) * rozmiar * log2(rozmiar) + 8 / pow(log(2), 2) * (rozmiar - 1));
  
}

void pomiar(vector<int>* tablice, double stopien_posortowania) {

  srand(time(NULL));
  int ostatni;
  Timer timer;
  ofstream plik("pomiar3.dat");
  double c = 0;
  
  for (int rozmiar : {10000, 100000}) {

    ostatni = rozmiar * stopien_posortowania - 1;
    
    for (int i=0; i<100; i++)
      for (int j=0; j<rozmiar; j++)
	tablice[i].push_back(rand());

    for (int i=0; i<100; i++)
      introsort(tablice[i], 0, ostatni, 0);
    
    timer.start();
    for (int i=0; i<100; i++)
      mergesort(tablice[i], 0, rozmiar-1);
    timer.stop();
    plik << timer.getElapsedTimeInMilliSec() << " ";

    for (int i=0; i<100; i++)
      for (int j=0; j<rozmiar; j++)
	tablice[i][j] = rand();

    for (int i=0; i<100; i++)
      introsort(tablice[i], 0, ostatni, 0);
    
    timer.start();
    for (int i=0; i<100; i++)
      quicksort(tablice[i], 0, rozmiar-1);
    timer.stop();
    plik << timer.getElapsedTimeInMilliSec() << " ";

    for (int i=0; i<100; i++)
      for (int j=0; j<rozmiar; j++)
	tablice[i][j] = rand();
    
    for (int i=0; i<100; i++)
      introsort(tablice[i], 0, ostatni, 0);

    // c = wspolczynnik(rozmiar);
    
    timer.start();
    for (int i=0; i<100; i++)
      introsort(tablice[i], 0, rozmiar-1, c * log2(rozmiar));
    timer.stop();
    plik << timer.getElapsedTimeInMilliSec() << endl;

    for (int i=0; i<100; i++)
      tablice[i].clear();
  }

  plik.close();
}

int main() {

  vector<int>* tablice = new vector<int>[100];

  pomiar(tablice, 0);

  return 0;
  
}
