#include <iostream>
using namespace std;
// PATTERN PRINTING
void square_print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void rectangle_print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void hollow_rectangle_print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == n - 1 || i == 0 || j == 0 || j == n + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void half_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void inverted_half_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void numeric_half_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i + 1)
            {
                cout << j + 1;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void inverted_numeric_half_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
            {
                cout << j + 1;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void inverted_full_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void full_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void solid_diamond_pattern(int num)
{
    int n = num / 2;
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the number= ";
    cin >> num;
    cout << "SQUARE" << endl;
    square_print(num);
    cout << "RECTANGLE" << endl;
    rectangle_print(num);

    cout << "HOLLOW RECTANGLE" << endl;
    hollow_rectangle_print(num);
    cout << "HALF PYRAMID" << endl;
    half_pyramid(num);
    cout << "INVERTED HALF PYRAMID" << endl;
    inverted_half_pyramid(num);
    cout << "NUMERIC HALF PYRAMID" << endl;
    numeric_half_pyramid(num);
    cout << "INVERTED NUMERIC HALF PYRAMID" << endl;
    inverted_numeric_half_pyramid(num);
    cout << "INVERTED FUL PYRAMID" << endl;
    inverted_full_pyramid(num);
    cout << "FULL PYRAMID" << endl;
    full_pyramid(num);
    cout << "SOLID DIAMOND PATTERN" << endl;
    solid_diamond_pattern(num);
}