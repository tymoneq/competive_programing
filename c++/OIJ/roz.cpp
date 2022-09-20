#include <bits/stdc++.h>
// https://sio2.mimuw.edu.pl/c/zwo21/p/roz/
using namespace std;
/**
 * SUMY PREFIKSOWE
 * ZROBIONE ale nie działa 3.09.2022
 */
void vectorIntPrint(vector<int> vector)
{
    if (!vector.size())
        return;
    for (int element : vector)
        cout << element << " ";
    cout << endl;
}
int main()
{
    int n, dlugoscOpadow;
    // cin >> n;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    vector<int> dane(2 * n);
    // cin >> dane[0];
    scanf("%d", &dane[0]);
    dlugoscOpadow = dane[0];
    for (int i = 1; i < 2 * n; i++)
    {
        // cin >> dane[i];
        scanf("%d", &dane[i]);
        if (dane[i] > dlugoscOpadow)
            dlugoscOpadow = dane[i];
    }
    vector<int> opady(dlugoscOpadow + 1);
    // printf("l, r %d %d", l, r);
    int l, r;
    for (int i = 0; i < n; i++)
    {
        l = dane[2 * i];
        r = dane[2 * i + 1];
        // printf("l, r %d %d\n", l, r);
        opady[l]++;
        opady[r + 1]--;
        // vectorIntPrint(opady);
    }
    for (int i = 1; i < dlugoscOpadow + 1; i++)
        opady[i] += opady[i - 1];
    // vectorIntPrint(dane);
    // vectorIntPrint(opady);
    // cout << dlugoscOpadow << endl;
    int maxOpady = opady[0];
    for (int i = 1; i < dlugoscOpadow; i++)
    {
        if (opady[i] > maxOpady)
            maxOpady = opady[i];
    }
    // cout << maxOpady;
    if (maxOpady == 1)
        printf("0");
    else
        printf("%d", maxOpady);

    return 0;
}