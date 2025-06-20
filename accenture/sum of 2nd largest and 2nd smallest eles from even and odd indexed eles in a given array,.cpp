#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n, vector<int> &a) {
    vector<int> b, c;
    for(int i=0;i<n;i++) {
        if(i%2 == 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    int x = INT_MIN, y = INT_MIN, p = INT_MAX, q = INT_MAX;
    for(auto it:b) {
        if(it>x) {
            y = x;
            x = it;
        }
        else if(it>y && it != x) y = it;
    }
    for(auto it:c) {
        if(it<p) {
            q = p;
            p = it;
        }
        else if(it<q && it != p) q = it;
    }
    cout << y + q <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(n, a);
}
