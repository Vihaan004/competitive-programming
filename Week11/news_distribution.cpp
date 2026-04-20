#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// DSU (Disjoint Set Union) maintains connected components
// parent compression + union by size => almost O(1) per operation
struct DSU {
    vi p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int a) { return (p[a] == a ? a : p[a] = find(p[a])); }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int group = 0; group < m; group++) {
        int k;
        cin >> k;
        if (k == 0) continue;

        int first;
        cin >> first;
        // everyone in this group is connected (a clique).
        // enough to connect all members to one representative.
        for (int i = 1; i < k; i++) {
            int v;
            cin >> v;
            dsu.unite(first, v);
        }
    }

    // news spreads to the entire connected component of the starting user
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << dsu.sz[dsu.find(i)];
    }
    cout << '\n';
    return 0;
}
