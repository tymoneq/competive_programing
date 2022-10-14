#include <iostream>

using namespace std;

// Definicja elementu listy sąsiedztwa

struct slistEl
{
  slistEl * next;                 // Następny element listy;
  int v;                          // Wierzchołek docelowy
  int i;                          // Numer krawędzi
};

int main( )
{
  int n, m;                       // Liczba wierzchołków, liczba krawędzi
  slistEl **G, **GE;              // Grafy
  int i, u, v, ei;
  slistEl *p, *r, *s;

  cin >> n >> m;                  // Czytamy rozmiary grafu

  G = new slistEl * [ n ];        // Tworzymy zerowy graf G
  for( i = 0; i < n; i++ ) G [ i ] = NULL;

  GE = new slistEl * [ m ];       // Tworzymy zerowy graf GE
  for( i = 0; i < m; i++ ) GE [ i ] = NULL;

  // Odczytujemy definicje krawędzi grafu G

  for( i = 0; i < m; i++ )
  {
    cin >> v >> u >> ei;          // Czytamy wierzchołki i numer krawędzi
    p = new slistEl;              // Tworzymy rekord listy
    p->v = u;                     // Wypełniamy go danymi
    p->i = ei;
    p->next = G [ v ];            // Element dołączamy do listy sąsiedztwa wierzchołka v
    G [ v ] = p;

    p = new slistEl;              // To samo dla krawędzi odwrotnej
    p->v = v;
    p->i = ei;
    p->next = G [ u ];
    G [ u ] = p;
  }

  // Tworzymy graf krawędziowy

  for( v = 0; v < n; v++ )       // Przechodzimy przez kolejne wierzchołki grafu
    for( p = G [ v ]; p; p = p->next ) // Przechodzimy przez listę sąsiadów wierzchołka v
      for( r = G [ p->v ]; r; r = r->next ) // Przechodzimy przez listę sąsiadów sąsiada v
        if( r->v != v )
        {
          s = new slistEl;        // Tworzymy nowy element listy
          s->v = r->i;            // Wierzchołkiem docelowym będzie krawędź wychodząca
          s->next = GE [ p->i ];  // Wierzchołkiem startowym będzie krawędź wchodząca
          GE [ p->i ] = s;        // Dodajemy krawędź do grafu krawędziowego
        }

  // Wyświetlamy wyniki

  cout << endl;

  for( i = 0; i < m; i++ )
  {
    cout << i << ": ";
    for( p = GE [ i ];p;p = p->next ) cout << p->v << " ";
    cout << endl;
  }

  // Usuwamy dynamiczne struktury

  for( i = 0; i < n; i++ )
  {
    p = G [ i ];
    while( p )
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [ ] G;

  for( i = 0; i < m; i++ )
  {
    p = GE [ i ];
    while( p )
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [ ] GE;

  return 0;
}
 