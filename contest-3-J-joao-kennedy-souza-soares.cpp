#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FastInput {
    inline char read() {
        char c;
        if (!cin.get(c)) return EOF;
        return c;
    }
    int nextInt() {
        char c;
        int x = 0;
        do {
            c = read();
            if (c == EOF) return -1;
        } while (c < '0' || c > '9');
        do {
            x = x * 10 + (c - '0');
            c = read();
        } while (c >= '0' && c <= '9');
        return x;
    }
};

int main() {
    FastInput in;
    int n = in.nextInt();
    if (n <= 0) return 0;

    vector<int> A(n);
    int maxA = 0;
    for (int i = 0; i < n; ++i) {
        A[i] = in.nextInt();
        if (A[i] > maxA) maxA = A[i];
    }

    vector<char> present(maxA + 1, 0);
    for (int x : A) present[x] = 1;

    vector<int> memo(maxA + 1, 1);
    int answer = 1;

    for (int v : A) {
        int mv = memo[v];
        for (int m = v + v; m <= maxA; m += v) {
            if (present[m] && memo[m] < mv + 1) {
                memo[m] = mv + 1;
                answer = max(answer, memo[m]);
            }
        }
    }

    cout << answer << endl;
    return 0;
}
