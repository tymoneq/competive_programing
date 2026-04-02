#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll totalSum = 0;
ll bestOffer = 0;
void printRes()
{

    int decimal1 = (bestOffer % 100) / 10;
    int decimal2 = bestOffer % 10;

    int decimal3 = (totalSum % 100) / 10;
    int decimal4 = totalSum % 10;

    cout << bestOffer / 100 << "." << decimal1 << decimal2 << " ";
    cout << totalSum / 100 << "." << decimal3 << decimal4  << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll buyersCnt = 0;
    ll sellersCnt = 0;

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

    for (int i = 0; i < n; i++)
    {

        double price;
        int b, s;
        cin >> price >> b >> s;
        ll p = price * 100;

        buyersCnt += b;

        pq.push({p, {b, s}});
    }

    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        sellersCnt += v.second.second;
        ll howMany = min(sellersCnt, buyersCnt);

        ll currentRes = howMany * v.first;

        if (currentRes > totalSum)
        {
            totalSum = currentRes;
            bestOffer = v.first;
        }

        buyersCnt -= v.second.first;
    }

    if (totalSum > 0)
    {
        printRes();
    }
    else
        cout << "impossible\n";
    return 0;
}