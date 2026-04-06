#include <bits/stdc++.h>
using namespace std;

template <class T> struct SegTree {
    using P = pair<T,T>;
    const P ID{INT_MIN, INT_MAX};
    P cmb(P a, P b) { return {max(a.first,b.first), min(a.second,b.second)}; }
    int n; vector<P> seg;
    void init(int _n) {
        for (n = 1; n < _n; ) n *= 2;
        seg.assign(2*n, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2*p], seg[2*p+1]); }
    void upd(int p, T val) {
        seg[p += n] = {val, val};
        for (p /= 2; p; p /= 2) pull(p);
    }
    P query(int l, int r) {
        P ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = cmb(ra, seg[l++]);
            if (r&1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        SegTree<int> seg; seg.init(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            seg.upd(i, x);
        }
        while (q--) {
            int op; cin >> op;
            if (op == 1) {
                int x, y; cin >> x >> y;
                seg.upd(x-1, y);
            } else {
                int p, r; cin >> p >> r;
                auto [mx, mn] = seg.query(p-1, r-1);
                cout << mx - mn << '\n';
            }
        }
    }
}