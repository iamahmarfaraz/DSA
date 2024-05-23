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

bool searchBST(Node *root, int target)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }
    bool ans;
    if (target > root->data)
    {
        // go right
        ans = searchBST(root->right, target);
    }
    else
    {
        // go left
        ans = searchBST(root->left, target);
    }
    return ans;
}

Node *LeftSubTreeMax(Node *root)
{
    //LEFT SubTree ka Max Element find krne ke liye
    if (root->right == NULL)
    {
        // LEFT MOST ELEMENT OF THE BST
        return root;
    }
    // go left only
    Node *ans = LeftSubTreeMax(root->right);
    return ans;
}

Node *RightSubTreeMin(Node *root)
{
    if (root->left == NULL)
    {
        // RIGHT MOST ELEMENT OF THE BST
        return root;
    }
    // go right only
    Node *ans = RightSubTreeMin(root->left);
    return ans;
}

Node *deleteNode(Node *&root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *right = root->right;
            delete root;
            return right;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *left = root->left;
            delete root;
            return left;
        }
        if (root->left != NULL && root->right != NULL)
        {
            Node *min = LeftSubTreeMax(root->left);
            root->data = min->data;
            root->left = deleteNode(root->left, min->data); // yha galti kari thi
            return root;
        }
    }
    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
    }
    else
    {
        root->right = deleteNode(root->right, target);
    }
    return root;
}



int main()
{
    // Node *root = NULL;
    // createBST(root);
    // cout<<"Before deletion"<<endl;
    // levelOrderTraversal(root);
    // cout << endl;
    // cout << "Printing preOrder : ";
    // preOrder(root);
    // cout << endl;
    // cout << "Printing inOrder : ";
    // inOrder(root);
    // cout << endl;
    // cout << "Printing postOrder : ";
    // postOrder(root);
    // cout << endl;

    // cout << "Minimum Valued Element in the BST : " << minBST(root) << endl;
    // cout << "Maximum Valued Element in the BST : " << maxBST(root) << endl;

    // int target = 80;
    // if (searchBST(root, target))
    // {
    //     cout << "Element is present in the BST" << endl;
    // }
    // else
    // {
    //     cout << "Element not present in the BST" << endl;
    //}

    // root = deleteNode(root,100);
    // cout<<" After Delete Operation "<<endl;
    // levelOrderTraversal(root);

   
    return 0;
}