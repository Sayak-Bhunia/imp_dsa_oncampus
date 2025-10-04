#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &a, int n, int k) {
    int res = 0;
    vector<int> b = a;
    sort(b.begin(), b.end());
    swap(b[n-1], b[k-1]);
    sort(b.begin()+k, b.end());
    for(int i=0;i<n;i++) {
        int j = 0;
        for(j=i;j<n;j++) {
            if(b[i] == a[j]) break;
        }
        if(j == i) continue;
        if(i == 0) {
            res += a[i]*a[j];
            swap(a[i], a[j]);
            continue;
        }
        res += 2*min(a[i], a[j])*b[0] + max(a[i], a[j])*b[0];
        swap(a[i], a[j]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        cout << helper(a, n, k) <<endl;
    }
}
