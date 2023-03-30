#include <iostream>
#include <iomanip>
using namespace std;

void transpose(int n, int m)
{
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    int count = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            matrix[i][j] = count;
            count++;
        }

    cout << "Начальная матрица:";
    cout << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(4) << matrix[i][j];
        cout << '\n';
    }

    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    cout << "Транспонированная матрица:";
    cout << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(4) << matrix[i][j];
        cout << '\n';
    }
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}


int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Введите размерности матрицы";
    int n, m;
    cin >> n >> m;

    transpose(n, m);

    return 0;
}