#include "kopiec.hpp"
using namespace std;

kopiec::kopiec() {

  wysokosc = 0;
  korzen = NULL;
  
}

void kopiec::dodaj(int klucz) {

  nowy = new wezel(klucz);
  
  if (korzen == NULL)
    korzen = ostatni = nowy;

  else if (ostatni->lewySyn == NULL) {
    
      ostatni->lewySyn = nowy;
      ostatni->lewySyn->ojciec = ostatni;
      naprawWGore();
      
  }

  else {
      
    ostatni->prawySyn = nowy;
    ostatni->prawySyn->ojciec = ostatni;
    naprawWGore();
    uaktualnijOstatniPoDodaniu();

  }
}

bool kopiec::jestLisciem(wezel* w) {

  if (w->lewySyn == NULL and w->prawySyn == NULL)
    return true;

  else
    return false;

}

bool kopiec::pusty() {

  if (korzen == NULL)
    return true;

  else
    return false;
}

void kopiec::naprawWGore() {

  wezel* iterator;

  if (ostatni->prawySyn != NULL)
    iterator = ostatni->prawySyn;

  else
    iterator = ostatni->lewySyn;

  while (iterator != korzen and iterator->klucz < iterator->ojciec->klucz) {

    int klucz = iterator->klucz;
    iterator->klucz = iterator->ojciec->klucz;
    iterator->ojciec->klucz = klucz;

    iterator = iterator->ojciec;
    
  }
}

void kopiec::naprawWDol(wezel* &w) {

  int mniejszy;

  if (!pusty() and !jestLisciem(w)) {
  
    if (w->prawySyn != NULL and w->lewySyn->klucz > w->prawySyn->klucz) {

      if (w->prawySyn->klucz < w->klucz) {

	mniejszy = w->prawySyn->klucz;
	w->prawySyn->klucz = w->klucz;
	w->klucz = mniejszy;
	naprawWDol(w->prawySyn);
	
      }
    }
    
    else if (w->prawySyn == NULL or (w->prawySyn != NULL or w->prawySyn->klucz < w->lewySyn->klucz)) {
      
      if (w->lewySyn->klucz < w->klucz) {
	
	mniejszy = w->lewySyn->klucz;
	w->lewySyn->klucz = w->klucz;
	w->klucz = mniejszy;
	naprawWDol(w->lewySyn);
	
      }
    }
  }
}

void kopiec::uaktualnijOstatniPoDodaniu() {
  
  while (ostatni != korzen and ostatni->ojciec->prawySyn == ostatni)
    ostatni = ostatni->ojciec;

  if (ostatni != korzen)
    ostatni = ostatni->ojciec->prawySyn;
  
  while (!jestLisciem(ostatni))
    ostatni = ostatni->lewySyn;
}

void kopiec::uaktualnijOstatniPrzedUsunieciem() {

  if (ostatni->prawySyn == NULL and ostatni->lewySyn == NULL) {
  
    while (ostatni != korzen and ostatni->ojciec->lewySyn == ostatni)
      ostatni = ostatni->ojciec;
    
    if (ostatni != korzen)
      ostatni = ostatni->ojciec->lewySyn;
    
    while (!jestLisciem(ostatni->prawySyn))
      ostatni = ostatni->prawySyn;
  }
}

int kopiec::zdejmijMinimalny() {
  
  if (!pusty()) {
  
    int najmniejszy = korzen->klucz;
      
    if (ostatni != korzen) {

      if (ostatni->lewySyn != NULL) {
	  
	korzen->klucz = ostatni->lewySyn->klucz;
	delete ostatni->lewySyn;
	ostatni->lewySyn = NULL;
	  
      }

      else {
	  
	uaktualnijOstatniPrzedUsunieciem();
	korzen->klucz = ostatni->prawySyn->klucz;
	delete ostatni->prawySyn;
	ostatni->prawySyn = NULL;
	  
      }

      naprawWDol(korzen);
    }

    else if (ostatni->lewySyn != NULL) {

      korzen->klucz = ostatni->lewySyn->klucz;
      delete ostatni->lewySyn;
      ostatni->lewySyn = NULL;
	
    }
      
    else {

      delete korzen;
      ostatni = korzen = NULL;

    }
    
    return najmniejszy;
  }
  
  else
    throw EmptyHeapException();
}

void kopiec::przejdzPoprzecznie(wezel* w) {

  if (w->lewySyn != NULL)
    przejdzPoprzecznie(w->lewySyn);
  if (w->prawySyn != NULL)
    przejdzPoprzecznie(w->prawySyn);
  cout << w->klucz << endl;
  
}

void kopiec::zawartosc() {

  przejdzPoprzecznie(korzen);

}
