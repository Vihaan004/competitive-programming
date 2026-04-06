#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int i = 0, j = n - 1;
    long long left = d[i], right = d[j], ans = 0;

    while (i < j) {
        if (left == right) {
            ans = left;
            i++; j--;
            if (i < j) {
                left += d[i];
                right += d[j];
            }
        } else if (left < right) {
            i++;
            left += d[i];
        } else {
            j--;
            right += d[j];
        }
    }

    cout << ans << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
