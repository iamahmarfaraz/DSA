#include <iostream>
using namespace std;
// Array is passed by refrence in function
void refarray(int arr[])
{
    arr[0] = 100;
}
int unique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
void pairprint(int arr[], int b)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << arr[i] << "," << arr[j] << "  ";
        }
        cout << endl;
    }
}
void sortzeroOne(int arr[], int size)
{
    int zercount = 0;
    int onecount = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zercount++;
        }
        else
        {
            onecount++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i < zercount)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
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
void shiftarraybyone(int arr[], int size)
{
    int temp = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}
void shiftarraybyK(int arr[], int size, int k)
{
    int temp[k];
    int tempcount=0;
    for (int i = size-k; i < size; i++)
    {
        temp[tempcount]=arr[i];
        tempcount++;
    }
    for (int i = (size-k-1); i >= 0; i--)
    {
        arr[i+k]=arr[i];
    }
    for (int i = 0; i < size-(size-k); i++)
    {
        arr[i]=temp[i];
    }   
}

// void dutchNationalflag(int arr[],int size){
//     // sort 0,1,2 in order

// }
void sortZerOne2pointer(int arr[],int size){
    // 2 POINTER APPROACH
    for (int i = 0,j=size-1; i < j;)
    {
        if (arr[i]==0)
        {
            i++;
        }
        else if (arr[j]==1)
        {
            j--;
        }
        else if (arr[i]==1 && arr[j]==0)
        {
            swap(arr[i],arr[j]);
        }
        
        
    }
    
}
int main()
{
    // int arr[] = {1, 2, 4};
    // int size = 3;
    // refarray(arr);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << endl;
    // int brr[] = {2, 10, 11, 13, 10, 2, 15, 13, 15};
    // int size1 = 9;
    // int finalans = unique(brr, size1);
    // cout << "UNIQUE NUMBER IN ARRAY IS:" << finalans << endl;

    // int crr[] = {10, 20, 30};
    // int size2 = 3;
    // pairprint(crr, size2);

    // int drr[] = {0, 1, 0, 1, 1, 0, 0, 0, 0};
    // int size3 = sizeof(drr) / sizeof(drr[0]);
    // sortzeroOne(drr, size3);
    // printarray(drr, size3);

    // int err[] = {10, 20, 30, 40, 50, 60};
    // int size4 = sizeof(err) / sizeof(err[0]);
    // shiftarraybyone(err, size4);
    // printarray(err, size4);

    // int frr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    // int size5 = sizeof(frr) / sizeof(frr[0]);
    // int k=4;
    // shiftarraybyK(frr,size5,k);
    // printarray(frr,size5);

    // int grr[]={0,1,0,2,0,0,1,2,2,1};

    int hrr[]={0,1,0,0,1,1,0,0,0};
    int size6 = sizeof(hrr) / sizeof(hrr[0]);
    sortZerOne2pointer(hrr,size6);
    printarray(hrr,size6);

    return 0;
}