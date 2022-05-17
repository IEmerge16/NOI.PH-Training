#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long X[N], Y[N];
    int par[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        par[i] = (abs(X[i]) + abs(Y[i])) % 2;
    }
    for (int i = 0; i < N; i++) {
        if (par[0] != par[i]) {
            cout << -1;
            return 0;
        }
    }
    int m;
    long long d[33];
    for (int i = 0; i < 32; i++) {
        d[i] = pow(2, 31 - i);
    }
    if (par[0] == 1) {
        m = 32;
    }
    else {
        d[32] = 1;
        m = 33;
    }
    cout << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << d[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < N; i++) {
        string ans;
        for (int j = 0; j < m; j++) {
            if (max(abs(X[i]), abs(Y[i])) == abs(X[i])) {
                if (X[i] < 0) {
                    ans += 'L';
                    X[i] += d[j];
                }
                else {
                    ans += 'R';
                    X[i] -= d[j];
                }
            }
            else {
                if (Y[i] < 0) {
                    ans += 'D';
                    Y[i] += d[j];
                }
                else {
                    ans += 'U';
                    Y[i] -= d[j];
                }
            }
        }
        cout << ans << '\n';
    }
}