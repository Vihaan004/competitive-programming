// #include <bits/stdc++.h>

// using namespace std;
// using vi = vector<int>;

// void solve() {
//     int n, k, q; // recipes, min. no. of recipes for a temp to be admissible, questions
//     cin >> n >> k >> q;

//     int max_temp = 0;
//     int min_temp = INT_MAX;

//     vector<pair<int, int>> recipes(n);
//     for (int i=0; i<n; i++) {
//         int l, r;
//         cin >> l >> r;
//         recipes[i].first = l; recipes[i].second = r;
//         max_temp = (r >= max_temp) ? r : max_temp;
//         min_temp = (l <= min_temp) ? l : min_temp;
//     }
//     vector<pair<int, int>> questions(q);
//     for (int i=0; i<q; i++) {
//         int l, r;
//         cin >> l >> r;
//         questions[i].first = l; questions[i].second = r;
//         max_temp = (r >= max_temp) ? r : max_temp;
//         min_temp = (l <= min_temp) ? l : min_temp;
//     }

//     // find number of admissible integer temperatures in range [aq, bq] (for each question pair q)
    
//     int range = max_temp - min_temp;
//     // cout << "min:" << min_temp << "\nmax:" << max_temp << endl;
//     vi cover(range+1);
//     // for each recipe
//     for (int i=0; i<n; i++) {
//         // calculate how many times each temp seen
//         // cout << "Recipe:" << recipes[i].first << ":" << recipes[i].second << endl;
//         for (int j=recipes[i].first; j<=recipes[i].second; j++) {
//             cover[j-min_temp]++;
//         }
//     }
//     // print cover
//     // for (int i=0; i<=range; i++) {
//     //     cout << "Temp " << i+min_temp << ": " << cover[i] << endl;
//     // }
//     int count = 0;
//     // for each question
//     for (int i=0; i<q; i++) {
//         // calculate which temps are admissible
//         for (int j=questions[i].first; j<=questions[i].second; j++) {
//             if (cover[j-min_temp] >= k) count++;
//         }
//         cout << count << "\n";
//         count = 0;
//     }
// }


    
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     // int t;
//     // cin >> t;
//     // while (t--) solve();
//     solve();
// }



#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n, k, q; // recipes, min. no. of recipes for a temp to be admissible, questions
    cin >> n >> k >> q;

    const int MAXT = 200000; // max possible temperature

    // difference array to build coverage
    vi diff(MAXT + 2, 0);    // +2 to safely handle r+1

    // read recipes and apply difference array trick
    vector<pair<int, int>> recipes(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        recipes[i].first = l; 
        recipes[i].second = r;

        // mark start and end+1
        diff[l] += 1;
        if (r + 1 <= MAXT) diff[r + 1] -= 1;
    }

    // build coverage: cover[t] = how many recipes cover temperature t
    vi cover(MAXT + 1, 0);
    cover[1] = diff[1];
    for (int t = 2; t <= MAXT; t++) {
        cover[t] = cover[t - 1] + diff[t];
    }

    // good[t] = 1 if temperature t is admissible (covered by at least k recipes), else 0
    vi good(MAXT + 1, 0);
    for (int t = 1; t <= MAXT; t++) {
        if (cover[t] >= k) good[t] = 1;
    }

    // prefix sum over good so we can answer queries in O(1)
    vi pref(MAXT + 1, 0);
    for (int t = 1; t <= MAXT; t++) {
        pref[t] = pref[t - 1] + good[t];
    }

    // read and answer questions
    // find number of admissible integer temperatures in range [aq, bq] (for each question pair q)
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        // number of admissible temps in [a, b] = pref[b] - pref[a-1]
        cout << (pref[b] - pref[a - 1]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--) solve();
    solve();
}
