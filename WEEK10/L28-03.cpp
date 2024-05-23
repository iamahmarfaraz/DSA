#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// CIRCULAR SINGLY LINKED LIST

class Node
{
public:
    int data;
    Node *Next;

    Node()
    {
        this->Next = NULL;
    }

    Node(int data)
    {
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
        tail - next = newNode;
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
        newNode->Next = head;
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

void deleteNode(Node *&head, Node *&tail, int position)
{
    int len = findLength(head);
    Node *temp = head;
    if (len == 0 || position < 1)
    {
        cout << "Can't Delete" << endl;
        return;
    }
    if (head == tail)
    {
        // Handle Single Element
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    else if (position == 1)
    {
        // Deletion at Head
        head = temp->Next;
        tail->Next=head;
        temp->Next = NULL; // Isolating the 1st Node
        delete temp;
    }

    else if (position == len)
    {
        while (temp->Next != tail)
        {
            temp = temp->Next;
        }
        temp->Next = head;
        tail->next = NULL;
        delete tail;
        tail = temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->Next;
        }
        prev->Next = curr->Next;
        curr->Next = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertionAtTail(head, tail, 10);
    insertionAtTail(head, tail, 20);
    insertionAtTail(head, tail, 30);
    insertionAtTail(head, tail, 40);
    insertionAtTail(head, tail, 50);

    printLinkedList(head);
    cout << head->data << endl;
    cout << tail->data << endl;

    // insertAtPosition(25, 3, head, tail);
    // printLinkedList(head);

    // deleteNode(head,tail,1);
    // printLinkedList(head);

    // deleteNode(head,tail,5);
    // printLinkedList(head);

    // deleteNode(head,tail,2);
    // printLinkedList(head);

    deleteNode(head, tail, 5);
    cout << head->data << endl;
    cout << tail->data << endl;
    ;
    printLinkedList(head);

    // deleteNode2(head, tail, 80);
    // printLinkedList(head);

    deleteNode2(head, tail, 20);
    printLinkedList(head);

    return 0;
}