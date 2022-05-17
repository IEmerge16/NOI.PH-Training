#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    bool adj[n][n];
    if (min(a, b) == 1 && !(a == 1 && b == 1 && (n == 2 || n == 3))) {
        if (b > 1) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (r != c) {
                        adj[r][c] = 1;
                    }
                    else {
                        adj[r][c] = 0;
                    }
                }
            }
            for (int i = 0; i < n - b; i++) {
                adj[i][i + 1] = 0;
                adj[i + 1][i] = 0;
            }
        }
        else {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    adj[r][c] = 0;
                }
            }
            for (int i = 0; i < n - a; i++) {
                adj[i][i + 1] = 1;
                adj[i + 1][i] = 1;
            }
        }
        cout << "YES" << endl;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << adj[r][c];
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
}