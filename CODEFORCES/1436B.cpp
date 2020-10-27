#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (int) (i == j || (i + 1) % n == j
              ) << ' ';
            }
            cout << endl;
        }
    }
}
