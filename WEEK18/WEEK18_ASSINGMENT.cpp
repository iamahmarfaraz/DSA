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

// Q.NO-17     &&     LEETCODE-Q.NO-1671
class MinimumNumberofRemovalstoMakeMountainArray
{
public:
    int lengthOfLISUsingBinarySearch(vector<int> &nums, vector<int> &lis)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        lis.push_back(1);
        // int lastIndex = ans.size()-1;
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            }
            else
            {
                // REplace the lowerbound index element "ans" array with nums[i]
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // Replace
                ans[index] = nums[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> lis;
        vector<int> lds;
        lengthOfLISUsingBinarySearch(nums, lis);
        reverse(nums.begin(), nums.end());
        lengthOfLISUsingBinarySearch(nums, lds);

        int mountain = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
                continue;
            mountain = max(mountain, (lis[i] + lds[nums.size() - i - 1] - 1));
        }
        return nums.size() - mountain;
    }
};

// Q.NO-18      &&     LEETCODE-Q.NO-1187
class MakeArrayStrictlyIncreasing
{
public:
#define INF (1e9 + 1)
    int solve(vector<int> &arr1, vector<int> &arr2, int prev, int curr)
    {
        if (curr >= arr1.size())
            return 0;

        int operation1 = INF;
        if (prev < arr1[curr])
        {
            // no operation
            operation1 = 0 + solve(arr1, arr2, arr1[curr], curr + 1);
        }
        int operation2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end())
        {
            // prev se just bigger arr2 me mil gya
            int indexJustGreaterThanPrev = it - arr2.begin();
            // arr1[i] = arr2[indexJustGreaterThanPrev];  //we dont want to change arr1 original
            // array so see below
            // operation2 = 1 + solve(arr1,arr2,arr1[curr],curr+1);  //instead of this
            operation2 = 1 + solve(arr1, arr2, arr2[indexJustGreaterThanPrev], curr + 1); // this.
        }
        return min(operation1, operation2);
    }

    int solveMemo(vector<int> &arr1, vector<int> &arr2, int prev, int curr, map<pair<int, int>, int> &dp)
    {
        if (curr >= arr1.size())
            return 0;

        if (dp.find({prev, curr}) != dp.end())
        {
            return dp[{prev, curr}];
        }

        int operation1 = INF;
        if (prev < arr1[curr])
        {
            // no operation
            operation1 = 0 + solveMemo(arr1, arr2, arr1[curr], curr + 1, dp);
        }
        int operation2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end())
        {
            // prev se just bigger arr2 me mil gya
            int indexJustGreaterThanPrev = it - arr2.begin();
            // arr1[i] = arr2[indexJustGreaterThanPrev];  //we dont want to change arr1 original
            // array so see below
            // operation2 = 1 + solve(arr1,arr2,arr1[curr],curr+1);  //instead of this
            operation2 = 1 + solveMemo(arr1, arr2, arr2[indexJustGreaterThanPrev], curr + 1, dp); // this.
        }
        return dp[{prev, curr}] = min(operation1, operation2);
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        // int ans =  solve(arr1,arr2,-1,0);
        map<pair<int, int>, int> dp;
        int ans = solveMemo(arr1, arr2, -1, 0, dp);
        return ans == INF ? -1 : ans;
    }
};

// Q.NO-19     &&       LEETCODE-Q.NO-122
class BestTimetoBuyandSellStockII
{
public:
    int solve(vector<int> &prices, int i, int canBuy)
    {
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (canBuy)
        {
            // case1 : buy stock
            int profit1 = -prices[i] + solve(prices, i + 1, 0);
            // case2 : ignore buying stock
            int profit2 = 0 + solve(prices, i + 1, 1);
            profit = max(profit1, profit2);
        }
        else
        {
            // sell stock
            // case3 : sell stock
            int profit3 = prices[i] + solve(prices, i + 1, 1);
            // case4 : ignore selling stock
            int profit4 = solve(prices, i + 1, 0);
            profit = max(profit3, profit4);
        }
        return profit;
    }

