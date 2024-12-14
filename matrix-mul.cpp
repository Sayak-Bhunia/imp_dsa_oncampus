#include <iostream>
using namespace std;

bool isCompatible(int n, int m, int p, int q) {
    return m == p;  // Number of columns of the first matrix should equal the number of rows of the second matrix
}

void mul(int n, int m, int p, int q, int a[][100], int b[][100], int res[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int n, int q, int res[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, p, q;
    
    // Read dimensions of the matrices
    cin >> n >> m;
    cin >> p >> q;

    // Check if multiplication is possible
    if (!isCompatible(n, m, p, q)) {
        cout << "Matrices are not compatible for multiplication!" << endl;
        return 1;
    }

    // Declare matrices
    int a[100][100], b[100][100];

    // Read the elements of the first matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Read the elements of the second matrix
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }

    // Resultant matrix
    int res[100][100];
    
    // Perform matrix multiplication
    mul(n, m, p, q, a, b, res);
    
    // Print the result
    printMatrix(n, q, res);

    return 0;
}
