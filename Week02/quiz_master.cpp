#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n, m; // students, topics
    cin >> n >> m;

    vi a(n);
    for (int i=0; i<n; i++) {cin >> a[i]; }

    // n=4
    // m = 1, 2, 3 ... (continuous topics)
    // a = 3, 7, 2, 9       [2, 3, 7, 9]
    // for each topic
    // find multiples of topic num
    // if smartness == multiple (student is proficient)


    // add student to team if not already in team

    // how to find student to minimize max diff?
    // 
    // 1. find valid teams (all topics covered)
    // 2. minimize max diff 

    // 2 is profi in topic 1
    // 2 is also profi in topic 2
    // 2 is is prof in topic 3




}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
