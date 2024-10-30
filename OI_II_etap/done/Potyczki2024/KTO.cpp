#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int n = 18;
    vector<int> Algosia(n), Bajtkek(n);

    for (int i = 0; i < n; i++)
        cin >> Algosia[i];

    for (int i = 0; i < n; i++)
        cin >> Bajtkek[i];

    sort(Algosia.begin(), Algosia.end(), greater<int>());
    sort(Bajtkek.begin(), Bajtkek.end(), greater<int>());

    int sumaBajtak = 0, sumaAlgosi = 0;
    for (int i = 0; i < n; i++)
    {
        sumaBajtak += Bajtkek[i];
        sumaAlgosi += Algosia[i];
    }

    if (sumaBajtak > sumaAlgosi)
    {
        cout << "Bajtek\n";
        return 0;
    }

    if (sumaBajtak < sumaAlgosi)
    {
        cout << "Algosia\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (Bajtkek[i] > Algosia[i])
        {
            cout << "Bajtek\n";
            return 0;
        }
        else if (Bajtkek[i] < Algosia[i])
        {
            cout << "Algosia\n";
            return 0;
        }
    }
    cout << "remis\n";
    return 0;
}
