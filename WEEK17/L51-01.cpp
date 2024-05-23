#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solveUsingMem(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int include = nums[index] + solveUsingMem(nums, index + 2, dp);
    int exclude = 0 + solveUsingMem(nums, index + 1, dp);
    dp[index] = max(include, exclude);
    return dp[index];
}

int rob(vector<int> &nums)
{
    int index = 0;
    int n = nums.size() - 1;
    vector<int> dp(n + 1, -1);
    return solveUsingMem(nums, index, dp);
}

int solveUsingTabulation(vector<int> &nums)
{
    int n = nums.size() - 1;
    // Step1
    vector<int> dp(n + 1, -1);
    // Step2
    dp[n] = nums[n];
    for (int index = n - 1; index >= 0; index--)
    {
        int temp = 0;
        if (index + 2 <= n)
        {
            temp = dp[index + 2];
        }
        int include = nums[index] + temp;
        int exclude = 0 + dp[index + 1];
        dp[index] = max(include, exclude);
    }
    return dp[0];
}

int solveUsingTabulationOptimized(vector<int> &nums)
{
    int n = nums.size() - 1;
    int prev = 0;
    int curr = nums[n];
    for (int index = n - 1; index >= 0; index--)
    {
        // int temp = 0;
        // if(index + 2 <= n){
        //     temp = dp[index+2];
        // }
        int include = nums[index] + prev;
        int exclude = 0 + curr;
        prev = curr;
        curr = max(include, exclude);
    }
    return curr;
}

int rob2(vector<int> &nums)
{
    return solveUsingTabulation(nums);
}

int solveUsingRec(vector<int> &coins, int amount)
{
    // Base Case
    if (amount == 0)
    {
        // No Coin Needed Now
        return 0;
    }
    if (amount < 0)
    {
        // Answer nhi bn rha
        return INT_MAX;
        // INT_MAX isley nhi return kiya kyunki phir 1 + INT_MAX integer range se bahir hota
    }

    // Recursive Relation
    int finalAns = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        int temp = solveUsingRec(coins, amount - coin);
        int ans;
        if (temp == INT_MAX)
        {
            continue;
        }
        else
        {
            ans = 1 + temp;
        }
        if (ans <= finalAns)
        {
            finalAns = ans;
        }
    }
    if (finalAns == INT_MAX)
    {
        return -1;
    }
    return finalAns;
}
int coinChange(vector<int> &coins, int amount)
{
    return solveUsingRec(coins, amount);
}

int solveUsingRec(vector<int> &coins, int amount)
{
    // Base Case
    if (amount == 0)
    {
        // No Coin Needed Now
        return 0;
    }

    // Recursive Relation
    int finalAns = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (coin <= amount)
        {
            int recAns = solveUsingRec(coins, amount - coin);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                finalAns = min(ans, finalAns);
            }
        }
    }
    return finalAns;
}

int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp)
{
    // Base Case
    if (amount == 0)
    {
        // No Coin Needed Now
        return 0;
    }

    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    // Recursive Relation
    int finalAns = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (coin <= amount)
        {
            int recAns = solveUsingMem(coins, amount - coin, dp);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                finalAns = min(ans, finalAns);
            }
        }
    }
    dp[amount] = finalAns;
    return dp[amount];
}

int solveUsingTabulation(vector<int> &coins, int amount)
{
    int n = amount + 1;
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // Analyse base case of Memoization and made this

    for (int value = 1; value <= amount; value++)
    {
        int finalAns = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];
            if (coin <= value)
            {
                int recAns = dp[value - coin];
                if (recAns != INT_MAX)
                {
                    int ans = 1 + recAns;
                    finalAns = min(ans, finalAns);
                }
            }
        }
        dp[value] = finalAns;
    }
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // int ans =  solveUsingRec(coins,amount);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }
    // int n = amount + 1;
    // vector<int> dp(n,-1);
    // int ans =  solveUsingMem(coins,amount,dp);
    // if(ans == INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }
    int ans = solveUsingTabulation(coins, amount);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int ans = rob(arr);
    cout << "House Robber Problem Using Memoization : " << ans << endl;
    cout << endl;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans2 = coinChange(coins, amount);
    cout << "Coin Change Problem Output : " << ans2 << endl;
    return 0;
}