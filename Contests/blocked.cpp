#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    for(int i=1; i<n; i++) {
        if(a[i-1] == a[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
