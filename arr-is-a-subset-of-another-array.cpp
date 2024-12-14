#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    unordered_set<int> set(a.begin(), a.end());
    bool f = false;
    for(auto it:b) {
        if(set.find(it) == set.end()) {
            f = true;;
            break;
        }
    }
    if(f) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}
