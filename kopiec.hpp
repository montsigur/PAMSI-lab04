#ifndef KOPIEC_HPP
#define KOPIEC_HPP
#include <iostream>
#include "EmptyHeapException.hpp"
using namespace std;

class wezel {

public:

  wezel* lewySyn;
  wezel* prawySyn;
  wezel* ojciec;
  int klucz;
  
  wezel(int wartosc) {

    lewySyn = prawySyn = ojciec = NULL;
    klucz = wartosc;
    
  }
};

class kopiec {

  int wysokosc;
  wezel* korzen;
  wezel* ostatni;
  wezel* nowy;

  void uaktualnijOstatniPoDodaniu();

  void uaktualnijOstatniPoUsunieciu();

  void uaktualnijOstatniPrzedUsunieciem();

  void naprawWGore();

  void naprawWDol(wezel* &w);

  bool jestLisciem(wezel* w);

  bool pusty();

  void przejdzPoprzecznie(wezel* w);

public:

  kopiec();

  void dodaj(int klucz);

  int zdejmijMinimalny();

  void zawartosc();
};

#endif
