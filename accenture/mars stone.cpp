#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(vector<int> &a, int m, int n) {
    set<int> set(a.begin(), a.end());
    vector<int> b;
    for(int i=1;i<=m;i++) {
        if(set.find(i) == set.end()) b.push_back(i);
    }
    sort(b.begin(), b.end());
    int c = 0, tw = 0;
    for(auto it:b) {
        if(tw + it<=m) {
            tw += it;
            c++;
        }
        else break;
    }
    cout << c <<endl;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(a, m, n);
}
