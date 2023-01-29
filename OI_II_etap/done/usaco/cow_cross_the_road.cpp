#include <bits/stdc++.h>

using namespace std;
int dr[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dc[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
ifstream fin;
ofstream fout;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, x, y, x1, y1;
    fin.open("visitfj.in"), fout.open("visitfj.out");

    int N, T;
    fin >> N >> T;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> A[i][j];
        }
    }

    vector<vector<int>> D(N, vector<int>(N, 0x7FFFFFFF));
    D[0][0] = 0;

    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int result = 0x7FFFFFFF;
    while (!q.empty())
    {
        int d = -q.top().first;
        int r = q.top().second / N;
        int c = q.top().second % N;
        q.pop();
        if (d != D[r][c])
        {
            continue;
        }

        int dist = abs(N - 1 - r) + abs(N - 1 - c);
        if (dist <= 2)
        {
            result = min(result, d + dist * T);
        }

        for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N ||
                D[nr][nc] < d + A[nr][nc] + 3 * T)
            {
                continue;
            }
            D[nr][nc] = d + A[nr][nc] + 3 * T;
            q.push(make_pair(-D[nr][nc], nr * N + nc));
        }
    }
    fout << result;

    fout.close(), fin.close();
    return 0;
}