#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestCommonSubsequenceUsingRec(string &text1, string &text2, int i, int j)
{
    // Base Case
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }
    int ans;
    if (text1[i] == text2[j])
    {
        ans = 1 + longestCommonSubsequenceUsingRec(text1, text2, i + 1, j + 1);
    }
    else
    {
        int temp1 = 0 + longestCommonSubsequenceUsingRec(text1, text2, i, j + 1);
        int temp2 = 0 + longestCommonSubsequenceUsingRec(text1, text2, i + 1, j);
        ans = max(temp1, temp2);
    }
    int finalAns = ans;
    return finalAns;
}

int longestCommonSubsequenceUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    // Base Case
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans;
    if (text1[i] == text2[j])
    {
        ans = 1 + longestCommonSubsequenceUsingMem(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
        int temp1 = 0 + longestCommonSubsequenceUsingMem(text1, text2, i, j + 1, dp);
        int temp2 = 0 + longestCommonSubsequenceUsingMem(text1, text2, i + 1, j, dp);
        ans = max(temp1, temp2);
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int longestCommonSubsequenceUsingTabulation(string &text1, string &text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // // Base Case    Analysis
    // dp[m-1][n-1] = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                int temp1 = 0 + dp[i][j + 1];
                int temp2 = 0 + dp[i + 1][j];
                ans = max(temp1, temp2);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

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

int longestCommonSubsequence(string text1, string text2)
{
    int i = text1.size();
    int j = text2.size();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    // int ans = longestCommonSubsequenceUsingRec(text1,text2,0,0);

    // int ans = longestCommonSubsequenceUsingMem(text1,text2,0,0,dp);

    // int ans = longestCommonSubsequenceUsingTabulation(text1, text2);

    int ans = longestCommonSubsequenceUsingTabulationSO(text1, text2);

    return ans;
}

int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int ans = longestCommonSubsequenceUsingTabulationSO(s, a);
    return ans;
}

int minDistanceUsingRec(string word1, string word2, int i, int j)
{
    // Base Cases
    if (j == word2.size())
    {
        // only deletion operation can be performed on the rest of the char of word1 so
        return word1.size() - i;
    }
    if (i == word1.size())
    {
        // only deletion operation can be performed on the rest of the char of word2 so
        return word2.size() - j;
    }
    int ans = 0;
    if (word1[i] == word2[j])
    {
        ans = 0 + minDistanceUsingRec(word1, word2, i + 1, j + 1);
    }
    else
    {
        int replace = 1 + minDistanceUsingRec(word1, word2, i + 1, j + 1);
        int insert = 1 + minDistanceUsingRec(word1, word2, i, j + 1);
        int deletion = 1 + minDistanceUsingRec(word1, word2, i + 1, j);
        ans = min(replace, min(insert, deletion));
    }
    int finalAns = ans;
    return finalAns;
}

int minDistanceUsingMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    // Base Cases
    if (j == word2.size())
    {
        // only deletion operation can be performed on the rest of the char of word1 so
        return word1.size() - i;
    }
    if (i == word1.size())
    {
        // only deletion operation can be performed on the rest of the char of word2 so
        return word2.size() - j;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (word1[i] == word2[j])
    {
        dp[i][j] = 0 + minDistanceUsingMem(word1, word2, i + 1, j + 1, dp);
    }
    else
    {
        int replace = 1 + minDistanceUsingMem(word1, word2, i + 1, j + 1, dp);
        int insert = 1 + minDistanceUsingMem(word1, word2, i, j + 1, dp);
        int deletion = 1 + minDistanceUsingMem(word1, word2, i + 1, j, dp);
        dp[i][j] = min(replace, min(insert, deletion));
    }
    return dp[i][j];
}

int minDistanceUsingTabulation(string &a, string &b)
{
    int i = a.size();
    int j = b.size();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    for (int row = 0; row <= i; row++)
    {
        // j means when string"b" ka Size j==b.size()
        // i means when string"a" ka Size i == a.size();
        dp[row][j] = i - row;
    }
    for (int col = 0; col <= j; col++)
    {
        dp[i][col] = j - col;
    }
    for (int a_index = i - 1; a_index >= 0; a_index--)
    {
        for (int b_index = j - 1; b_index >= 0; b_index--)
        {
            if (a[a_index] == b[b_index])
            {
                dp[a_index][b_index] = 0 + dp[a_index + 1][b_index + 1];
            }
            else
            {
                int replace = 1 + dp[a_index + 1][b_index + 1];
                int insert = 1 + dp[a_index][b_index + 1];
                int deletion = 1 + dp[a_index + 1][b_index];
                dp[a_index][b_index] = min(replace, min(insert, deletion));
            }
        }
    }
    return dp[0][0];
}

int minDistanceUsingTabulationSO(string &a, string &b)
{
    int i = a.size();
    int j = b.size();
    vector<int> prev(i + 1, 0);
    vector<int> curr(i + 1, 0);

    for (int row = 0; row <= i; row++)
    {
        // j means when string"b" ka Size j==b.size()
        // i means when string"a" ka Size i == a.size();
        prev[row] = i - row;
    }
    // for(int col=0;col<=j;col++){
    //     curr[col] = j - col;
    // }
    for (int b_index = j - 1; b_index >= 0; b_index--)
    {
        // MOST IMPORTANT LINE
        // CURR ke Last dabbe me Value dalna hrr baar jb curr me puri
        // value fill krke prev of de do uske baad
        curr[i] = j - b_index;
        for (int a_index = i - 1; a_index >= 0; a_index--)
        {

            if (a[a_index] == b[b_index])
            {
                curr[a_index] = 0 + prev[a_index + 1];
            }
            else
            {
                int replace = 1 + prev[a_index + 1];
                int insert = 1 + prev[a_index];
                int deletion = 1 + curr[a_index + 1];
                curr[a_index] = min(replace, min(insert, deletion));
            }
        }
        prev = curr;
    }
    return prev[0];
}

int minDistance(string word1, string word2)
{
    // int ans = minDistanceUsingRec(word1,word2,0,0);
    vector<vector<int>> dp(word1.size(), vector<int>(word2.length(), -1));
    // int ans = minDistanceUsingMem(word1,word2,0,0,dp);
    // int ans = minDistanceUsingTabulation(word1,word2);
    int ans = minDistanceUsingTabulationSO(word1, word2);

    return ans;
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    int ans = longestCommonSubsequence(text1, text2);
    cout << endl
         << "Q1:)  Longest Common Subsequence of \"" << text1 << "\" & \"" << text2 << "\" is : " << ans << endl
         << endl;

    string s = "bbbab";
    int ans2 = longestPalindromeSubseq(s);
    cout << endl
         << "Q2:)  Longest Palindromic Subsequence of String \"" << s << "\" is : " << ans2 << endl
         << endl;

    string word1 = "horse";
    string word2 = "ros";
    int ans3 = minDistance(word1, word2);
    cout << endl
         << "Q3:)  Minimum No. Operation to Convert \"" << word1 << "\" into \"" << word2 << "\" is : " << ans3 << endl
         << endl;
    return 0;
}