#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vll = vector<long long>;

void solve() {
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i] = max score from index i
    vll dp(n, 0);
    long long ans = 0;

    // right to left so jump target is already computed
    for (int i = n - 1; i >= 0; i--) {
        // jump exits array
        if ((i + a[i]) >= n) dp[i] = a[i];
        // add current value + best score from landing index
        else dp[i] =  a[i] + dp[i + a[i]];
        // keep best start score
        ans = max(ans, dp[i]);
    }
    
    cout << ans << "\n";
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
