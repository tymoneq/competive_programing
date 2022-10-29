#include <bits/stdc++.h>

using namespace std;
int szach[8][8];
int main()
{
    int row_k, row_d, koll, koll_d;
    char kol_k, kol_d;
    cin >> kol_k >> row_k >> kol_d >> row_d;
    row_k -= 1;
    row_d -= 1;
    switch (kol_k)
    {
    case 'a':
        koll = 0;
        break;
    case 'b':
        koll = 1;
        break;
    case 'c':
        koll = 2;
        break;
    case 'd':
        koll = 3;
        break;
    case 'e':
        koll = 4;
        break;
    case 'f':
        koll = 5;
        break;
    case 'g':
        koll = 6;
        break;
    case 'h':
        koll = 7;
        break;
    }
    switch (kol_d)
    {
    case 'a':
        kol_d = 0;
        break;
    case 'b':
        kol_d = 1;
        break;
    case 'c':
        kol_d = 2;
        break;
    case 'd':
        kol_d = 3;
        break;
    case 'e':
        kol_d = 4;
        break;
    case 'f':
        kol_d = 5;
        break;
    case 'g':
        kol_d = 6;
        break;
    case 'h':
        kol_d = 7;
        break;
    }

    szach[row_k][koll] = 1;
    szach[row_d][kol_d] = 2;
    
    return 0;
}