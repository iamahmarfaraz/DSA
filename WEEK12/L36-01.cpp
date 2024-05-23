#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
void firstUniqChar(string s)
{
    queue<char> q;
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << "#"
                 << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0; // how much gas is short
    int balance = 0; // how much extra gas left after travelling
    // index from where we start movement
    int start = 0;

    for (int i = start; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    if (balance - deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

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

int main()
{
    // string s = "ababc";
    // firstUniqChar(s);

    // vector<int> gas ={1,2,3,4,5};
    // vector<int> cost ={3,4,5,1,2};
    // cout<<"Index at which we should start our journey : "<<canCompleteCircuit(gas,cost);

    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}