
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    // Your code here

    // input
    // 5 (number of testcases)
    // 5 (number of athletes in array)
    // 3 1 2 6 4 (the strength of each athlete)
    // 6
    // 2 1 3 2 4 3
    // 4
    // 7 9 3 1
    // 2
    // 1 1000
    // 3
    // 100 150 200

    vi athletes(n);
    for (int i = 0; i < n; ++i) {
        cin >> athletes[i];
    }
    sort(athletes.begin(), athletes.end());
    int min_diff = INT_MAX;
    // find min diff consecutive elements
    for (int i=1; i<n; ++i) {
        min_diff = min(min_diff, athletes[i] - athletes[i - 1]);
    }
    cout << min_diff << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}