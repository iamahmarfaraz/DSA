#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selectionSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < (size - 1); i++)
    {
        int minElement = INT_MAX;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < minElement)
            {
                minElement=arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }
}
void insertionSort(vector<int> &arr)
{
    int j;
    int size=arr.size();
    for (int i = 1; i < size; i++)
    {
        int temp=arr[i];
        for ( j = i-1; j >= 0; j--)
        {
            if (arr[j]>temp)
            {
                arr[j+1]=arr[j];
                
            }
            
        }
        arr[j+1]=temp;
        
    }
    
}
void printVector(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    // cout<<"Array before Bubble Sorting "<<endl;
    // printVector(arr);
    // cout<<endl;
    // bubbleSort(arr);
    // cout<<"Array after Bubble Sorting "<<endl;
    // printVector(arr);

    // cout << "Array before Selection Sort " << endl;
    // printVector(arr);
    // cout << endl;
    // selectionSort(arr);
    // cout << "Array after Selection Sort " << endl;
    // printVector(arr);

    // cout << "Array before Insertion Sort " << endl;
    // printVector(arr);
    // cout << endl;
    // insertionSort(arr);
    // cout << "Array after Insertion Sort " << endl;
    // printVector(arr);

    return 0;
}