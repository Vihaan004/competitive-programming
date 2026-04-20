#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long cT, cH, cU;
        cin >> cT >> cH >> cU;

        // pair T and U
        long long x = min(cT, cU);
        cT -= x;
        cU -= x;
        long long ans = 4 * x;
        ans += 3 * cU;
        ans += 3 * cH;
        ans += 2 * cT;
        if (cT > 2 * cH) ans += 1;

        cout << ans << '\n';
    }
    return 0;
}