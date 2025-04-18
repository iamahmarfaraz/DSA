#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q.NO-1   &&    LEETCODE-Q.N0-279
class PerfectSquares
{
public:
    // Top-Down
    int squareHelperMemo(int n, vector<int> &dp)
    {
        // Base Case
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int i = 1;
        int end = sqrt(n);
        int finalans = INT_MAX;
        while (i <= end)
        {
            int perfectSquare = i * i;
            int ans = 1 + squareHelperMemo(n - perfectSquare, dp);
            if (ans < finalans)
            {
                finalans = ans;
            }
            i++;
        }
        dp[n] = finalans;
        return dp[n];
    }

    int squareHelperTab(int n, vector<int> &dp)
    {
        // Base Case
        // if(n == 1)return 1;
        // if(n==0)return 0;
        // if(dp[n] != -1){
        //     return dp[n];
        // }

        // initial condition according to the base case
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int start = 1;
            int end = sqrt(i);
            int finalans = INT_MAX;
            while (start <= end)
            {
                int perfectSquare = start * start;
                int ans = 1 + dp[i - perfectSquare];
                if (ans < finalans)
                {
                    finalans = ans;
                }
                start++;
            }
            dp[i] = finalans;
        }

        return dp[n];
    }

    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        // return squareHelperMemo(n,dp);
        return squareHelperTab(n, dp);
    }
};

// Q.NO-2    &&    LEETCODE-Q.NO-983
int t[366];
class MinimumCostForTickets
{
public:
    int memoized(vector<int> &days, vector<int> &costs, int &n, int idx)
    {
        if (idx >= n)
            return 0; // you can't travel, so no cost

        if (t[idx] != -1)
            return t[idx];

        // if i take 1-day pass at idx
        int cost_1 = costs[0] + memoized(days, costs, n, idx + 1);

        // if i take 7-day pass at idx
        int i = idx;
        while (i < n && days[i] < days[idx] + 7)
        {
            i++;
        }
        int cost_7 = costs[1] + memoized(days, costs, n, i);

        // if i take 30-day pass at idx
        int j = idx;
        while (j < n && days[j] < days[idx] + 30)
        {
            j++;
        }
        int cost_30 = costs[2] + memoized(days, costs, n, j);

        return t[idx] = min(cost_1, min(cost_7, cost_30));
    }
    int tabulation(vector<int> &days, vector<int> &costs, int &n, int idx)
    {
        // if(idx >= n)
        //     return 0; //you can't travel, so no cost

        // if(t[idx] != -1)
        //     return t[idx];

        // initial value according to base condition
        t[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            // if i take 1-day pass at idx
            int cost_1 = costs[0] + t[i + 1];

            // if i take 7-day pass at idx
            int idx = i;
            while (idx < n && days[idx] < days[i] + 7)
            {
                idx++;
            }
            int cost_7 = costs[1] + t[idx];

            // if i take 30-day pass at idx
            idx = i;
            while (idx < n && days[idx] < days[i] + 30)
            {
                idx++;
            }
            int cost_30 = costs[2] + t[idx];

            t[i] = min(cost_1, min(cost_7, cost_30));
        }

        return t[0];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        memset(t, -1, sizeof(t));
        int n = days.size();
        // return memoized(days, costs, n, 0);
        return tabulation(days, costs, n, 0);
    }
};

// Q.NO-3    &&    LEETCODE-Q.NO-712
class MinimumASCII
{
public:
    int helper(string &s1, string &s2, int s1Pointer, int s2Pointer)
    {
        // Base cases
        if (s1 == s2)
        {
            return 0;
        }
        if (s1Pointer >= s1.size())
        {
            int cost = 0;
            while (s2Pointer < s2.size())
            {
                char ch = s2[s2Pointer];
                cost += int(ch);
                s2Pointer++;
            }
            return cost;
        }
        if (s2Pointer >= s2.size())
        {
            int cost = 0;
            while (s1Pointer < s1.size())
            {
                char ch = s1[s1Pointer];
                cost += int(ch);
                s1Pointer++;
            }
            return cost;
        }

        int ans = 0;

        // recurssion
        if (s1[s1Pointer] == s2[s2Pointer])
        {
            ans = 0 + helper(s1, s2, s1Pointer + 1, s2Pointer + 1);
        }
        else
        {
            // case1:remove s1's char
            int case1 = int(s1[s1Pointer]) + helper(s1, s2, s1Pointer + 1, s2Pointer);
            // case2:remove s2's char
            int case2 = int(s2[s2Pointer]) + helper(s1, s2, s1Pointer, s2Pointer + 1);
            ans = min(case1, case2);
        }
        return ans;
    }

