#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class MinStack
{
public:
    vector<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            // It means ,i am inserting first element
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop_back();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.back().first;
        }
        return -1;
    }

    int getMin()
    {
        if (!st.empty())
        {
            return st.back().second;
        }
        return -1;
    }
};

vector<int> nextSmallerElement(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] > st.top()) // didn't check UNDERFLOW cause this stack will never be empty atleast "-1" will be in this stack
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (arr[i] < st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > st.top()) // didn't check UNDERFLOW cause this stack will never be empty atleast "-1" will be in this stack
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (arr[i] < st.top())
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}

 vector<int> nextSmallerElement2(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);
    for (int i = size - 1; i >= 0; i--)
    {
            while (st.top() != -1 && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement2(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < size; i++)
    {
            while (st.top() != -1 && arr[i] < arr[st.top()])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next= nextSmallerElement2(heights);
        // yha pr glti karoge
        for(int i=0;i<next.size();i++){
            if(next[i] == -1){
                next[i] = heights.size();
            }
        }
        vector<int> prev= prevSmallerElement2(heights);
        int area = INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width=next[i] - prev[i] - 1;
            int tempArea=width * heights[i];
            if(tempArea > area){
                area=tempArea;
            }
        }
        return area;
    }

int main()
{
    // vector<int> arr={8,4,6,2,3};
    // vector<int> ans=nextSmallerElement(arr);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

    // vector<int> ans1=prevSmallerElement(arr);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     cout<<ans1[i]<<" ";
    // }
    // cout<<endl;

    vector<int> heights={2,1,5,6,2,3};
    int area=largestRectangleArea(heights);
    cout<<"Largest Area : "<<area<<endl;

    return 0;
}