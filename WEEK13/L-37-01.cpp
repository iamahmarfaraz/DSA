#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    // asli traversal now starts
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL && !q.empty()) // q.empty() condition is for last level when there is no child node so the queue will be empty
        {
            // but this case will get stucked in infinite loose when B.T's root have no child node so we can use q.size>1 condition in it
            cout << endl;
            q.push(NULL);
        }
        else
        {
            // Valid wala Case
            cout << front->data << " ";
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



int maxDepth(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    int ans = max(left, right);
    return ans;
}

int diameterOfBinaryTree(Node* root) {
        if(root == NULL){
            return 0;
        }
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int combo = maxDepth(root->left) + maxDepth(root->right);
        int ans= max(combo,max(left,right));
        return ans;
    }

int main()
{
    Node *root = creatTree();

    // cout << "Printing preOrder : ";
    // preOrder(root);
    // cout << endl;
    // cout << "Printing inOrder : ";
    // inOrder(root);
    // cout << endl;
    // cout << "Printing postOrder : ";
    // postOrder(root);
    // cout << endl;
    // cout << endl;
    // cout << "Printing Level Order Traversal: " << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    cout<<"Diamter of the Tree : "<<diameterOfBinaryTree(root);
    return 0;
}