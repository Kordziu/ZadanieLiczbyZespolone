#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct statystyka {

  int l_odp;
  int l_dobrych;
  
};

statystyka inicjuj(statystyka &);
statystyka dodaj_dobra(statystyka &);
statystyka dodaj_zla(statystyka &);
double proc_dobrych(statystyka &);
int liczba_zlych(statystyka &);
void wyswietl_stat(statystyka &);

#endif