    int solveMemo(vector<int> &prices, int i, int canBuy, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy] != -1)
        {
            return dp[i][canBuy];
        }

        int profit = 0;
        if (canBuy)
        {
            // case1 : buy stock
            int profit1 = -prices[i] + solveMemo(prices, i + 1, 0, dp);
            // case2 : ignore buying stock
            int profit2 = 0 + solveMemo(prices, i + 1, 1, dp);
            profit = max(profit1, profit2);
        }
        else
        {
            // sell stock
            // case3 : sell stock
            int profit3 = prices[i] + solveMemo(prices, i + 1, 1, dp);
            // case4 : ignore selling stock
            int profit4 = solveMemo(prices, i + 1, 0, dp);
            profit = max(profit3, profit4);
        }
        return dp[i][canBuy] = profit;
    }

    int solveTab(vector<int> &prices)
    {

        // dp initialized with base case i.e 0 at all element in 2d dp after i>=prices.size()
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    // case1 : buy stock
                    int profit1 = -prices[i] + dp[i + 1][0];
                    // case2 : ignore buying stock
                    int profit2 = 0 + dp[i + 1][1];
                    profit = max(profit1, profit2);
                }
                else
                {
                    // sell stock
                    // case3 : sell stock
                    int profit3 = prices[i] + dp[i + 1][1];
                    // case4 : ignore selling stock
                    int profit4 = dp[i + 1][0];
                    profit = max(profit3, profit4);
                }
                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }

    int solveTabSO(vector<int> &prices)
    {

        // dp initialized with base case i.e 0 at all element in 2d dp after i>=prices.size()
        // vector<vector<int>>dp(prices.size()+1,vector<int>(3,0));

        vector<int> curr(3, 0);
        vector<int> next(3, 0);

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    // case1 : buy stock
                    int profit1 = -prices[i] + next[0];
                    // case2 : ignore buying stock
                    int profit2 = 0 + next[1];
                    profit = max(profit1, profit2);
                }
                else
                {
                    // sell stock
                    // case3 : sell stock
                    int profit3 = prices[i] + next[1];
                    // case4 : ignore selling stock
                    int profit4 = next[0];
                    profit = max(profit3, profit4);
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }

        return curr[1];
    }

    int maxProfit(vector<int> &prices)
    {
        // return solve(prices,0,true);

        // vector<vector<int>>dp(prices.size()+1,vector<int>(3,-1));
        // return solveMemo(prices,0,true,dp);
        // return solveTab(prices);
        return solveTabSO(prices);
    }
};

// Q.NO-20      &&       LEETCODE-Q.NO-123
class BestTimetoBuyandSellStockIII
{
public:
    int solve(vector<int> &prices, int i, int canBuy, int noOfTransaction)
    {
        if (noOfTransaction <= 0)
            return 0;
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (canBuy)
        {
            //  BOUGHT THE STOCK
            int buy1 = -prices[i] + solve(prices, i + 1, 0, noOfTransaction - 1);
            //  IGNORED BUYING STOCK
            int buy2 = 0 + solve(prices, i + 1, 1, noOfTransaction);
            profit = max(buy1, buy2);
        }
        else
        {
            //  SOLD A STOCK
            int sold1 = prices[i] + solve(prices, i + 1, 1, noOfTransaction - 1);
            //  IGNORED SELLING STOCK
            int sold2 = 0 + solve(prices, i + 1, 0, noOfTransaction);
            profit = max(sold1, sold2);
        }
        return profit;
    }

