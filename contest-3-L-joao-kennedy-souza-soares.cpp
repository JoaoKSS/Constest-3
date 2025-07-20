#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
vector<long long> S;
long long memo[51][2];

long long solve(int i, int t) {
    if (i == N) return 0;
    long long &res = memo[i][t];
    if (res != -1) return res;
    if (t == 0) {
        res = max(
            S[i] + solve(i+1, 1),  
            solve(i+1, 0)          
        );
    } else {
        res = min(
            S[i] + solve(i+1, 1),  
            solve(i+1, 0)          
        );
    }
    return res;
}

int main() {
    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    memset(memo, -1, sizeof(memo));
    long long alice = solve(0, 1); 
    long long total = 0;
    for (long long x : S) total += x;
    long long bob = total - alice;
    cout << alice << " " << bob << endl;
    return 0;
}
