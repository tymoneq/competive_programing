#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)
typedef long long ll;

struct Vertex
{
    vector<int> synowie;
    string type;
    ll sumaDlugoscipod;
    int ilePlikowPod;
    int DlugoscNazwy;
};

class Solve
{
protected:
    const ll INF = 1e17 + 5;
    vector<Vertex> drzewo;
    ll best_score = INF;
    int n, ilePlikow = 0;
    const string FILE = "FILE";
    const string FOLDER = "FOLDER";

public:
    inline void read_data()
    {
        cin >> n;
        drzewo.resize(n + 1);
        FOR(i, n + 1, 1)
        {
            string name;
            int m;
            cin >> name >> m;
            drzewo[i].DlugoscNazwy = name.size();

            if (m == 0)
            {
                ilePlikow++;
                drzewo[i].type = FILE;
            }
            else
            {
                drzewo[i].type = FOLDER;
                if (i == 1)
                    drzewo[i].DlugoscNazwy = 0;

                FOR(j, m, 0)
                {
                    int a;
                    cin >> a;
                    drzewo[i].synowie.push_back(a);
                }
            }
        }
    }

    inline void firstdfs(int v, int p)
    {

        drzewo[v].ilePlikowPod = 0;
        drzewo[v].sumaDlugoscipod = 0;
        for (int w : drzewo[v].synowie)
            if (w != p)
            {
                firstdfs(w, v);
                drzewo[v].sumaDlugoscipod += drzewo[w].sumaDlugoscipod + drzewo[w].ilePlikowPod * (drzewo[v].DlugoscNazwy + (v == 1 ? 0 : 1));
                drzewo[v].ilePlikowPod += drzewo[w].ilePlikowPod;
            }

        if (drzewo[v].type == FILE)
        {
            drzewo[v].ilePlikowPod = 1;
            drzewo[v].sumaDlugoscipod = drzewo[v].DlugoscNazwy;
        }
    }

    inline void change_root(int v, int p, ll wynik)
    {
        best_score = min(best_score, wynik);
        for (int w : drzewo[v].synowie)
            if (w != p && drzewo[w].type == FOLDER && drzewo[w].ilePlikowPod > 0)
            {
                ll wynikSyna = wynik + 3 * (ilePlikow - drzewo[w].ilePlikowPod) - ((drzewo[w].DlugoscNazwy + 1) * drzewo[w].ilePlikowPod);

                change_root(w, v, wynikSyna);
            }
    }

    inline void solve()
    {
        read_data();
        firstdfs(1, 1);
        change_root(1, 1, drzewo[1].sumaDlugoscipod);
        cout << best_score << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);

    Solve solution;
    solution.solve();
    return 0;
}