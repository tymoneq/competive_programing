#include <bits/stdc++.h>

using namespace std;
unsigned long NWD(unsigned long a, unsigned long b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
inline unsigned long NWW(unsigned long a, unsigned long b) { return a * b / NWD(a, b); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A, B;
    long C;
    cin >> A >> B >> C;
    unsigned long nwd = NWD(A, B);
    unsigned long nww = NWW(A, B);
    if (nwd <= C)
    {
        long temp = C / nww;
        cout << temp;
    }
    else
        cout << 0;

    return 0;
}