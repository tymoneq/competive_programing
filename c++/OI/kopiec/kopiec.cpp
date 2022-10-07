#include <cstdlib>
#include <iostream>
#define N 5000 // maksymalna liczba elementow w kopcu
using namespace std;

// Deklaracja klasy kopca
class kopiec
{
public:
  int tab[N];
  int size;
  kopiec();
  void insert_into(int v);
  void delete_root();
  void wyswietl(int poczatek);
  void sort();
};

// Przyklad uzycia
int main(int argc, char *argv[])
{
  // utworz kopiec
  kopiec K;

  // wstaw elementy do kopca
  K.insert_into(2);
  K.insert_into(5);
  K.insert_into(3);
  K.insert_into(1);
  K.insert_into(7);

  // wsywietl elementy kopca poczawszy od pierwszego
  K.wyswietl(1);
  system("PAUSE");

  // usun korzen i wsywietl elementy kopca poczawszy od pierwszego
  K.delete_root();
  K.wyswietl(1);
  system("PAUSE");

  // posortuj kopiec
  K.sort();

  system("PAUSE");
  return EXIT_SUCCESS;
}

//************
// METODY
//************

// Konstruktor - tworzy pusty kopiec
kopiec::kopiec()
{
  size = 0;
}

// Wstawia element o wartosci v do kopca
void kopiec::insert_into(int v)
{
  tab[size + 1] = v;
  int s = size + 1;
  while (s != 1)
  {
    if (tab[s / 2] < tab[s])
    {
      swap(tab[s / 2], tab[s]);
      s /= 2;
    }
    else
      break;
  }
  size++;
}

// Usuwa korzen kopca
void kopiec::delete_root()
{
  tab[1] = tab[size];
  size--;
  int tmp = 1;
  while (tmp * 2 <= size)
  {
    if (tab[tmp] < tab[tmp * 2] || tab[tmp] < tab[tmp * 2 + 1])
    {
      if (tab[tmp * 2] > tab[tmp * 2 + 1] || tmp * 2 + 1 > size)
      {
        swap(tab[tmp], tab[tmp * 2]);
        tmp = tmp * 2;
      }
      else
      {
        swap(tab[tmp], tab[tmp * 2 + 1]);
        tmp = tmp * 2 + 1;
      }
    }
    else
      break;
  }
}

// Sortuje kopiec
void kopiec::sort()
{
  for (int i = 0; i <= size; i++)
  {
    cout << tab[1] << " ";
    delete_root();
  }
  cout << tab[1] << "\n";
}

// Wyswietla zawartosc kopca poczawszy od elementu poczatek
void kopiec::wyswietl(int poczatek)
{
  if (poczatek <= size)
  {
    cout << poczatek << " : " << tab[poczatek] << " \n";
    if (poczatek * 2 <= size)
      wyswietl(poczatek * 2);
    if (poczatek * 2 + 1 <= size)
      wyswietl(poczatek * 2 + 1);
  }
}