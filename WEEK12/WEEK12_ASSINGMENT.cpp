#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class MyQueue
// Q.NO 1
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int ans = -1;
        if (!s2.empty())
        {
            ans = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            ans = s2.top();
        }
        s2.pop();
        return ans;
    }

    int peek()
    {
        int front = -1;
        if (!s2.empty())
        {
            front = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        while (size - 1)
        {
            size--;
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        int top = q.front();
        return top;
    }

    bool empty()
    {
        bool ans = false;
        if (q.empty())
        {
            ans = true;
        }
        return ans;
    }
};

class Kqueue
{
public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;

    Kqueue(int _n, int _K) : n(_n), k(_k), freespot(0)
    {
        arr = new int[n];
        next = new int[n];
        rear = new int[k];
        front = new int[k];
        for (int i = 0; i < k; i++)
        {
            rear[i] = front[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        if (freespot == -1)
        {
            return false;
        }

        // Find first free index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // if first element in q
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // Link new element to that Queue's rearest element
            next[rear[qi]] = index;
        }

        // Update Next
        next[index] = -1;

        // Update rear
        rear[qi] = index;

        // push the value
        arr[index] = x;
        return false;
    }

    int pop(int qi)
    {
        // Underflow
        if (front[qi] == -1)
        {
            return -1;
        }

        // Find Index to pop
        int index = front[qi];

        // Front Update
        front[qi] = next[index];

        // Update freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> q;

    // First window process
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        /*remove all the elements from queue that is smaller the element from the back
        side of the queue*/
        while (!q.empty() && element > nums[q.back()])
        {
            q.pop_back();
        }
        // now insert that element
        q.push_back(i);
    }

    // Remaining window process
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[q.front()]);
        int element = nums[i];
        // removal
        //  out of range wala removal
        if (i - q.front() >= k)
        {
            q.pop_front();
        }
        // chotee element pop krdo
        while (!q.empty() && element > nums[q.back()])
        {
            q.pop_back();
        }
        // addition
        q.push_back(i);
    }
    // last window ka answer
    ans.push_back(nums[q.front()]);
    return ans;
}

vector<int> minSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> q;

    // First window process
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        /*remove all the elements from queue that is larger the element from the back
        side of the queue*/
        while (!q.empty() && element <= nums[q.back()])
        {
            q.pop_back();
        }
        // now insert that element
        q.push_back(i);
    }

    // Remaining window process
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[q.front()]);
        int element = nums[i];
        // removal
        //  out of range wala removal
        if (i - q.front() >= k)
        {
            q.pop_front();
        }
        // bade element pop krdo
        while (!q.empty() && element <= nums[q.back()])
        {
            q.pop_back();
        }
        // addition
        q.push_back(i);
    }
    // last window ka answer
    ans.push_back(nums[q.front()]);
    return ans;
}

vector<int> sumMinMax(vector<int> &arr, int k)
{
    vector<int> maxAns = maxSlidingWindow(arr, k);
    vector<int> minAns = maxSlidingWindow(arr, k);
    vector<int> ans;
    for (int i = 0; i < maxAns.size(); i++)
    {
        int sum = maxAns[i] + minAns[i];
        ans.push_back(sum);
    }
}

int main()
{
    return 0;
}