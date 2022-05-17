#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

vector<pair<pair<ull, ull>, char>> ans;

void sum(ull a, ull b) {
    ans.push_back(make_pair(make_pair(a, b), '+'));
}

void XOR(ull a, ull b) {
    ans.push_back(make_pair(make_pair(a, b), '^'));
}

ull hp2(ull n) {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n ^ (n >> 1);
}

void mult(ull k, ull n) {
    ull t1 = k, t2 = n;
    while (t1 > 1) {
        sum(t2, t2);
        t2 *= 2;
        t1 /= 2;
    }
    ull p2 = hp2(k), s = p2;
    k -= p2;
    while (k > 0) {
        sum(s * n, hp2(k) * n);
        p2 = hp2(k);
        s += p2;
        k -= p2;
    }
}

ll inv(ll x, ll y) {
    ll y0 = y, a = 1, b = 0;
    while (x > 1) {
        ll q = x / y, t = y;
        y = x % y, x = t;
        t = b;
        b = a - q * b;
        a = t;
    }
    if (a < 0)
        a += y0;
    return a;
}

int main() {
    ull x; 
    cin >> x;
    ull p = hp2(x), k = p * x;
    mult(p, x);
    ull y = x ^ k;
    XOR(x, k);
    ull a = inv(x, y), b = (a * x - 1) / y;
    mult(a, x); 
    mult(b, y);
    if ((b * y) % 2 == 1) {
        sum(a * x, x);
        sum(b * y, x);
        XOR(a * x + x, b * y + x);
    }
    else {
        XOR(a * x, b * y);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first.first << ' ' << ans[i].second << ' ' << ans[i].first.second << '\n';
    }
}