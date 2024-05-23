#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// GENERIC TREE

class Node
{
public:
    int data;
    int childNo;
    Node **child;

    Node(int val) : data(val)
    {
        
    }

    ~Node()
    {
        delete[] child; // Remember to free memory in the destructor
    }
};

Node *createGenericTree()
{
    cout << "Enter data : ";
    int data, childNo;
    cin >> data;
    cout << endl;
    cout << "& No. of Child : ";
    cin >> childNo;
    cout << endl;
    Node *root = new Node(data);
    root->childNo = childNo;
    root->child = new Node *[childNo];

    int i = 0;
    while (i < root->childNo)
    {
        cout << "Child of Node" << root->data << endl;
        root->child[i] = createGenericTree();
        i++;
    }

    return root;
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
            // Valid wala Case
            cout << front->data << " ";
            // push Child
            for (int i = 0; i < root->childNo; i++)
            {
                if (front->child[i] != NULL)
                {
                    q.push(front->child[i]);
                }
            }
        }
    }
}

int main()
{
    Node *root = createGenericTree();
    levelOrderTraversal(root);
    return 0;
}