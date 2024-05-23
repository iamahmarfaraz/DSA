#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    // divide
    mergeSort(v, temp, start, mid);
    mergeSort(v, temp, mid + 1, end);

    // conqour
    int i = start, j = mid + 1;
    // first array = start -> mid
    // second array = mid + 1 -> end
    // merged array => start -> end
    int k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    // handle remaining elements in case of diff array size
    while (i <= mid)
        temp[k++] = v[i++];

    while (j <= end)
        temp[k++] = v[j++];

    // let;s copy merged data
    while (start <= end)
    {
        v[start] = temp[start];
        start++;
    }
}

void print(int **v, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<int> arr={30,12,98,33,45,2,56,122,4};
    // vector<int> temp(arr.size());
    // int size=arr.size();
    // int end=size-1;
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // mergeSort(arr,temp,0,end);
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // // 1. allocate int
    // int *intPtr = new int(5);

    // // using malloc
    // int *mptr = (int *)malloc(4);
    // *mptr = 5;

    // cout << *intPtr << " " << *mptr << endl;
    // delete intPtr;
    // free(mptr);

    // // 1D allocation
    // int *arrnew = new int[5];

    // // using malloc
    // int *arrmalloc = (int *)malloc(5 * sizeof(int));

    // for (int i = 0; i < 5; i++)
    // {
    //     int d;
    //     cin >> d;
    //     arrnew[i] = arrmalloc[i] = d;
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arrnew[i] << " " << arrmalloc[i] << endl;
    // }
    // delete[] arrnew;
    // free(arrmalloc);

    // 2D allocation
    int rows = 5, cols = 5;
    int **ptr2d = new int *[rows];

    for (int i = 0; i < rows; ++i)
        ptr2d[i] = new int[cols];

    int **ptr2dmalloc = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
        ptr2dmalloc[i] = (int *)malloc(sizeof(int) * cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr2d[i][j] = 7;
            ptr2dmalloc[i][j] = 8;
        }
    }

    print(ptr2d, rows, cols);
    print(ptr2dmalloc, rows, cols);

    for (int i = 0; i < rows; ++i)
        delete[] ptr2d[i];
    delete[] ptr2d;

    for (int i = 0; i < rows; ++i)
        free(ptr2dmalloc[i]);
    free(ptr2dmalloc);

    return 0;
}