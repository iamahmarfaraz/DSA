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