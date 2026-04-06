#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n - 1; i++) cin >> a[i];

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;

    vector<vector<int>> st(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n - 1; i++) st[0][i] = i;
    st[0][n] = n;

    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            int x = st[k - 1][i];
            int y = st[k - 1][i + (1 << (k - 1))];
            st[k][i] = (a[x] >= a[y] ? x : y);
        }
    }

    vector<int> lg(n + 1);
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    auto getMaxPos = [&](int l, int r) {
        int k = lg[r - l + 1];
        int x = st[k][l];
        int y = st[k][r - (1 << k) + 1];
        return (a[x] >= a[y] ? x : y);
    };

    vector<ll> dp(n + 1, 0);
    ll ans = 0;

    for (int i = n - 1; i >= 1; i--) {
        if (i == a[i]) continue;
        int k = getMaxPos(i + 1, a[i]);
        dp[i] = dp[k] + (ll)(n - a[i]) + (ll)(a[i] - k);
        ans += dp[i];
    }

    cout << ans << '\n';
    return 0;
}