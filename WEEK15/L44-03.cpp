#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// HEAPS IMP QUESTIONS

class NodeBST
{
public:
    int data;
    NodeBST *left;
    NodeBST *right;

    NodeBST(int val) : data(val)
    {
        this->left = NULL;
        this->right = NULL;
    }
};

NodeBST *insertIntoBST(NodeBST *root, int data)
{
    if (root == NULL)
    {
        root = new NodeBST(data);
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

void createBST(NodeBST *&root)
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

void levelOrderTraversal(NodeBST *root)
{
    queue<NodeBST *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krete h

    while (!q.empty())
    {
        NodeBST *front = q.front();
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

class Info
{
public:
    int maxVal;
    bool isValidHeap;
};

int kthSmallestElement(int *arr, int k, int size)
{
    priority_queue<int> pq;
    // Push first K elements in heap
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }
    // insert rest element only if that element is smaller than the top of heap cause top of max heap gives the maximum value
    for (int i = k; i < size; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // Push first K elements in heap
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        pq.push(element);
    }
    // insert rest element only if that element is larger than the top of heap cause top of min heap gives the minimum value
    for (int i = k; i < nums.size(); i++)
    {
        int element = nums[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
}

Info isCBTaValidHeap(Node *&root)
{
    if (root == NULL)
    {
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isValidHeap = true;
        return temp;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.maxVal = root->data;
        temp.isValidHeap = true;
        return temp;
    }
    Info left = isCBTaValidHeap(root->left);
    Info right = isCBTaValidHeap(root->right);
    if (root->data > left.maxVal && root->data > right.maxVal && left.isValidHeap && right.isValidHeap)
    {
        Info ans;
        ans.maxVal = root->data;
        ans.isValidHeap = true;
        return ans;
    }
    else
    {
        Info ans;
        ans.maxVal = max(root->data, max(left.maxVal, right.maxVal));
        ans.isValidHeap = false;
        return ans;
    }
}

bool positionOfLastNode(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    bool nullFound = false;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            nullFound = true;
        }
        else
        {
            if (nullFound)
            {
                return false;
            }
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}

bool isCompleteTree(Node *root)
{
    return positionOfLastNode(root);
}

void storeINORDER(NodeBST* root,vector<int> &inOrder){
    if (root == NULL)
    {
        return;
    }
    storeINORDER(root->left,inOrder);
    inOrder.push_back(root->data);
    storeINORDER(root->right,inOrder);
    
}

void replaceInOrderToPostOrder(NodeBST* root,vector<int> in,int &index){
    if (root == NULL)
    {
        return;
    }
    replaceInOrderToPostOrder(root->left,in,index);
    replaceInOrderToPostOrder(root->right,in,index);
    root->data = in[index];
    index++;
}

Node* convertBSTtoHeap(Node * root){
    vector<int> inOrder;
    storeINORDER(root,inOrder);
    //REplace the node values with the sorted inOrder values using post order traversal
    int index = 0;
    replaceInOrderToPostOrder(root,inOrder,index);
    return root;
}

int main()
{
    int arr[] = {3, 7, 4, 5, 6, 8, 9};
    int k = 4;
    int size = 7;
    int ans = kthSmallestElement(arr, k, size);
    cout << "Kth Smallest Element of the Array is : " << ans << endl;

    vector<int> arr2 = {3, 7, 4, 5, 6, 8, 9};
    int k1 = 2;
    int ans1 = findKthLargest(arr2, k1);
    cout << "Kth Largest Element of the Array is : " << ans1 << endl;

    Node *root

        return 0;
}