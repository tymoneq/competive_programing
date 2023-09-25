#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ifstream fin("bin_przyklad.txt");
    ofstream fout("wyniki2_5.txt");
    ll p, tmp, k;
    while (fin >> p)
    {
        vector<int> V, ANS;
        while (p > 0)
        {
            k = p % 10;
            V.push_back(k);
            p /= 10;
        }
        for (int i = 0; i < V.size() - 1; i++)
        {
            tmp = V[i] ^ V[i + 1];
            ANS.push_back(tmp);
        }
        ANS.push_back(V[V.size() - 1]);

        reverse(ANS.begin(), ANS.end());

        for (int w : ANS)
            fout << w;

        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}