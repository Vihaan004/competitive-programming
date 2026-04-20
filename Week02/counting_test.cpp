#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;


void solve() {
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    int pref[n+1][26] = {0};

    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) {
            pref[i+1][j] = pref[i][j];
        }
        int index = str[i] - 'a';
        pref[i+1][index]++;
    }

    int l, r;
    char target;
    for (int i=0; i<q; i++) {
        cin >> l >> r >> target;
        int index = target - 'a';
        int l_block = (l - 1) / n; int li = (l - 1) % n + 1;
        int r_block = (r - 1) / n; int ri = (r - 1) % n + 1;
        
        int count = 0;
        if (l_block == r_block) {
            count += pref[ri][index] - pref[li-1][index];
        } else {
            count += pref[n][index] - pref[li - 1][index];
            count += (r_block - l_block - 1) * pref[n][index];
            count += pref[ri][index];
        }
        cout << count << endl;

        // int ri = r % n;
        // int li = l % n;
        // cout << (pref[ri][index] + r/n * pref[n][index]) - (pref[li-1][index] + l/n * pref[n][index]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // solve();
    int t;
    cin >> t;
    while (t--) solve();
}
// void solve() {
//     int n, q;
//     cin >> n >> q;
//     // string str;
//     // cin >> str;
    
//     unordered_map<char, int> freq;
//     for (int i=0; i<n; i++) {
//         // freq[str[i]]++;
//         char c; cin >> c;
//         freq[c]++;
//     }

//     int l, r;
//     char target;
//     for (int i=0; i<q; i++) {
//         cin >> l >> r >> target;
//         cout << freq[target];
//     }

//     // for (auto it = freq.begin(); it != freq.end(); it++) {
//     //     cout << it->first << ":" << it->second << endl;
//     // }
// }
    