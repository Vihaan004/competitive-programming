#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    priority_queue<int> heap;
    long long power = 0;

    for (int i=0; i<n; i++) {
        int card;
        cin >> card;
        if (card > 0) {
            heap.push(card);
        } else if (!heap.empty()) {
            power += heap.top();
            heap.pop();
        }
    }
    cout << power << endl;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}

    // vi bonusDeck;
    // int power = 0;

    // int card;
    // for (int i=0; i<n; i++) {
    //     cin >> card;
    //     if (card > 0) {
    //         bonusDeck.push_back(card);
    //         // cout << "Added to deck: " << card << endl;
    //     } else if (!bonusDeck.empty()){
    //         auto boost = max_element(bonusDeck.begin(), bonusDeck.end());
    //         power += *boost;
    //         // cout << "Boost applied: " << *boost << endl;
    //         auto rIt = find(bonusDeck.rbegin(), bonusDeck.rend(), *boost); // last occurrence
    //         bonusDeck.erase(next(rIt).base()); // use card
    //     }
    // }
    // cout << power << endl;