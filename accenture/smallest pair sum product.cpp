#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n, int k, vector<int> &a) {
    if(a.size()<2) return -1;
    int i = 0, j = 1;
    sort(a.begin(), a.end());
    while(j<n) {
        if(a[i] + a[j]<=k) return a[i]*a[j];
        i++;
        j++;
    }
    return 0;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << helper(n, k, a) <<endl;
}
