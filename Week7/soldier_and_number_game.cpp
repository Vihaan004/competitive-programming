#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<pair<int,int>> queries(t);
    int mx = 0;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b};
        mx = max(mx, a);
    }

    vector<int> spf(mx + 1), omega(mx + 1), pref(mx + 1), primes;

    for (int i = 2; i <= mx; i++) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }

        omega[i] = omega[i / spf[i]] + 1;
        pref[i] = pref[i - 1] + omega[i];

        for (int p : primes) {
            long long v = 1LL * i * p;
            if (v > mx || p > spf[i]) break;
            spf[v] = p;
        }
    }

    for (auto [a, b] : queries) {
        cout << pref[a] - pref[b] << '\n';
    }
}
