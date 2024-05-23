#include <iostream>
using namespace std;

// RECURSION

int factorial(int n)
{
    // Base Case
    if (n == 1)
    {
        return 1;
    }

    // Recursion

    int ans = n * factorial(n - 1);

    return ans;
}

void printCounting(int n)
{
    if (n == 0)
    {
        return;
    }

    // Processing
    cout << n << " ";

    // Recursion
    printCounting(n - 1);
}

int powerOfTwo(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = 2 * powerOfTwo(n - 1);
    return ans;
}

int fib(int n)
{
    // Base case
    if (n == 1)
    {
        return 1;
        
    }
    if (n==0)
    {
        return 0;
        
    }

    int ans=fib(n-1) + fib(n-2);
    return ans;
}

int sumUptoN(int n){
    //Base Case
    if (n==1)
    {
        return 1;
    }
    int ans=n+sumUptoN(n-1);
    return ans;
    
}

int main()
{
    cout << "Factorial using Recursion : " << factorial(5) << endl;

    printCounting(5);
    cout << endl;

    cout << powerOfTwo(5) << endl;

    // cout<<fib(7)<<endl;
    fib(7);

    cout<<"Sum Upto N : "<<sumUptoN(5);



    return 0;
}