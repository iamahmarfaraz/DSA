#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;

    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from original array to left array
    int k = s;
    // k -> starting index of left array values in original arrya
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values from original array to right array
    k = mid + 1;
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left array is already sorted
    // right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    // yahi pr galti karte h log
    int mainArrayIndex = s;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {

        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // 2 more cases

    // 1 case -> left array exhaust but right array me element abhi bhi bache hai
    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // 2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // 1 more step pending
    delete[] left;
    delete[] right;
}

void mergesort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // break
    int mid = (s + e) / 2;
    // recusive call for left array
    mergesort(arr, s, mid);
    // recusive call for right array
    mergesort(arr, mid + 1, e);
    // merge 2 sorted arrays
    merge(arr, s, e);
}

void mergeIn(int arr[], int s, int e)
{
    int mid = (s + e) / 2;

    // actual merge logic here
    // left array is already sorted
    // right array is already sorted
    int leftIndex = 0;
    int rightIndex = mid + 1;
    ;
    // yahi pr galti karte h log
    int mainArrayIndex = s;

    while (leftIndex <= mid && rightIndex <= e)
    {

        if (arr[leftIndex] < arr[rightIndex])
        {
            arr[mainArrayIndex] = arr[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = arr[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // 2 more cases

    // 1 case -> left array exhaust but right array me element abhi bhi bache hai
    while (rightIndex <= e)
    {
        arr[mainArrayIndex] = arr[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // 2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
    while (leftIndex <= mid)
    {
        arr[mainArrayIndex] = arr[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
}

void mergesortINplace(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // break
    int mid = (s + e) / 2;
    // recusive call for left array
    mergesort(arr, s, mid);
    // recusive call for right array
    mergesort(arr, mid + 1, e);
    // merge 2 sorted arrays
    mergeIn(arr, s, e);
}

int main()
{
    int arr[] = {2, 1, 6, 9, 4, 5};
    int size = 6;
    int s = 0;
    int e = size - 1;

    // cout << "Before merge sort: " << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // mergesort(arr, s, e);

    // cout << "After merge sort: " << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    cout << "Before merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesortINplace(arr, s, e);

    cout << "After merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}