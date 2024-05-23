#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int pivotelementindex(vector<int> &nums, int size)
{
    int start = 0;
    int end = (size - 1);
    for (; start <= end;)
    {
        int mid = (start + ((end - start) / 2));
        if (start == end)
        {
            // it'll handle the single element case
            return start;
        }
        else if ((mid - 1) >= 0 && nums[mid] < nums[mid - 1])
        {
            return mid - 1;
        }
        else if ((mid + 1) < size && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] < nums[0])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int binarysearch(vector<int> &nums, int target, int start, int end)
{
    int ans = -1;
    for (; start <= end;)
    {
        int mid = (start + ((end - start) / 2));
        if (nums[mid] == target)
        {
            ans = mid;
            return ans;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int search(vector<int> &nums, int target)
{
    int start = 0;
    int size = nums.size();
    int pivotindex = pivotelementindex(nums, size);
    int ans = -1;
    if (target >= nums[0] && target <= nums[pivotindex])
    {
        // binary search in A
        ans = binarysearch(nums, target, start, pivotindex);
    }
    else
    {
        // binary search in B
        ans = binarysearch(nums, target, (pivotindex + 1), (size - 1));
    }
    return ans;
}

int mySqrt(int x)
{
    int start = 0;
    int end = x;
    int ans;
    for (; start <= end;)
    {
        long long int mid = start + ((end - start) / 2);
        if ((mid * mid) == x)
        {
            return mid;
        }
        else if ((mid * mid) < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int size = m * n;
    int start = 0;
    int end = (size - 1);
    for (; start <= end;)
    {
        int mid = start + ((end - start) / 2);
        int i = mid / n;
        int j = mid % n;
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    // int arr[] = {12, 14, 16, 2, 4, 6, 8, 10};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int pivotAns = pivotelementindex(arr, size);
    // if (pivotAns == -1)
    // {
    //     cout << "No pivot index found" << endl;
    // }
    // else
    // {
    //     cout << "Pivot index is : " << pivotAns << endl;
    // }
    vector<int> v;

    // v.push_back(12);
    // v.push_back(14);
    // v.push_back(16);
    // v.push_back(2);
    // v.push_back(6);
    // v.push_back(8);
    // v.push_back(10);

    // int target = 14;
    // int targetsearch = search(v, target);
    // if (targetsearch == -1)
    // {
    //     cout << "Element not found" << endl;
    // }
    // else
    // {
    //     cout << " Element found at : " << targetsearch << " index" << endl;
    // }

    vector<vector<int>> lrr;
    int target=24;
    vector<int> sub1 = {2, 4, 6, 8};
    vector<int> sub2 = {10, 12, 14, 16};
    vector<int> sub3 = {18, 20, 22, 24};
    vector<int> sub4 = {28, 34, 40, 50};
    lrr.push_back(sub1);
    lrr.push_back(sub2);
    lrr.push_back(sub3);
    lrr.push_back(sub4);
    if (searchMatrix(lrr,target))
    {
        cout<<"Target is present in 2D matrix"<<endl;
    }
    else{
        cout<<"Target not found in 2D matrix"<<endl;
    }
    
    return 0;
}