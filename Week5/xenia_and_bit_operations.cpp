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