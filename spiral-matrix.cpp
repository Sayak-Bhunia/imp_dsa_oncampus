#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n,m;
    cin >> n >> m;
    int mx = INT_MIN;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    int i;
    while(top<=bottom && left<=right) {
        for(i=left;i<=right;i++) cout << a[top][i] <<endl;
        top++;
        for(i=top;i<=bottom;i++) cout << a[i][right] <<endl;
        right--;
        if(top<=bottom) {
            for(i=right;i>=left;i--) cout << a[bottom][i] <<endl;
            bottom--;
        }
        if(left<=right) {
            for(i=bottom;i>=top;i--) cout << a[i][left] <<endl;
            left++;
        }
    }
}
