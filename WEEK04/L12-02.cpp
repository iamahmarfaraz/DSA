#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 10; //how many digit we need after decimal
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}
int divide(int dividend, int divisor)
{
    int s = 0, e = dividend;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;
        // check if mid is the answer, treat mid as Quotient
        // Quotient * Divisor + Reminder = Dividend,
        // Predicate: Quotient * Divisor <= Dividend
        if (mid * divisor <= dividend)
        {
            ans = mid;
            // go right for more precise answer
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

double myPrecisionDivide(int dividend, int divisor)
{
    double quotient = divide(dividend, divisor);
    int precision = 5;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = quotient;
        while (j * divisor <= dividend)
        {
            quotient = j;
            j += step;
        }
        step /= 10;
    }
    return quotient;
}

int main()
{
    int n = 63;
    // cout << mySqrt(n) << endl;
    cout << myPrecisionSqrt(n) << endl;

    int dividend = 29;
    int divisor = 7;
    cout << myPrecisionDivide(dividend, divisor) << endl;
    return 0;
}
