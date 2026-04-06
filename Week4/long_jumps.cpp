#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vll = vector<long long>;

void solve() {
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vll dp(n, 0);
    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        if ((i + a[i]) >= n) dp[i] = a[i];
        else dp[i] =  a[i] + dp[i + a[i]];
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
