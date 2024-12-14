#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n,m;
    cin >> n >> m;
    vector<int> a(n+m), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    vector<int> merged(m+n);
    int i = 0, j = 0, k = 0;
    while(i<n && j<m) {
        if(a[i]<b[j]) merged[k++] = a[i++];
        else merged[k++] = b[j++];
    }
    while(i<n) merged[k++] = a[i++];
    while(j<m) merged[k++] = b[j++];
    int sz = m + n;
    if(sz%2 == 0) cout << (merged[sz/2-1]+merged[sz/2])/2.0 <<endl;
    else cout << merged[sz/2] <<endl;
}
