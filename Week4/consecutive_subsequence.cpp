#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    // longest increasing subsequence algo
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[value] = {length, last_index}
    map<int, pair<int, int>> dp;

    for (int i = 0; i < n; i++) {
        int val = a[i];
        
        // if we can extend sequence ending at val-1
        if (dp.count(val - 1)) {
            if (!dp.count(val) || dp[val-1].first + 1 > dp[val].first) {
                dp[val] = {dp[val-1].first + 1, i};
            }
        } else {
            // start new
            if (!dp.count(val)) {
                dp[val] = {1, i};
            }
        }
    }
    
    int maxLen = 0, endVal = 0;
    for (auto& [val, p] : dp) {
        if (p.first > maxLen) {
            maxLen = p.first;
            endVal = val;
        }
    }
    
    vi result;
    int currVal = endVal;
    for (int len = maxLen; len > 0; len--) {
        result.push_back(dp[currVal].second + 1); // 1-indexed
        currVal--;
    }
    reverse(result.begin(), result.end());
    
    cout << maxLen << "\n";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
