#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

const int N = 4;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    double matrix[N][N];
    
    int upperSize = (N * (N + 1)) / 2;
    int lowerSize = (N * (N - 1)) / 2;

    double upperTriangle[upperSize];
    double lowerTriangle[lowerSize];

    cout << "Вихідна матриця " << N << "x" << N << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = (double)(rand() % 201 - 100) / 10.0;
            cout << setw(6) << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }

    int uIndex = 0;
    int lIndex = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) {
                upperTriangle[uIndex++] = matrix[i][j];
            }
            else {
                lowerTriangle[lIndex++] = matrix[i][j];
            }
        }
    }

    cout << "\nВерхній трикутник (включаючи головну діагональ):" << endl;
    for (int i = 0; i < upperSize; i++) {
        cout << setw(6) << setprecision(2) << upperTriangle[i];
    }
    cout << endl;

    cout << "\nНижній трикутник (без головної діагоналі):" << endl;
    for (int i = 0; i < lowerSize; i++) {
        cout << setw(6) << setprecision(2) << lowerTriangle[i];
    }
    cout << endl;

    system("pause");
    return 0;
}