#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// DOUBLY LINKED LIST

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printDoublyLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertionAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    tail->next = newNode;
    newNode->prev = tail;
}

void insertionAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    newNode->prev = tail;
    tail=newNode;
}

void insertionAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    int len = findLength(head);
    if (position == 1)
    {
        insertionAtHead(head, tail, data);
    }
    else if (position > len)
    {
        insertionAtTail(head, tail, data);
    }
    else
    {
        Node *newNode = new Node(data);
        Node *currNode = head;
        Node *prevNode = NULL;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

void deleteAtHead(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        // HANDLE SINGLE ELEMENT
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    head->prev = NULL;
    head->prev=tail;
    tail->next=head;
    delete temp;
}

void deleteAtTail(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        // HANDLE SINGLE ELEMENT
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *prevNode = tail->prev;
    prevNode->next = NULL;
    tail->prev = NULL;
    delete tail;
    tail = prevNode;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    int len = findLength(head);
    if (head == NULL)
    {
        cout << "Can't Delete Linked List is Empty" << endl;
    }

    if (position == 1)
    {
        deleteAtHead(head, tail);
        return;
    }
    else if (position > len)
    {
        deleteAtTail(head, tail);
    }
    else
    {
        Node *currNode = head;
        Node *prevNode = NULL;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node *nextNode = currNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertionAtHead(head, tail, 250);
    insertionAtHead(head, tail, 200);
    insertionAtHead(head, tail, 150);
    insertionAtHead(head, tail, 100);
    insertionAtHead(head, tail, 50);
    insertionAtTail(head, tail, 300);
    insertionAtPosition(head, tail, 175, 4);
    printDoublyLinkedList(head);
    deleteAtHead(head, tail);
    deleteAtTail(head, tail);
    printDoublyLinkedList(head);
    deleteAtPosition(head, tail, 3);
    printDoublyLinkedList(head);

    return 0;
}