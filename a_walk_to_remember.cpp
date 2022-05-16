#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

vector<pair<int, int>> ans;

int main() {
    int n, m, R, C;
    cin >> n >> m >> R >> C;
    ans.pb(mp(2, 1));
    ans.pb(mp(3, 1));
    ans.pb(mp(2, 3));
    ans.pb(mp(3, 2));
    for (int i = 2; i <= 27; i++) {
        ans.pb(mp(2 * i, 2 * i - 2));
        ans.pb(mp(2 * i, 2 * i - 1));
        ans.pb(mp(2 * i + 1, 2 * i - 2));
        ans.pb(mp(2 * i + 1, 2 * i - 1));
    }
    ans.pb(mp(56, 54));
    ans.pb(mp(56, 55));
    int curr = m;
    while (curr > 0) {
        int p = log2(curr);
        if (2 * p + 3 == 57) {
            ans.pb(mp(57, 56));
        }
        else {
            ans.pb(mp(57, 2 * p + 3));
        }
        curr -= 1 << p;
    }
    cout << 57 << ' ' << ans.size() << ' ' << 57 << ' ' << 1 << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}