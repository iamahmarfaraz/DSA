#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        // Pushing all the elements of Queue in Stack
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        // Pushing back the element in Queue from Stack (Reversed)
        q.push(st.top());
        st.pop();
    }
}

void reverseByK(queue<int> &q, int k)
{
    if (k > q.size() || k == 0)
    {
        return;
    }

    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
    for (int i = 0; i < (q.size() - k); i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

void interleaveQueue(queue<int> &q)
{
    queue<int> first;
    queue<int> second;
    int mid = q.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        int temp = q.front();
        q.pop();
        second.push(temp);
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        first.push(temp);
    }
    while ((!first.empty()) || (!second.empty()))
    {
        if (!second.empty())
        {
            int temp = second.front();
            second.pop();
            q.push(temp);
        }
        if (!first.empty())
        {
            int temp = first.front();
            first.pop();
            q.push(temp);
        }
    }
}

void firstNegativeInEachWindow(int *arr, int n, int k)
{
    deque<int> dq;
    // Process first k elements
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        if (element < 0)
        {
            dq.push_back(i);
        }
    }
    // Process Remaining Window
    for (int i = k; i < n; i++)
    {
        // Aage brhne se pehle purani window ka ans do(last window ka ans nhi print hoga usko alag se print karao)
        if (dq.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }
        // check if we Remove the dq.front()
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // Now check for addition
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // Handle last window
    if (dq.empty())
    {
        cout << "0 ";
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{
    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    //     reverseQueue(q);

    // cout<<"Printing Queue in reverse : "<<endl;

    // reverseByK(q,5);

    // interleaveQueue(q);
    // cout << "Printing Queue reversed by K : " << endl;
    // while (!q.empty())
    // {
    //     cout << "Element : " << q.front() << endl;
    //     q.pop();
    // }

    int  arr[] ={2,-5,4,-1,-2,0,5};
    int n = 7;
    int k = 3;
    firstNegativeInEachWindow(arr,n,k);

    return 0;
}