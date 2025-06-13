#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool helper(int n) {
    
}

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int mn = INT_MAX, c = 0, currIdx = -1, currVal = 0;
    bool f1 = false, f2 = false;
    for(int i=0;i<n;i++) {
        if(a[i] == x || a[i] == y) {
            if(currIdx != -1 && a[i] != currVal) mn = min(mn, i - currIdx - 1);
            currIdx = i;
            currVal = a[i];
        }      
        if(a[i] == x) f1 = true;
        if(a[i] == y) f2 = true;
    }
    if(!f1 || !f2) cout << -1 <<endl;
    else cout << mn <<endl;
}
