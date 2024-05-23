#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int s, int e)
{
    // base case
    if (s > e)
    {
        return 0;
    }

    // chori karlo -> ith index pr
    int option1 = nums[s] + solve(nums, s + 2, e);

    // chori mat karo  -> ith index pr
    int option2 = 0 + solve(nums, s + 1, e);

    int finalAns = max(option1, option2);
    return finalAns;
}

int rob2(vector<int> &arr)
{
    int size = arr.size();
    // yha pe glti karoge
    if (size == 1)
    {
        // we handled single house case seperately cause if "size = 1" then in "op1=solve(arr,0,n-2)" ,n-2 will access an invalid index "-1"
        // and s=0 and e=-1 so the solve function will correctly run for single element case
        return arr[0];
    }

    int op1 = solve(arr, 0, size - 2);
    int op2 = solve(arr, 1, size - 1);
    int ans = max(op1, op2);
    return ans;
}

int deArrange(vector<int> &arr, int size)
{
    // Base Case
    if (size == 2)
    {
        return 1;
    }
    if (size == 1)
    {
        return 0;
    }
    // 1st index element swapped with ith index element ,ith index element is placed at 1st index
    int ans1 = (size - 1) * deArrange(arr, size - 2);
    // 1st index element place ith index, and the ith index element can be  placed at any index except 1st and ith
    int ans2 = (size - 1) * deArrange(arr, size - 1);
    return ans1 + ans2;
}

// painting fence algo
int getPaintWays(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    int ans = (k - 1) * (getPaintWays(n - 1, k) + getPaintWays(n - 2, k));
    return ans;
}

int minDistance(string &a, string &b, int i, int j)
{
    // base case
    if (i >= a.length())
    {
        // word1 wali string end hogyi
        // yani word1 ki length may be word 2 se choti h
        return b.length() - j;
    }
    if (j >= b.length())
    {
        // word 2 end hogya
        // yaaani word 1 ki length may be greater than word2 hai
        return a.length() - i;
    }
    int ans = 0;

    if (a[i] == b[j])
    {
        // match
        ans = 0 + minDistance(a, b, i + 1, j + 1);
    }
    else
    {
        // not match
        // operation perform karo
        // insert
        int option1 = 1 + minDistance(a, b, i, j + 1);
        // remove
        int option2 = 1 + minDistance(a, b, i + 1, j);
        // replace
        int option3 = 1 + minDistance(a, b, i + 1, j + 1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}

int solvematrix(vector<vector<int>> &matrix, int i, int j, int row, int col, int &maxi)
{
    // base case
    if (i >= row || j >= col)
    {
        return 0;
    }

    // explore all 3 directions
    int right = solvematrix(matrix, i, j + 1, row, col, maxi);
    int diagnol = solvematrix(matrix, i + 1, j + 1, row, col, maxi);
    int down = solvematrix(matrix, i + 1, j, row, col, maxi);

    // check can we build sqaure form current position
    if (matrix[i][j] == 1)
    {
        int ans = 1 + min(right, min(down, diagnol));
        // cout << "For i: " << i << "j: " << j << endl;
        // ye important hai
        maxi = max(maxi, ans);
        return maxi;
    }
    else
    {
        // agar 0 pr hi khade ho toh answer bhi zero hga
        return 0;
    }
}
int maximalSquare(vector<vector<int>> &matrix)
{
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    int ans = solvematrix(matrix, i, j, row, col, maxi);
    return maxi * maxi;
}

int main()
{
    // vector<int> rob = {1, 2, 3, 1};
    // cout << "The max amount robbed = " << rob2(rob);

    // vector<int> arr = {10, 20, 30};
    // int size = arr.size();
    // cout << "Count De-Arrangement = " << deArrange(arr, size);

    // int n = 3;
    // int k = 3;
    // int ans = getPaintWays(n, k);
    // cout << ans << endl;
    // return 0;

    // string word1 = "horse";
    // string word2 = "ros";
    // cout << "Minimum no. of operations to convert word1 into word2 : " << minDistance(word1, word2, 0, 0);

    vector<vector<int>> matrix;
    vector<int> row1 = {1, 0, 1, 0, 0};
    vector<int> row2 = {1, 0, 1, 1, 1};
    vector<int> row3 = {1, 1, 1, 1, 1};
    vector<int> row4 = {1, 0, 0, 1, 0};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    cout << "Area of Largest sqaure containing 1 : " << maximalSquare(matrix) << endl;
    return 0;
}