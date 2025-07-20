#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> parent(n+1, 0), sz(n+1, 0);
    vector<int> stk;
    stk.reserve(n);
    vector<int> order;
    order.reserve(n);
    parent[1] = -1;
    stk.push_back(1);
    while (!stk.empty()) {
        int u = stk.back(); stk.pop_back();
        order.push_back(u);
        for (int v : adj[u]) if (v != parent[u]) {
            parent[v] = u;
            stk.push_back(v);
        }
    }
    for (int i = n-1; i >= 0; --i) {
        int u = order[i];
        sz[u] = 1;
        for (int v : adj[u]) if (v != parent[u]) {
            sz[u] += sz[v];
        }
    }

    set<pair<int,int>> pairs;
    int total = n - 1;
    vector<char> dp(total+1);

    for (int u = 1; u <= n; ++u) {
        vector<int> comp;
        comp.reserve(adj[u].size());
        for (int v : adj[u]) {
            if (v == parent[u])
                comp.push_back(n - sz[u]);
            else
                comp.push_back(sz[v]);
        }
        fill(dp.begin(), dp.end(), 0);
        dp[0] = 1;
        for (int c : comp) {
            for (int s = total; s >= c; --s) {
                if (dp[s-c]) dp[s] = 1;
            }
        }
        for (int s = 1; s < total; ++s) {
            if (dp[s]) {
                pairs.emplace(s, total - s);
            }
        }
    }

    vector<pair<int,int>> result(pairs.begin(), pairs.end());
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto &pr : result) {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}