    int solveMem(vector<int> &prices, int i, int canBuy, int noOfTransaction, vector<vector<vector<int>>> &dp)
    {
        if (noOfTransaction <= 0)
            return 0;
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy][noOfTransaction] != -1)
        {
            return dp[i][canBuy][noOfTransaction];
        }

        int profit = 0;
        if (canBuy)
        {
            //  BOUGHT THE STOCK
            int buy1 = -prices[i] + solveMem(prices, i + 1, 0, noOfTransaction - 1, dp);
            //  IGNORED BUYING STOCK
            int buy2 = 0 + solveMem(prices, i + 1, 1, noOfTransaction, dp);
            profit = max(buy1, buy2);
        }
        else
        {
            //  SOLD A STOCK
            int sold1 = prices[i] + solveMem(prices, i + 1, 1, noOfTransaction - 1, dp);
            //  IGNORED SELLING STOCK
            int sold2 = 0 + solveMem(prices, i + 1, 0, noOfTransaction, dp);
            profit = max(sold1, sold2);
        }
        return dp[i][canBuy][noOfTransaction] = profit;
    }

    int solveTab(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(5, 0)));

        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 4; k++)
                {
                    if (j)
                    {
                        //  BOUGHT THE STOCK
                        int buy1 = -prices[i] + dp[i + 1][0][k - 1];
                        //  IGNORED BUYING STOCK
                        int buy2 = 0 + dp[i + 1][1][k];
                        dp[i][j][k] = max(buy1, buy2);
                    }
                    else
                    {
                        //  SOLD A STOCK
                        int sold1 = prices[i] + dp[i + 1][1][k - 1];
                        //  IGNORED SELLING STOCK
                        int sold2 = 0 + dp[i + 1][0][k];
                        dp[i][j][k] = max(sold1, sold2);
                    }
                }
            }
        }

        return dp[0][1][4];
    }

    int solveTabSO(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(5, 0)));
        vector<vector<int>> next(3, vector<int>(5, 0));
        vector<vector<int>> curr(3, vector<int>(5, 0));

        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 4; k++)
                {
                    if (j)
                    {
                        //  BOUGHT THE STOCK
                        int buy1 = -prices[i] + next[0][k - 1];
                        //  IGNORED BUYING STOCK
                        int buy2 = 0 + next[1][k];
                        curr[j][k] = max(buy1, buy2);
                    }
                    else
                    {
                        //  SOLD A STOCK
                        int sold1 = prices[i] + next[1][k - 1];
                        //  IGNORED SELLING STOCK
                        int sold2 = 0 + next[0][k];
                        curr[j][k] = max(sold1, sold2);
                    }
                }
            }
            next = curr;
        }

        return curr[1][4];
    }

    int maxProfit(vector<int> &prices)
    {
        // return solve(prices,0,1,4);
        //  vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(5,-1)));
        //  return solveMem(prices,0,1,4,dp);
        // return solveTab(prices);
        return solveTabSO(prices);
    }
};

// Q.NO-21      &&       LEETCODE-Q.NO-188
class BestTimetoBuyandSellStockIV
{
public:
    int solve(vector<int> &prices, int i, int canBuy, int noOfTransaction)
    {
        if (noOfTransaction <= 0)
            return 0;
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (canBuy)
        {
            //  BOUGHT THE STOCK
            int buy1 = -prices[i] + solve(prices, i + 1, 0, noOfTransaction - 1);
            //  IGNORED BUYING STOCK
            int buy2 = 0 + solve(prices, i + 1, 1, noOfTransaction);
            profit = max(buy1, buy2);
        }
        else
        {
            //  SOLD A STOCK
            int sold1 = prices[i] + solve(prices, i + 1, 1, noOfTransaction - 1);
            //  IGNORED SELLING STOCK
            int sold2 = 0 + solve(prices, i + 1, 0, noOfTransaction);
            profit = max(sold1, sold2);
        }
        return profit;
    }

