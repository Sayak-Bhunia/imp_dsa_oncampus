#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lint long long int

int main() {
    vector<lint> a;
    lint x;
    while(cin >> x) a.push_back(x);
    int n = a.size();
    vector<lint> pref(n+1, 0);
    for(int i=0;i<n;i++) pref[i+1] = pref[i] + a[i]; 
    unordered_map<lint, int> mp;
    lint res = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            lint sum = pref[j] - a[i];
            int c = mp[sum];
            c++;
            if(c == 2) res = max(res, sum);
        }
        if(i>2000 && i%2000 == 0) unordered_map<lint, int>().swap(mp);
    }
    cout << res <<endl;
}
