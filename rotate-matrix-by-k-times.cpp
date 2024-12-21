#include <bits/stdc++.h>
#define lint long long 
using namespace std;

void rotateMatrix(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();
    int row = 0, col = 0;
    int prev, curr;
    while(row<n && col<m) {
        if(row + 1 == n || col + 1 == m) break;
        prev = a[row+1][col];
        for(int i=col;i<m;i++) {
            curr = a[row][i];
            a[row][i] = prev;
            prev = curr;
        }
        row++;
        for(int i=row;i<n;i++) {
            curr = a[i][m-1];
            a[i][m-1] = prev;
            prev = curr;
        }
        m--;
        if(row<n) {
            for(int i=m-1;i>=col;i--) {
                curr = a[n-1][i];
                a[n-1][i] = prev;
                prev = curr;
            }
        }
        n--;
        if(col<m) {
            for(int i=n-1;i>=row;i--) {
                curr = a[i][col];
                a[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

void rotateMatrixKTimes(vector<vector<int>>& a, int k) {    
    for(int i=0;i<k;i++) rotateMatrix(a);
}

int main() {   
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    rotateMatrixKTimes(a, k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << a[i][j] << " ";
        cout <<endl;
    }
}
