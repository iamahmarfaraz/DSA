#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root, int &D)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left, D);
    int right = height(root->right, D);
    int currD = left + right;
    D = max(D, currD);
    int ans = max(left, right) + 1;
    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    // Q.NO:-1 && LEETCODE-Q.NO - 543

    int D = 0;
    height(root, D);
    return D;
}

int height1(TreeNode *root, bool &ans)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = height1(root->left, ans);
    int right = height1(root->right, ans);

    if (abs(left - right) > 1)
    {
        ans = false;
    }

    int ans1 = max(left, right) + 1;
    return ans1;
}
bool isBalanced(TreeNode *root)
{
    // Q.NO:-2    &&     LEETCODE-Q.NO - 110

    bool ans = true;
    height1(root, ans);
    return ans;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{

    // Q.NO - 3     &&    LEETCODE - Q.NO-100

    if (p == NULL && q == NULL)
        return true;
    if (p == NULL)
        return false;
    if (q == NULL)
        return false;
    if (p->val != q->val)
        return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
}

vector<int> diagonal(TreeNode *root)
{

    // Q.NO - 4     &&    GFG

    vector<int> ans;
    if (!root)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        while (temp)
        {
            ans.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{

    // Q.NO:-5      &&      LEETCODE-Q.NO:-987

    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q; // root,(row,col)
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty())
    {
        auto frontPair = q.front();
        q.pop();
        TreeNode *frontNode = frontPair.first;
        auto frontCord = frontPair.second;
        int row = frontCord.first;
        int col = frontCord.second;
        mp[col][row].insert(frontNode->val);

        if (frontNode->left)
        {
            q.push({frontNode->left, {row + 1, col - 1}});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, {row + 1, col + 1}});
        }
    }

    // Storing ans
    for (auto it : mp)
    {
        auto &colMap = it.second;
        vector<int> temp;
        for (auto colIt : colMap)
        {
            auto &mSet = colIt.second;
            temp.insert(temp.end(), mSet.begin(), mSet.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    // Q.NO:-6       &&      LEETCODE-Q.NO-103

    if (root == nullptr)
        return {}; // Handle edge case for an empty tree

    queue<TreeNode *> q;
    q.push(root);
    // q.push(NULL);

    bool leftToRight = true;
    vector<vector<int>> ans;
    // vector<int> temp;

    while (!q.empty())
    {

        int width = q.size();
        vector<int> temp(width);

        for (int i = 0; i < width; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : width - 1 - i;
            temp[index] = frontNode->val;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        ans.push_back(temp);
        leftToRight = !leftToRight;
    }
    return ans;
}

int sumTree(TreeNode *root)
{

    // Q.NO:-7    &&     GFG

    if (!root)
        return 0;

    int oldVal = root->val;
    root->val = sumTree(root->left) + sumTree(root->right);
    return oldVal + root->val;
}

int solve(TreeNode *root, long long currSum, int targetSum)
{
    // Use long long for currSum
    if (!root)
        return 0;

    // Update the current sum
    currSum += root->val;

    // Check if the current path sum equals targetSum
    int count = (currSum == targetSum) ? 1 : 0;

    // Include paths from the left and right subtrees
    count += solve(root->left, currSum, targetSum);
    count += solve(root->right, currSum, targetSum);

    return count;
}

int pathSum(TreeNode *root, int targetSum)
{

    // Q.NO-8      &&      LEETCODE-Q.NO-437

    if (!root)
        return 0;

    // Find paths starting from the current node
    int ans = solve(root, 0, targetSum);

    // Find paths starting from the left and right children
    ans += pathSum(root->left, targetSum);
    ans += pathSum(root->right, targetSum);

    return ans;
}

vector<int> inorderTraversal(TreeNode *root)
{
    // Morris Traversal
    // Q.NO:-9     &&    LEETCODE-Q.NO:-94

    vector<int> ans;
    TreeNode *curr = root;

    while (curr)
    {
        // if Left is NULL then visit the curr and go right
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // Left Node is not NULL
        else
        {
            // Find the Inorder Predecessor,then establish the connecrtion
            // For Inorder Predecessor - once go left then right up until node->right == NULL
            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            // if Right Node of pred is NULL,then go to left after establishing Link
            // then traverse the curr node to curr->left;
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // Right is not NULL
            else
            {
                // left is Visited ,so go right after Visiting Curr Node while removing-
                // the curr link
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

pair<int, int> solve(TreeNode *root)
{
    if (!root)
    {
        return {0, 0};
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    if (left.first > right.first)
    {
        return {1 + left.first, root->val + left.second};
    }
    else if (left.first < right.first)
    {
        return {1 + right.first, root->val + right.second};
    }
    else
    {
        // If heights are equal, choose the path with the maximum sum
        return {1 + left.first, root->val + max(left.second, right.second)};
    }
}

int sumOfLongRootToLeafPath(TreeNode *root)
{

    // Q.NO:-10     &&     GFG

    pair<int, int> ans = solve(root);
    return ans.second;
}

pair<int, int> helper(TreeNode *root)
{
    if (!root)
        return {0, 0};

    auto left = helper(root->left);
    auto right = helper(root->right);

    // inlcude root,mean now u cant take left.first or right.first
    // cause its parent(root) is taken
    int a = root->val + left.second + right.second;

    // exluding root,now we can tak both first and second of left and
    // right answer(max of first,second)
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a, b};
}
int getMaxSumm(TreeNode *root)
{

    // Q.NO:-11    &&     GFG     &&    LEETCODE:- HOUSE ROBBER III

    auto ans = helper(root);
    return max(ans.first, ans.second);
}

void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
{
    if (!root)
        return;

    // Assign parent for left and right children
    if (root->left)
    {
        mp[root->left] = root;
        findParent(root->left, mp);
    }
    if (root->right)
    {
        mp[root->right] = root;
        findParent(root->right, mp);
    }
}

// Step 2: Find the target node by traversing the tree
TreeNode *burnNode(TreeNode *root, int target)
{
    if (!root)
        return NULL;
    if (root->val == target)
        return root;

    // Recursively check left and right subtrees
    TreeNode *left = burnNode(root->left, target);
    TreeNode *right = burnNode(root->right, target);

    // Return whichever subtree contains the target
    return left ? left : right;
}

int minTime(TreeNode *root, int target)
{

    // Q.NO:-12       &&         GFG

    unordered_map<TreeNode *, TreeNode *> parent; // Map to store parent references
    findParent(root, parent);                     // Step 1: Populate the parent map

    TreeNode *targetNode = burnNode(root, target); // Step 2: Find the target node

    // If target node is not found, return 0 (edge case)
    if (!targetNode)
        return 0;

    // BFS to spread the fire
    queue<TreeNode *> q;
    q.push(targetNode); // Start the fire from the target node
    q.push(NULL);       // Marker for each second

    unordered_map<TreeNode *, bool> visited; // To track visited nodes
    visited[targetNode] = true;

    int ans = -1; // Variable to track the time taken to burn all nodes
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            ans++; // Increment time when we reach a second
            if (!q.empty())
            {
                q.push(NULL); // Add marker for the next second
            }
        }
        else
        {
            // Spread fire to parent if not visited
            if (parent[curr] && !visited[parent[curr]])
            {
                visited[parent[curr]] = true;
                q.push(parent[curr]);
            }

            // Spread fire to left child if not visited
            if (curr->left && !visited[curr->left])
            {
                visited[curr->left] = true;
                q.push(curr->left);
            }

            // Spread fire to right child if not visited
            if (curr->right && !visited[curr->right])
            {
                visited[curr->right] = true;
                q.push(curr->right);
            }
        }
    }

    return ans; // Return the total time taken to burn the tree
}

vector<TreeNode *> ans;
unordered_map<string, int> mp;
string preOrder(TreeNode *root)
{
    if (!root)
        return "N";

    string left = preOrder(root->left);
    string right = preOrder(root->right);
    string temp = to_string(root->val) + "," + left + "," + right;
    if (mp[temp] == 1)
    {
        ans.push_back(root);
    }
    mp[temp]++;
    return temp;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{

    // Q.NO:-13       &&      LEETCODE-Q.N0:-652

    preOrder(root);
    return ans;
}

int main()
{

    return 0;
}