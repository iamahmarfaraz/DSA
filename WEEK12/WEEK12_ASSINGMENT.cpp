#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class MyQueue

// Q.NO 1
// LEETCODE -- Q.NO-232

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

// Q.NO--2
// LEETCODE -- Q.NO-225

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

    // Q.NO-3

public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;

    Kqueue(int _n, int _k) : n(_n), k(_k), freespot(0)
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

    // LEETCODE -- Q.NO-239

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

    // Q.NO - 4

    vector<int> maxAns = maxSlidingWindow(arr, k);
    vector<int> minAns = maxSlidingWindow(arr, k);
    vector<int> ans;
    for (int i = 0; i < maxAns.size(); i++)
    {
        int sum = maxAns[i] + minAns[i];
        ans.push_back(sum);
    }
}

class RecentCounter
{

    // Q.NO - 5
    // LEETCODE -- Q.NO-933

public:
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        // step1- push in queue
        q.push(t);
        // step2- invalid range wali calls ko front of queue se remove krte jao
        int range = t - 3000;
        while (!q.empty() && q.front() < range)
        {
            q.pop();
        }
        // step3- return q.size()
        return q.size();
    }
};

int findTheWinner(int n, int k)
{

    // Q.NO-6
    // LEETCODE -- Q.NO-1832

    queue<int> q;

    // push all the players inside the queue
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        int it = k;
        while (it != 0)
        {
            int temp = q.front();
            q.pop();
            if (it != 1)
            {
                q.push(temp);
            }
            it--;
        }
    }
    return q.front();
}

vector<int> deckRevealedIncreasing(vector<int> &deck)
{

    // Q.NO - 7
    // LEETCODE -- Q.NO-950

    sort(deck.begin(), deck.end());

    // push all the index in queue
    queue<int> q;
    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }

    // create a ans array/vector of same length as deck
    vector<int> ans(deck.size(), 0);

    int i = 0;
    while (!q.empty())
    {
        ans[q.front()] = deck[i];
        q.pop();
        if (!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    return ans;
}

int peopleAwareOfSecret(int n, int delay, int forget)
{

    // Q.NO - 8
    // LEETCODE -- Q.NO-2327

    const int M = 1e9 + 7;
    int curr = 0; // no. of active spreaders
    int ans = 1;
    queue<pair<int, int>> delayQ, forgetQ; // us din kitne naye log ko secret pta lga h hue hain ye store krega

    delayQ.push({1, 1});
    forgetQ.push({1, 1});
    for (int i = 1; i <= n; i++)
    {
        // step1 :- check kitne log forget kr rhe
        if (!forgetQ.empty() && forgetQ.front().first + forget <= i)
        {
            // that means front is forgotten the secret
            auto front = forgetQ.front();
            forgetQ.pop();
            auto noOfPersonForgotten = front.second;
            ans = (ans - noOfPersonForgotten + M) % M;
            curr = (curr - noOfPersonForgotten + M) % M;
        }
        // Step2 :- make new active spreaders
        if (!delayQ.empty() && delayQ.front().first + delay <= i)
        {
            // that means ab front active spreader h
            auto front = delayQ.front();
            delayQ.pop();
            curr = (curr + front.second) % M;
        }
        // step3:- spread the secret
        if (curr > 0)
        {
            ans = (ans + curr) % M;
            forgetQ.push({i, curr});
            delayQ.push({i, curr});
        }
    }
    return ans;
}

int main()
{
    return 0;
}