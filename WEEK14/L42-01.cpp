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

Node * BST_To_DoublyLL(Node *root,Node *&head)
{
    if (root == NULL)
    {
        return NULL;
    }
    BST_To_DoublyLL(root->right,head);
    root->right =  head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    BST_To_DoublyLL(root->left,head);
    return root;
}

Node* convertDLLtoBST(Node* &head, int n) {
	//base case
	if(head == NULL || n<=0) {
		return NULL;
	}

	//LNR
	//L
	Node* leftSubtree = convertDLLtoBST(head, n/2);

	//N 
	Node* root = head;
	root->left = leftSubtree;
	//head update
	head  = head ->right;

	///R
	Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
	root->right = rightSubtree;
	return root;
	
}

void printLinkedList(Node* head) {
	Node* temp = head;
	cout << "printing the entire list: " << endl;
	while(temp != NULL) {
		cout << temp->data <<"->";
		temp = temp->right;
	}
	cout << endl;
}


int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "Before deletion" << endl;
    levelOrderTraversal(root);
    cout << endl;
    Node *head = NULL;
    BST_To_DoublyLL(root,head);
    cout << "  Linked List From BST  " << endl;
    printLinkedList(head);

    Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->right = second;
	second->left = first;
	second->right = third;
	third->left = second;

	Node* head = first;
	//10<->20<->30

	Node* root = convertDLLtoBST(head, 3);
	levelOrderTraversal(root);

    return 0;
}