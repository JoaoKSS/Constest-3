#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int total = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            int leftQ = 0, rightQ = 0;
            for (int j = 0; j < i; ++j) {
                if (s[j] == 'Q') leftQ++;
            }
            for (int k = i + 1; k < n; ++k) {
                if (s[k] == 'Q') rightQ++;
            }
            total += leftQ * rightQ;
        }
    }
    
    cout << total << endl;
    return 0;
}
