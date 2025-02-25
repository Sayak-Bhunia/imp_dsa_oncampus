// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    unordered_set<int> set(a.begin(), a.end());
    bool f = false;
    for(auto it:b) {
        if(set.find(it) != set.end()) {
            f = true;
            break;
        }
    }
    if(f) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}
