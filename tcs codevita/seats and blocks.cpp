#include <bits/stdc++.h>
using namespace std;

int helper(vector<bool> &f, int l, int r, int k, int n, int s) {
    vector<bool> f1(s, false);
    int dry = n - k;
    int wet = k;
    int lastidx = -1;
    for(int i=l;i<=r;i++) {
        if(!f[i] && dry>0) {
            dry--;
            f1[i] = true;
        }
        else if(f[i] && wet>0) {
            wet--;
            f1[i] = true;
        }
        for(int j=l;j<=i;j++) {
            if(!f1[j] && wet>0) {
                wet--;
                f1[j] = true;
            }
        }
        if(wet == 0 && dry == 0) {
            wet = 0;
            lastidx = i;
            break;
        }
    }
    int res = lastidx - l;
    if(wet != 0 || dry != 0) return INT_MAX;
    return res;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int s,n,k,m;
        cin >> s >> n >> k >> m;
        vector<int> a(m);
        for(int i=0;i<m;i++) cin >> a[i];
        vector<bool> f(s, false);
        int idx = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<a[i];j++) {
                if(i%2) f[idx] = true;
                idx++;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<s;i++) {
            for(int j=i+n;j<s;j++) res = min(res, helper(f, i, j, k, n, s));
        }
        if(res == INT_MAX) cout << 0 <<endl;
        cout << res <<endl;
    }
}
