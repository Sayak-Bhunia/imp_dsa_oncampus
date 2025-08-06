#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C, Q;
    cin >> C >> Q;
    vector<long long> d(C+1, 0), pref(C+2, 0);
    vector<pair<int, pair<int, int>>> q;
    for(int i=0;i<Q;i++) {
        int type, a, b;
        cin >> type >> a >> b;
        q.push_back({type, {a, b}});
        if(type == 1) d[a] += b;
    }
    for(int i=1;i<=C;i++) pref[i] = pref[i-1] + d[i];
    vector<long long> res;
    for(auto it:q) {
        if(it.first == 2) {
            int l = it.second.first;
            int r = it.second.second;
            long long sum = pref[r] - (l>0?pref[l-1]:0);
            res.push_back(sum);
        }
    }
    for(auto it:res) cout << it << " ";
}
