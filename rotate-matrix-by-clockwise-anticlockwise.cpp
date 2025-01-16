void rotateClockwise(vector<vector<int>>& a) {
    int n = a.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = a[i][j];
        }
    }
    a = temp; 
}

void rotateAnticlockwise(vector<vector<int>>& a) {
    int n = a.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[n - j - 1][i] = a[i][j];
        }
    }
    a = temp; 
}
