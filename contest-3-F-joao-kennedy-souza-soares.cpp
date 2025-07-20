#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int r = n % 2020;
        if (n >= 2020 * r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
