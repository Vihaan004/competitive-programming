#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n , k;
    cin >> n >> k;
    
    vi values(n);
    for(int i=0; i<n; i++) { cin >> values[i]; }
    
    int left = 0;
    int right = 0;
    long long count = 0;
    int distinct = 0;
    unordered_map<int, int> freq;
    for(int right=0; right<n; right++){
        // vi window(n);
        // window.push_back(values[right]);
        freq[values[right]]++;
        if(freq[values[right]] == 1) {
            distinct++;
        }
        while(distinct > k) {
            freq[values[left]]--;
            if(freq[values[left]] == 0) {
                distinct--;
            }
            left++;
        }
        count += right - left + 1;
    }
    cout << count;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    // int t;
    // cin >> t;
    // while (t--) solve();
}
