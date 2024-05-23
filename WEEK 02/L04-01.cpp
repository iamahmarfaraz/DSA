#include <iostream>
using namespace std;

void hollow_full_pyramid(int n)
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
            // print stars for first and last column
            if (j == 0 || j == i + 1 - 1)
            {
                cout << "* ";
            }
            // print space in between them
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void inverted_hollow_full_pyramid(int n)
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
            if (j == 0 || j == n - i - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void flipped_diamond(int n)
{
    int n1 = n / 2;
    for (int i = 0; i < n1; i++)
    {
        // INVERTED HALF PYRAMID 1
        for (int j = 0; j < n1 - i; j++)
        {
            cout << "* ";
        }
        // FULL PYRAMID
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            cout << "  ";
        }
        // INVERTED HALF PYRAMID 2
        for (int j = 0; j < n1 - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n1; i++)
    {
        // HALF PYRAMID 1
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        // FULL PYRAMID
        for (int j = 0; j < (2 * n1) - (2 * i) - 1; j++)
        {
            cout << "  ";
        }
        // HALF PYRAMID 2
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void fancy_pattern1(int n)
{
    int k = 1;
    for (int i = 0; i < n; i++)
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
            }
        }
        k++;
        cout << endl;
    }
}
void inverted_fancy_pattern1(int n)
{
    int k = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 * n) - (2 * i) - 1; j++)
        {
            if (j % 2 == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << k << " ";
            }
        }
        k--;
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        // SPACES
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        // STARS
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }

        for (int j = i + 1; j > 0; j--)
        {
            if (i == 0)
            {
                cout << " ";
            }
            else
            {

                cout << j << " ";
            }
        }
        cout << endl;
    }
}
void inverted_hollow_half_pyramid(int n)
{
    // * * * *
    // *   *
    // * *
    // *
    for (int i = 0; i < n; i++)
    {

        // stars
        for (int j = 0; j < n - i; j++)
        {
            if (j == 0 || j == n - i - 1 || i == 0)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (i == 0 || i == n - 1 || j == 0)
            {
                cout << j + 1 << " ";
                if (j == n - 1)
                {
                    break;
                }
            }
            else
            {
                if (j == 2 * i + 1 - 1)
                {
                    cout << i + 1;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch << " ";
            ch++;
        }
        ch = ch - 2;
        for (int j = ch; j >= 'A'; j--)
        {

            if (i == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << ch << " ";
                ch--;
            }
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        // STARS
        for (int j = 0; j < n + 3 - i; j++)
        {
            cout << "* ";
        }
        // NUMBER
        for (int j = 0; j < 2 * i + 1; j++)
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
        for (int j = 0; j < n + 3 - i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}
void solid_half_diamond1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void solid_half_diamond2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "* ";
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
void butterfly_pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < (2 * n) - (2 * i) - 2; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < (2 * i); j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}
void full_pyramid2(int n)
{
    int lastrowstars;
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
            if (i == n - 1)
            {
                lastrowstars = i + 1;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < lastrowstars; i++)
    {
        cout << "* ";
    }
}
void new_fancy_pattern(int n){
    int k=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2*i)+1; j++)
        {
            
            if (j%2==1)
            {
                cout<<"* ";
            }
            else{
                cout<<k<<" ";
                k++;
            }
        }
        cout<<endl;
    }
    
}

int main()
{
    int num;
    cout << "Enter the number= ";
    cin >> num;
    cout << "HOLLOW FULL PYRAMID" << endl;
    hollow_full_pyramid(num);
    cout << "INVERTED HOLLOW FULL PYRAMID" << endl;
    inverted_hollow_full_pyramid(num);
    cout << "FLIPPED DIAMOND" << endl;
    flipped_diamond(num);
    cout << "FANCY PATTERN 1" << endl;
    fancy_pattern1(num);
    cout << "INVERTED FANCY PATTERN 1" << endl;
    inverted_fancy_pattern1(num);
    cout << "PATTERN2" << endl;
    pattern2(num);
    cout << "INVERTED HOLLOW HALF PYRAMID" << endl;
    inverted_hollow_half_pyramid(num);
    cout << "PATTERN3" << endl;
    pattern3(num);
    cout << "PATTERN4" << endl;
    pattern4(num);
    cout << "PATTERN5" << endl;
    pattern5(num);
    cout << "SOLID HALF DIAMOND 1" << endl;
    solid_half_diamond1(num);
    cout << "SOLID HALF DIAMOND 2 " << endl;
    solid_half_diamond2(num);
    cout << "FLOY'D TRIANGLE" << endl;
    floyd_triangle(num);
    cout << "BUTTERFLY PATTERN" << endl;
    butterfly_pattern(num);
    cout << "FULL PYRAMID 2" << endl;
    full_pyramid2(num);
    cout << "NEW FANCY PATTERN " << endl;
    new_fancy_pattern(num);
}