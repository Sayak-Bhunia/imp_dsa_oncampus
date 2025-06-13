#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool helper(vector<int> &a, int n, int t) {
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++) {
        if(mp.find(t - a[i]) != mp.end()) {
            for(int j=0;j<mp[t - a[i]];j++) {
                cout << "(" << t - a[i] << "," << a[i] << " " << ")" << " ";
            }
        }
        mp[a[i]]++;
    }
}

int main() {
    int n, t;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> t;
    helper(a, n, t);
}
