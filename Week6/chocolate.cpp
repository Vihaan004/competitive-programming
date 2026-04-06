#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pos;
    for (int i = 0; i < n; i++) if (a[i]==1) pos.push_back(i);

    if (pos.empty()) { 
        cout << 0 << "\n";
        return;
    }
    if ((int) pos.size() == 1) { 
        cout << 1 << "\n";
        return;
    }

    long long ans = 1;
    for (int i = 1; i < (int)pos.size(); i++) {
        int gap = pos[i]-pos[i-1]-1;
        ans *= (gap + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
