#include "Statystyka.hh"
#include "WyrazenieZesp.hh"
using namespace std;

statystyka inicjuj(statystyka& stat)
{
  stat.l_odp=0;
  stat.l_dobrych=0;
  return stat;
}
statystyka dodaj_dobra(statystyka& stat)
    {
      // stat.l_odp++;
      stat.l_dobrych++;
      return stat;
    }

statystyka dodaj_zla(statystyka& stat)
    {
      stat.l_odp++;
      return stat;
    }
	    
int liczba_zlych(statystyka & stat)
{
  int l_zlych;
  l_zlych=stat.l_odp-stat.l_dobrych;

  return l_zlych;
}

double proc_dobrych(statystyka & stat)
{
  double procent;
  procent=stat.l_dobrych*100/stat.l_odp;
  return procent;
}

void wyswietl_stat(statystyka & stat)
{
  cout << "liczba dobrych odpowiedzi: " << stat.l_dobrych <<endl;
  cout << "liczba zlych odpowiedzi: " << liczba_zlych(stat) <<endl;
  cout << "procentowy wynik testu: " << proc_dobrych(stat) <<"%" <<endl;
}
