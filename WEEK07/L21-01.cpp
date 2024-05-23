#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int size, int index)
{
    bool ans;
    // Base Case
    if (index >= size)
    {
        return true;
    }

    // Processing
    if (arr[index] < arr[index + 1])
    {
        // Recursion
        ans = checkSorted(arr, size, index + 1);
    }
    else
    {
        return false;
    }
    return ans;
}

int binarySearchRE(vector<int> &arr, int start, int end, int target)
{
    int ans;
    // Base Case
    if (start > end)
    {
        return -1;
    }
    int mid = start + ((end - start) / 2);
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        ans = binarySearchRE(arr, start, mid - 1, target);
    }
    else
    {
        ans = binarySearchRE(arr, mid + 1, end, target);
    }
    return ans;
}

void subSequence(string &cutiee, string output, int index)
{
    // Base case
    if (index >= cutiee.length())
    {
        cout << output << endl;
        return;
    }
    char ch = cutiee[index];
    // Exclude
    subSequence(cutiee, output, index + 1);
    // include "ch" in "output" string
    output.push_back(ch);
    subSequence(cutiee, output, index + 1);
}

int maxSegment(int n, int x, int y, int z)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
        // in that way if segment is not cutted perfectly we'll return INT_MAX so that it'll not considered in max()
    }

    // have cutted 1 segment of "x" length from "n" length rod rest of the cut will be handled by recursion
    int option1 = 1 + maxSegment(n - x, x, y, z);
    // have cutted 1 segment of "y" length from "n" length rod rest of the cut will be handled by recursion
    int option2 = 1 + maxSegment(n - y, x, y, z);
    // have cutted 1 segment of "z" length from "n" length rod rest of the cut will be handled by recursion
    int option3 = 1 + maxSegment(n - z, x, y, z);

    int finalAns = max(option1, max(option2, option3));
    return finalAns;
}

int coinChange(vector<int> &coins, int amount)
{
    // Base case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }

    int finalAns = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        if (coin <= amount)
        {
            int recAns = coinChange(coins, amount - coin);
            if (recAns >= 0)
            {
                ans = 1 + recAns;
            }
        }
        finalAns = min(finalAns, ans);
    }
    if (finalAns == INT_MAX)
    {
        return -1;
    }
    return finalAns;
}

int solve(vector<int> &nums, int size, int index)
{
    // base case
    if (index >= size)
    {
        return 0;
    }

    // chori karlo -> ith index pr
    int option1 = nums[index] + solve(nums, size, index + 2);

    // chori mat karo  -> ith index pr
    int option2 = 0 + solve(nums, size, index + 1);

    int finalAns = max(option1, option2);
    return finalAns;
}
int rob(vector<int> &nums)
{
    int size = nums.size();
    int index = 0;
    int ans = solve(nums, size, index);
    return ans;
}

int main()
{
    // vector<int> arr = {10, 20, 30, 40, 20, 50, 60, 70};
    // int size = arr.size();
    // if (checkSorted(arr, size, 0))
    // {
    //     cout << "Array is Sorted" << endl;
    // }
    // else
    // {
    //     cout << "Array isn't Sorted" << endl;
    // }

    // vector<int> brr = {10, 20, 30, 40, 50, 60, 70};
    // int size = brr.size();
    // int start = 0;
    // int end = size - 1;
    // int target = 50;
    // if (binarySearchRE(brr, start, end, target) == -1)
    // {
    //     cout << "Element not found in Array" << endl;
    // }
    // else
    // {
    //     cout << "Element found at : " << binarySearchRE(brr, start, end, target) << endl;
    // }

    // string s="abc";
    // string output="";
    // subSequence(s,output,0);

    // vector<int> arr = {1, 2, 5};
    // int amount = 11;
    // cout << "Minimum number of coin use to make " << amount << "  : " << coinChange(arr, amount);

    vector<int> nums={1,2,3,1};
    cout<<"Max amount of money robbed : "<<rob(nums);

    return 0;
}