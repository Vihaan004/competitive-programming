// #include <bits/stdc++.h>
// using namespace std;

// struct SegTree {
//     int k = 0;            // number of levels (given n)
//     int n = 1;            // number of leaves = 2^k
//     vector<int> seg;

//     void init(int _k) {
//         k = _k;
//         n = 1 << k;
//         seg.assign(2 * n, 0);
//     }

//     bool isOrAtNode(int p) const {
//         // depth(root)=0, depth(leaves)=k
//         // height-from-leaves for node p is (k - depth(p))
//         // operation is OR if that height is odd, XOR if even
//         int depth = 31 - __builtin_clz(p); // floor(log2(p)), p>=1
//         int height = k - depth;
//         return (height % 2 == 1);
//     }

//     void pull(int p) {
//         if (isOrAtNode(p)) seg[p] = seg[2 * p] | seg[2 * p + 1];
//         else seg[p] = seg[2 * p] ^ seg[2 * p + 1];
//     }

//     void upd(int idx, int val) {
//         int p = idx + n;
//         seg[p] = val;
//         for (p /= 2; p; p /= 2) pull(p);
//     }

//     int all() const { return seg[1]; }
// };
 
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m; cin >> n >> m;

//     SegTree seg;
//     seg.init(n);
//     for (int i = 0; i < (1 << n); i++) {
//         int x; cin >> x;
//         seg.upd(i, x);
//     }
//     while (m--) {
//         int p, b;cin >> p >> b;
//         seg.upd(p - 1, b);
//         cout << seg.all() << '\n';
//     }
// }

// submission
#include <bits/stdc++.h>
using namespace std;

int seg[1<<18 | 1];
int N;

void build(int v, int l, int r, int dep) {
    if (l == r) return;
    int mid = (l+r)/2;
    build(2*v, l, mid, dep-1);
    build(2*v+1, mid+1, r, dep-1);
    if (dep % 2 == 1) seg[v] = seg[2*v] | seg[2*v+1];
    else seg[v] = seg[2*v] ^ seg[2*v+1];
}

void upd(int v, int l, int r, int pos, int val, int dep) {
    if (l == r) { seg[v] = val; return; }
    int mid = (l+r)/2;
    if (pos <= mid) upd(2*v, l, mid, pos, val, dep-1);
    else upd(2*v+1, mid+1, r, pos, val, dep-1);
    if (dep % 2 == 1) seg[v] = seg[2*v] | seg[2*v+1];
    else seg[v] = seg[2*v] ^ seg[2*v+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    N = 1<<n;
    for (int i = 1; i <= N;i++) cin >> seg[N + i - 1];
    // build bottom-up manually using dep
    build(1, 1, N, n);
    while (m--) {
        int p, b;cin >> p >> b;
        upd(1, 1, N, p, b, n);
        cout << seg[1] << '\n';
    }
}