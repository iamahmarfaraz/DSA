#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int> &arr, int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    int pivot = end;
    int j = start;
    int i = start - 1;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[j]);

    // Left part array(left of pivot) Recursion
    quickSort(arr, start, i - 1);
    // Right part array(Right of pivot) Recursion
    quickSort(arr, i + 1, end);
}


int main()
{
    vector<int> arr = {7, 2, 1, 8, 6, 3, 5, 4};
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    // Before Quick Sort
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    // After Quick Sort
    quickSort(arr, start, end);
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return 0;
}