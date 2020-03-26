#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"
using namespace std;

int main(int argc, char **argv)
{
  // Wczytywanie, wyswietlanie liczby zespolonej i obliczanie wyrazenia zespolonego test
  // LZespolona L1=utworz(2,1);
  //cout << L1 << endl;
  //LZespolona L2=utworz(1,2);
  //cout << L2 << endl;
  //LZespolona L3=L1+L2;
  //cout << L3 << endl;

  //Wczytywanie i wyswietlanie wyrazenia zespolonego test
  /*
  WyrazenieZesp WZ;
  cout << "podaj wyrazenie" << endl;
  cin >> WZ;
  cout << WZ << endl;
  */
  
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz;
  statystyka stat;
  int wyjscie=3;

  inicjuj(stat);
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Podaj wynik operacji ";
    cout << WyrZ_PytanieTestowe << endl;
   
	cin >> odpowiedz;
	while(cin.fail() && wyjscie!=1){
	  wyjscie--;
	  cout<<"Błąd wprowadzania, pozostało jeszcze "<<wyjscie<<" szans"<<endl;
	  cin.clear();
	  cin.ignore(10000,'\n');
	  cin>>odpowiedz;
	}
    if(odpowiedz==Oblicz(WyrZ_PytanieTestowe)){
      cout << "Twoja odpowiedz: " << odpowiedz << endl;
      cout<<"Odpowiedz poprawna"<<endl;
      dodaj_dobra(stat);
      cin.clear();
      wyjscie=3;
	}
    else{
      cout<<"Błąd. Poprawny wynik to: "<< Oblicz(WyrZ_PytanieTestowe)<<endl;}
    dodaj_zla(stat);
    cin.clear();
    wyjscie=3;
    }
   
  cout << endl;
  cout << " Koniec testu" << endl;
  wyswietl_stat(stat);
  cout << endl;
  
}
