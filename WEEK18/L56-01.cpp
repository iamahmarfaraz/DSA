#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool canPartitionRec(vector<int> &nums, int index, int currSum, int target)
{
    // Base Cases
    if (index >= nums.size())
    {
        return 0;
    }
    if (currSum > target)
    {
        return 0;
    }
    if (currSum == target)
    {
        return true;
    }
    bool include = canPartitionRec(nums, index + 1, currSum + nums[index], target);
    bool exclude = canPartitionRec(nums, index + 1, currSum, target);
    return include || exclude;
}

bool canPartitionMem(vector<int> &nums, int index, int currSum, int target, vector<vector<int>> &dp)
{
    // Base Cases
    if (index >= nums.size())
    {
        return 0;
    }
    if (currSum > target)
    {
        return 0;
    }
    if (currSum == target)
    {
        return true;
    }
    if (dp[index][currSum] != -1)
    {
        return dp[index][currSum];
    }
    bool include = canPartitionMem(nums, index + 1, currSum + nums[index], target, dp);
    bool exclude = canPartitionMem(nums, index + 1, currSum, target, dp);
    return dp[index][currSum] = (include || exclude);
}

bool canPartitionTabulation(vector<int> &nums, int &target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int row = 0; row < n; row++)
    {
        dp[row][target] = 1;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int currSum = target - 1; currSum >= 0; currSum--)
        {
            // if(dp[index][currSum] > target){
            //     continue;
            // }
            // if(dp[index][currSum] == target){
            //     return true;
            // }
            bool include = 0;
            if (currSum + nums[index] <= target)
            {
                include = dp[index + 1][currSum + nums[index]];
            }

            bool exclude = dp[index + 1][currSum];
            dp[index][currSum] = (include || exclude);
        }
    }
    return dp[0][0];
}

bool canPartitionTabulationSO(vector<int> &nums, int &target)
{
    int n = nums.size();
    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);
    next[target] = 1;
    curr[target] = 1;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int currSum = target - 1; currSum >= 0; currSum--)
        {
            bool include = 0;
            if (currSum + nums[index] <= target)
            {
                include = next[currSum + nums[index]];
            }

            bool exclude = next[currSum];
            curr[currSum] = (include || exclude);
        }
        next = curr;
    }
    return next[0];
}

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i];
    }
    if (totalSum & 1)
    {
        return false;
    }
    int target = totalSum / 2;
    int currSum = 0;
    // bool ans = canPartitionRec(nums,0,currSum,target);
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    // bool ans = canPartitionMem(nums,0,currSum,target,dp);

    // bool ans = canPartitionTabulation(nums,target);

    bool ans = canPartitionTabulationSO(nums, target);

    return ans;
}

long long int MOD = 1000000007;
int numRollsToTargetRec(int n, int &k, int currSum, int &target)
{
    // Base Case
    if (currSum == target && n == 0)
    {
        // dice bhi khatam and Target bhi bn gya hai
        return 1;
    }
    if (currSum != target && n == 0)
    {
        // Dice khatam hogyi hai but Target nhi bnn paya
        return 0;
    }
    if (currSum == target && n != 0)
    {
        // Target ke barabrr bn gya but Dice abhi baki hai jb target jb bne tb dice sare
        // Utilised hogye ho this is the condition
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int temp = numRollsToTargetRec(n - 1, k, currSum + i, target);
        ans += temp;
    }
    return ans;
}
int numRollsToTargetMem(int n, int &k, int target, vector<vector<int>> &dp)
{
    // Base Case
    if (target < 0)
    {
        // So that invalid index didn't get executed
        return 0;
    }
    if (target == 0 && n == 0)
    {
        return 1;
    }
    if (target != 0 && n == 0)
    {
        return 0;
    }
    if (target == 0 && n != 0)
    {
        return 0;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int temp = numRollsToTargetMem(n - 1, k, target - i, dp) % MOD;
        ans = (ans % MOD + temp) % MOD;
    }
    dp[n][target] = ans;
    return dp[n][target];
}

int numRollsToTargetTabulation(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[n][target] = 1;

    for (int n_index = n - 1; n_index >= 0; n_index--)
    {
        for (int target_index = target - 1; target_index >= 0; target_index--)
        {
            int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                int temp = 0;
                if (target_index + i <= target)
                {
                    // temp = (dp[n_index-1][target_index - i])%MOD;
                    temp = dp[n_index + 1][target_index + i];
                }
                else
                {
                    // ab target index me kuch bhi plus krunga to Out Of Bound
                    // hojayega cause ab sare "i" bde hote jayenge
                    break;
                }
                ans = (ans % MOD + temp % MOD) % MOD;
            }
            dp[n_index][target_index] = ans;
        }
    }
    return dp[0][0];
}

int numRollsToTargetTabulationSO(int n, int k, int target)
{
    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);

    next[target] = 1;

    for (int n_index = n - 1; n_index >= 0; n_index--)
    {
        for (int target_index = target - 1; target_index >= 0; target_index--)
        {
            int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                int temp = 0;
                if (target_index + i <= target)
                {
                    // temp = (dp[n_index-1][target_index - i])%MOD;
                    temp = next[target_index + i];
                }
                else
                {
                    break;
                }
                ans = (ans % MOD + temp % MOD) % MOD;
            }
            curr[target_index] = ans;
        }
        // Shifting ,yhi bhulte hai hmesha
        next = curr;
    }
    return next[0];
}

int numRollsToTarget(int n, int k, int target)
{
    int currSum = 0;
    // int ans = numRollsToTargetRec(n,k,currSum,target);
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // int ans = numRollsToTargetMem(n,k,target,dp);
    //  int ans = numRollsToTargetTabulation(n,k,target);
    int ans = numRollsToTargetTabulationSO(n, k, target);

    return ans;
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    if (canPartition(nums))
    {
        cout << endl
             << endl
             << "Partition possible " << endl
             << endl;
    }
    else
    {
        cout << endl
             << endl
             << "Partition not possible " << endl
             << endl;
    }

    int n = 2;
    int k = 6;
    int target = 7;
    int ans = numRollsToTarget(n, k, target);
    cout << endl
         << endl
         << "No of Possible ways to achieve Target sum \"" << target << "\" by using " << n << " Dices having " << k << " faces : " << ans << endl
         << endl;
    return 0;
}