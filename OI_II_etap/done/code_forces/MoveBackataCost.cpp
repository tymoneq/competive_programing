#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	vector<int> front(n);
	int frontfront = n;
	int frontback = n;
	multiset<int> back;
	for (int i = n - 1; i >= 0; i--)
	{
		if (frontfront >= frontback || a[i] <= front[frontfront]) front[--frontfront] = a[i];
		else back.insert(a[i] + 1);
		while (frontfront < frontback && !back.empty() && front[frontback - 1] > *back.begin())
		{
			back.insert(front[frontback - 1] + 1);
			frontback--;
		}
	}
	vector<int> answer;
	for (int i = frontfront; i < frontback; i++) answer.pb(front[i]);
	for (auto t : back) answer.pb(t);
	for (auto t : answer) printf("%d ", t);
	printf("\n");
}

int main()
{
    int NT = 1;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        solve();
    }
    return 0;
}