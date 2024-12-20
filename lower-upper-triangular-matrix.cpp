#include <bits/stdc++.h>
#define lint long long 
using namespace std;

bool helper(vector<vector<int>> &a, int n, int m) { // lower
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<m;j++) {
            if(a[i][j] != 0) return false;
        }
    }
    return true;
 }

bool helper(vector<vector<int>> &a, int n, int m) { //upper
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[i][j] != 0) return false;
        }
    }
    return true;
 }

int main() {   
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<m;j++) cin >> a[i][j];
    }
    if(helper(a, n, m)) cout << "YES" <<endl;
    else cout << "NO" <<endl; 
}
