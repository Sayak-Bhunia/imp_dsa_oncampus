#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(vector<int> &a, int n, int u, int r) {
    if(n == 0) return -1;
    int sum = accumulate(a.begin(), a.end(), 0);
    int mn = u*r;
    if(sum<mn) return 0;
    int i = 0;
    while(mn>0) mn -= a[i++];
    return i;
}

int main() {
    int n,u,r;
    cin >> n >> u >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << helper(a, n, u, r) <<endl;
}
