#include "mergesort.hpp"
#include "quicksort.hpp"
#include "introsort.hpp"
#include "heapsort.hpp"
#include "timer/src/Timer.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

double wspolczynnik(int rozmiar) {

  return (2 * pow(rozmiar, 2) * log2(rozmiar) - pow(rozmiar, 2) / log(2) + 1 / log(2))
       / (4 * rozmiar * pow(log2(rozmiar), 2) - 8 / log(2) * rozmiar * log2(rozmiar) + 8 / pow(log(2), 2) * (rozmiar - 1));
  
}

void pomiar(vector<int>* tablice,
	    double stopien_posortowania,
	    unsigned int nr_algorytmu) {


  string nazwa_pliku("pomiar");
  char buffer[30];
  
  switch (nr_algorytmu) {

  case 1:
    sprintf(buffer, "_mergesort_%.1f%%.dat", stopien_posortowania*100);
    break;
    
  case 2:
    sprintf(buffer, "_quicksort_%.1f%%.dat", stopien_posortowania*100);
    break;

  case 3:
    sprintf(buffer, "_introsort_%.1f%%.dat", stopien_posortowania*100);
    break;
    
  }

  nazwa_pliku += string(buffer);
  
  srand(time(NULL));
  int ostatni;
  Timer timer;
  double c = 0;
  ofstream plik(nazwa_pliku);
  
  for (int rozmiar : {100}) {
    
    for (int i=0; i<100; i++)
      tablice[i].clear();

    ostatni = rozmiar * abs(stopien_posortowania) - 1;
    
    for (int i=0; i<100; i++)
      for (int j=0; j<rozmiar; j++)
	tablice[i].push_back(rand());

    for (int i=0; i<100; i++)
      introsort(tablice[i], 0, ostatni, 0);

    if (stopien_posortowania < 0)
      for (int i=0; i<100; i++) {

	vector<int> temp;
	for (int j=rozmiar-1; j>-1; j--)
	  temp.push_back(tablice[i][j]);
	
	tablice[i].clear();
	
	for (int j=0; j<rozmiar; j++)
	  tablice[i].push_back(temp[j]);

	temp.clear();
      }
	
    switch (nr_algorytmu) {

    case 1:
    
      timer.start();
      for (int i=0; i<100; i++)
	mergesort(tablice[i], 0, rozmiar-1);
      timer.stop();
      plik << timer.getElapsedTimeInMilliSec() << endl;
      break;

    case 2:
      
      timer.start();
      for (int i=0; i<100; i++)
	quicksort(tablice[i], 0, rozmiar-1);
      timer.stop();
      plik << timer.getElapsedTimeInMilliSec() << endl;
      break;

    case 3:
      
      // c = wspolczynnik(rozmiar);
      c = 1.39;
    
      timer.start();
      for (int i=0; i<100; i++)
	introsort(tablice[i], 0, rozmiar-1, c * log2(rozmiar));
      timer.stop();
      plik << timer.getElapsedTimeInMilliSec() << endl;
      break;

    }
  }
  
  for (int i=0; i<100; i++)
    tablice[i].clear();
    
  plik.close();
}

int main(int argc, char** argv) {

  vector<int>* tablice = new vector<int>[100];

  // if (argc > 1) {
  
  //   string algorytm(argv[1]);

  //   if (algorytm == string("mergesort"))
  //     pomiar(tablice, 0, 1, "pomiar_mergesort.dat");

  //   else if (algorytm == string("quicksort"))
  //     pomiar(tablice, 0, 2, "pomiar_quicksort.dat");

  //   else if (algorytm == string("introsort"))
  //     pomiar(tablice, 0, 3, "pomiar_introsort.dat");
    
  // }

  for (int i=1; i<4; i++)
    for (double s : {0.0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, -1.0})
      pomiar(tablice, s, i);

}
