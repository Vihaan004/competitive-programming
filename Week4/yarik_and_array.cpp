#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // max subarray sum (kadane algo)
    vi best_end(n);
    best_end[0] = a[0];

    int answer = best_end[0];

    for (int i = 1; i < n; i++) {
        if ((a[i] + a[i-1]) % 2 != 0) {
            best_end[i] = max(a[i], best_end[i-1] + a[i]);
        } else {
            best_end[i] = a[i];
        }
        answer = max(answer, best_end[i]);
    }
    cout << answer << "\n";
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
