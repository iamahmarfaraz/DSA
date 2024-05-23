#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

int solve(stack<int> &st, int pos)
{
    if (pos <= 1)
    {
        return st.top();
    }

    int temp = st.top();
    st.pop();
    int ans = solve(st, pos - 1);
    // BackTracking
    st.push(temp);
    return ans;
}

int getMiddle(stack<int> &st)
{
    int size = st.size();
    int pos = 0;
    if (st.empty())
    {
        cout << "No Middle element" << endl;
        return -1;
    }
    else
    {
        if (size & 1)
        {
            // Odd
            pos = size / 2 + 1;
        }
        else
        {
            // even
            pos = size / 2;
        }
    }
    int ans = solve(st, pos);
    return ans;
}

void insertAtBottomStack(stack<int> &st, int data)
{
    int size = st.size();
    if (size == 0)
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottomStack(st, data);
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottomStack(st, temp);
}

void insertionInSortedStack(stack<int> &st, int data)
{
    if (st.empty() || data >= st.top())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    insertionInSortedStack(st, data);
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    int size = st.size();
    if (size == 0)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertionInSortedStack(st, temp);
}

void stackPrint(stack<int> &st)
{
    stack<int> temp=st;
    while (!temp.empty())
    {
        cout << temp.top() << " " << endl;
        temp.pop();
    }
    cout << endl;
}

int main()
{
    // string s="Ahmar";
    // stack<char> st;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     st.push(s[i]);
    // }
    // while (!st.empty())
    // {
    //     cout<<st.top();
    //     st.pop();
    // }cout<<endl;

    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);

    // int ans = getMiddle(st);
    // cout << "Middle Element of the stack : " << ans << endl;

    // insertAtBottomStack(st,5);
    // while (!st.empty())
    // {
    //     cout<<st.top()<<" "<<endl;
    //     st.pop();
    // }
    // cout<<endl;

    // cout << "Before Reversing Stack : " << endl;
    // while (!st.empty())
    // {
    //     cout << st.top() << " " << endl;
    //     st.pop();
    // }
    // cout << endl;

    // cout << "After Reversing Stack : " << endl;
    // reverseStack(st);
    // while (!st.empty())
    // {
    //     cout << st.top() << " " << endl;
    //     st.pop();
    // }
    // cout << endl;

    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);

    // insertionInSortedStack(st,35);
    // cout << "After insertion in a sorted Stack : " << endl;
    // while (!st.empty())
    // {
    //     cout << st.top() << " " << endl;
    //     st.pop();
    // }
    // cout << endl;

    stack<int> st;
    st.push(60);
    st.push(10);
    st.push(12);
    st.push(11);
    st.push(14);
    st.push(5);

    // cout << "Before Sorting : ";
    // stackPrint(st);
    sortStack(st);
    cout << "After Sorting : ";
    stackPrint(st);
    //cout<<st.top();

    return 0;
}