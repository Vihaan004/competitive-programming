#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x, y;
        cin >> n >> k >> x >> y;

        vi a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end()); // smallest to largest
        ll ans = (ll)4e18;

        ll removed_sum = 0;
        // choose some shelves to zero (largest first)
        // shelves count stay n but sum drops

        for (int i = 0; i <= n; i++) {
            ll sum_after = sum - removed_sum;

            // no redistribution: just zeros applied
            int max_after;
            if (i == n) {
                max_after = 0;
            } else {
                max_after = a[n - 1 - i];  // largest among not-zeroed
            }
            if (max_after <= k) {
                ans = min(ans, (ll)i * x);
            }
            // one redistribution over all n shelves
            ll q = sum_after / n;
            ll r = sum_after % n;
            ll max_b = q + (r > 0 ? 1 : 0);
            if (max_b <= k) {
                ans = min(ans, (ll)i * x + y);
            }
            if (i == n) break;
            // then clear one more largest shelf
            removed_sum += a[n - 1 - i];
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
