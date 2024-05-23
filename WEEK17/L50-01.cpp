#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solveUsingMem(int n, vector<int> &dp)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return n;
    }
    // Step3: if ans already exist then return the ans without processing
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // Step2: Store and return using DP
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
    return dp[n];
}
int fib(int n)
{
    // Step1: Create DP Array
    vector<int> dp(n + 1, -1);
    return solveUsingMem(n, dp);
}

// tabulation method
int solveUsingTabulation(int n)
{
    // step1: create dp array
    vector<int> dp(n + 1, -1);
    // step2: analyse base case and fill dp array
    dp[0] = 0;
    if (n == 0)
    {
        return 0;
    }
    dp[1] = 1;
    // step3: fill the remaingin dp array
    // array size = n+1
    // index move from 0 to n
    // 0 and 1 index ko already fill krlia h
    // 2 index se n index tak abhi filled nahi h
    for (int index = 2; index <= n; index++)
    {
        // copy paste karo recursive logic ko
        // repalce recursive calls  with dp array
        // make sure dp array is using looping variable
        dp[index] = dp[index - 1] + dp[index - 2];
    }
    // return ans;
    return dp[n];
}

int solveUsingTabulationSpaceOptimised(int n)
{
    int prev = 0;
    if (n == 0)
    {
        return 0;
    }
    int curr = 1;
    if (n == 1)
    {
        return 1;
    }
    int ans;
    for (int index = 2; index <= n; index++)
    {
        ans = curr + prev;
        // prev and curr ko ek step aage move krna
        prev = curr;
        curr = ans;
    }
    // return ans;
    return ans;
}

int main()
{
    int n = 4;
    int ans = fib(n);
    return 0;
}