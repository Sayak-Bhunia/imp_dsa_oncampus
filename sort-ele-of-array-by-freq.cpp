#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    unordered_map<int, int> mp;
    for(auto it:a) mp[it]++;
    sort(a.begin(), a.end(), [&](int x, int y){
        if(mp[x] == mp[y]) return x>y; //same freq hle value er desc order e 
        else return mp[x]<mp[y]; //freq er asc order e
    });
    for(auto it:a) cout << it << " ";
}
