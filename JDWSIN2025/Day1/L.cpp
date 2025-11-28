#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N, ans = 1;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];

        map<int, int> Ile, IleMniejszych;

        for (int i = 0; i < N; i++)
            Ile[A[i]]++;

        int sum = 0;
        for (auto el : Ile)
        {
            IleMniejszych[el.first] += sum;
            sum += el.second;
        }

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
            {

                int median = A[i] + A[j];
                int current_ans = 0;
                if (A[i] == A[j])
                {
                    ans = max(ans, Ile[A[i]]);
                    continue;
                }

                int mn, mx;
                mn = min(A[i], A[j]);
                mx = max(A[i], A[j]);

                if (median % 2 == 1)
                    continue;

                median /= 2;

                if (Ile.find(median) == Ile.end())
                    continue;

                current_ans += Ile[median];

                int lewe = IleMniejszych[median] - IleMniejszych[mn];
                int prawe = IleMniejszych[mx] - Ile[median] - IleMniejszych[median] + Ile[mx];

                int tmp = min(lewe, prawe);
                current_ans += tmp * 2;
                lewe -= tmp;
                prawe -= tmp;
                if (lewe > 0)
                {
                    current_ans += min(lewe, Ile[median] - 1);
                }
                else if (prawe > 0)
                {
                    current_ans += min(prawe, Ile[median]);
                }
                ans = max(ans, current_ans);
            }

        cout << ans << "\n";
    }

    return 0;
}