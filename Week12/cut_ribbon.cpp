#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    // max num of pieces for each len, -inf for impossible
    vi dp(n + 1, INT_MIN);
    dp[0] = 0;

    for(int len = 1; len <= n; ++len) {
        if(len - a >= 0) dp[len] = max(dp[len], dp[len - a] + 1);
        if(len - b >= 0) dp[len] = max(dp[len], dp[len - b] + 1);
        if(len - c >= 0) dp[len] = max(dp[len], dp[len - c] + 1);
    }
    cout << dp[n] << '\n';
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
