#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        cout << "+-";
    cout << "+\n";
    for (char w : s)
        cout << "|" << w;
    cout << "|\n";
    for (int i = 0; i < s.size(); i++)
        cout << "+-";
    cout << "+\n";
    return 0;
}