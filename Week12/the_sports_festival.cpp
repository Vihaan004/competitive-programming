#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    vector<long long> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // dp[l][r] = min cost to merge s[l:r]
    for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + (s[r] - s[l]);
        }
    }
    cout << dp[0][n - 1] << '\n';
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
