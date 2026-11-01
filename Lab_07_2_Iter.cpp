// Lab_07_2_1.cpp
// Варіант 29
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним способом.
// Пошук мінімального елемента побічної діагоналі матриці (n x n).
//5 -10 10

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int MinSecondaryDiagonal(int** a, const int n);

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    int Low, High;
    cout << "Low = ";
    cin >> Low;
    cout << "High = ";
    cin >> High;

    // Створення динамічної квадратної матриці (n x n)
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // 1. Формування та виведення початкової матриці
    Create(a, n, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, n);

    // 2. Пошук мінімального елемента побічної діагоналі
    int minDiag = MinSecondaryDiagonal(a, n);
    cout << "Min element on secondary diagonal = " << minDiag << endl;

    // Звільнення пам'яті
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

// Формування матриці за допомогою генератора випадкових чисел
void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Форматне виведення матриці на екран
void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функція пошуку мінімального елемента побічної діагоналі
int MinSecondaryDiagonal(int** a, const int n) {
    // Елемент побічної діагоналі для i-го рядка знаходиться в стовпчику j = n - 1 - i
    int minVal = a[0][n - 1];

    for (int i = 1; i < n; i++) {
        int j = n - 1 - i;
        if (a[i][j] < minVal) {
            minVal = a[i][j];
        }
    }

    return minVal;
}