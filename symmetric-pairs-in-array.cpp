#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    unordered_map<int, int> mp;
    for(auto it:a) {
        int x = it.first;
        int y = it.second;
        if(mp.find(y) != mp.end() && mp[y] == x) {
            cout << "(" << y << "," << x << ")" <<endl;
            cout << "(" << x << "," << y << ")" <<endl;
        }
        else mp[x] = y;
    }
}
