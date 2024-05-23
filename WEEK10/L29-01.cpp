#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// SINGLY LINKED LIST

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

void reverseLinkedList(Node *&head, Node *&tail)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextprev = NULL;
    Node *nextcurr = NULL;
    tail = head;
    while (curr != NULL)
    {
        // Keeping the track of upcoming prev & curr
        nextprev = curr;
        nextcurr = curr->Next;
        // Reversing
        curr->Next = prev;
        // Relocating "prev" & "curr" to the place of "nextprev" & "nextcurr"
        prev = nextprev;
        curr = nextcurr;
    }
    head = prev;
}

Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->Next;
        if (fast != NULL)
        {
            fast = fast->Next;
            slow = slow->Next;
        }
    }
    return slow;
}

bool isPalindrome(Node *head, Node *tail)
{
    if (head->Next == NULL)
        return true;
    // breaking L.L into 2 halves
    Node *midNode = middleNode(head);
    Node *head2 = midNode->Next;
    midNode->Next = NULL;
    // Reversing 2nd half of L.L
    reverseLinkedList(head2, tail);
    // Comparing 2 halves of Linked List
    Node *temp = head;
    Node *temp2 = head2;
    while (temp2 != NULL)
    {
        if (temp->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp = temp->Next;
            temp2 = temp2->Next;
        }
    }
    // if(temp != NULL || temp2 != NULL){
    //     return false;
    // }
    return true;
}

bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->Next;
        if (fast != NULL)
        {
            fast = fast->Next;
            slow = slow->Next;
        }
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

Node *getStartOfLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->Next;
        if (fast != NULL)
        {
            fast = fast->Next;
            slow = slow->Next;
        }
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->Next;
        fast = fast->Next;
    }
    return slow;
}

void breakingLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->Next;
        if (fast != NULL)
        {
            fast = fast->Next;
            slow = slow->Next;
        }
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    Node *tailCorrector = NULL;
    while (slow != fast)
    {
        tailCorrector = fast;
        slow = slow->Next;
        fast = fast->Next;
    }
    tailCorrector->Next = NULL;
}

void add1ToList(Node *&head, Node *&tail)
{
    // Reverse
    reverseLinkedList(head, tail);
    // Add 1
    Node *temp = head;
    int carry = 1;
    Node *lastTemp = NULL;
    while (temp != NULL)
    {
        int totalsum = temp->data + carry;
        int digit = totalsum % 10;
        carry = totalsum / 10;
        temp->data = digit;
        lastTemp = temp;
        temp = temp->Next;
        if (carry == 0)
            break;
    }
    // if carry remains
    if (carry != 0)
    {
        Node *newNode = new Node(carry);
        lastTemp->Next = newNode;
    }
    // reverse again
    reverseLinkedList(head, tail);
}

void add2List(Node *&head1, Node *&head2, Node *&tail1, Node *&tail2, Node *&ansHead, Node *&ansTail)
{
    int len1 = findLength(head1);
    int len2 = findLength(head2);
    if (len1 > len2)
    {
        reverseLinkedList(head1, tail1);
    }
    if (len2 > len1)
    {
        reverseLinkedList(head2, tail2);
    }
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int totalsum = temp1->data + temp2->data + carry;
        int digit = totalsum % 10;
        carry = totalsum / 10;
        insertionAtHead(ansHead, ansTail, digit);
        temp1 = temp1->Next;
        temp2 = temp2->Next;
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            int totalsum = temp1->data + carry;
            int digit = totalsum % 10;
            carry = totalsum / 10;
            insertionAtHead(ansHead, ansTail, digit);
            temp1 = temp1->Next;
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            int totalsum = temp2->data + carry;
            int digit = totalsum % 10;
            carry = totalsum / 10;
            insertionAtHead(ansHead, ansTail, digit);
            temp2 = temp2->Next;
        }
    }
    if (carry != 0)
    {
        insertionAtHead(ansHead, ansTail, carry);
    }
}

