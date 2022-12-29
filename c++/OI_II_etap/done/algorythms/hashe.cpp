#include <bits/stdc++.h>
using namespace std;

long long hsh[100];
long long power[100];
const int mod = 1e9 + 9, mod2 = 1e9 + 7, p = 31;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string znaki = "abcab";
    for (int i = 1; i < znaki.size(); i++)
        hsh[i] = (hsh[i - 1] * p + (znaki[i - 1] - 'a' + 1)) % mod;
    for (int i = 1; i < 100; i++)
        power[i] = (power[i - 1] * p) % mod;
    // zakres ca, wielomin dla dowolnego podsłowa;
    // jak mamy dwa modula  to trzeba je liczyć oddzielne
    int val = (hsh[4] - (hsh[2] * power[4 - 2]) % mod) % mod;

    return 0;
}