#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int getMoneyAmountRec(int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return 0;
    }
    int finalAns = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        int left = getMoneyAmountRec(start, i - 1);
        int right = getMoneyAmountRec(i + 1, end);
        //
        int ans = i + max(left, right);
        finalAns = min(finalAns, ans);
    }
    return finalAns;
}

int getMoneyAmountMem(int start, int end, vector<vector<int>> &dp)
{
    // Base Case
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int finalAns = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        int left = getMoneyAmountMem(start, i - 1, dp);
        int right = getMoneyAmountMem(i + 1, end, dp);
        //
        int ans = i + max(left, right);
        finalAns = min(finalAns, ans);
    }
    dp[start][end] = finalAns;
    return dp[start][end];
}

int getMoneyAmountTabulation(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
    for (int start_index = n - 1; start_index >= 1; start_index--)
    {
        for (int end_index = 1; end_index <= n; end_index++)
        {
            if (start_index >= end_index)
            {
                continue;
            }
            int finalAns = INT_MAX;
            for (int i = start_index; i <= end_index; i++)
            {
                int left = dp[start_index][i - 1];
                int right = dp[i + 1][end_index];
                int ans = i + max(left, right);
                finalAns = min(finalAns, ans);
            }
            dp[start_index][end_index] = finalAns;
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n)
{
    int start = 1;
    int end = n;
    // int ans = getMoneyAmountRec(start,end);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // int ans = getMoneyAmountMem(start,end,dp);
    int ans = getMoneyAmountTabulation(n);

    return ans;
}

int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int s, int e)
{
    // base case
    if (s > e)
    {
        return 0;
    }
    if (s == e)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        // i is used here for partitioning
        ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}]) +
                           solveUsingRecursion(arr, maxi, s, i) +
                           solveUsingRecursion(arr, maxi, i + 1, e));
    }
    return ans;
}

int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int s, int e, vector<vector<int>> &dp)
{
    // base case
    if (s > e)
    {
        return 0;
    }
    if (s == e)
    {
        return 0;
    }
    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        // i is used here for partitioning
        ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}]) +
                           solveUsingMem(arr, maxi, s, i, dp) +
                           solveUsingMem(arr, maxi, i + 1, e, dp));
    }
    dp[s][e] = ans;
    return dp[s][e];
}

int solveUsingTabulation(vector<int> &arr, map<pair<int, int>, int> &maxi)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for (int s_index = n; s_index >= 0; s_index--)
    {
        for (int e_index = 0; e_index <= n - 1; e_index++)
        {
            if (s_index >= e_index)
            {
                continue;
            }
            int ans = INT_MAX;
            for (int i = s_index; i < e_index; i++)
            {
                // i is used here for partitioning
                ans = min(ans, (maxi[{s_index, i}] * maxi[{i + 1, e_index}]) + dp[s_index][i] + dp[i + 1][e_index]);
            }
            dp[s_index][e_index] = ans;
        }
    }

    return dp[0][n - 1];
}

int mctFromLeafValues(vector<int> &arr)
{
    // pre computation
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingTabulation(arr, maxi);
    return ans;
}

int main()
{
    int ans = getMoneyAmount(10);
    cout << endl
         << "Q1:) Get Money Amount : " << ans << endl
         << endl;

    vector<int> arr={6,2,4};
    int ans2 = mctFromLeafValues(arr);
    cout << endl
         << "Q2:) Minimum cost tree from leaf values : " << ans2 << endl
         << endl;
    return 0;
}