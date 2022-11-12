#include <bits/stdc++.h>

using namespace std;
struct flowers
{
    int red;
    int green;
    int blue;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int C, Z, N, T;
    cin >> C >> Z >> N >> T;
    vector<flowers> kwat(T);
    vector<vector<vector<int>>> Res(T+1);
    for (int i = 0; i < T; i++)
    {
        int c, z, n;
        cin >> c >> z >> n;
        flowers fl;
        fl.red = c;
        fl.green = z;
        fl.blue = n;
        kwat[i] = fl;
    }
   
    
    return 0;
}
