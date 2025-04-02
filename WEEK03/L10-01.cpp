#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void seperateNegPos(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortcolor(int arr[], int size)
{
    int left = 0;
    int right = (size - 1);
    for (int i = 0; i <= right;)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[left]);
            left++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[right]);
            right--;
        }
        else
        {
            i++;
        }
    }
}
void shiftarraybyK(int arr[], int size, int k)
{
    int temp[k];
    int tempcount = 0;
    for (int i = size - k; i < size; i++)
    {
        temp[tempcount] = arr[i];
        tempcount++;
    }
    for (int i = (size - k - 1); i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < size - (size - k); i++)
    {
        arr[i] = temp[i];
    }
}

int missingnumInarray(int arr[], int n, int size)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == arr[j])
            {
                return true;
            }
        }
        return i;
    }
}
int missingnumInarray2(int arr[], int n, int size)
{
    int sum1 = 0;
    for (int i = 0; i <= n; i++)
    {
        sum1 += i;
    }
    int sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        sum2 += arr[i];
    }
    int total = sum1 - sum2;
    return total;
}
void rearranging(int arr[], int size)
{
    int left = 0;
    int right = (size - 1);
    for (int i = 0; left < size; i++)
    {
        if (arr[i] >= 0)
        {
            swap(arr[left], arr[i]);
            left = left + 2;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[right], arr[i]);
            right = right - 2;
        }
    }
    return;
}
void print2d(int arr[][4], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
vector<int> maxOneRow(int arr[][4], int size)
{
    vector<int> ans;
    int max = INT_MIN;
    int one;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < sizeof(arr[i]); j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            one = i;
        }
    }
    ans.push_back(max);
    ans.push_back(one);
    return ans;
}

void rotateImage(int arr[][4], int size)
{
    int temp[4][4];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0, k = (size - 1); j < size, k >= 0; j++, k--)
        {
            temp[i][j]=arr[k][i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j]=temp[i][j];
        }
        
    }
    
    
}

int main()
{
    // int arr[]={23,-7,40,11,-8,23,-7};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // print(arr,size);
    // seperateNegPos(arr,size);
    // print(arr,size);

    // int brr[] = {0, 1, 0, 2, 1, 0, 1, 2};
    // int size1 = sizeof(brr) / sizeof(brr[0]);
    // sortcolor(brr, size1);
    // print(brr, size1);

    // int n = 8;
    // int crr[] = {0, 7, 3, 2, 5, 6, 8, 4};
    // int size2 = sizeof(crr) / sizeof(crr[0]);
    // int miss = missingnumInarray2(crr, n, size2);
    // // int missing = missingnumInarray(crr, n, size2);
    // cout << "The missing number is : " << miss << endl;

    // int drr[] = {3, 1, -2, -5, 2, -4};
    // int size3 = sizeof(drr) / sizeof(drr[0]);
    // print(drr,size3);
    // rearranging(drr,size3);
    // cout<<"After re-arranging array in +ve and -ve value alternatively "<<endl;
    // print(drr,size3);

    // int err[][4] = {
    //     {1, 0, 0, 0},
    //     {0, 1, 1, 0},
    //     {0, 1, 1, 0},
    //     {1, 1, 1, 0},
    //     {0, 0, 1, 0}};
    // int size4 = sizeof(err) / sizeof(err[0]);
    // int max = maxOneRow(err, size4);
    // cout << "The row with maximum no. of 1's is : " << max;

    int frr[][4] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int size5 = sizeof(frr) / sizeof(frr[0]);
    print2d(frr, size5);
    rotateImage(frr, size5);
    cout << "After rotating 90 degree : \n";
    print2d(frr, size5);

    return 0;
}