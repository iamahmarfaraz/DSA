#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Info
{
public:
    char val;
    int count;
    Info(char a, int b)
    {
        this->val = a;
        this->count = b;
    }
};

class compare
{
public:
    bool operator()(Info a, Info b)
    {
        return a.count < b.count;
    }
};

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < piles.size(); i++)
    {
        int element = piles[i];
        maxHeap.push(element);
    }

    while (k--)
    {
        int topElement = maxHeap.top();
        maxHeap.pop();
        topElement = topElement - (topElement / 2);
        maxHeap.push(topElement);
    }
    int sum = 0;
    while (!maxHeap.empty())
    {
        int top = maxHeap.top();
        maxHeap.pop();
        sum += top;
    }
    return sum;
}

string reorganizeString(string s)
{
    int freq[26] = {0};
    // Count frequency of each character in string
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
    }

    // Push character in MaxHeap
    priority_queue<Info, vector<Info>, compare> maxHeap;
    // Push all the character in heap if freq > 0
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            Info temp(i + 'a', freq[i]);
            // temp.val = i + 'a';
            // temp.count = freq[i];
            maxHeap.push(temp);
        }
    }
    string ans = "";
    while (maxHeap.size() > 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();
        Info second = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;
        ans.push_back(second.val);
        second.count--;

        if (first.count > 0)
        {
            maxHeap.push(first);
        }
        if (second.count > 0)
        {
            maxHeap.push(second);
        }
    }

    if (maxHeap.size() == 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();
        ans.push_back(first.val);
        first.count--;
        if (first.count != 0)
        {
            // Can't be able to find the answer
            return "";
        }
    }
    return ans;
}

string longestDiverseString(int a, int b, int c)
{
    // Push character in MaxHeap
    priority_queue<Info, vector<Info>, compare> maxHappy;
    if (a > 0)
    {
        Info temp1('a', a);
        // temp1.val = 'a';
        // temp1.count = a;
        maxHappy.push(temp1);
    }
    if (b > 0)
    {
        Info temp2('b', b);
        // temp2.val = 'b';
        // temp2.count = b;
        maxHappy.push(temp2);
    }
    if (c > 0)
    {
        Info temp3('c', c);
        // temp3.val = 'c';
        // temp3.val = c;
        maxHappy.push(temp3);
    }
    string ans = "";
    while (maxHappy.size() > 1)
    {

        Info first = maxHappy.top();
        maxHappy.pop();
        Info second = maxHappy.top();
        maxHappy.pop();

        ans.push_back(first.val);
        first.count--;
        if (first.count > 0)
        {
            ans.push_back(first.val);
            first.count--;
        }

        if (second.count >= 2 && second.count >= first.count)
        {
            ans.push_back(second.val);
            ans.push_back(second.val);
            second.count -= 2;
        }
        else
        {
            ans.push_back(second.val);
            second.count--;
        }
        if (first.count != 0)
        {
            maxHappy.push(first);
        }
        if (second.count != 0)
        {
            maxHappy.push(second);
        }
    }
    if (maxHappy.size() == 1)
    {
        Info first = maxHappy.top();
        maxHappy.pop();
        ans.push_back(first.val);
        first.count--;
        if (first.count > 0)
        {
            ans.push_back(first.val);
            first.count--;
            // if(first.count != 0){
            //     return "";
            // }
        }
    }
    return ans;
}

int medianInAStream(vector<int> &arr){
    int size = arr.size();
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    // Making MaxHeap with 1st half 
    for (int i = 0; i < (size/2); i++)
    {
        maxHeap.push(arr[i]);
    }
    
    // Maling MinHeap with the other Half
    for (int i = (size/2); i < size; i++)
    {
        minHeap.push(arr[i]);
    }
    int maxHeapSize = maxHeap.size();
    int minHeapSize = minHeap.size();
    if ((maxHeapSize+1)==minHeapSize)
    {
        return minHeap.top();
    }
    if (maxHeapSize == (minHeapSize+1))
    {
        return maxHeap.top();
    }
    if (maxHeapSize == minHeapSize)
    {
        int MaxHeapTop = maxHeap.top();
        int MinHeapTop = minHeap.top();
        int ans = (MaxHeapTop+MinHeapTop)/2;
        return ans;
    }
    
    
}



int main()
{
    vector<int> piles = {5, 4, 9};
    int k = 2;
    int ans = minStoneSum(piles, k);
    cout << endl;
    cout << "Total Number of Stones remaning in the piles after " << k << " operations : \"" << ans << "\" " << endl;
    cout << " " << endl;

    string s = "aab";
    string ans1 = reorganizeString(s);
    cout << "ReOrganized String = " << ans1 << endl<<endl;

    int a=1,b=1,c=7;
    string ans2 = longestDiverseString(a,b,c);
    cout<<"Longest Happy String : "<<ans2<<endl;

    

    return 0;
}