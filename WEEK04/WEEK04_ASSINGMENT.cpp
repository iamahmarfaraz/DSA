#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int findPairs(vector<int> &nums, int k)
{
    // Q.NO 1
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> count;
    while (j < size)
    {
        int diff = nums[j] - nums[i];
        if (i == j)
        {
            j++;
        }

        else if (diff == k)
        {
            count.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return count.size();
}
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // Q.NO2
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    int finalLow;
    int finalHigh;
    while ((high - low + 1) >= k)
    {
        int diffLow = (abs(x - arr[low]));
        int diffHigh = (abs(x - arr[high]));
        if ((high - low + 1) == k)
        {
            finalLow = low;
            finalHigh = high;
        }
        if (diffLow > diffHigh)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    vector<int> ans;
    for (int i = finalLow; i <= finalHigh; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int exponentialSearch(vector<int> &arr, int target)
{
    int size = arr.size();
    if (arr[0] == target)
    {
        return 0;
    }
    int i = 1;
    int store = -1;
    while (i < size)
    {
        if (arr[i] == target)
        {
            return i;
        }
        else if (arr[i] < target)
        {
            store = i;
            i = i * 2;
        }
        else
        {
            break;
        }
    }
    int start = store + 1;
    int end = min(i, size) - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
bool ispossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalsum + arr[i] <= mid)
        {
            totalsum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            totalsum = arr[i];
        }
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    if (M > N)
    {
        return -1;
    }
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    int start = 0;
    int end = sum;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (ispossible(A, N, M, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
bool possibleSol(vector<int> &arr, int k, int mid)
{
    int cowCount = 1;
    int lastPos = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            cowCount++;
            lastPos = arr[i];
            if (cowCount == k)
            {
                return true;
            }
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    while (s <= e)
    {
        int mid=s+(e-s)/2;
        if (possibleSol(stalls, k, mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int heightofCut(vector<int> &arr,int mid){
    long long int ans=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<mid)
        {
            continue;
        }
        int sum=arr[i]-mid;
        ans += sum;
    }
    return ans;
}
int EKOSPOJ(vector<int>&arr,int m){
    int size=arr.size();
    int ans=-1;
    int s=0;
    int max=INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        } 
    }
    int e=max;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if (heightofCut(arr,mid)==m)
        {
            return mid;
        }
        else if (heightofCut(arr,mid)>m)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        
        
    }
    return ans;
    
}
void print(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // vector<int> a = {3, 1, 4, 1, 5};
    // int k = 2;
    // int ans = findPairs(a, k);
    // cout << "K-diff pairs in an Array : " << ans;

    // vector<int> b = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    // int k = 4;
    // int x = 35;
    // vector<int> kClosest = findClosestElements(b, k, x);
    // print(kClosest);

    // vector<int> c = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    // int x = 13;
    // int exponentialSearchAns = exponentialSearch(c, x);
    // if (exponentialSearchAns == -1)
    // {
    //     cout << "Element not found in the array" << endl;
    // }
    // else
    // {
    //     cout << "Element found at " << exponentialSearchAns << " index of the array" << endl;
    // }
    // int arr[] = {12, 34, 67, 90};
    // int size = 4;
    // int m = 2;
    // int bookAlloc = findPages(arr, size, m);
    // cout << bookAlloc;

    // vector<int> arr={4,2,1,3,6};
    // int k=2;
    // int cowAns=aggressiveCows(arr,k);
    // cout<<cowAns;

    vector<int> eko={20,15,10,17};
    int m=7;
    int ekoAns=EKOSPOJ(eko,m);
    cout<<"Minimum height at which the chainshaw should cut : "<<ekoAns<<endl;

    return 0;
}