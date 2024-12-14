#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int x = k%n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + x);
    reverse(a.begin() + x, a.end());
    for(auto it:a) cout << it << " ";
}
