#include <iostream>
#include <limits.h>
using namespace std;
int findmax(int arr[][3], int row, int col)
{
    int max = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}
void sumarrayrow(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        cout << "The sum of row " << i << " is : " << sum << endl;
    }
}
void sumarraycolomn(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }
        cout << "The sum of column " << i << " is : " << sum << endl;
    }
}
void diagonalsum(int arr[][3], int size)
{
    int sum = 0;
    for (int i = size - 1, j = 0; i >= 0, j < size; i--, j++)
    {
        sum += arr[i][j];
    }
    cout << "The sum of diagonal of the array is : " << sum;
}
void transpose(int arr[][3],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
        
    }
    
}
void print(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int n = 3;
    // print(arr,n);
    // cout<<"Max number present in array is: "<<findmax(arr,n,n);
    // sumarrayrow(arr,n);
    // sumarraycolomn(arr, n);
    // diagonalsum(arr, n);
    transpose(arr,n);
    print(arr,n);

    return 0;
}