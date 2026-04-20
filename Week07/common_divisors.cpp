#include <bits/stdc++.h>
using namespace std;

bool works(const string& s, const string& base, int len) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != base[i % len]) {return false;}
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int g = gcd((int)s.size(), (int)t.size());
    int ans = 0;

    for (int d = 1; 1LL * d * d <= g; d++) {
        if (g % d) {continue;}

        if (works(s, s, d) && works(t, s, d)) { ans++;}

        int e = g / d;
        if (e != d && works(s, s, e) && works(t, s, e)) {ans++;}
    }

    cout << ans << '\n';
}
