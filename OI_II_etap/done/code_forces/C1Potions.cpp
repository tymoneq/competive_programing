#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll current_health = 0;
    priority_queue<ll> pq;
    ll current_ans = 0;

    cin >> n;

    while (n--)
    {
        ll potion;
        cin >> potion;

        if (potion >= 0)
        {
            current_health += potion;
            current_ans += 1;
        }
        else
        {
            if (current_health >= -potion)
            {
                current_health += potion;
                current_ans += 1;
                pq.push(-potion);
            }
            else if (current_health < -potion && (!pq.empty() && pq.top() > -potion))
            {
                current_health += pq.top();
                pq.pop();
                current_health += potion;
                pq.push(-potion);
            }
        }

     
    }

    cout << current_ans << "\n";
    return 0;
}