    int solveMem(vector<int> &prices, int i, int canBuy, int noOfTransaction, vector<vector<vector<int>>> &dp)
    {
        if (noOfTransaction <= 0)
            return 0;
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy][noOfTransaction] != -1)
        {
            return dp[i][canBuy][noOfTransaction];
        }

        int profit = 0;
        if (canBuy)
        {
            //  BOUGHT THE STOCK
            int buy1 = -prices[i] + solveMem(prices, i + 1, 0, noOfTransaction - 1, dp);
            //  IGNORED BUYING STOCK
            int buy2 = 0 + solveMem(prices, i + 1, 1, noOfTransaction, dp);
            profit = max(buy1, buy2);
        }
        else
        {
            //  SOLD A STOCK
            int sold1 = prices[i] + solveMem(prices, i + 1, 1, noOfTransaction - 1, dp);
            //  IGNORED SELLING STOCK
            int sold2 = 0 + solveMem(prices, i + 1, 0, noOfTransaction, dp);
            profit = max(sold1, sold2);
        }
        return dp[i][canBuy][noOfTransaction] = profit;
    }

    int solveTab(vector<int> &prices, int &limit)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>((2 * limit + 1), 0)));

        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= (2 * limit); k++)
                {
                    if (j)
                    {
                        //  BOUGHT THE STOCK
                        int buy1 = -prices[i] + dp[i + 1][0][k - 1];
                        //  IGNORED BUYING STOCK
                        int buy2 = 0 + dp[i + 1][1][k];
                        dp[i][j][k] = max(buy1, buy2);
                    }
                    else
                    {
                        //  SOLD A STOCK
                        int sold1 = prices[i] + dp[i + 1][1][k - 1];
                        //  IGNORED SELLING STOCK
                        int sold2 = 0 + dp[i + 1][0][k];
                        dp[i][j][k] = max(sold1, sold2);
                    }
                }
            }
        }

        return dp[0][1][2 * limit];
    }

    int solveTabSO(vector<int> &prices, int &limit)
    {
        vector<vector<int>> next(3, vector<int>((2 * limit + 1), 0));
        vector<vector<int>> curr(3, vector<int>((2 * limit + 1), 0));

        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= (2 * limit); k++)
                {
                    if (j)
                    {
                        //  BOUGHT THE STOCK
                        int buy1 = -prices[i] + next[0][k - 1];
                        //  IGNORED BUYING STOCK
                        int buy2 = 0 + next[1][k];
                        curr[j][k] = max(buy1, buy2);
                    }
                    else
                    {
                        //  SOLD A STOCK
                        int sold1 = prices[i] + next[1][k - 1];
                        //  IGNORED SELLING STOCK
                        int sold2 = 0 + next[0][k];
                        curr[j][k] = max(sold1, sold2);
                    }
                }
            }
            next = curr;
        }

        return curr[1][(2 * limit)];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // return solve(prices,0,1,2*k);
        //  vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>((2*k+1),-1)));
        //  return solveMem(prices,0,1,2*k,dp);
        //  return solveTab(prices,k);
        return solveTabSO(prices, k);
    }
};

// Q.NO-22     &&      LEETCODE-Q.NO-714
class BestTimetoBuyandSellStockwithTransactionFee
{
public:
    int solve(vector<int> &prices, int i, int canBuy, int &fee)
    {
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (canBuy)
        {
            // BOUGHT STOCK
            int buy1 = -prices[i] + solve(prices, i + 1, 0, fee);
            // IGNORED
            int buy2 = 0 + solve(prices, i + 1, 1, fee);
            profit = max(buy1, buy2);
        }
        else
        {
            // SOLD THE STOCK
            int sold1 = prices[i] - fee + solve(prices, i + 1, 1, fee);
            // IGNORED
            int sold2 = 0 + solve(prices, i + 1, 0, fee);
            profit = max(sold1, sold2);
        }
        return profit;
    }

    int solveMem(vector<int> &prices, int i, int canBuy, int &fee, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy] != -1)
        {
            return dp[i][canBuy];
        }

        int profit = 0;
        if (canBuy)
        {
            // BOUGHT STOCK
            int buy1 = -prices[i] + solveMem(prices, i + 1, 0, fee, dp);
            // IGNORED
            int buy2 = 0 + solveMem(prices, i + 1, 1, fee, dp);
            profit = max(buy1, buy2);
        }
        else
        {
            // SOLD THE STOCK
            int sold1 = prices[i] - fee + solveMem(prices, i + 1, 1, fee, dp);
            // IGNORED
            int sold2 = 0 + solveMem(prices, i + 1, 0, fee, dp);
            profit = max(sold1, sold2);
        }
        return dp[i][canBuy] = profit;
    }

    int solveTab(vector<int> &prices, int &fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                if (canBuy)
                {
                    // BOUGHT STOCK
                    int buy1 = -prices[i] + dp[i + 1][0];
                    // IGNORED
                    int buy2 = 0 + dp[i + 1][1];
                    dp[i][canBuy] = max(buy1, buy2);
                }
                else
                {
                    // SOLD THE STOCK
                    int sold1 = prices[i] - fee + dp[i + 1][1];
                    // IGNORED
                    int sold2 = 0 + dp[i + 1][0];
                    dp[i][canBuy] = max(sold1, sold2);
                }
            }
        }

        return dp[0][1];
    }

    int solveTabSO(vector<int> &prices, int &fee)
    {
        vector<int> next(3, 0);
        vector<int> curr(3, 0);

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                if (canBuy)
                {
                    // BOUGHT STOCK
                    int buy1 = -prices[i] + next[0];
                    // IGNORED
                    int buy2 = 0 + next[1];
                    curr[canBuy] = max(buy1, buy2);
                }
                else
                {
                    // SOLD THE STOCK
                    int sold1 = prices[i] - fee + next[1];
                    // IGNORED
                    int sold2 = 0 + next[0];
                    curr[canBuy] = max(sold1, sold2);
                }
            }
            next = curr;
        }

        return curr[1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        // return solve(prices,0,1,fee);
        //  vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solveMem(prices,0,1,fee,dp);
        //  return solveTab(prices,fee);
        return solveTabSO(prices, fee);
    }
};

