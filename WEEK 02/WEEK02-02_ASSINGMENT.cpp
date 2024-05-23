#include <iostream>
using namespace std;
void numericHollowHalfPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i || i == num - 1)
            {
                cout << j + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void numericHollowInvertedHalfPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            if (i == 0)
            {
                cout << j + 1 << " ";
            }
            else if (j == 0)
            {
                cout << i + 1 << " ";
            }
            else if (j == num - i - 1)
            {
                cout << num << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void numericPalindromeEquilateralPyramid(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void solidHalfDiamond(int num)
{
    int n1 = num / 2;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    int n2 = n1 - 1;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2 - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void fancypattern1(int num)
{
    for (int i = 0; i < num; i++)
    {
        // FIG.1
        for (int j = 0; j < (2 * num) - 2 - i; j++)
        {
            cout << "* ";
        }
        // FIG.2
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (j % 2 == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << i + 1 << " ";
            }
        }
        // FIG.3
        for (int j = 0; j < (2 * num) - 2 - i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}
void fancypattern2(int num)
{
    int k = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (j % 2 == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << k << " ";
                k++;
            }
        }
        cout << endl;
    }
    int p = k - num;
    for (int i = 0; i < num; i++)
    {
        int k = p;
        for (int j = 0; j < (2 * num) - (2 * i) - 1; j++)
        {
            if (j % 2 == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << k << " ";
                k++;
            }
        }
        p = p - (num - 1) + i;
        cout << endl;
    }
}
void fancypattern3(int num)
{
    for (int i = 0; i < num; i++)
    {
        int k = 0;
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            if (j == 0 || j == (2 * i))
            {
                cout << "* ";
            }
            else if (j <= i)
            {
                cout << k + 1 << " ";
                k++;
            }
            else
            {
                --k;
                cout << k << " ";
            }
        }
        cout << endl;
    }
    int num1 = num - 1;
    for (int i = 0; i < num1; i++)
    {
        int k = 0;
        for (int j = 0; j < ((2 * num1) - (2 * i) - 1); j++)
        {
            if (j == 0 || j == ((2 * num1) - (2 * i) - 2))
            {
                cout << "* ";
            }
            else if (j <= num1)
            {
                cout << k + 1 << " ";
                k++;
            }
            else
            {
                --k;
                cout << k << " ";
            }
        }
        cout << endl;
    }
}
void floyd_triangle(int n)
{
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
}
void pascalsTriangle(int num)
{
    for (int i = 1; i <= num; i++)
    {
        int c = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
            c = c * (i - j) / j;
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cout << "ENTER A NUMBER : " << endl;
    cin >> num;
    // numericHollowHalfPyramid(num);
    // numericHollowInvertedHalfPyramid(num);
    // numericPalindromeEquilateralPyramid(num);
    // solidHalfDiamond(num);
    // fancypattern1(num);
    // fancypattern2(num);
    // fancypattern3(num);
    // floyd_triangle(num);
    pascalsTriangle(num);

    return 0;
}