    int helpermemo(string &s1, string &s2, int s1Pointer, int s2Pointer, vector<vector<int>> &dp)
    {
        // Base cases
        if (s1 == s2)
        {
            return 0;
        }
        if (s1Pointer >= s1.size())
        {
            int cost = 0;
            while (s2Pointer < s2.size())
            {
                char ch = s2[s2Pointer];
                cost += int(ch);
                s2Pointer++;
            }
            return cost;
        }
        if (s2Pointer >= s2.size())
        {
            int cost = 0;
            while (s1Pointer < s1.size())
            {
                char ch = s1[s1Pointer];
                cost += int(ch);
                s1Pointer++;
            }
            return cost;
        }

        if (dp[s1Pointer][s2Pointer] != -1)
        {
            return dp[s1Pointer][s2Pointer];
        }

        int ans = 0;

        // recurssion
        if (s1[s1Pointer] == s2[s2Pointer])
        {
            ans = 0 + helpermemo(s1, s2, s1Pointer + 1, s2Pointer + 1, dp);
        }
        else
        {
            // case1:remove s1's char
            int case1 = int(s1[s1Pointer]) + helpermemo(s1, s2, s1Pointer + 1, s2Pointer, dp);
            // case2:remove s2's char
            int case2 = int(s2[s2Pointer]) + helpermemo(s1, s2, s1Pointer, s2Pointer + 1, dp);
            ans = min(case1, case2);
        }
        dp[s1Pointer][s2Pointer] = ans;
        return dp[s1Pointer][s2Pointer];
    }

    int helperTab(string &s1, string &s2)
    {
        // Base cases
        // if(s1 == s2){
        //     return 0;
        // }
        // if(s1Pointer >= s1.size()){
        //     int cost = 0;
        //     while(s2Pointer < s2.size()){
        //         char ch = s2[s2Pointer];
        //         cost += int(ch);
        //         s2Pointer++;
        //     }
        //     return cost;
        // }
        // if(s2Pointer >= s2.size()){
        //     int cost = 0;
        //     while(s1Pointer < s1.size()){
        //         char ch = s1[s1Pointer];
        //         cost += int(ch);
        //         s1Pointer++;
        //     }
        //     return cost;
        // }

        // if(dp[s1Pointer][s2Pointer] != -1){
        //     return dp[s1Pointer][s2Pointer];
        // }

        // initialize according to base case
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize base cases
        for (int i = m - 1; i >= 0; i--)
        {
            dp[i][n] = int(s1[i]) + dp[i + 1][n];
        }

        for (int j = n - 1; j >= 0; j--)
        {
            dp[m][j] = int(s2[j]) + dp[m][j + 1];
        }

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                int ans = 0;

                // recurssion
                if (s1[i] == s2[j])
                {
                    ans = 0 + dp[i + 1][j + 1];
                }
                else
                {
                    // case1:remove s1's char
                    int case1 = int(s1[i]) + dp[i + 1][j];
                    // case2:remove s2's char
                    int case2 = int(s2[j]) + dp[i][j + 1];
                    ans = min(case1, case2);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        // return helper(s1,s2,0,0);
        // return helpermemo(s1,s2,0,0,dp);
        return helperTab(s1, s2);
    }
};

// Q.NO-4     &&     LEETCODE-Q.NO-5
class LongestPalindromicSubstring
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        if (start >= end)
        {
            return true;
        }
        if (s[start] != s[end])
        {
            return false;
        }
        bool ans = isPalindrome(s, start + 1, end - 1);
        return ans;
    }
    bool isPalindromeMem(string &s, int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
        {
            return true;
        }
        if (s[start] != s[end])
        {
            return false;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        dp[start][end] = isPalindromeMem(s, start + 1, end - 1, dp);
        return dp[start][end];
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isPalindromeMem(s, i, j, dp))
                {
                    string t = s.substr(i, j - i + 1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};

// Q.NO-5      &&      LEETCODE-Q.NO-115
class DistinctSubsequences
{
public:
    int helper(string &s, string &t, int i, int j)
    {
        if (j == t.size())
            return 1; // matched full t
        if (i == s.size())
            return 0; // s finished but t not

        int count = 0;
        if (s[i] == t[j])
        {
            count += helper(s, t, i + 1, j + 1); // match
        }
        count += helper(s, t, i + 1, j); // skip s[i]

        return count;
    }

    int helperMemo(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == t.size())
            return 1; // matched full t
        if (i == s.size())
            return 0; // s finished but t not

        if (dp[i][j] != -1)
            return dp[i][j];

        int count = 0;
        if (s[i] == t[j])
        {
            count += helperMemo(s, t, i + 1, j + 1, dp); // match
        }
        count += helperMemo(s, t, i + 1, j, dp); // skip s[i]

        return dp[i][j] = count;
    }

    unsigned long long helperTab(string &s, string &t)
    {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[i][n] = 1; // base case: empty t
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j])
                {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }

    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return helper(s, t, 0, 0);
        // return helperMemo(s, t, 0, 0, dp);
        return (int)helperTab(s, t);
    }
};

