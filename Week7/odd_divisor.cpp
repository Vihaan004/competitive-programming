#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    while (n % 2 == 0) n /= 2;
    cout << (n > 1 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
