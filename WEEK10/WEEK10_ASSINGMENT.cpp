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
        this->Next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->Next = NULL;
    }
};

class ListNode
{

public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void delete_N_nodesAfter_M_nodes(Node *&head, int &m, int n)
{
    // Q.NO 1
    int i = 0;
    Node *temp = head;
    Node *prevTemp = NULL;
    while (temp != NULL)
    {
        int nDelete = n;
        i++;
        prevTemp = temp;
        temp = temp->Next;
        if ((i % m == 0))
        {
            while (nDelete > 0 && temp != NULL)
            {
                Node *nextNode = temp->Next;
                temp->Next = NULL;
                delete temp;
                temp = nextNode;
                nDelete--;
            }
            prevTemp->Next = temp;
        }
    }
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    Node *temp1 = list1;
    Node *headAns = list1;
    Node *temp2 = list2;
    Node *prevTemp1 = NULL;
    Node *nextTemp2 = NULL;
    // Node *prevTemp2 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            prevTemp1 = temp1;
            temp1 = temp1->Next;
        }
        else
        {
            if (prevTemp1 != NULL)
            {

                prevTemp1->Next = temp2;
            }
            else
            {
                headAns = list2;
            }
            nextTemp2 = temp2->Next;
            temp2->Next = temp1;
            prevTemp1 = temp2;
            // prevTemp2 = temp2;
            temp2 = nextTemp2;
        }
    }
    while (temp2 != NULL)
    {
        if (prevTemp1 != NULL)
        {
            prevTemp1->Next = temp2;
        }
        prevTemp1 = temp2;
        temp2 = temp2->Next;
    }
    return headAns;
}

void printKthNodeFromEnd(Node *&head, int &k)
{
    if (head == NULL)
    {
        return;
    }
    printKthNodeFromEnd(head->Next, k);
    if (k == 0)
    {
        cout << "Kth Node From the End is : " << head->data << endl;
    }
    k--;
}

Node *middleNode(Node *head)
{
    if (head == nullptr || head->Next == nullptr)
    {
        return head;
    }
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

Node *mergeTwoLists2(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    Node *ans = new Node(-1);
    Node *mptr = ans;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            mptr->Next = list1;
            mptr = list1;
            list1 = list1->Next;
        }
        else
        {
            mptr->Next = list2;
            mptr = list2;
            list2 = list2->Next;
        }
    }
    if (list1 != NULL)
    {
        mptr->Next = list1;
        //    mptr = temp1;
        //    temp1 = temp1->next;
    }
    if (list2 != NULL)
    {
        mptr->Next = list2;
        //    mptr = temp2;
        //    temp2 = temp2->next;
    }
    return ans->Next;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->Next == NULL)
    {
        return head;
    }
    Node *mid = middleNode(head);
    Node *head1 = head;
    Node *head2 = mid->Next;
    mid->Next = 0;
    head1 = sortList(head1);
    head2 = sortList(head2);
    return mergeTwoLists2(head1, head2);
}

class twoDNode
{
public:
    int data;
    twoDNode *Next;
    twoDNode *Bottom;

    twoDNode()
    {
        this->Next = NULL;
        this->Bottom = NULL;
    }

    twoDNode(int data)
    {
        this->data = data;
        this->Next = NULL;
        this->Bottom = NULL;
    }
};

twoDNode *flattenList(twoDNode *&root)
{
    if (root->Next == NULL)
    {
        return root;
    }

    twoDNode *temp1 = root;
    twoDNode *temp2 = root->Next;
    twoDNode *nexttemp = temp2->Next;
    temp1->Next = NULL;
    temp2->Next = NULL;
    if (temp2->data <= temp1->data)
    {
        root = temp2;
    }
    twoDNode *prevTemp1 = NULL;
    twoDNode *nextTemp2 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            prevTemp1 = temp1;
            temp1 = temp1->Bottom;
        }
        else
        {
            nextTemp2 = temp2->Bottom;
            temp2->Bottom = temp1;
            if (prevTemp1 != NULL)
            {
                prevTemp1->Bottom = temp2;
            }
            prevTemp1 = temp2;
            temp2 = nextTemp2;
        }
    }
    root->Next = nexttemp;
    twoDNode *ans = flattenList(root);
    return ans;
}

void print2DLinkedList(twoDNode *head)
{
    twoDNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Bottom;
    }
    cout << endl;
}

class Node1
{
public:
    int val;
    Node1 *next;
    Node1 *random;

