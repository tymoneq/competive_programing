#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

struct state
{
    int r;
    int c;
    int ld;
    bool smell;

    state(int r, int c, int ld, bool smell) : r(r), c(c), ld(ld), smell(smell)
    {
    }

    int pack()
    {
        return (smell ? 1 : 0) + 2 * (ld + 1) + 10 * c + 10000 * r;
    }

    static state unpack(int x)
    {
        return state(x / 10000, (x / 10) % 1000,
                     (x / 2) % 5 - 1, x & 1);
    }
};

int getcell(const vector<vector<int>> &A, int r, int c)
{
    if (r < 0 || r >= A.size() || c < 0 || c >= A[r].size())
    {
        return 0;
    }
    return A[r][c];
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("dream.in","r", stdin);
    freopen("dream.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    queue<int> q;
    vector<int> D(10000000, -1);

    int s = state(0, 0, -1, false).pack();
    q.push(s);
    D[s] = 0;

    while (!q.empty())
    {
        state st = state::unpack(q.front());
        q.pop();

        if (st.r == N - 1 && st.c == M - 1)
        {
            cout << D[st.pack()] << '\n';
            return 0;
        }
        if (A[st.r][st.c] == 4 && st.ld != -1)
        {
            int col = getcell(A, st.r + dr[st.ld], st.c + dc[st.ld]);
            if (col != 0 && col != 3)
            {
                state nst = state(st.r + dr[st.ld], st.c + dc[st.ld], st.ld, col == 2);
                if (D[nst.pack()] != -1)
                {
                    continue;
                }
                D[nst.pack()] = D[st.pack()] + 1;
                q.push(nst.pack());
                continue;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int col = getcell(A, st.r + dr[i], st.c + dc[i]);
            if (col == 0 || (col == 3 && !st.smell))
            {
                continue;
            }
            state nst = state(st.r + dr[i], st.c + dc[i], i,
                              col == 2 ? true : col == 4 ? false
                                                         : st.smell);
            if (D[nst.pack()] != -1)
            {
                continue;
            }
            D[nst.pack()] = D[st.pack()] + 1;
            q.push(nst.pack());
        }
    }
    cout << "-1\n";
    return 0;
}