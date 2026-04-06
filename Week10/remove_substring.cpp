#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi L(m), R(m);

    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (s[i] == t[j]) {
            L[j] = i;
            j++;
        }
    }

    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
        if (s[i] == t[j]) {
            R[j] = i;
            j--;
        }
    }

    int ans = 0;
    ans = max(ans, R[0]);
    ans = max(ans, n - 1 - L[m - 1]);

    for (int i = 0; i + 1 < m; i++) {
        ans = max(ans, R[i + 1] - L[i] - 1);
    }
    cout << ans << '\n';
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
