#include <iostream>
#include <vector>
using namespace std;

void printSpiral(const vector<vector<int>>& matrix, int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Move → (left to right)
        for (int col = left; col <= right; col++)
            cout << matrix[top][col] << " ";
        top++;

        // Move ↓ (top to bottom)
        for (int row = top; row <= bottom; row++)
            cout << matrix[row][right] << " ";
        right--;

        // Move ← (right to left)
        if (top <= bottom) {
            for (int col = right; col >= left; col--)
                cout << matrix[bottom][col] << " ";
            bottom--;
        }

        // Move ↑ (bottom to top)
        if (left <= right) {
            for (int row = bottom; row >= top; row--)
                cout << matrix[row][left] << " ";
            left++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    printSpiral(matrix, n, m);
}
