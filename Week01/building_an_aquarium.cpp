#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    
    vector<int> columns(n);
    for (int i=0; i<n; i++) {
        cin >> columns[i];
    }

    // binary search on height
    int left = 1;
    int right = INT_MAX;
    int result = 1; // cause h>=1

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int need = 0;
        // calc units for each column for this height
        for (int i=0; i<n; i++) {
            if (columns[i] < mid) {
                need += mid - columns[i];
                if (need > x) break; // overflow already
            }
        }
        // if possible, checkpoint and try higher, else go lower
        if (need <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << "\n";

}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}

//     auto canAchieve = [&](int h) {
//         int water = 0;
//         for (int col : columns) {
//             water += max(0, h - col);
//         }
//         return water <= x;
//     };

//     int left = 0, right = columns[n-1] + x / n + 1;
    
//     while (left < right) {
//         int mid = (left + right + 1) / 2;
//         if (canAchieve(mid)) {
//             left = mid;
//         } else {
//             right = mid - 1;
//         }
//     }

//     cout << left << "\n";
// }
