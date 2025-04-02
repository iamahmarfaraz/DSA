#include <iostream>
using namespace std;

// OLD METHOD TO FIND MAX
// int maxofThree(int a, int b, int c)
// {
//     if (a > b && a > c)
//     {
//         return a;
//     }
//     if (b > a && b > c)
//     {
//         return b;
//     }
//     else
//     {
//         return c;
//     }
// }

int maxofThree(int num1, int num2, int num3)
{
    int max1 = max(num1, num2);
    int max2 = max(max1, num3);
    // OR
    // int max2=max(a,max(b,c));
    return max2;
}
void counting(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << endl;
    }
}
void check_prime_number(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << n << " ISN'T A PRIME NUMBER"<<endl;
        }
        else
        {
            cout << n << " IS A PRIME NUMBER"<<endl;
        }
    }
}

void check_evenodd(int n)
{
    if (n % 2 == 0)
    {
        cout << "GIVEN NUMBER IS EVEN NUMBER" << endl;
    }
    else
    {
        cout << "GIVEN NUMBER IS ODD NUMBER" << endl;
    }
}
int sumofallnumber(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i + 1;
    }
    return sum;
}
int sumofallevennumber(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i + 1;
        }
    }
    return sum;
}

int main()
{
    cout << "ENTER THREE NUMBER TO FIND THE MAX:- ";
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    cout << "MAX OF THREE NUMBER = " << maxofThree(num1, num2, num3) << endl;
    cout << "ENTER THE NUMBER UPTO WHICH YOU WANT THE COUNTING :- ";
    int num4;
    cin >> num4;
    counting(num4);
    cout << "ChECK WHETHER THE NUMBER IS PRIME OR NOT " << endl;
    int num5;
    cin >> num5;
    check_prime_number(num5);
    cout << "ChECK WHETHER THE NUMBER IS EVEN OR ODD " << endl;
    int num6;
    cin >> num6;
    check_evenodd(num6);
    cout << "ENTER THE VALUE OF N:- " << endl;
    int num7;
    cin >> num7;
    cout << "THE SUM OF ALL THE NUMBER FROM 1 TO N IS: " << sumofallnumber(num7) << endl;
    cout << "ENTER THE VALUE OF N:- " << endl;
    int num8;
    cin >> num8;
}