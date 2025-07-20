#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
int n, d;
string s;
bool JC[101];
int MEM[101];

int F(int pos) {
    if (pos == n) return 0;
    if (pos > n) return INF;
    if (JC[pos]) return MEM[pos];

    int best = INF;
    for (int jump = 1; jump <= d; ++jump) {
        int nxt = pos + jump;
        if (nxt <= n && s[nxt - 1] == '1') {
            int res = F(nxt);
            if (res != INF)
                best = min(best, res + 1);
        }
    }

    JC[pos] = true;
    return MEM[pos] = best;
}

int main() {
    cin >> n >> d;
    cin >> s;

    for (int i = 1; i <= n; ++i) {
        JC[i] = false;
    }

    int ans = F(1);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
