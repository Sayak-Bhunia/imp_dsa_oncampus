#include <bits/stdc++.h>
using namespace std;

void spiralOrderPrint(vector<vector<int>> &a, int n, int m) {
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    while (top <= bottom && left <= right) {
        // Move → Right (Top Row)
        for (int i = left; i <= right; i++) 
            cout << a[top][i] << endl;
        top++; // Shrink top boundary

        // Move ↓ Down (Right Column)
        for (int i = top; i <= bottom; i++) 
            cout << a[i][right] << endl;
        right--; // Shrink right boundary

        if (top <= bottom) { // Ensure valid bottom row exists
            // Move ← Left (Bottom Row)
            for (int i = right; i >= left; i--) 
                cout << a[bottom][i] << endl;
            bottom--; // Shrink bottom boundary
        }

        if (left <= right) { // Ensure valid left column exists
            // Move ↑ Up (Left Column)
            for (int i = bottom; i >= top; i--) 
                cout << a[i][left] << endl;
            left++; // Shrink left boundary
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    spiralOrderPrint(a, n, m);
}
