#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string A, B, C;
    cin >> A >> B >> C;

    int32_t n = A.length();

    int64_t count_0 = 0;
    int64_t count_1 = 0;
    int64_t total_valid_pairs = 0;

    for (int32_t i = n - 1; i >= 0; --i) {
        int32_t d = (A[i] - '0') + (B[i] - '0') - (C[i] - '0');

        int64_t next_0 = 0;
        int64_t next_1 = 0;

        if (d == 0) {
            next_0 = 1 + count_0;
            next_1 = 0;
        } else if (d == 10) {

            next_1 = 1 + count_0;
            next_0 = 0;
        } else if (d == 9) {

            next_1 = count_1;
            next_0 = 0;
        } else if (d == -1) {

            next_0 = count_1;
            next_1 = 0;
        } else {
            next_0 = 0;
            next_1 = 0;
        }

        count_0 = next_0;
        count_1 = next_1;

        total_valid_pairs += count_0;
    }

    cout << total_valid_pairs << "\n";

    return 0;
}