#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    long long prev_b = -1;
    long long len = 1;
    bool possible = true;
    
    for (int i=0; i<n; i++) {
        long long a;
        cin >> a;
        if (!possible) continue; 
        
        // exactly when the i-th volunteer paying attention
        long long b = (m - a) % m;
        
        if (i > 0) {
            long long diff = (b - prev_b + m) % m;
            if (diff <= len) {
                len = len + 1 - diff;
            } else {
                len = 1; // splits - reset blocked interval
            }
            
            // interval of blocked times covers all modulo possibilities
            if (len >= m) {
                possible = false;
            }
        }
        
        prev_b = b;
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}