#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */
ostream& operator<<(ostream&, WyrazenieZesp&);
ostream& operator<<(ostream&, Operator&);
istream& operator>>(istream&, WyrazenieZesp&);
istream& operator>>(istream&, Operator&);
LZespolona Wyswietl(LZespolona LZ);
LZespolona utworz(double re, double im);
void Wyswietl(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);

#endif
