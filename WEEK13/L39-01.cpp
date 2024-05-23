#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

// BINARY TREE

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *creatTree()
{
    cout << "Enter the value : " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        // Base Case and alsp agar aaage Node nhi banana to enter data == -1
        return NULL;
    }
    Node *root = new Node(data);
    // Step2 Create left sub tree
    cout << "Left of Node" << root->data << endl;
    root->left = creatTree();
    // Step2 Create right sub tree
    cout << "Right of Node" << root->data << endl;
    root->right = creatTree();

    return root;
}

void leftviewWithLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << root->data << " ";
    // asli traversal now starts
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL && !q.empty()) // q.empty() condition is for last level when there is no child node so the queue will be empty
        {
            Node *traverse = q.front();
            cout << traverse->data << " ";
            // cout << endl;
            q.push(NULL);
        }
        else
        {
            // Valid wala Case
            // cout << front->data << " ";
            // push left
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            // push right
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void rightviewWithLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << root->data << " ";
    // asli traversal now starts
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL && !q.empty()) // q.empty() condition is for last level when there is no child node so the queue will be empty
        {
            Node *traverse = q.front();
            cout << traverse->data << " ";
            // cout << endl;
            q.push(NULL);
        }
        else
        {
            // Valid wala Case
            // cout << front->data << " ";
            // push right
            if (front->right != NULL)
            {
                q.push(front->right);
            }
            // push left
            if (front->left != NULL)
            {
                q.push(front->left);
            }
        }
    }
}

void leftView(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    level++;
    if (root->left != NULL)
    {
        leftView(root->left, ans, level);
    }
    if (root->right != NULL)
    {
        leftView(root->right, ans, level);
    }
}

void rightView(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    level++;
    if (root->right != NULL)
    {
        rightView(root->right, ans, level);
    }
    if (root->left != NULL)
    {
        rightView(root->left, ans, level);
    }
}

void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push(make_pair(root, 0)); // pushing 1st element(root) on our own;
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = frontNode->data;
        }
        // push left child
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        // push right child
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void buttomView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push(make_pair(root, 0)); // pushing 1st element(root) on our own;
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;
        mp[hd] = frontNode->data;
        // push left child
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        // push right child
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void leftboundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->left != NULL)
    {
        leftboundary(root->left);
    }
    else //(root->left == NULL && root->right != NULL)
    {
        leftboundary(root->right);
    }
}

void leafNode(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    if (root->left != NULL)
    {
        leafNode(root->left);
    }
    if (root->right != NULL)
    {
        leafNode(root->right);
    }
}

void rightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        rightBoundary(root->right);
    }
    else //(root->right == NULL && root->left != NULL)
    {
        rightBoundary(root->left);
    }
    cout << root->data << " ";
}

void printBoundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        leftboundary(root);
    }
    leafNode(root);
    if (root->right != NULL)
    {
        rightBoundary(root->right); // cause we already printed the root in leftBoundary func
    }
    if (root->left == NULL)
    {
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = creatTree();
    // cout<<"Left view of the Tree : ";
    // leftviewWithLevelOrder(root);
    // cout<<endl;
    // vector<int> ans;
    // vector<int> ans1;
    // int level = 0;
    // cout << "Left view of the Tree : ";
    // leftView(root, ans, level);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    // cout << "Right view of the Tree : ";
    // rightView(root, ans1, level);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     cout << ans1[i] << " ";
    // }
    // cout << endl;
    // cout << "Top View of the Binary Tree :";
    // topView(root);

    // cout << "buttom View of the Binary Tree :";
    // buttomView(root);

    cout << "Boundary Traversal : ";
    printBoundaryTraversal(root);

    return 0;
}