// Q.NO-6       &&      LEETCODE-Q.NO-139
class WordBreak
{
public:
    bool check(vector<string> &wordDict, string &word)
    {
        for (auto it : wordDict)
        {
            if (it == word)
                return true;
        }
        return false;
    }

    bool solve(string &s, vector<string> &wordDict, int start)
    {
        if (start == s.size())
            return true;

        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (check(wordDict, word))
            {
                flag = flag || (solve(s, wordDict, i + 1));
            }
        }
        return flag;
    }

    bool solveMemo(string &s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        if (start == s.size())
            return true;

        if (dp[start] != -1)
        {
            return dp[start];
        }

        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (check(wordDict, word))
            {
                flag = flag || (solveMemo(s, wordDict, i + 1, dp));
            }
        }
        dp[start] = flag;
        return flag;
    }

    bool solveTab(string &s, vector<string> &wordDict)
    {

        vector<bool> dp(s.size() + 1, false);

        dp[s.size()] = true;

        for (int idx = s.size() - 1; idx >= 0; idx--)
        {
            string word = "";
            bool flag = false;
            for (int i = idx; i < s.size(); i++)
            {
                word += s[i];
                if (check(wordDict, word))
                {
                    flag = flag || dp[i + 1];
                }
            }
            dp[idx] = flag;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        // return solve(s, wordDict, 0);
        vector<int> dp(s.size() + 1, -1);
        // return solveMemo(s, wordDict, 0,dp);
        return solveTab(s, wordDict);
    }
};

