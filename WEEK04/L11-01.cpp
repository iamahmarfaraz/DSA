#include <iostream>
#include <vector>
using namespace std;
// SEARCHING & SORTING

bool linearsearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int binarysearch(int arr[], int size, int target)
{
    int start = 0;
    int end = (size - 1);
    for (; start <= end;)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return -1;
}

int firstOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = (size - 1);
    int ans = -1;
    for (; start <= end;)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return ans;
}

int lastOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = (size - 1);
    int ans = -1;
    for (; start <= end;)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return ans;
}
int totaloccurance(int arr[], int size, int target)
{
    int start = 0;
    int end = (size - 1);
    int ans = -1;
    for (; start <= end;)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }

    int start1 = 0;
    int end1 = (size - 1);
    int ans1 = -1;
    for (; start1 <= end1;)
    {
        int mid = (start1 + end1) / 2;
        if (arr[mid] == target)
        {
            ans1 = mid;
            start1 = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end1 = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start1 = mid + 1;
        }
    }
    int total = (ans1 - ans) + 1;
    return total;
}

int missingNumberBydifferentapproachonBinarySearch(int arr[], int size)
{
    int start = 0;
    int end = (size);
    int ans = -1;
    for (; start <= end;)
    {
        int mid = start + ((end - start) / 2); // best practice to find mid
        if ((arr[mid] - mid) == 1)
        {
            start = mid + 1;
        }
        else if ((arr[mid] - mid) == 2)
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}
int peakIndexInMountainArray(vector<int> &arr)
{

    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int ans;

    for (; s < e;)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {

            // A wali line me hu
            // peak right me exist krti h

            s = mid + 1;
        }
        else
        {

            // yaa toh main B line pr hu
            // ya toh main Peak element pr hu
            ans=mid;
            e = mid-1;
        }
    }
    return ans;
}

int main()
{
    // int arr[] = {1, 30, 16, 70, 90, 65};
    // int target = 70;
    // int size = sizeof(arr) / sizeof(arr[0]);
    // if (linearsearch)
    // {
    //     cout<<target<<" is present in the array"<<endl;
    // }
    // else{
    //     cout<<target<<" isn't present in the array"<<endl;
    // }
    // int index = binarysearch(arr, size, target);
    // cout<<index<<endl;
    // if (index == -1)
    // {
    //     cout << target << " not present in the array" << endl;
    // }
    // else
    // {
    //     cout << "The target number " << target << " is present at " << index << " index of the array " << endl;
    // }

    // int brr[] = {10, 20, 30, 30, 30, 30, 40, 50};
    // int target1 = 30;
    // int size1 = sizeof(brr) / sizeof(brr[0]);

    // if (firstOccurence(brr, size1, target1) == -1)
    // {
    //     cout << target1 << " not found in the array" << endl;
    // }
    // else
    // {
    //     cout << target1 << " is present in the array at " << firstOccurence(brr, size1, target1) << " index" << endl;
    // }

    // int answer=lastOccurence(brr,size1,target1);
    // if (answer==-1)
    // {
    //     cout<<target1<<" not found in the array "<<endl;
    // }
    // else{
    //     cout<<target1<<" is present at "<<answer<<" index of the array "<<endl;
    // }

    // int totaloccuranceans = totaloccurance(brr, size1, target1);
    // cout << "The total number of time " << target1 << " is present in this array is : " << totaloccuranceans << endl;

    // int crr[] = {1, 2, 3, 5, 6, 7, 8, 9};
    // int size2 = sizeof(crr) / sizeof(crr[0]);
    // int newAns = missingNumberBydifferentapproachonBinarySearch(crr, size2);
    // if (newAns == -1)
    // {
    //     cout << "No elemnt is missing in the array" << endl;
    // }
    // else
    // {
    //     cout << "Missing element should be at " << newAns << " index" << endl;
    // }

    vector<int> arrr;
    arrr.push_back(10);
    arrr.push_back(20);
    arrr.push_back(30);
    arrr.push_back(90);
    arrr.push_back(60);
    arrr.push_back(50);
    arrr.push_back(40);

    int vecAns=peakIndexInMountainArray(arrr);
    cout<<"The peak value in mountain array is at : "<<vecAns<<" index"<<endl;

    return 0;
}