#include <bits/stdc++.h>

using namespace std;

const char NON_EXIST = 'X';
const char EXIST_DIFF_POS = '!';
const char EXIST = '*';

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<string> Dict(N);

    for (auto &el : Dict)
        cin >> el;

    int Q;
    cin >> Q;
    while (Q--)
    {
        string code;
        cin >> code;

        int ans = 0;

        for (int k = 0; k < N; k++)
        {
            set<char> NonExist;
            map<char, int> diff_pos;
            map<int, char> good_pos;

            for (int i = 0; i < 5; i++)
            {
                if (code[i] == NON_EXIST)
                {
                    NonExist.insert(Dict[k][i]);
                }
                if (code[i] == EXIST_DIFF_POS)
                {
                    diff_pos[Dict[k][i]] = i;
                }
                if (code[i] == EXIST)
                {
                    good_pos[i] = Dict[k][i];
                }
            }

            for (int j = 0; j < N; j++)
            {

                // przechodzenie po literach

                bool valid = true;
                for (int l = 0; l < 5; l++)
                {
                    if (NonExist.count(Dict[j][l]))
                    {
                        valid = false;
                        break;
                    }
                    if (good_pos.find(l) != good_pos.end() && good_pos[l] != Dict[j][l])
                    {
                        valid = false;
                        break;
                    }
                }
                vector<int> tmp;

                for (auto el : diff_pos)
                {
                    bool exist = false;
                    for (int l = 0; l < 5; l++)
                    {
                        if (Dict[j][l] == el.first && l != el.second)
                            exist = true;
                    }

                    if (exist)
                        tmp.push_back(1);
                }

                if (tmp.size() != diff_pos.size())
                    valid = false;

                if (valid)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}