#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin.open("herding.in"), fout.open("herding.out");
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
        fin >> a[i];

    sort(a.begin(), a.end());
    if (a[0] == a[2] - 2)
    {
        fout << 0 << "\n";
    }
    else if ((a[1] == a[2] - 2) || (a[0] == a[1] - 2))
    {
        fout << 1 << "\n";
    }
    else
    {
        fout << 2 << "\n";
    }
    fout << max(a[2] - a[1], a[1] - a[0]) - 1;
    fout.close(), fin.close();
    return 0;
}