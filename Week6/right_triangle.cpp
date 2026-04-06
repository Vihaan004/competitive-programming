#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
 
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '*') row[i]++, col[j]++;
 
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (g[i][j] == '*') {
            ans += (row[i] - 1) * (col[j] - 1);
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}