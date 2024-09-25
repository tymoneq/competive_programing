#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;

    int pointsA = 0, PointsB = 0;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            pointsA++;
        else
            PointsB++;

        if (pointsA >= 1000 && pointsA - PointsB >= 3)
        {
            cout << "A " << pointsA << " " << PointsB << "\n";
            break;
        }
        if (PointsB >= 1000 && PointsB - pointsA >= 3)
        {
            cout << "B " << PointsB << " " << pointsA << "\n";
            break;
        }
    }

    return 0;
}