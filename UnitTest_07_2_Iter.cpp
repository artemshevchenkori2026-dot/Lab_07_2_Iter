#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_Iter/Lab_07_2_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0721
{
    TEST_CLASS(UnitTestLab0721)
    {
    public:
        TEST_METHOD(TestMethodMinSecondaryDiagonal)
        {
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Матриця 3x3:
            //  1   2   [9]  -> елемент побічної діагоналі (i=0, j=2): 9
            //  4  [3]   6   -> елемент побічної діагоналі (i=1, j=1): 3
            // [-5] 8    7   -> елемент побічної діагоналі (i=2, j=0): -5
            a[0][0] = 1;  a[0][1] = 2;  a[0][2] = 9;
            a[1][0] = 4;  a[1][1] = 3;  a[1][2] = 6;
            a[2][0] = -5; a[2][1] = 8;  a[2][2] = 7;

            int minDiag = MinSecondaryDiagonal(a, n);

            Assert::AreEqual(-5, minDiag); // Мінімальний серед {9, 3, -5} є -5

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}