#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int t;
    cin >> t;

    const vector<int> coins = {1, 3, 6, 10, 15};
    const int T = 1000;
    const int INF = numeric_limits<int>::max();
    vector<int> dp(T + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= T; ++i) {
        for (int c : coins) {
            if (i >= c && dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
            }
        }
    }

    while (t--) {
        int n;
        cin >> n;
        if (n <= T) {
            cout << dp[n] << endl;
        } else {
            int k = (n - T + 14) / 15; 
            int rem = n - k * 15;
            cout << (k + dp[rem]) << endl;
        }
    }
    return 0;
}
