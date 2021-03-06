#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*
void Wyswietl(WyrazenieZesp WyrZ)

  cout << LZespolona << WyrZ;
}
*/
//Przeciązenie operatora do wyświetlania Wyrazenia zespolonego
ostream& operator<<(ostream& os, WyrazenieZesp& wyr) {
	os << wyr.Arg1 << wyr.Op << wyr.Arg2;
	return os;
}

ostream& operator<<(ostream& os, Operator& op) {
  char znak;
 
  switch(op) {
    case Op_Dodaj:
      znak = '+';
      break;
    case Op_Odejmij:
      znak = '-';
      break;
    case Op_Mnoz:
      znak = '*';
      break;
    case Op_Dziel:
      znak ='/';
      break;
  }
  os<<znak;
  return os;
}

//Przeciążenie operatora do wczytywania Wyrazenia zespolonego
istream& operator>>(istream& is, WyrazenieZesp& wyr) {
	is >> wyr.Arg1 >> wyr.Op >> wyr.Arg2;
	return is;
}

istream& operator>>(istream& is, Operator& op) {
  char znak;
  is >> znak;
  switch(znak) {
    case '+':
      op = Op_Dodaj;
      break;
    case '-':
      op = Op_Odejmij;
      break;
    case '*':
      op = Op_Mnoz;
      break;
    case '/':
      op = Op_Dziel;
      break;
  }
  return is;
}


LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    LZespolona Wynik;
    
  switch(WyrZ.Op){

  case Op_Dodaj:
    Wynik=WyrZ.Arg1+WyrZ.Arg2;
  break;

  case Op_Odejmij:
    Wynik=WyrZ.Arg1-WyrZ.Arg2;  
  break;

  case Op_Mnoz:
    Wynik=WyrZ.Arg1*WyrZ.Arg2;
  break;

  case Op_Dziel:
    Wynik=WyrZ.Arg1/WyrZ.Arg2;
  break;
  }
  return Wynik;
}
