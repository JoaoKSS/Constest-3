#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f[4000][4000];
int cnt[4000];

int main() {
    int n;
    cin >> n;
    vector<int> b(n), comp;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        comp.push_back(b[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int m = comp.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin();
    }
    int ans = 1;
    vector<int> seen;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        cnt[x]++;
        if (cnt[x] > ans) ans = cnt[x];
        for (int y : seen) {
            int t = f[x][y] + 1;
            if (t > f[y][x]) {
                f[y][x] = t;
                if (t + 1 > ans) ans = t + 1;
            }
        }
        if (cnt[x] == 1) seen.push_back(x);
    }
    cout << ans << endl;
    return 0;
}