#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, K;
    cin >> M >> K;
    if ((K >= pow(2, M)) || (M == 1 && K == 1)) {
        cout << -1;
    }
    else if (K > 0) {
        cout << K << " ";
        for (int i = 0; i < pow(2, M); i++) {
            if (i != K) {
                cout << i << " ";
            }
        }
        cout << K << " ";
        for (int i = pow(2, M) - 1; i >= 0; i--) {
            if (i != K) {
                cout << i << " ";
            }
        }
    }
    else {
        for (int i = 0; i < pow(2, M); i++) {
            cout << i << " " << i << " ";
        }
    }
}