#include <iostream>
using namespace std;

void displayMatrix(const int mat[4][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumMatrix(const int mat[4][4], int rows, int cols) {
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            total += mat[i][j];
        }
    }
    return total;
}

double averageMatrix(const int mat[4][4], int rows, int cols) {
    return (double)sumMatrix(mat, rows, cols) / (rows * cols);
}

int findMaximum(const int mat[4][4], int rows, int cols) {
    int maxVal = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > maxVal) {
                maxVal = mat[i][j];
            }
        }
    }
    return maxVal;
}

int findMinimum(const int mat[4][4], int rows, int cols) {
    int minVal = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] < minVal) {
                minVal = mat[i][j];
            }
        }
    }
    return minVal;
}

int countAboveThreshold(const int mat[4][4], int rows, int cols, int threshold) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > threshold) {
                count++;
            }
        }
    }
    return count;
}

void addMatrices(const int a[3][3], const int b[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(const int a[3][3], const int b[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

bool multiplyMatrices(const int a[4][4], int rowsA, int colsA, const int b[4][4], int rowsB, int colsB, int result[4][4]) {
    if (colsA != rowsB) {
        cout << "Matrix multiplication cannot be performed." << endl;
        return false;
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return true;
}

int main() {
    int imageGrid[4][4] = {
        { 45, 120, 200,  85},
        { 10, 255, 130,  95},
        {180,  60, 150, 210},
        {  5, 140,  75, 190}
    };

    cout << "=== Part C: Image Grid Processor ===" << endl;
    displayMatrix(imageGrid, 4, 4);
    cout << "Total Brightness: " << sumMatrix(imageGrid, 4, 4) << endl;
    cout << "Average Brightness: " << averageMatrix(imageGrid, 4, 4) << endl;
    cout << "Maximum Brightness: " << findMaximum(imageGrid, 4, 4) << endl;
    cout << "Minimum Brightness: " << findMinimum(imageGrid, 4, 4) << endl;
    cout << "Pixels above threshold 128: " << countAboveThreshold(imageGrid, 4, 4, 128) << endl << endl;

    int A3x3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B3x3[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int sumRes[3][3], diffRes[3][3];

    addMatrices(A3x3, B3x3, sumRes, 3, 3);
    subtractMatrices(A3x3, B3x3, diffRes, 3, 3);

    cout << "=== Part D: Addition (3x3) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << sumRes[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    cout << "=== Part E: Subtraction (3x3) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << diffRes[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    int multA[4][4] = {{1, 2, 0, 0}, {3, 4, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int multB[4][4] = {{5, 6, 0, 0}, {7, 8, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int prodRes[4][4];

    cout << "=== Part F & G: Multiplication & Validation ===" << endl;
    cout << "1. Compatible Test (2x2 * 2x2):" << endl;
    if (multiplyMatrices(multA, 2, 2, multB, 2, 2, prodRes)) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << prodRes[i][j] << "\t";
            cout << endl;
        }
    }

    cout << endl << "2. Incompatible Test (2x3 * 2x2):" << endl;
    multiplyMatrices(multA, 2, 3, multB, 2, 2, prodRes);

    return 0;
}
