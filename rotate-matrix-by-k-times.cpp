// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateMat(vector<vector<int>> &a, int k) {
    int n = a.size(), m = a[0].size();
    int top = k, left = k, bottom = n - k - 1, right = m - k - 1;
    if(top>=bottom || left>=right) return;
    vector<int> res;
    for(int i=left;i<=right;i++) res.push_back(a[top][i]);
    for(int i=top+1;i<=bottom;i++) res.push_back(a[i][right]);
    for(int i=right-1;i>=left;i--) res.push_back(a[bottom][i]);
    for(int i=bottom-1;i>=top;i--) res.push_back(a[i][left]);
    rotate(res.begin(), res.begin() + res.size() - 1, res.end());
    int idx = 0;
    for(int i=left;i<=right;i++) a[top][i] = res[idx++];
    for(int i=top+1;i<=bottom;i++) a[i][right] = res[idx++];
    for(int i=right-1;i>=left;i--) a[bottom][i] = res[idx++];
    for(int i=bottom-1;i>=top;i--) a[i][left] =res[idx++];
}

void helper(vector<vector<int>> &a, int n, int m, int k) {
    int layers = min(n, m)/2;
    for(int i=0;i<k;i++) {
        for(int j=0;j<layers;j++) rotateMat(a, j);
    }
}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    helper(a, n, m, k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << a[i][j] << " ";
        cout <<endl;
    }
}
