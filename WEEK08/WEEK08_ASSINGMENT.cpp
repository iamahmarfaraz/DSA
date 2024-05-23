#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int countInversion(vector<int> &v, vector<int> &temp, int start, int end)
{
    int count = 0;
    if (start >= end)
        return 0;

    int mid = (start + end) / 2;
    // divide
    count += countInversion(v, temp, start, mid);
    count += countInversion(v, temp, mid + 1, end);

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
        count += mid - i + 1;
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
    return count;
}

void mergeInPlace(vector<int> &arr, int s, int e)
{
    int size = e - s + 1;
    int gap = size / 2 + size % 2;
    while (gap > 0)
    {
        int i = s, j = s + gap;
        while (j <= e)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++, j++;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergesort(vector<int> &arr, int s, int e)
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
    mergeInPlace(arr, s, e);
}

void print(vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int maxSub(vector<int> &v, int s, int e)
{
    if (s == e)
        return v[s];
    int maxleft = INT_MIN;
    int maxright = INT_MIN;
    int mid = s + (e - s) / 2;
    int leftAns = maxSub(v, s, mid);
    int rightAns = maxSub(v, mid + 1, e);

    int leftsum = 0, rightsum = 0;
    for (int i = mid; i >= s; i--)
    {
        leftsum += v[i];
        if (leftsum > maxleft)
        {
            maxleft = leftsum;
        }
    }

    for (int i = mid + 1; i <= e; i++)
    {
        rightsum += v[i];
        if (rightsum > maxright)
        {
            maxright = rightsum;
        }
    }
    int crossSum = maxleft + maxright;
    return max(leftAns, max(rightAns, crossSum));
}

void combinationSumHelp(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    // Base Case
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
    {
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        combinationSumHelp(candidates, target - candidates[i], temp, ans, i);
        // Back Tracking
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    combinationSumHelp(candidates, target, temp, ans, 0);
    return ans;
}

void permutationString2(vector<int> &s, int index, int size, vector<vector<int>> &ans)
{
    // Base Case
    if (index >= size)
    {
        ans.push_back(s);
        return;
    }
    unordered_map<int, bool> visited;
    for (int j = index; j < size; j++)
    {
        if (visited.find(s[j]) != visited.end())
        {
            continue;
        }
        visited[s[j]] = true;
        swap(s[index], s[j]);
        permutationString2(s, index + 1, size, ans);
        // BACKTRACKING
        swap(s[index], s[j]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutationString2(nums, 0, nums.size(), ans);
    return ans;
}

void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void countArrangementHelper(vector<int> &v, int &n, int &ans, int currNum)
{
    // base
    if (currNum == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        ++ans;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum;
            countArrangementHelper(v, n, ans, currNum + 1);
            v[i] = 0; // backtracking
        }
    }
}
int countArrangement(int n)
{
    vector<int> v(n + 1);
    int ans = 0;
    countArrangementHelper(v, n, ans, 1);
    return ans;
}

bool canDistributeHelp(vector<int> &counts, vector<int> &quantity, int ithCustomer)
{
    // Base Case
    if (ithCustomer == quantity.size())
    {
        return true;
    }

    for (int i = 0; i < counts.size(); ++i)
    {
        if (counts[i] >= quantity[ithCustomer])
        {
            counts[i] -= quantity[ithCustomer];
            if (canDistributeHelp(counts, quantity, ithCustomer + 1))
            {
                return true;
            }
            counts[i] += quantity[ithCustomer]; // BackTrack
        }
    }
    return false;
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> countMap;
    for (auto num : nums)
    {
        countMap[num]++;
    }
    vector<int> counts;
    for (auto it : countMap)
    {
        counts.push_back(it.second);
    }
    sort(quantity.rbegin(), quantity.rend());
    return canDistributeHelp(counts, quantity, 0);
}

int main()
{
    // vector<int> arr = {8, 4, 2, 1};
    // vector<int> temp(arr.size(), 0);
    // int size = arr.size();
    // int end = size - 1;
    // cout << "Inversion Count of the Array : " << countInversion(arr, temp, 0, end);

    // vector<int> mrg={1,2,8,9,12,13,3,4,7,10};
    // int end=mrg.size() - 1;
    // cout<<"Before Inplace Merge Sort"<<endl;
    // print(mrg,mrg.size());
    // mergesort(mrg,0,end);
    // cout<<"After Inplace Merge Sort"<<endl;
    // print(mrg,mrg.size());

    // vector<int> nums = {-2, 1, -3, 4, -1, 2, -5, 4};
    // cout << "Max SubArray : " << maxSub(nums, 0, nums.size() - 1);

    // vector<int> candidate={2,3,6,7};
    // int target=7;
    // vector<vector<int>> ans=combinationSum(candidate,target);
    // print(ans);

    // vector<int> per = {1, 1, 2};
    // vector<vector<int>> ans2 = permuteUnique(per);
    // print(ans2);

    // int n = 3;
    // countArrangement(n);

    vector<int> nums={1,1,2,2};
    vector<int> quantity={2,2};
    if (canDistribute(nums,quantity))
    {
        cout<<"it is possible to distribute \"nums\" according to the given conditions"<<endl;
    }
    else{
        cout<<"it is not possible to distribute nums according to the given conditions"<<endl;
    }
    

    return 0;
}