#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // can only consume 67 or 76 items at a time
    // calculate distinct ways to consume n items
    // do mod 1e9 + 7 every step

    // state = s
    // ways to reach s = ways to reach s - 67 + ways to reach s - 76
    // dp[0] = 1
    // dp[s] = dp[s - 67] + dp[s - 76]

    vi dp(1000000 + 1);
    dp[0] = 1;
    for (int s = 1; s <= 1000000; s++) {
        long long ways = 0;
        if (s >= 67) ways += dp[s - 67];
        if (s >= 76) ways += dp[s - 76];
        dp[s] = ways % 1000000007;
    }

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}
