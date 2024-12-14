#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    unordered_set<int> set;
    bool f = false;
    for(auto it:a) set.insert(it);
    for(auto it:b) {
        if(set.find(it) != set.end()) {
            f = 0;
            break;
        }
    }
    if(f) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}