// Q.NO-7     &&      LEETCODE-Q.NO-140
class WordBreakII
{
public:
    vector<string> solve(string &s, unordered_map<string, bool> &mp, int start)
    {
        if (start == s.size())
            return {""};

        vector<string> ans;
        string word;

        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (mp.find(word) == mp.end())
                continue;

            // found a valid word
            auto rightPart = solve(s, mp, i + 1);
            for (auto eachRightPart : rightPart)
            {
                string endPart;
                if (eachRightPart.size() > 0)
                {
                    endPart = " " + eachRightPart;
                }
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    vector<string> solveMemo(string &s, unordered_map<string, bool> &mp, int start, unordered_map<int, vector<string>> &dp)
    {
        if (start == s.size())
            return {""};

        if (dp.find(start) != dp.end())
        {
            return dp[start];
        }

        vector<string> ans;
        string word;

        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (mp.find(word) == mp.end())
                continue;

            // found a valid word
            auto rightPart = solveMemo(s, mp, i + 1, dp);
            for (auto eachRightPart : rightPart)
            {
                string endPart;
                if (eachRightPart.size() > 0)
                {
                    endPart = " " + eachRightPart;
                }
                ans.push_back(word + endPart);
            }
        }
        dp[start] = ans;
        return ans;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> mp;
        for (auto word : wordDict)
        {
            mp[word] = true;
        }

        unordered_map<int, vector<string>> dp;

        // return solve(s,mp,0);
        return solveMemo(s, mp, 0, dp);
    }
};

// Q.NO-8     &&      LEETCODE-Q.NO-95
class UniqueBinarySearchTreesII
{
public:
    vector<TreeNode *> solve(int start, int end)
    {
        if (start > end)
            return {nullptr}; // Important: return vector with a single `nullptr`

        vector<TreeNode *> ans;

        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> leftSubtrees = solve(start, i - 1);
            vector<TreeNode *> rightSubtrees = solve(i + 1, end);

            for (auto left : leftSubtrees)
            {
                for (auto right : rightSubtrees)
                {
                    TreeNode *root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> solveMemo(int start, int end, unordered_map<string, vector<TreeNode *>> &dp)
    {
        if (start > end)
            return {nullptr}; // Important: return vector with a single `nullptr`

        string key = to_string(start) + "," + to_string(end);

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }

        vector<TreeNode *> ans;

        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> leftSubtrees = solve(start, i - 1);
            vector<TreeNode *> rightSubtrees = solve(i + 1, end);

            for (auto left : leftSubtrees)
            {
                for (auto right : rightSubtrees)
                {
                    TreeNode *root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
        }

        dp[key] = ans;
        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        unordered_map<string, vector<TreeNode *>> dp;
        // return solve(1, n);
        return solveMemo(1, n, dp);
    }
};

// Q.NO-9      &&     LEETCODE-Q.NO-337
class HouseRobberIII
{
public:
    unordered_map<TreeNode *, int> dp;
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;

        // Option to rob this node
        int include = root->val;

        if (root->left)
        {
            include += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right)
        {
            include += solve(root->right->left) + solve(root->right->right);
        }

        // don't rob the house
        int exclude = solve(root->left) + solve(root->right);

        return max(include, exclude);
    }

    int solveMemo(TreeNode *root)
    {
        if (!root)
            return 0;

        if (dp.find(root) != dp.end())
        {
            return dp[root];
        }

        // Option to rob this node
        int include = root->val;

        if (root->left)
        {
            include += solveMemo(root->left->left) + solveMemo(root->left->right);
        }
        if (root->right)
        {
            include += solveMemo(root->right->left) + solveMemo(root->right->right);
        }

        // don't rob the house
        int exclude = solveMemo(root->left) + solveMemo(root->right);

        return dp[root] = max(include, exclude);
    }

    int rob(TreeNode *root)
    {
        // return solve(root);
        return solveMemo(root);
    }
};

// Q.NO-10     &&      LEETCODE-Q.NO-877
class StoneGame
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};

// Q.NO-11     &&      LEETCODE-Q.NO-1140
class StoneGameII
{
public:
    int solve(vector<int> &piles, int idx, int M, bool aliceTurn)
    {
        if (idx == piles.size())
            return 0;

        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int total = 0;
        for (int X = 1; X <= 2 * M; X++)
        {
            if (idx + X - 1 >= piles.size())
                break;
            total += piles[idx + X - 1];
            if (aliceTurn)
            {
                ans = max(ans, total + solve(piles, idx + X, max(M, X), !aliceTurn));
            }
            else
            {
                ans = min(ans, solve(piles, idx + X, max(M, X), !aliceTurn));
            }
        }

        return ans;
    }

