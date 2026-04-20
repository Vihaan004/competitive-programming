#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (auto &x : a) {cin >> x;}
    for (auto &x : b) {cin >> x;}

    long long g = 0;
    for (int i = 1; i < n; i++) {
        long long diff = a[i] >= a[0] ? a[i] - a[0] : a[0] - a[i];
        g = gcd(g, diff);
    }

    for (int i = 0; i < m; i++) {
        cout << gcd(g, a[0] + b[i]) << (i + 1 == m ? '\n' : ' ');
    }
}
