#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    unordered_map<int, pair<int, int>> mp;
    for(int i=0;i<n;i++) {
        mp[a[i]].first++;
        mp[a[i]].second = i;
    }
    for(auto it:mp) {
        if(it.second.first>1) cout << it.second.second << " ";
    }
}