    int solveMemo(vector<int> &piles, int idx, int M, bool aliceTurn, vector<vector<vector<int>>> &dp)
    {
        if (idx == piles.size())
            return 0;

        if (dp[idx][M][aliceTurn] != -1)
        {
            return dp[idx][M][aliceTurn];
        }

        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int total = 0;
        for (int X = 1; X <= 2 * M; X++)
        {
            if (idx + X - 1 >= piles.size())
                break;
            total += piles[idx + X - 1];
            if (aliceTurn)
            {
                ans = max(ans, total + solveMemo(piles, idx + X, max(M, X), !aliceTurn, dp));
            }
            else
            {
                ans = min(ans, solveMemo(piles, idx + X, max(M, X), !aliceTurn, dp));
            }
        }

        dp[idx][M][aliceTurn] = ans;

        return ans;
    }

    int solveTab(vector<int> &piles)
    {
        int n = piles.size();

        // Increase 2nd dimension to handle max(j, X) safely
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = n; M >= 1; M--)
            {
                for (int k = 1; k >= 0; k--)
                {
                    int ans = k ? INT_MIN : INT_MAX;
                    int total = 0;
                    for (int X = 1; X <= 2 * M; X++)
                    {
                        if (i + X > n)
                            break;
                        total += piles[i + X - 1];
                        int nextM = max(M, X);
                        if (k)
                        {
                            ans = max(ans, total + dp[i + X][nextM][!k]);
                        }
                        else
                        {
                            ans = min(ans, dp[i + X][nextM][!k]);
                        }
                    }
                    dp[i][M][k] = ans;
                }
            }
        }

        return dp[0][1][1];
    }

    int stoneGameII(vector<int> &piles)
    {
        // return solve(piles,0,1,true);
        // vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        // return solveMemo(piles,0,1,true,dp);
        return solveTab(piles);
    }
};

// Q.NO-12      &&      LEETCODE-Q.NO-1406
class Solution
{
public:
    int solve(int i, vector<int> &stone)
    {
        if (i >= stone.size())
            return 0;

        int sum = 0;
        int maxDiff = INT_MIN;

        for (int k = 0; k < 3 && i + k < stone.size(); ++k)
        {
            sum += stone[i + k];
            maxDiff = max(maxDiff, sum - solve(i + k + 1, stone));
        }

        return maxDiff;
    }

    int solveMemo(int i, vector<int> &stone, vector<int> &dp)
    {
        if (i >= stone.size())
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int maxDiff = INT_MIN;

        for (int k = 0; k < 3 && i + k < stone.size(); ++k)
        {
            sum += stone[i + k];
            maxDiff = max(maxDiff, sum - solveMemo(i + k + 1, stone, dp));
        }

        return dp[i] = maxDiff;
    }

    int solveTab(vector<int> &stone)
    {
        vector<int> dp(stone.size() + 1, 0);

        for (int i = stone.size() - 1; i >= 0; i--)
        {
            int sum = 0;
            int maxDiff = INT_MIN;

            for (int k = 0; k < 3 && i + k < stone.size(); ++k)
            {
                sum += stone[i + k];
                maxDiff = max(maxDiff, sum - dp[i + k + 1]);
            }
            dp[i] = maxDiff;
        }

        return dp[0];
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        // int diff = solve(0, stoneValue);
        // int diff = solveMemo(0, stoneValue, dp);
        int diff = solveTab(stoneValue);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};

// Q.NO-13     &&     LEETCODE-Q.NO-312
class BurstBalloons
{
public:
    int solve(vector<int> &nums, int left, int right)
    {
        if (left + 1 == right)
            return 0; // No balloon to burst between left and right

        int maxCoins = 0;
        for (int i = left + 1; i < right; ++i)
        {
            int coins = nums[left] * nums[i] * nums[right];
            coins += solve(nums, left, i) + solve(nums, i, right);
            maxCoins = max(maxCoins, coins);
        }

        return maxCoins;
    }

