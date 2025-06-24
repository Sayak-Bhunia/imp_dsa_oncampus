#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n, vector<int> &a) {
    unordered_map<int, int> mp;
    int x = INT_MIN, y = INT_MIN;
    for(auto it:a) {
        mp[it]++;
        if(it>x) {
            y = x;
            x = it;
        }
        else if(it>y && it != x) y = it;
    }
    if(mp[a[0]] == n) return 0;
    else return mp[y];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << helper(n, a) <<endl;
}