// Q.NO-23        &&         LEETCODE-Q.NO-494
class TargetSum
{
public:
    int solve(vector<int> &nums, int i, int target)
    {
        if (i >= nums.size())
        {
            return target == 0 ? 1 : 0;
        }

        int plus = solve(nums, i + 1, target - nums[i]);
        int minus = solve(nums, i + 1, target + nums[i]);

        return plus + minus;
    }

    int solveMem(vector<int> &nums, int i, int sum, int &target, unordered_map<string, int> &memo)
    {
        if (i >= nums.size())
        {
            return sum == target ? 1 : 0;
        }

        // Create a unique key for the current state
        string key = to_string(i) + "," + to_string(sum);

        // Check if the result is already computed
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        int plus = solveMem(nums, i + 1, sum + nums[i], target, memo);
        int minus = solveMem(nums, i + 1, sum - nums[i], target, memo);

        return memo[key] = plus + minus;
    }

    int solveMemo2(vector<int> &nums, int i, int target, map<pair<int, int>, int> &dp)
    {
        if (i >= nums.size())
        {
            return target == 0 ? 1 : 0;
        }

        if (dp.find({i, target}) != dp.end())
        {
            return dp[{i, target}];
        }

        int plus = solveMemo2(nums, i + 1, target - nums[i], dp);
        int minus = solveMemo2(nums, i + 1, target + nums[i], dp);

        return dp[{i, target}] = plus + minus;
    }

    int solveTab(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        dp[{nums.size(), 0}] = 1;

        int total = 0;
        for (auto num : nums)
        {
            total += num;
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int sum = -total; sum <= total; sum++)
            {
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end() ? dp[{i + 1, sum - nums[i]}] : 0;
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end() ? dp[{i + 1, sum + nums[i]}] : 0;
                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        // return solve(nums,0,target);
        //  unordered_map<string, int> memo;
        //  return solveMem(nums,0,0,target,memo);
        //  map<pair<int,int>,int>dp;
        //  return solveMemo2(nums,0,target,dp);
        return solveTab(nums, target);
    }
};

// Q.NO-24     &&       LEETCODE-Q.NO-474
class OnesandZeroes
{
public:
    int solve(vector<string> &strs, int i, int m, int n, unordered_map<int, pair<int, int>> &count)
    {
        if (i >= strs.size() || (m == 0 && n == 0))
            return 0;

        int inc = 0;
        int one = count[i].first;
        int zero = count[i].second;
        if (m >= zero && n >= one)
        {
            inc = 1 + solve(strs, i + 1, m - zero, n - one, count);
        }
        int excl = 0 + solve(strs, i + 1, m, n, count);

        return inc > excl ? inc : excl;
    }

    int solveMem(vector<string> &strs, int i, int m, int n, unordered_map<int, pair<int, int>> &count, vector<vector<vector<int>>> &dp)
    {
        if (i >= strs.size() || (m == 0 && n == 0))
            return 0;

        if (dp[i][m][n] != -1)
        {
            return dp[i][m][n];
        }

        int inc = 0;
        int one = count[i].first;
        int zero = count[i].second;
        if (m >= zero && n >= one)
        {
            inc = 1 + solveMem(strs, i + 1, m - zero, n - one, count, dp);
        }
        int excl = 0 + solveMem(strs, i + 1, m, n, count, dp);

        return dp[i][m][n] = inc > excl ? inc : excl;
    }

    int solveTab(vector<string> &strs, int m_Count, int n_Count, unordered_map<int, pair<int, int>> &count)
    {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m_Count + 1, vector<int>(n_Count + 1, 0)));

