#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lint long long int

int main() {
    int n;
    cin >> n;
    vector<lint> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    int res = 1;
    int l = 0;
    for(int r=0;r<n;r++) {
        while(a[r]-a[l]>n-1) l++;
        res = max(res, r - l + 1);
    }
    cout << res <<endl;
}
