#include <bits/stdc++.h>

using namespace std;

unsigned long long pi(long long x, long long y, long long u, long long v) {
    long long num = y - v; // Licznik
    long long den = x - u; // Mianownik
    
    if (den == 0) {
        return ((uint64_t)1 << 32) | 0; 
    }
    // Prosta pozioma
    if (num == 0) {
        return ((uint64_t)0 << 32) | 1; 
    }
    // Skracanie
    long long g = std::gcd(num, den);
    num /= g;
    den /= g;
    // Normalizacja znaku
    if (den < 0) {
        num = -num;
        den = -den;
    }

    // PAKOWANIE:
    // Rzutujemy na uint32_t, aby bezpiecznie uciąć liczbę do 32 bitów (szczególnie ważne dla liczb ujemnych),
    // a potem na uint64_t, żeby móc przesunąć o 32 miejsca w lewo.
    uint64_t packed_num = (uint32_t)num;
    uint64_t packed_den = (uint32_t)den;
    return (packed_num << 32) | packed_den;
}
void solve(){
    map<unsigned long long, long long> Lskos, Rskos;
    unsigned long long up = 0, down = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x,y,u,v; cin >> x >> y >> u >> v;
        if(x != u){
            unsigned long long a = pi(x,y,u,v);
            //cout << a << endl;
            if(x < u) Rskos[a] = Rskos[a] + 1;
            else Lskos[a] = Lskos[a] + 1;
        }
        else{
            if(y < v) up++;
            else down++;
        }
        
    }
    unsigned long long res = 0;
    for(auto [a, ile] : Lskos){
        if(Rskos.count(a)) res += ile*Rskos[a];
    }
    res += up*down;
    cout << res << "\n";
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
} 