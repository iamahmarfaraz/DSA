#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // not the 1st element
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data : " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krete h

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // valid node wala case
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void preOrder(Node *&root)
{
    // NLR
    // Base case
    if (root == NULL)
    {
        return;
    }
    // N
    cout << root->data << " ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}

void inOrder(Node *&root)
{
    // LNR
    // Base case
    if (root == NULL)
    {
        return;
    }
    // L
    inOrder(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrder(root->right);
}

void postOrder(Node *&root)
{
    // LRN
    // Base case
    if (root == NULL)
    {
        return;
    }
    // L
    postOrder(root->left);
    // R
    postOrder(root->right);
    // N
    cout << root->data << " ";
}

int minBST(Node *root)
{
    if (root->left == NULL)
    {
        // LEFT MOST ELEMENT OF THE BST
        return root->data;
    }
    // go left only
    int ans = minBST(root->left);
    return ans;
}

int maxBST(Node *root)
{
    if (root->right == NULL)
    {
        // RIGHT MOST ELEMENT OF THE BST
        return root->data;
    }
    // go right only
    int ans = maxBST(root->right);
    return ans;
}

Node *createBST_UsingInOrder(int *arr, int start, int end)
{
    int mid = start + ((end - start) / 2);
    int data = arr[mid];
    if (start >= end)
    {
        Node *ans = new Node(data);
        return ans;
    }
    Node *root = new Node(data);
    root->left = createBST_UsingInOrder(arr, start, mid - 1);
    root->right = createBST_UsingInOrder(arr, mid + 1, end);
    return root;
}

bool solve(Node *root, long long int upper, long long int lower)
{
    if (root == NULL)
    {
        return true;
    }
    bool cond1 = (root->data < upper);
    bool cond2 = (root->data > lower);
    bool leftAns = solve(root->left, root->data, lower);
    bool rightAns = solve(root->right, upper, root->data);

    if (cond1 && cond2 && leftAns && rightAns)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isValidBST(Node *root)
{
    long long int lower = -2147483657;
    long long int upper = 2147483657;
    bool ans = solve(root, upper, lower);
    return ans;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;
    if ((root->data > p->data && root->data < q->data) || (root->data < p->data && root->data > q->data))
    {
        // "P" left subtree me hai while "Q" right subtree me h
        return root;
    }
    Node *ans;
    if (p->data < root->data && q->data < root->data)
    {
        // Go to Left Subtree
        ans = lowestCommonAncestor(root->left, p, q);
    }
    else if (p->data > root->data && q->data > root->data)
    {
        // Go to Right Subtree
        ans = lowestCommonAncestor(root->right, p, q);
    }
    return ans;
}

int kthSmallest(Node* root, int &k) {
        // LNR
    // Base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int Leftans = kthSmallest(root->left,k);
    if(Leftans != -1){
        return Leftans;
    }
    // N
    k--;
    if(k==0){
        return root->data;
    }
    
    // R
    int Rightans = kthSmallest(root->right,k);
    return Rightans;
  }

int main()
{
    // int arr[] = {10, 20, 30, 40, 50, 60, 70};
    // int size = 7;
    // int end = size - 1;
    // Node *InOrderRoot = createBST_UsingInOrder(arr, 0, end);
    // cout << "  Binary Tree Created Using InOrder  " << endl;
    // levelOrderTraversal(InOrderRoot);

    // Node *root = NULL;
    // createBST(root); // 100 50 30 70 200 120 300
    // Node *p = new Node(30);
    // Node *q = new Node(70);

    // Node *ans = lowestCommonAncestor(root, p, q);
    // cout << "LCA of \"" << p->data << "\" & \"" << q->data << "\" Node is : " << ans->data << endl;
    return 0;
}