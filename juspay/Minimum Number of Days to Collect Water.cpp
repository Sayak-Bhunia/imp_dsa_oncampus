#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool helper(ll d, ll w, vector<int> &warr, vector<int> &refill) {
    ll sum = 0;
    for(int i=0;i<warr.size();i++) {
        sum += ((d/refill[i]) + 1)*(ll)warr[i];
        if(sum>=w) return true;
    }
    return sum>=w;
}

ll minDaysToCollectWater(ll w, vector<int> &warr, vector<int> &refill) {
    ll l = 0, r = 1e18, res = -1;
    while(l<=r) {
        ll m = l + (r - l)/2;
        if(helper(m, w, warr, refill)) {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}

int main() {
    ll w = 20;
    vector<int> warr = {3, 5};
    vector<int> refill = {1, 2};

    cout << minDaysToCollectWater(w, warr, refill) << endl; // Output: 3
    return 0;
}
