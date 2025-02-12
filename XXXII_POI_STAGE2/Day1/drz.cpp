#include <bits/stdc++.h>

using namespace std;

#define FOR(_name, _to, _val) for (int(_name) = (_val); (_name) < (_to); (_name)++)

class Solve
{
protected:
    int N, Q;

    int mask;
    vector<char> Parents;
    string bajtazar;

public:
    inline void read_data()
    {
        cin >> N >> Q;

        mask = 1 << N;
        cin >> bajtazar;

        Parents.resize(mask + 1);

        FOR(i, mask, 0)
        cin >> Parents[i];
    }

    inline bool get_ans(const string &current_string, int v)
    {
        int left_son = v * 2;
        int right_son = v * 2 + 1;
        int mid = current_string.size() / 2;

        if (left_son >= mask)
        {
            if ((Parents[left_son - mask] == current_string[0] && Parents[right_son - mask] == current_string[1]) || (Parents[left_son - mask] == current_string[1] && Parents[right_son - mask] == current_string[0]))
                return true;

            return false;
        }

        string left_son_str = "";
        string right_son_str = "";

        FOR(i, mid, 0)
        left_son_str += (current_string[i]);

        FOR(i, current_string.size(), mid)
        right_son_str += (current_string[i]);

        bool first_combination = get_ans(left_son_str, left_son) & get_ans(right_son_str, right_son);

        bool second_combination = get_ans(right_son_str, left_son) & get_ans(left_son_str, right_son);

        return (first_combination | second_combination);
    }

    inline void solve()
    {
        read_data();

        bool ans = get_ans(bajtazar, 1);

        cout << (ans ? "TAK\n" : "NIE\n");
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve s;
    s.solve();

    return 0;
}