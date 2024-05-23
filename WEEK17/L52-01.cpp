#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int paintUsingRec(int n, int k)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    int ans = (k - 1) * (paintUsingRec(n - 2, k) + paintUsingRec(n - 1, k));
    return ans;
}

int paintUsingMem(int n, int k, vector<int> &dp)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (k - 1) * (paintUsingMem(n - 2, k, dp) + paintUsingMem(n - 1, k, dp));
    return dp[n];
}

int paintUsingTabulation(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k + k * (k - 1);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (k - 1) * (dp[i - 2] + dp[n - 1]);
    }
    return dp[n];
}

int paintUsingTabulationSO(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    // vector<int> dp(n+1,-1);
    int prev = k;
    int curr = k + k * (k - 1);
    int ans;
    for (int i = 3; i <= n; i++)
    {
        ans = (k - 1) * (prev + curr);
        prev = curr;
        curr = ans;
    }
    return ans;
}

int knapSack0_1UsingRec(int capacity, int *wt, int *profit, int n, int index)
{
    // Base Case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + knapSack0_1UsingRec(capacity - wt[index], wt, profit, n, index + 1);
    }
    exclude = 0 + knapSack0_1UsingRec(capacity, wt, profit, n, index + 1);
    int ans = max(include, exclude);
    return ans;
}

int knapSack0_1UsingMem(int capacity, int *wt, int *profit, int n, int index, vector<vector<int>> &dp)
{
    // Base Case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }
    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }

    int include = 0;
    int exclude = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + knapSack0_1UsingMem(capacity - wt[index], wt, profit, n, index + 1, dp);
    }
    exclude = 0 + knapSack0_1UsingMem(capacity, wt, profit, n, index + 1, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int knapSack0_1UsingTabulation(int capacity, int *wt, int *profit, int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    for (int row = 0; row <= capacity; row++)
    {
        // Base Case Analysis of Memoization
        dp[row][n] = 0;
    }
    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0];
}

int knapSack0_1UsingTabulationSO(int capacity, int *wt, int *profit, int n)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, -1);

    // for (int row = 0; row <= capacity; row++)
    // {
    //     // Base Case Analysis of Memoization
    //     dp[row][n] = 0;
    // }
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i <= capacity; i++)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + prev[i - wt[j]];
            }
            exclude = 0 + prev[i];
            curr[i] = max(include, exclude);
        }
        prev = curr;
        // fill(curr.begin(), curr.end(), -1);
    }
    return prev[capacity];
}

int knapSack0_1UsingTabulationSO_BEST(int capacity, int *wt, int *profit, int n)
{
    vector<int> prev(capacity + 1, 0);
    // vector<int> curr(capacity+1,-1);

    // for (int row = 0; row <= capacity; row++)
    // {
    //     // Base Case Analysis of Memoization
    //     dp[row][n] = 0;
    // }
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = capacity; i >= 0; i--)
        {
            int include = 0;
            int exclude = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + prev[i - wt[j]];
            }
            exclude = 0 + prev[i];
            prev[i] = max(include, exclude);
        }
        // prev=curr;
        // fill(curr.begin(), curr.end(), -1);
    }
    return prev[capacity];
}

int main()
{
    int n = 3;
    int k = 3;
    int ans = paintUsingRec(n, k);
    cout << "Painting Fence Algorithm using Recursion : " << ans << endl;

    vector<int> dp(n + 1, -1);
    int ans2 = paintUsingMem(n, k, dp);
    cout << "Painting Fence Algorithm using Memoization : " << ans2 << endl;

    int ans3 = paintUsingTabulation(n, k);
    cout << "Painting Fence Algorithm using Tabulation : " << ans3 << endl;

    int ans4 = paintUsingTabulationSO(n, k);
    cout << "Painting Fence Algorithm using Tabulation After Space Optimization : " << ans4 << endl;

    int capacity = 6;
    int wt[] = {1, 2, 3};
    int profit[] = {10, 15, 40};
    int n1 = 3;
    int ans5 = knapSack0_1UsingRec(capacity, wt, profit, n1, 0);
    cout << "0/1 KnapSack Algorithm Using Recursion : " << ans5 << endl;

    vector<vector<int>> dp2(capacity + 1, vector<int>(n + 1, -1));
    int ans6 = knapSack0_1UsingMem(capacity, wt, profit, n1, 0, dp2);
    cout << "0/1 KnapSack Algorithm Using Memoization : " << ans6 << endl;

    int ans7 = knapSack0_1UsingTabulation(capacity, wt, profit, n1);
    cout << "0/1 KnapSack Algorithm Using Tabulation : " << ans7 << endl;

    int ans8 = knapSack0_1UsingTabulationSO(capacity, wt, profit, n1);
    cout << "0/1 KnapSack Algorithm Using Tabulation After Space Optimization : " << ans8 << endl;

    int ans9 = knapSack0_1UsingTabulationSO_BEST(capacity, wt, profit, n1);
    cout << "0/1 KnapSack Algorithm Using Tabulation After Best Space Optimization : " << ans9 << endl;

    return 0;
}