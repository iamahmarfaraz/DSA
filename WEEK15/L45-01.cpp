#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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
        newNode->next = head; // point newNode->Next to the head Node
        head = newNode;       // make "newNode" the new head
    }
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans)
{

    priority_queue<Info *, vector<Info *>, compare> pq;

    // 1 step : process firsk k elements
    for (int row = 0; row < k; row++)
    {
        int element = arr[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }

    while (!pq.empty())
    {
        Info *temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        // store in ans vector
        ans.push_back(topData);

        // next element for the same row, jisme se pop kia h just abhi
        // use insert bhi toh karna hai
        if (topCol + 1 < n)
        {
            // iska matlab row me or element abhi present hai
            Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        }
    }
}

class compare1
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &lists)
{
    priority_queue<Node *, vector<Node *>, compare1> pq;

    // 1 step : process firsk k elements
    for (int i = 0; i < lists.size(); i++)
    {
        Node *listHead = lists[i];
        if (listHead)
        { // Check if the list is not empty
            pq.push(listHead);
        }
    }
    Node *head = NULL;
    Node *tail = NULL;
    while (!pq.empty())
    {
        Node *topNode = pq.top();
        pq.pop();
        if (head == NULL)
        {
            // Inserting 1st Element in the Answer LL
            head = topNode;
            tail = topNode;
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
        }
        if (topNode->next != NULL)
        {
            pq.push(topNode->next);
        }
    }
    return head;
}

vector<int> smallestRange(vector<vector<int>> &nums)
{

    priority_queue<Info *, vector<Info *>, compare> pq;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    // process first k elements ko
    for (int i = 0; i < nums.size(); i++)
    {
        int element = nums[i][0];
        int row = i;
        int col = 0;
        Info *temp = new Info(element, row, col);
        pq.push(temp);
        maxi = max(maxi, element);
    }
    Info *temp = pq.top();
    mini = temp->data;

    // Phele element of k array ko process krne ke baad ye Answer aa rha
    int ansStart = mini;
    int ansEnd = maxi;

    while (!pq.empty())
    {
        Info *topNode = pq.top();
        int topData = topNode->data;
        int topCol = topNode->colIndex;
        int topRow = topNode->rowIndex;

        pq.pop();

        mini = topNode->data;
        // maxi ki value pehle se padi hui h
        // compare krlete h for smaller range
        if ((maxi - mini) < (ansEnd - ansStart))
        {
            // update ans;
            ansStart = mini;
            ansEnd = maxi;
        }

        // insertion wala step
        if (topCol + 1 < nums[topRow].size())
        {
            int newElement = nums[topRow][topCol + 1];
            maxi = max(maxi, newElement);
            Info *newInfo = new Info(newElement, topRow, topCol + 1);
            pq.push(newInfo);
        }
        else
        {
            // aggge koi element nahi h push krne ko
            break;
        }
    }
    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{
    int arr[3][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14}};
    int n = 4;
    int k = 3;

    vector<int> ans;
    mergeKSortedArrays(arr, n, k, ans);

    cout << "printing Ans array: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "  Q2  " << endl;
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    Node *head3 = NULL;
    Node *tail3 = NULL;

    insertionAtHead(head1, tail1, 5);
    insertionAtHead(head1, tail1, 4);
    insertionAtHead(head1, tail1, 1);

    insertionAtHead(head2, tail2, 4);
    insertionAtHead(head2, tail2, 3);
    insertionAtHead(head2, tail2, 1);

    insertionAtHead(head3, tail3, 6);
    insertionAtHead(head3, tail3, 2);

    vector<Node *> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    Node *mergedList = mergeKLists(lists);
    cout << "    Printing Merged K Linked List    " << endl;
    printLinkedList(mergedList);

    cout<<endl;
    cout<<"    Q3    "<<endl;
    vector<vector<int>> nums ={
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> ans1 = smallestRange(nums);
    cout<<"Smallest Range : ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}