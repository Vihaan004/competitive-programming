#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vector<vi> children(n+1);
    for (int v = 2; v <= n; v++) {
        int p; cin >> p;
        children[p].push_back(v);
    }

    for (int u = 1; u <= n; u++) {
        if(children[u].empty()) continue;  // leaf
        int leafChildren = 0;
        for (int v : children[u]) {
            if (children[v].empty()) leafChildren++;
        }
        if(leafChildren < 3) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
