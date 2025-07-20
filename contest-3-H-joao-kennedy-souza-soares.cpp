#include <iostream>
#include <algorithm>
#include <cstring>  

using namespace std;

const int MAX_N = 100000 + 5;

long long v[MAX_N];
long long sorted_v[MAX_N];

long long memo_prefix_original[MAX_N];
long long memo_prefix_sorted[MAX_N];

int n;

long long get_prefix_sum_original(int pos) {
    if (pos == 0) return 0;
    if (memo_prefix_original[pos] != -1) return memo_prefix_original[pos];
    return memo_prefix_original[pos] = get_prefix_sum_original(pos - 1) + v[pos];
}

long long get_prefix_sum_sorted(int pos) {
    if (pos == 0) return 0;
    if (memo_prefix_sorted[pos] != -1) return memo_prefix_sorted[pos];
    return memo_prefix_sorted[pos] = get_prefix_sum_sorted(pos - 1) + sorted_v[pos];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        memo_prefix_original[i] = -1;
        memo_prefix_sorted[i] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        sorted_v[i] = v[i];
    }
    sort(sorted_v + 1, sorted_v + n + 1);

    int m;
    cin >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            long long ans = get_prefix_sum_original(r) - get_prefix_sum_original(l - 1);
            cout << ans << endl;
        } else {
            long long ans = get_prefix_sum_sorted(r) - get_prefix_sum_sorted(l - 1);
            cout << ans << endl;
        }
    }

    return 0;
}
