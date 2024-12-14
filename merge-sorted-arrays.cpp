#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n,m;
    cin >> n >> m;
    vector<int> a(n+m), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i>=0 && j>=0) {
            if(a[i]>b[j]) a[k--] = a[i--];
            else a[k--] = b[j--];
    }
    while(j>=0) a[k--] = b[j--];
--------------------------------------- or ------
    vector<int> merged(m+n);
    int i = 0, j = 0, k = 0;
    while(i<n && j<m) {
        if(a[i]<b[j]) merged[k++] = a[i++];
        else merged[k++] = b[j++];
    }
    while(i<n) merged[k++] = a[i++];
    while(j<m) merged[k++] = b[j++];
    for(auto it:a) cout << it << " ";
}
