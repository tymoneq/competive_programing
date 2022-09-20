#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long x, n;

int suma_cufr(long long number)
{
    int wynik = 0;
    while (number != 0)
    {
        wynik += number % 10;
        number /= 10;
    }
    return wynik;
}
int main()
{
    cin >> n >> x;
    vector<long long> sum_vec = {0, x};
    map<long long, int> index = {{x, 1}};

    for (int i = 2; i <= n; i++)
    {
        sum_vec.push_back(2 * suma_cufr(sum_vec[i - 1]));
        if (index.find(sum_vec[i]) != index.end())
        {
            int start_cyklu = index[sum_vec[i]];
            int koniec_cyklu = i;
            int dl_cyklu = koniec_cyklu-start_cyklu;
            int index_cyklu = (n- start_cyklu) % dl_cyklu;
            cout << sum_vec[start_cyklu+index_cyklu]<< endl;
            return 0;
        }
        index[sum_vec[i]] = i;

    }
    cout << sum_vec[n] << endl;
    return 0;
}