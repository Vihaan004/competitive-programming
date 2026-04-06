#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi deg(n+1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if(deg[i] == 1) leaves++;
    }
    // cout << leaves << '\n';
    cout << (leaves + 1) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
