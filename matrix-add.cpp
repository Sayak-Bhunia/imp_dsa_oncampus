#include <iostream>
using namespace std;

bool areCompatible(int r1, int c1, int r2, int c2) {
    return (r1 == r2 && c1 == c2);
}

void printMatrix(int rows, int cols, int matrix[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sumMatrices(int rows, int cols, int a[][100], int b[][100], int res[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void inputMatrix(int rows, int cols, int matrix[][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> r2 >> c2;

    if (!areCompatible(r1, c1, r2, c2)) {
        cout << "Matrices are not compatible for addition." << endl;
        return 1;
    }

    int a[100][100];
    cout << "Enter elements of the first matrix:" << endl;
    inputMatrix(r1, c1, a);

    int b[100][100];
    cout << "Enter elements of the second matrix:" << endl;
    inputMatrix(r2, c2, b);

    int res[100][100];
    sumMatrices(r1, c1, a, b, res);

    cout << "Resultant matrix after addition:" << endl;
    printMatrix(r1, c1, res);

    return 0;
}
