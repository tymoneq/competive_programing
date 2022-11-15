#include <bits/stdc++.h>
using namespace std;
int knapStack(int W, vector<pair<int, int>> &obj, int n)
{
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (obj[i - 1].second <= w)
                K[i][w] = max(obj[i - 1].first + K[i - 1][w - obj[i - 1].second], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> obj(N); // first val second weights
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        obj[i] = make_pair(a, b);
    }
    auto val = knapStack(W, obj, N);
    cout << val;
    return 0;
}