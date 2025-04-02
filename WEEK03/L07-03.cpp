#include <iostream>
#include <limits.h>
using namespace std;

void counter(int arr[], int size)
{
    int zerocounter = 0;
    int onecounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zerocounter++;
        }
        else
        {
            onecounter++;
        }
    }
    cout << "Number of zeros in the array = " << zerocounter << endl;
    cout << "Number of one's in the array = " << onecounter << endl;
}
int minArray(int arr[], int size)
{
    int minAns = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minAns)
        {
            minAns = arr[i];
        }
    }
    return minAns;
}
void reversearray(int arr[], int size)
{
    int num;
    for (int i = 0; i <= ((size - 1) / 2); i++)
    {
        num = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = num;
    }
}
void extremeprint(int arr[],int size)
{
    for (int i = 0,j = size - 1; i <= j; i++, j--)
    {
        if (i == j)
        {
            cout << arr[i] << " ";
        }
        else
        {
            cout << arr[i] << " " << arr[j] << " ";
        }
    }
    cout<<endl;
}
void maximum_no_inarray(int arr[],int size){
    int max=INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    cout<<"Max number present in array is "<<max;
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
int main()
{
    int size = 8;
    int arr[8] = {0, 1, 1, 1, 0, 0, 1, 1};
    int brr[8] = {12, 56, 34, 90, 2, 56, 89, 45};
    counter(arr, size);
    cout << "The minimum value present in the array is = " << minArray(brr, size) << endl;
    reversearray(brr, size);
    printarray(brr, size);
    extremeprint(brr,size);
    maximum_no_inarray(brr,size);
    return 0;
}