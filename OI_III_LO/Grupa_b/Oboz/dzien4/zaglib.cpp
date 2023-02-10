#include <bits/stdc++.h>
#include "zag.h"
using namespace std;

// obecna pozycja kota, liczba pudełek, liczba ruchów.
int current, n, nom;
// czy znaleziony
bool found;

bool otworz(int k)
{
    assert(k > 0);
    assert(k <= n);
    assert(!found);
    assert(nom < 100000); // jest to wartość, którą należy dostosować do swoich potrzeb
    nom++;
    if (current == k)
    {
        found = true;
        return true;
    }
    int nextMove;
    if (!(cin >> nextMove))
        assert(false & "Brak ruchów na wejściu"[0]);
    assert(abs(nextMove - current) == 1);
    current = nextMove;
    return false;
}

int main()
{
    cin >> n >> current;
    rozpocznij(n);
    assert(found);
    cout << "Wykonano " << nom << " zapytań\n";
}