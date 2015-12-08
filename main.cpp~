// Fifo
//
// Tematem zadania jest szablonowa kolejka Fifo (First In First Out)
// W implementacji musi byc uzyta lista polaczona.
// Implementacje metod powinny sie znajdowac poza definicja klasy Fifio.
//
// W przypadku proby wyjecia z pustego Fifo wyrzucany jest wyjatek.
// Klasa wyjatku musi byc zdefiniowana wewnatrz szablonu Fifo.
//
// Prosze nie zmieniac tego pliku (bo wtedy zmienia sie numer linii w wyniku).
// Program ma sie kompilowac do wykonywalnego o nazwie "ft" z opcjami -Wall -g
//

#include <iostream>
using namespace std;
#define CONTEXT "file:"<<__FILE__<<" line:"<<__LINE__<< ": "

#include "Fifo.h"


int main(int argc, char** argv) {

  Fifo<int> ififo;
  ififo.in(12).in(3);

  cout << CONTEXT << "rozmiar " <<ififo.size() << endl;
  cout << ififo.out() << endl;
  cout << ififo.out() << endl;
  cout << CONTEXT << (ififo.empty()? "pusta":"nie pusta") << endl;

  try { // tu bedziemy probowac wjac cos z pustego fifo i powinismy dostac wyjatek
    cout << ififo.out() << endl;
  } catch ( ... ) {
    util::handler<int>();
  }

  for( int i = 0; i < 100; i++ ) {
    ififo.in( i % 45);
  }
  cout << CONTEXT << "nowy rozmiar " << ififo.size() << endl;

  Fifo<std::string> sfifo;
  sfifo.in("Jeden").in("dwa").in("trzy");
  sfifo.in("cztery");

  while( sfifo )
    cout << sfifo.out()  << endl;
}
/* wynik
file:ft.C line:25: rozmiar 2
12
3
file:ft.C line:28: pusta
Puste fifo
file:ft.C line:39: nowy rozmiar 100
Jeden
dwa
trzy
cztery

 */
