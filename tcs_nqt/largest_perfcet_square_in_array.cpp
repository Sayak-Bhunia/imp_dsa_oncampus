#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int helper(int n) {
    int x = static_cast<int>(sqrt(n));
    return x*x == n;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int mx = INT_MIN;
    for(auto it:a) {
        if(helper(it)) mx = max(mx, it);
    }
    cout << mx <<endl;
}
