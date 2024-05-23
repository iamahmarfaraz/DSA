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
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftheight = maxDepth(root->left);
    int rightheight = maxDepth(root->right);
    int diff = abs(leftheight - rightheight);

    bool currNodeAns = (diff <= 1);

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    if (currNodeAns && leftAns && rightAns)
    {
        return true;
    }
    return false;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root == p)
    {
        return p;
    }
    if (root == q)
    {
        return q;
    }
    Node *leftAns = lowestCommonAncestor(root->left, p, q);
    Node *rightAns = lowestCommonAncestor(root->right, p, q);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else
    {
        return NULL;
    }
}

bool KthAncestorOfNode(Node *root, int &k, Node *&ans, Node *p)
{
    if (root == NULL)
    {
        return false;
    }
    if (root == p)
    {
        k--;
        return true;
    }
    if (ans != NULL)
    {
        return true;
    }
    bool left = KthAncestorOfNode(root->left, k, ans, p);
    if (k == 0)
    {
        // agr left subtree se ane pe answer mila to uske liye ye "IF" condition
        ans = root;
        k--;
        return true;
    }
    if (left == true)
    {
        // agr Left me "p" mil gya hai to Right me kyu jana ancestor chahiye to peeche jao
        return true;
    }

    bool right = KthAncestorOfNode(root->right, k, ans, p);
    if (k == 0)
    {
        // agr right subtree se ane pe answer mila to uske liye ye "IF" condition
        ans = root;
        k--;
        return true;
    }
    if (left == true || right == true)
    {
        // agr dono me ek bhi true hai iska mtlb we are returning after getting "P" so k--
        k--;
    }
    return left || right;
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

void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{

    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node *constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // 1 case main solve krta hu
    int element = preOrder[preIndex];
    preIndex++;
    Node *root = new Node(element);
    // element search krna padega  inorder me
    // int position = searchInorder(inOrder, size, element);
    int position = valueToIndexMap[element];
    // baaaki recursion sambhal lega
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);

    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

    return root;
}

Node *constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postorder[], int inorder[], int &postIndex, int inorderStart, int inorderEnd, int size)
{

    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // 1 case main solve krunga
    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element);
    // search karo inorder me
    int position = valueToIndexMap[element];
    // baaki recursion sambhal lega
    // right ki call pehle lagegi
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, position + 1, inorderEnd, size);

    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, position - 1, size);

    return root;
}

int main()
{
    // Node *root = creatTree();
    // Node *root = new Node(10);
    // Node *l1 = new Node(20);
    // Node *l2 = new Node(40);
    // Node *l3 = new Node(50);
    // Node *l4 = new Node(70);
    // Node *l5 = new Node(80);
    // Node *l6 = new Node(90);
    // Node *l7 = new Node(100);
    // Node *r1 = new Node(30);
    // root->left = l1;
    // root->right = r1;
    // l1->left = l2;
    // l1->right = l3;
    // l2->left = l4;
    // l2->right = l5;
    // l5->left = l6;
    // l5->right = l7;
    // Node *ans;
    // int k = 2;
    // bool a = KthAncestorOfNode(root, k, ans, l6);
    // cout << ans->data << endl;
    map<int, int> valueToIndexMap;

    // int preOrder[] = {2, 8, 10, 6, 4, 12};
    // int inOrder[] = {10, 8, 6, 2, 4, 12};
    // int size = 6;
    // int preOrderIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = 5;

    // createMapping(inOrder, size, valueToIndexMap);
    // Node *ans = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex,inorderStart,inorderEnd,size);
    // cout << "The B.T Created is : " << endl;
    // levelOrderTraversal(ans);

    int inorder[] = {8, 14, 6, 2, 10, 4};
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, inorderEnd, size);
    cout << "Printing the entire tree: " << endl;
    levelOrderTraversal(root);
    return 0;
}