#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val)
    {
        this->left = NULL;
        this->right = NULL;
    }
};

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

// Q.NO -1   &&    GFG - Inorder Successor in BST

// Returns the inorder successor of the Node x in BST (rooted at 'root')
int inOrderSuccessor(Node *root, Node *x)
{
    Node *succ = NULL;
    Node *curr = root;

    while (curr)
    {
        if (curr->data > x->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return (succ != NULL) ? succ->data : -1;
}

// Q.NO - 2
// Returns the inorder predecessor of the Node x in BST (rooted at 'root')
int inOrderPredecessor(Node *root, Node *x)
{
    Node *pre = NULL;
    Node *curr = root;

    while (curr)
    {
        if (curr->data < x->data)
        {
            pre = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    return (pre != NULL) ? pre->data : -1;
}

// Q.NO - 3      &&      LEETCODE - Q.NO-1008
TreeNode *build(int &index, int min, int max, vector<int> &preorder)
{
    if (index >= preorder.size())
    {
        return NULL;
    }

    TreeNode *root = nullptr;
    if (preorder[index] > min && preorder[index] < max)
    {
        root = new TreeNode(preorder[index++]);
        root->left = build(index, min, root->val, preorder);
        root->right = build(index, root->val, max, preorder);
    }
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int min = INT_MIN;
    int max = INT_MAX;

    int i = 0;

    return build(i, min, max, preorder);
}

// Q.NO-4   GFG
int countPairs(Node *root1, Node *root2, int x)
{
    int ans = 0;
    stack<Node *> s1, s2;
    Node *a = root1;
    Node *b = root2;

    while (1)
    {
        // Push all left nodes of first tree (Inorder)
        while (a)
        {
            s1.push(a);
            a = a->left;
        }

        // Push all right nodes of second tree (Reverse Inorder)
        while (b)
        {
            s2.push(b);
            b = b->right;
        }

        // If either stack is empty, break the loop
        if (s1.empty() || s2.empty())
        {
            break;
        }

        Node *aTop = s1.top();
        Node *bTop = s2.top();

        int sum = aTop->data + bTop->data;

        // If pair found
        if (sum == x)
        {
            ans++;
            s1.pop();
            s2.pop();
            // Move to next potential nodes
            a = aTop->right;
            b = bTop->left;
        }
        // If sum is less, move to next larger value in first BST
        else if (sum < x)
        {
            s1.pop();
            a = aTop->right;
        }
        // If sum is greater, move to next smaller value in second BST
        else
        {
            s2.pop();
            b = bTop->left;
        }
    }

    return ans;
}

// Q.NO-5    && LEETCODE-Q.NO-1382
void buildInOrder(TreeNode *root, vector<int> &inOrder)
{
    if (!root)
        return;

    // LNR
    buildInOrder(root->left, inOrder);
    inOrder.push_back(root->val);
    buildInOrder(root->right, inOrder);
}

TreeNode *buildBalanceBST(vector<int> inOrder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;

    TreeNode *root = new TreeNode(inOrder[mid]);
    root->left = buildBalanceBST(inOrder, start, mid - 1);
    root->right = buildBalanceBST(inOrder, mid + 1, end);

    return root;
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inOrder;
    buildInOrder(root, inOrder);

    // Build balance BST Using Inorder
    TreeNode *ans = buildBalanceBST(inOrder, 0, inOrder.size() - 1);

    return ans;
}

// Q.NO-6  &&   GFG
int morrisFindNoOfNodes(Node *root)
{
    Node *curr = root;
    int count = 0;

    while (curr)
    {
        if (curr->left == NULL)
        {
            count++;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float medianMorris(Node *root, int n)
{
    Node *curr = root;
    int i = 0;

    int odd1 = (n + 1) / 2, odd1Val = -1;
    int even1 = (n / 2), even1Val = -1;
    int even2 = (n / 2) + 1, even2Val = -1;

    while (curr)
    {
        if (curr->left == NULL)
        {
            i++;
            if (i == odd1)
                odd1Val = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr;
                i++;
                if (i == odd1)
                    odd1Val = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                curr = curr->right;
            }
        }
    }

    float median = 0;

    if ((n & 1) == 0)
    {
        // even
        median = (even1Val + even2Val) / 2.0;
    }
    else
    {
        median = odd1Val;
    }

    return median;
}

float findMedian(Node *root)
{
    // Code here
    int n = morrisFindNoOfNodes(root);

    return medianMorris(root, n);
}

// Q.NO-7    &&    GFG
bool solveDead(Node *root, int mini, int maxi)
{
    if (!root)
        return false;

    // Check for dead end condition
    if (mini == maxi)
        return true;

    // Recursively check in left and right subtrees
    bool leftAns = solveDead(root->left, mini, root->data - 1);
    bool rightAns = solveDead(root->right, root->data + 1, maxi);

    return leftAns || rightAns;
}
bool isDeadEnd(Node *root)
{
    int mini = 1; // beacuse BST Contains postive integers only greater than 0
    int maxi = INT_MAX;
    return solveDead(root, mini, maxi);
}

// Q.NO-8    &&    LEETCODE-Q.NO-938
void range(TreeNode *root, int &low, int &high, int &ans)
{
    if (!root)
        return;

    if (root->val >= low && root->val <= high)
    {
        ans += root->val;
    }

    range(root->left, low, high, ans);
    range(root->right, low, high, ans);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    range(root, low, high, ans);
    return ans;
}

// Q.NO-9     &&     GFG
Node *flattenBSTIntoLinkedList(Node *root)
{
    Node *curr = root;
    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while (curr)
    {
        if (curr->left == NULL)
        {
            prev->left = NULL;
            prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr;
                prev->left = NULL;
                prev->right = curr;
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return dummy->right;
}

// Q.NO-10   &&    GFG
Node *bstBuilder(Node *root, int &index, vector<int> &arr, vector<int> &ans, int succ)
{
    int element = arr[index];
    if (!root)
    {
        Node *root = new Node(element);
        ans[index] = succ;
        return root;
    }
    if (element < root->data)
    {
        root->left = bstBuilder(root->left, index, arr, ans, root->data);
    }
    else
    {
        root->right = bstBuilder(root->right, index, arr, ans, succ);
    }
    return root;
}
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node *root = new Node(-1);
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        root = bstBuilder(root, i, arr, ans, -1);
    }
    return ans;
}

// Q.NO-11
void helperValidBSTFromPreOrder(int &index, int min, int max, vector<int> &preorder)
{
    if (index >= preorder.size())
    {
        return;
    }

    int value = preorder[index];

    // Check if the current value is within the allowed range
    if (value > min && value < max)
    {
        // Move to the next element
        index++;

        // Recurse for the left subtree with updated max
        helperValidBSTFromPreOrder(index, min, value, preorder);

        // Recurse for the right subtree with updated min
        helperValidBSTFromPreOrder(index, value, max, preorder);
    }
}

int validBSTFromPreOrder(vector<int> preorder)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int index = 0;

    helperValidBSTFromPreOrder(index, min, max, preorder);

    // If the entire preorder sequence was traversed, it is a valid BST
    return (index == preorder.size()) ? 1 : 0;
}

// Q.NO-12    &&     GFG-HARD
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;
    Node *a = root1;
    Node *b = root2;
    while (a || b || !s1.empty() || !s2.empty())
    {
        while (a)
        {
            s1.push(a);
            a = a->left;
        }
        while (b)
        {
            s2.push(b);
            b = b->left;
        }

        // stack2 is empty and only stack1 have nodes or if s1.top
        // ka data is less than s2.top ka data
        if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data))
        {
            Node *s1Top = s1.top();
            s1.pop();
            ans.push_back(s1Top->data);
            a = s1Top->right;
        }
        else
        {
            Node *s2Top = s2.top();
            s2.pop();
            ans.push_back(s2Top->data);
            b = s2Top->right;
        }
    }
    return ans;
}

int main()
{

    return 0;
}