#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

// red button - num * 2
// blue button - num - 1
// num < 0 - breakdown
// initial num = n
// goal num = m
// return min button presses

// n = 7, m = 21
// 7, 14, 28, 56
// 
// 7, 7*2^1, 7*2^2, 7*2^3

void solve() {
    int n, m;
    cin >> n >> m;

    // if (m < n) cout << (n-m);
    // else if (m == n) cout << 0;
    // else {

    // }
    
    queue<int> q;
    vi dist(20001, -1); // cause m <= 10^4
    // vi visited(10000);

    q.push(n);
    dist[n] = 0;
    // visited[n] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == m) {
            cout << dist[curr];
            return;
        }
        int red = curr * 2;
        if (red < 20001 && dist[red] == -1) {
            dist[red] = dist[curr] + 1;
            q.push(red);
        }
        int blue = curr - 1;
        if (dist[blue] == -1 && blue > 0) {
            dist[blue] = dist[curr] + 1;
            q.push(blue);
        }        
    }
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
