#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;

    Node()
    {
        cout << "I'm inside Default Constructor" << endl;
        this->Next = NULL;
    }

    Node(int data)
    {
        cout << "I'm inside Parameterized Constructor" << endl;
        this->data = data;
        this->Next = NULL;
    }
};

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

int findLength(Node *&head)
{
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
                temp = temp->Next;
                len++;
        }
        return len;
}

void insertionAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // Empty L.L
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // INSERTION AT HEAD
        Node *newNode = new Node(data);
        newNode->Next = head; // point newNode->Next to the head Node
        head = newNode;       // make "newNode" the new head
    }
}

void insertionAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // Empty L.L
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->Next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    int len = findLength(head);

    if (position == 1)
    {
        insertionAtHead(head, tail, data);
        return;
    }
    else if (position > len)
    {
        insertionAtTail(head, tail, data);
        return;
    }
    else
    {
        Node *newNode = new Node(data);

        //     Node* prev = NULL;
        //     Node* curr = head;
        //     while(position != 1) {
        //         position--;
        //         prev = curr;
        //         curr = curr->next;
        //     }

        //     //step3:
        //     newNode -> next = curr;

        //     //step4:
        //     prev -> next = newNode;

        // OR

        Node *temp = head;
        int tempPos = 1;
        while (tempPos != position - 1)
        {
            tempPos++;
            temp = temp->Next;
        }
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

// GENERIC WAY TO FIND TAIL OF A L.L
// void createTail(Node *head, Node *&tail){
//     Node * temp = head;
//     while (temp != NULL)
//     {
//         temp = temp->Next;
//     }
//     tail=temp;
// }

int main()
{
    // // Node a;
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *forth = new Node(40);
    // Node *fifth = new Node(50);
    // first->Next = second;
    // second->Next = third;
    // third->Next = forth;
    // forth->Next = fifth;

    // Node *head = first;
    // Node *tail = fifth;
    int count = 0;
    // printLinkedList(head, count);
    // cout << "Length of Linked List : " << count << endl;

    // insertionAtHead(head, 5);
    // printLinkedList(head, count);

    // insertionAtTail(head, tail, 60);
    // printLinkedList(head, count);

    Node *head = NULL;
    Node *tail = NULL;
    insertionAtTail(head, tail, 10);
    insertionAtTail(head, tail, 20);
    insertionAtTail(head, tail, 30);
    insertionAtTail(head, tail, 40);
    insertionAtTail(head, tail, 50);

    printLinkedList(head, count);

    insertAtPosition(25,3,head,tail);
    printLinkedList(head,count);
    return 0;
}