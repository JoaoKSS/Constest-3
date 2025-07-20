#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;
bool JC[101][101];
long long MEM[101][101];
int n, m;

long long F(int i, int j) {
    if (i > n || j > m) return INF;
    if (i == n && j == m) return 0;

    if (JC[i][j]) return MEM[i][j];
    long long best = INF;
    best = min(best, F(i, j + 1) + i);
    best = min(best, F(i + 1, j) + j);

    JC[i][j] = true;
    return MEM[i][j] = best;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                JC[i][j] = false;
            }
        }
        long long cost = F(1, 1);
        cout << (cost == k ? "YES" : "NO") << endl;
    }
    return 0;
}