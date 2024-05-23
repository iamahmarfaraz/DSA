#include <iostream>
using namespace std;
void createarray(int a[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the value at index " << i << " = ";
        cin >> a[i];
    }
}
void printarray(int arr[], int num1)
{
    cout << "The array is: ";
    for (int i = 0; i < num1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void double_thearray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 2 * arr[i];
    }
}
void sumarray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "The sum of all the values of array is: " << sum << endl;
}

int linearsearch(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return 2;
}
int main()
{
    int n = 10;
    int arr[n];
    createarray(arr, n);
    printarray(arr, n);
    sumarray(arr, n);
    cout << "Enter the you're searching in the array: ";
    int desirednum;
    cin >> desirednum;
    if (linearsearch(arr, n, desirednum) != 2)
    {
        cout << "The number is present in array at " << linearsearch(arr, n, desirednum) << " index" << endl;
    }
    else
    {
        cout << "The number isn't present in array" << endl;
    }
    double_thearray(arr, n);
    printarray(arr, n);

    return 0;
}