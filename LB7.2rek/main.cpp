#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, K, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, K, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, const int K, int rowNo)
{
    PrintRow(a, rowNo, K, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, K, rowNo + 1);
    else
        cout << endl;
}

void findMaxInColumn(int** a, const int rowCount, int j, int i, int& max)
{
    if (i >= rowCount)
    {
        return;
    }

    if (a[i][j] > max)
    {
        max = a[i][j];
    }

    findMaxInColumn(a, rowCount, j, i + 1, max);
}

void findSumOfMaxInOddColumns(int** a, const int rowCount, const int colCount, int j = 1, int sum = 0)
{
    if (j >= colCount)
    {
        cout << "—ума максимальних елемент≥в по непарних стовпц€х: " << sum << endl;
        return;
    }

    int max = a[0][j];
    findMaxInColumn(a, rowCount, j, 0, max);

    sum += max;

    findSumOfMaxInOddColumns(a, rowCount, colCount, j + 2, sum);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -34;
    int High = 26;
    int rowCount;
    int colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, colCount, rowCount, 0);

    findSumOfMaxInOddColumns(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