        for (int i = strs.size() - 1; i >= 0; i--)
        {
            int one = count[i].first;
            int zero = count[i].second;
            for (int m = m_Count; m >= 0; m--)
            {
                for (int n = n_Count; n >= 0; n--)
                {
                    int inc = 0;
                    if (m >= zero && n >= one)
                    {
                        inc = 1 + dp[i + 1][m - zero][n - one];
                    }
                    int excl = 0 + dp[i + 1][m][n];
                    dp[i][m][n] = inc > excl ? inc : excl;
                }
            }
        }

        return dp[0][m_Count][n_Count];
    }

    int solveTabSO(vector<string> &strs, int m_Count, int n_Count, unordered_map<int, pair<int, int>> &count)
    {
        vector<vector<int>> curr(m_Count + 1, vector<int>(n_Count + 1, 0));
        vector<vector<int>> next(m_Count + 1, vector<int>(n_Count + 1, 0));

        for (int i = strs.size() - 1; i >= 0; i--)
        {
            int one = count[i].first;
            int zero = count[i].second;
            for (int m = m_Count; m >= 0; m--)
            {
                for (int n = n_Count; n >= 0; n--)
                {
                    int inc = 0;
                    if (m >= zero && n >= one)
                    {
                        inc = 1 + next[m - zero][n - one];
                    }
                    int excl = 0 + next[m][n];
                    curr[m][n] = inc > excl ? inc : excl;
                }
            }
            next = curr;
        }

        return curr[m_Count][n_Count];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        unordered_map<int, pair<int, int>> count; // count[index] = {1's count,0's count}
        for (int i = 0; i < strs.size(); i++)
        {
            int zeros = 0, ones = 0;
            for (auto ch : strs[i])
            {
                int temp = ch - '0';
                if (temp == 0)
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }
            count[i] = {ones, zeros};
        }
        // return solve(strs,0,m,n,count);
        //  vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        // return solveMem(strs,0,m,n,count,dp);
        // return solveTab(strs,m,n,count);
        return solveTabSO(strs, m, n, count);
    }
};

// Q.NO-25        &&       LEETCODE-Q.NO-801
class MinimumSwapsToMakeSequencesIncreasing
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int prev1, int prev2)
    {
        if (i >= nums1.size())
            return 0;

        int swap = INT_MAX, noSwap = INT_MAX;
        if (prev1 < nums2[i] && prev2 < nums1[i])
        {
            // Case where swap kiya tb koi problem nhi hoga
            // will handle both the swap case of (i) increasing subseq
            // (ii) increasing subseq is discontinuing
            swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
        }
        // noSwap - only if its following increasing subsequence pattern
        // else if its not then if we go for noSwap then increasing subsequence
        // pattern is continue to be ruined
        if (prev1 < nums1[i] && prev2 < nums2[i])
        {
            noSwap = 0 + solve(nums1, nums2, i + 1, nums1[i], nums2[i]);
        }
        return min(swap, noSwap);
    }

    int solveMem(vector<int> &nums1, vector<int> &nums2, int i, int prev1, int prev2, vector<vector<int>> &dp, int isSwap)
    {
        if (i >= nums1.size())
            return 0;

        if (dp[i][isSwap] != -1)
        {
            return dp[i][isSwap];
        }

        int swap = INT_MAX, noSwap = INT_MAX;
        if (prev1 < nums2[i] && prev2 < nums1[i])
        {

            swap = 1 + solveMem(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
        }

        if (prev1 < nums1[i] && prev2 < nums2[i])
        {
            noSwap = 0 + solveMem(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        }
        return dp[i][isSwap] = min(swap, noSwap);
    }

    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

        for (int i = nums1.size() - 1; i >= 1; i--)
        {
            for (int j = 1; j >= 0; j--)
            {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];
                if (j)
                {
                    swap(prev1, prev2);
                }
                int swap = INT_MAX, noSwap = INT_MAX;
                if (prev1 < nums2[i] && prev2 < nums1[i])
                {

                    swap = 1 + dp[i + 1][1];
                }

                if (prev1 < nums1[i] && prev2 < nums2[i])
                {
                    noSwap = 0 + dp[i + 1][0];
                }
                dp[i][j] = min(swap, noSwap);
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // return solve(nums1,nums2,0,-1,-1);
        // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1)); //dp[i][swap or noSwap]
        // return solveMem(nums1,nums2,0,-1,-1,dp,0);

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveTab(nums1, nums2);
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