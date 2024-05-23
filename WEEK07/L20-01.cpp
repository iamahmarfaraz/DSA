#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size)
{
    // Base Case
    if (size == 0)
    {
        return;
    }
    cout << *arr << " ";
    // Recursion
    printArray(arr + 1, size - 1);
}

bool searchArray(int arr[], int size, int target)
{
    // Base Case
    if (size == 0)
    {
        return false;
    }
    if (*arr == target)
    {
        return true;
    }

    // Recursion
    bool ans = searchArray(arr + 1, size - 1, target);
    return ans;
}

int findMin(int arr[], int size, int index, int &mini)
{
    if (index >= size)
    {
        return mini;
    }
    if (arr[index] < mini)
    {
        mini = arr[index];
    }
    findMin(arr, size, index + 1, mini);
}

void solvefun(int arr[], int size, int index, vector<int> &ans)
{
    // Base Case
    if (index >= size)
    {
        return;
    }
    // Processing
    if ((arr[index] % 2) == 0)
    {
        ans.push_back(arr[index]);
    }
    // Recursion
    solvefun(arr, size, index + 1, ans);
}

void doubletheArray(int arr[], int size)
{
    // Base Case
    if (size == 0)
    {
        return;
    }
    // Processing
    *arr = 2 * (*arr);

    // Recursion
    doubletheArray(arr + 1, size - 1);
}

int findMax(int arr[], int size, int index, int &maxi)
{
    if (index >= size)
    {
        return maxi;
    }
    if (arr[index] > maxi)
    {
        maxi = arr[index];
    }
    findMax(arr, size, index + 1, maxi);
}

int searchArrayIndex(int arr[], int size, int index, int target)
{
    // Base Case
    if (index >= size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }

    // Recursion
    int ans = searchArrayIndex(arr, size, index + 1, target);
    return ans;
}

vector<int> printOccurence(int arr[], int size, int target, int index)
{
    vector<int> indexStore;
    // Base Case
    if (index >= size)
    {
        return indexStore;
    }
    if (arr[index] == target)
    {
        indexStore.push_back(index);
    }
    vector<int> finaAns = printOccurence(arr, size, target, index + 1);

    // Merge indexStore with finaAns
    finaAns.insert(finaAns.end(), indexStore.begin(), indexStore.end());

    return finaAns;
}

vector<int> digitStore(int num, vector<int> &ans)
{
    // Base Case
    if (num < 1)
    {
        return ans;
    }
    ans.push_back(num % 10);
    num /= 10;
    digitStore(num,ans);
    return ans;
}

void vectorStore(vector<int> &arr,int index,int &num,int i){
    // Base Case
    if (index<0)
    {
        return;
    }
    //Processing
    num=num + (i*arr[index]);

    // Recursion
    vectorStore(arr,index-1,num,i*10);
    return;
}

int main()
{
    // int arr[] = {10, 20, 30, 40, 50};
    // int size = 5;
    // printArray(arr, size);
    // cout << "ELEMENT PRESENT OR NOT : " << searchArray(arr, size, 60) << endl;

    // int min = INT_MAX;
    // cout << "Minimum number : " << findMin(arr, size, 0, min) << endl;

    // vector<int> brr;
    // solvefun(arr, size, 0, brr);
    // for (int num = 0; num < brr.size(); num++)
    // {
    //     cout << brr[num] << " ";
    // }
    // cout << endl;

    // int maxi = INT_MIN;
    // cout << "Maximum number : " << findMax(arr, size, 0, maxi) << endl;

    // cout << "ELEMENT PRESENT OR NOT : " << searchArrayIndex(arr, size, 0, 30) << endl;

    // int crr[] = {1, 2, 3, 4, 5};
    // int size1 = 5;
    // doubletheArray(crr, size1);
    // for (int i = 0; i < size1; i++)
    // {
    //     cout << crr[i] << " ";
    // }
    // cout << endl;

    // int drr[] = {2, 4, 6, 12, 98, 32, 2, 45, 78, 2, 1, 9, 56, 2, 45, 78, 2};
    // int size2 = sizeof(drr) / sizeof(drr[0]);
    // vector<int> totalOcc = printOccurence(drr, size2, 2, 0);
    // for (int i = 0; i < totalOcc.size(); i++)
    // {
    //     cout << totalOcc[i] << " ";
    // }
    // cout << endl;

    // int num = 4215;
    // vector<int> digitSt;
    // digitStore(num,digitSt);
    // reverse(digitSt.begin(), digitSt.end());
    // for (int i = 0; i < digitSt.size(); i++)
    // {
    //     cout << digitSt[i] << " ";
    // }
    // cout << endl;

    vector<int> arr={4,2,1,7};
    int index=(arr.size() - 1);
    int num=0;
    int i=1;
    vectorStore(arr,index,num,i);
    cout<<num<<endl;

    return 0;
}