Node *reverseKGroup(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->Next == NULL)
    {
        return head;
    }
    // 1 case main solve karunga
    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = curr->Next;
    int pos = 0;

    int len = findLength(head);
    if (len < k)
    {
        return head;
    }
    while (pos < k)
    {
        nextNode = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }
    Node *recursionKaAns = NULL;
    recursionKaAns = reverseKGroup(nextNode, k);
    head->Next = recursionKaAns;
    return prev;
}

void deleteDuplicates(Node *&head)
{

    if (head == NULL)
    {
        return;
    }
    if (head->Next == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        if (temp->data == temp->Next->data)
        {
            // remove
            Node *nextNode = temp->Next;
            temp->Next = nextNode->Next;
            nextNode->Next = NULL;
            delete nextNode;
        }
        else
        {
            temp = temp->Next;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // insertionAtTail(head, tail, 10);
    // insertionAtTail(head, tail, 20);
    // insertionAtTail(head, tail, 30);
    // insertionAtTail(head, tail, 40);
    // insertionAtTail(head, tail, 50);

    // printLinkedList(head);
    // reverseLinkedList(head, tail);
    // printLinkedList(head);

    // Node * ans = middleNode(head);
    // cout<<"Middle Element of the Linked List : "<<ans->data<<endl;

    // insertionAtTail(head, tail, 1);
    // insertionAtTail(head, tail, 0);
    // insertionAtTail(head, tail, 2);
    // insertionAtTail(head, tail, 2);
    // insertionAtTail(head, tail, 0);
    // insertionAtTail(head, tail, 1);

    // if (isPalindrome(head, tail))
    // {
    //     cout << "Linked List is Palindrome" << endl;
    // }
    // else
    // {
    //     cout << "Linked List isn't Palindrome" << endl;
    // }

    // insertionAtTail(head, tail, 10);
    // insertionAtTail(head, tail, 20);
    // insertionAtTail(head, tail, 30);
    // insertionAtTail(head, tail, 40);
    // insertionAtTail(head, tail, 50);
    // insertionAtTail(head, tail, 60);
    // insertionAtTail(head, tail, 70);
    // tail->Next=head->Next->Next->Next;

    // if (hasCycle(head))
    // {
    //     cout<<"Linked List is Cyclic"<<endl;
    // }
    // else{
    //     cout<<"Linked List isn't Cyclic"<<endl;
    // }
    // cout<<endl;

    // Node * ansCyc=getStartOfLoop(head);
    // cout<<"The Loop starts with \" "<<ansCyc->data<<" \" of address : \" "<<ansCyc<<" \""<<endl;
    // cout<<head->Next->Next->Next<<endl;

    // breakingLoop(head);
    // printLinkedList(head);

    // insertionAtTail(head, tail, 9);
    // insertionAtTail(head, tail, 9);
    // insertionAtTail(head, tail, 9);

    // printLinkedList(head);
    // add1ToList(head,tail);
    // cout<<"After adding 1 to L.L : ";
    // printLinkedList(head);

    // insertionAtTail(head, tail, 4);
    // insertionAtTail(head, tail, 3);
    // insertionAtTail(head, tail, 4);

    // Node *head2 = NULL;
    // Node *tail2 = NULL;
    // insertionAtTail(head2, tail2, 2);
    // insertionAtTail(head2, tail2, 3);
    // insertionAtTail(head2, tail2, 9);
    // insertionAtTail(head2, tail2, 1);

    // Node *ansHead = NULL;
    // Node *ansTail = NULL;

    // add2List(head, head2, tail, tail2, ansHead, ansTail);
    // printLinkedList(ansHead);

    insertionAtTail(head, tail, 10);
    insertionAtTail(head, tail, 20);
    insertionAtTail(head, tail, 20);
    insertionAtTail(head, tail, 30);
    insertionAtTail(head, tail, 30);
    insertionAtTail(head, tail, 40);
    printLinkedList(head);
    deleteDuplicates(head);
    printLinkedList(head);

    return 0;
}