    int solveMemo(vector<int> &nums, int left, int right, vector<vector<int>> &dp)
    {
        if (left + 1 == right)
            return 0; // No balloon to burst between left and right

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int maxCoins = 0;
        for (int i = left + 1; i < right; ++i)
        {
            int coins = nums[left] * nums[i] * nums[right];
            coins += solveMemo(nums, left, i, dp) + solveMemo(nums, i, right, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[left][right] = maxCoins;
    }

    int maxCoins(vector<int> &nums)
    {
        // Insert virtual boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // return solve(nums, 0, nums.size() - 1);
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        return solveMemo(nums, 0, nums.size() - 1, dp);
    }
};

// Q.NO-14     &&      LEETCODE-Q.NO-97
class InterleavingString
{
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        bool flag = false;
        if ((i < s1.size()) && s1[i] == s3[k])
        {
            flag = flag || solve(s1, s2, s3, i + 1, j, k + 1);
        }
        if ((j < s2.size()) && s2[j] == s3[k])
        {
            flag = flag || solve(s1, s2, s3, i, j + 1, k + 1);
        }
        return flag;
    }

    bool solveMemo(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;
        if (k == s3.size())
            return false;

        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        bool flag = false;
        if ((i < s1.size()) && s1[i] == s3[k])
        {
            flag = flag || solveMemo(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if ((j < s2.size()) && s2[j] == s3[k])
        {
            flag = flag || solveMemo(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j][k] = flag;
    }

    bool solveTab(string &s1, string &s2, string &s3)
    {
        vector<vector<vector<bool>>> dp(s1.size() + 1, vector<vector<bool>>(s2.size() + 1, vector<bool>(s3.size() + 1, false)));

        // initialize value according to base case
        dp[s1.size()][s2.size()][s3.size()] = true;

        for (int i = s1.size(); i >= 0; i--)
        {
            for (int j = s2.size(); j >= 0; j--)
            {
                for (int k = s3.size() - 1; k >= 0; k--)
                {
                    bool flag = false;
                    if ((i < s1.size()) && s1[i] == s3[k])
                    {
                        flag = flag || dp[i + 1][j][k + 1];
                    }
                    if ((j < s2.size()) && s2[j] == s3[k])
                    {
                        flag = flag || dp[i][j + 1][k + 1];
                    }
                    dp[i][j][k] = flag;
                }
            }
        }

        return dp[0][0][0];
    }

    bool isInterleave(string &s1, string &s2, string &s3)
    {
        // return solve(s1,s2,s3,0,0,0);
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        // return solveMemo(s1,s2,s3,0,0,0,dp);
        return solveTab(s1, s2, s3);
    }
};

// Q.NO-15     &&      LEETCODE-Q.NO-1312
class Solution
{
public:
    int longestCommonSubsequenceUsingTabulationSO(string &text1, string &text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(m + 1, 0); //"m" isley liya cause row wise array bnana tha
        vector<int> curr(m + 1, 0);

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                {
                    ans = 1 + prev[i + 1];
                }
                else
                {
                    int temp1 = 0 + prev[i];
                    int temp2 = 0 + curr[i + 1];
                    ans = max(temp1, temp2);
                }
                curr[i] = ans;
            }
            prev = curr;
        }
        return prev[0];
    }
    int minInsertions(string s)
    {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = longestCommonSubsequenceUsingTabulationSO(s, a);
        return (s.size() - ans);
    }
};

// Q.NO-16      &&     LEETCODE-Q.NO-354
class RussianDollEnvelopes
{
public:
    int lengthOfLISUsingBinarySearch(vector<vector<int>> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0][1]); // use height instead of width
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (nums[i][1] > ans.back())
            {
                ans.push_back(nums[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // Custom sort
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
             {
            //return whoever's width is greater and if widths are equal then
            //return based on height
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0]; });
        return lengthOfLISUsingBinarySearch(envelopes);
    }
};

int main()
{
    PerfectSquares *ans1 = new PerfectSquares();
    int sol1 = ans1->numSquares(13);
    cout << "ANSWER OF Q1 :- " << sol1 << endl;

    MinimumCostForTickets *ans2 = new MinimumCostForTickets();
    vector<int> days;
    days.push_back(1);
    days.push_back(4);
    days.push_back(6);
    days.push_back(7);
    days.push_back(8);
    days.push_back(20);

    vector<int> costs;
    costs.push_back(2);
    costs.push_back(7);
    costs.push_back(15);

    int sol2 = ans2->mincostTickets(days, costs);
    cout << "ANSWER OF Q2 :- " << sol2 << endl;

    return 0;
}