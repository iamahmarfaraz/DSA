#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int lengthOfLISUsingRec(vector<int> &nums, int curr, int prev)
{
    // Base case
    if (curr >= nums.size())
    {
        return 0;
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + lengthOfLISUsingRec(nums, curr + 1, curr); // instead of doing prev+1 we
        // putted curr cause we will directly jump to curr ignoring all the excluded element
    }

    int exclude = 0 + lengthOfLISUsingRec(nums, curr + 1, prev);
    int ans = max(exclude, include);
    return ans;
}

int lengthOfLISUsingMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    // Base case
    if (curr >= nums.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + lengthOfLISUsingMem(nums, curr + 1, curr, dp); // instead of doing prev+1 we
        // putted curr cause we will directly jump to curr ignoring all the excluded element
    }

    int exclude = 0 + lengthOfLISUsingMem(nums, curr + 1, prev, dp);
    dp[curr][prev + 1] = max(exclude, include);
    return dp[curr][prev + 1];
}

int lengthOfLISUsingTabulation(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

    for (int curr_index = nums.size() - 1; curr_index >= 0; curr_index--)
    {
        for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
        {
            int include = 0;
            if (prev_index == -1 || nums[curr_index] > nums[prev_index])
            {
                include = 1 + dp[curr_index + 1][curr_index + 1]; // instead of doing prev+1 we
                // putted curr cause we will directly jump to curr ignoring all the excluded element
            }

            int exclude = 0 + dp[curr_index + 1][prev_index + 1];
            dp[curr_index][prev_index + 1] = max(exclude, include);
        }
    }
    return dp[0][0];
}

int lengthOfLISUsingTabulationSO(vector<int> &num)
{
    int n = num.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr_index = n - 1; curr_index >= 0; curr_index--)
    {
        for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
        {

            int include = 0;
            if (prev_index == -1 || num[curr_index] > num[prev_index])
            {
                include = 1 + nextRow[curr_index + 1];
            }
            int exclude = 0 + nextRow[prev_index + 1];
            currRow[prev_index + 1] = max(include, exclude);
        }
        // shifting
        nextRow = currRow;
    }
    return nextRow[0];
}

int lengthOfLISUsingBinarySearch(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    // int lastIndex = ans.size()-1;
    int size = nums.size();
    for (int i = 1; i < size; i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // REplace the lowerbound index element "ans" array with nums[i]
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            // Replace
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;
    // int ans = lengthOfLISUsingRec(nums,curr,prev);
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    // int ans = lengthOfLISUsingMem(nums,curr,prev,dp);
    // int ans = lengthOfLISUsingTabulation(nums);
    // int ans = lengthOfLISUsingTabulationSO(nums);
    int ans = lengthOfLISUsingBinarySearch(nums);

    return ans;
}

bool check(vector<int> &curr, vector<int> &prev)
{
    // Curr -> Bda Dabba
    // Prev -> Chota wla Dabba
    if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int maxHeightUsingLIS(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    // vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr_index = n - 1; curr_index >= 0; curr_index--)
    {
        for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
        {

            int include = 0;
            if (prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index]))
            {
                int heightToAdd = cuboids[curr_index][2];
                include = heightToAdd + nextRow[curr_index + 1];
            }
            int exclude = 0 + nextRow[prev_index + 1];
            currRow[prev_index + 1] = max(include, exclude);
        }
        // shifting
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = maxHeightUsingLIS(cuboids);
    return ans;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS(nums);
    cout << endl
         << "Q1:) Longest Increasing Subsequence's Output : " << ans << endl
         << endl;
    return 0;
}