    Node1(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node1 *copyRandomList(Node1 *head)
{
    if (!head)
        return NULL;

    // Step1 :- clone a -> a'
    Node1 *temp = head;
    while (temp)
    {
        Node1 *newNode = new Node1(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    // Step 2 :- Assing "random" ptr links of a
    temp = head;
    while (temp != nullptr)
    {
        Node1 *newNode = temp->next;
        if (temp->random != NULL)
        {
            newNode->random = temp->random->next;
        }
        temp = newNode->next;
    }

    // Step 3:- Detach a' from a
    temp = head;
    Node1 *cloneHead = temp->next;
    while (temp != NULL)
    {
        Node1 *cloneTemp = temp->next;
        temp->next = cloneTemp->next;
        if (cloneTemp->next != NULL)
        {
            cloneTemp->next = cloneTemp->next->next;
        }
        temp = temp->next;
    }
    return cloneHead;
}

Node *rotateRight(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int size = findLength(head);
    k = k % size;
    if (k == 0)
        return head;
    Node *temp = head;
    // return helper(head,k,temp);
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = head;
    temp = head;

    int traverse = size - k;
    while (traverse != 1)
    {
        traverse--;
        temp = temp->Next;
    }
    Node *ans = temp->Next;
    temp->Next = NULL;
    return ans;
}

vector<int> nodesBetweenCriticalPoints(Node *head)
{
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    Node *prev = head;
    if (!prev)
        return ans;
    Node *curr = head->Next;
    if (!curr)
        return ans;
    Node *nxt = head->Next->Next;
    if (!nxt)
        return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;
    while (nxt)
    {
        bool isCP = ((curr->data > prev->data && curr->data > nxt->data) ||
                     (curr->data < prev->data && curr->data < nxt->data))
                        ? true
                        : false;

        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->Next;
        curr = curr->Next;
        nxt = nxt->Next;
    }
    if (lastCP == firstCP)
    {
        return ans;
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

Node *mergeNodes(Node *head)
{
    if (head->Next->Next == NULL)
        return head->Next;
    Node *temp = head->Next;
    Node *prevTemp = NULL;
    Node *ans = NULL;
    int sum = 0;
    while (temp != NULL)
    {
        if (temp->data != 0)
        {
            sum += temp->data;
        }
        else
        {
            Node *newNode = new Node(sum);
            sum = 0;
            if (prevTemp != NULL)
            {
                prevTemp->Next = newNode;
            }
            else
            {
                ans = newNode;
            }
            prevTemp = newNode;
        }
        temp = temp->Next;
    }
    //  // Handle the last non-zero value
    // if (sum != 0) {
    //     ListNode *newNode = new ListNode(sum);
    //     if (prevTemp != nullptr) {
    //         prevTemp->next = newNode;
    //     } else {
    //         ans = newNode;
    //     }
    // }
    return ans;
}

ListNode *oddEvenList(ListNode *head)
{

    // Q.NO 11 --
    // LEETCODE Q.NO-328

    if (head == NULL || head->next == NULL ||
        head->next->next == NULL)
    {
        return head;
    }
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *firstEvenTrack = head->next;
    ListNode *trackLastOdd = NULL;

    while (odd != NULL && even != NULL)
    {

        ListNode *newOdd = odd->next;
        if (newOdd)
        {
            newOdd = newOdd->next;
        }
        odd->next = newOdd;
        odd = newOdd;
        if (odd)
        {
            trackLastOdd = odd;
        }

        ListNode *newEven = even->next;
        if (newEven)
        {
            newEven = newEven->next;
        }
        even->next = newEven;
        even = newEven;
    }
    trackLastOdd->next = firstEvenTrack;

    return head;
}

ListNode *reverse(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *doubleIt(ListNode *head)
{

    // Q.NO-12
    // LEETCODE-Q.N0-2816

    ListNode *reversedLL_Head = reverse(head);
    int carry = 0;
    ListNode *ans = NULL;
    ListNode *ansHead = NULL;
    while (reversedLL_Head)
    {
        int sum = reversedLL_Head->val + reversedLL_Head->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode(digit);
        if (ans == NULL)
        {
            ans = newNode;
            ansHead = newNode;
        }
        else
        {
            ans->next = newNode;
            ans = newNode;
        }
        reversedLL_Head = reversedLL_Head->next;
    }
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        ans->next = newNode;
    }
    ListNode *finalAns = reverse(ansHead);
    return finalAns;
}

int lengthOfList(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *swapNodes(ListNode *head, int k)
{

    // Q.NO -- 13
    // LEETCODE -- Q.NO 1721


    int length = lengthOfList(head);
    if (length == 1)
        return head;
    int i = 1;
    ListNode *temp = head;
    ListNode *firstSwap = NULL;
    while (i < k)
    {
        temp = temp->next;
        i++;
    }
    firstSwap = temp;
    temp = head;

    ListNode *lastSwap = NULL;
    i = 1;
    int lastSwapIndex = length - k;
    while (i <= lastSwapIndex)
    {
        temp = temp->next;
        i++;
    }
    lastSwap = temp;
    int firstSwapValue = firstSwap->val;
    firstSwap->val = lastSwap->val;
    lastSwap->val = firstSwapValue;
    return head;
}

void sanatizeMap(ListNode *curr, unordered_map<int, ListNode *> &mp, int csum)
{
    int csum2 = csum;
    while (true)
    {
        csum2 += curr->val;
        if (csum2 == csum)
            break;
        mp.erase(csum2);
        curr = curr->next;
    }
}
ListNode *removeZeroSumSublists(ListNode *head)
{

    // Q.N0 -- 14
    // LEETCODE -- Q.NO 1171

    if (!head || (head->next == NULL && head->val == 0))
        return 0;
    unordered_map<int, ListNode *> mp;
    auto it = head;
    int currSum = 0;
    while (it)
    {
        currSum += it->val;
        if (currSum == 0)
        {
            head = it->next;
            mp.clear();
        }
        else if (mp.find(currSum) != mp.end())
        {
            sanatizeMap(mp[currSum]->next, mp, currSum);
            mp[currSum]->next = it->next;
        }
        else
        {
            mp[currSum] = it;
        }
        it = it->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertionAtTail(head, tail, 9);
    insertionAtTail(head, tail, 1);
    insertionAtTail(head, tail, 3);
    insertionAtTail(head, tail, 5);
    insertionAtTail(head, tail, 9);
    insertionAtTail(head, tail, 4);
    insertionAtTail(head, tail, 10);
    insertionAtTail(head, tail, 1);

    printLinkedList(head);

    cout << endl
         << "Delete N nodes after every M node" << endl
         << endl;
    int m = 2, n = 1;
    delete_N_nodesAfter_M_nodes(head, m, n);
    printLinkedList(head);

    // Node *head1 = NULL;
    // Node *tail1 = NULL;
    // insertionAtTail(head1, tail1, 1);
    // insertionAtTail(head1, tail1, 2);
    // insertionAtTail(head1, tail1, 4);
    // printLinkedList(head1);

    // Node *head2 = NULL;
    // Node *tail2 = NULL;
    // insertionAtTail(head2, tail2, 1);
    // insertionAtTail(head2, tail2, 3);
    // insertionAtTail(head2, tail2, 4);
    // printLinkedList(head2);

    // cout<<"After Merging : "<<endl;
    // Node * ans=mergeTwoLists(head1,head2);
    // printLinkedList(ans);
    // return 0;

    // Node *head3 = NULL;
    // Node *tail3 = NULL;
    // insertionAtTail(head3, tail3, 4);
    // insertionAtTail(head3, tail3, 3);
    // insertionAtTail(head3, tail3, 2);
    // insertionAtTail(head3, tail3, 1);
    // printLinkedList(head3);
    // int k = 2;
    // printKthNodeFromEnd(head3, k);

    twoDNode *root = NULL;
    twoDNode *a = new twoDNode(5);
    twoDNode *a1 = new twoDNode(7);
    twoDNode *a2 = new twoDNode(8);
    twoDNode *a3 = new twoDNode(30);

    twoDNode *b = new twoDNode(10);
    twoDNode *b1 = new twoDNode(20);

    twoDNode *c = new twoDNode(19);
    twoDNode *c1 = new twoDNode(22);
    twoDNode *c2 = new twoDNode(50);

    twoDNode *d = new twoDNode(28);
    twoDNode *d1 = new twoDNode(35);
    twoDNode *d2 = new twoDNode(40);
    twoDNode *d3 = new twoDNode(45);

    a->Bottom = a1;
    a1->Bottom = a2;
    a2->Bottom = a3;
    a->Next = b;

    b->Bottom = b1;
    b->Next = c;

    c->Bottom = c1;
    c1->Bottom = c2;
    c->Next = d;

    d->Bottom = d1;
    d1->Bottom = d2;
    d2->Bottom = d3;

    root = a;

    twoDNode *ans = flattenList(root);
    print2DLinkedList(ans);
}