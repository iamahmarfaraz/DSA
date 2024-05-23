#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Nstack
{
public:
    int *a, *top, *next;
    int n;        // no. of stacks
    int size;     // size of main array
    int freespot; // tells free space in main array

    Nstack(int _n, int _s) : n(_n), size(_s)
    {
        freespot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }

    // pushing X in mth Stack
    void push(int X, int m)
    {
        if (freespot == -1)
        {
            // Stack OverFlow
            cout << "Stack OverFlow" << endl;
            return;
        }
        // 1.Find Index
        int index = freespot;

        // 2.Update Freespot
        freespot = next[index];

        // 3.Push Value
        a[index] = X;

        // 4.Update next
        next[index] = top[m - 1];

        // 5.Update Top
        top[m - 1] = index;
    }

    // pop from mth Stack
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            // Stack UnderFlow
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        // 1.Find Index
        int index = top[m - 1];

        // 2.Update Top
        top[m - 1] = next[index];

        // 3.Update next
        next[index] = freespot;

        // 4.Update Freespot
        freespot = index;
        return a[index];
    }

    ~Nstack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

class StockSpanner
{
public:
    stack<int> st;
    vector<int> v;

    StockSpanner()
    {
        st.push(-1);
    }

    int next(int price)
    {
        v.push_back(price);
        while ((st.top() > -1) && price >= v[st.top()])
        {
            st.pop();
        }
        int end = v.size() - 1;
        int ans = end - st.top();
        st.push(end);
        return ans;
    }
};

stack<char> validParanthesis(string &s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (!st.empty() && ch == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    return st;
}
int countRev(string s)
{
    int count = 0;
    stack<char> temp = validParanthesis(s);
    if (temp.empty())
    {
        return 0;
    }
    if (s.size() & 1)
    {
        return -1;
    }
    stack<char> ans;
    while (!temp.empty())
    {
        if (!ans.empty() && ans.top() == '{' && temp.top() == '}')
        {
            count += 2;
            ans.pop();
        }
        else if (!ans.empty() && ans.top() == '{' && temp.top() == '{')
        {
            count++;
            ans.pop();
        }
        else if (!ans.empty() && ans.top() == '}' && temp.top() == '}')
        {
            count++;
            ans.pop();
        }
        else
        {
            ans.push(temp.top());
        }
        temp.pop();
    }
    return count;
}

string removeDuplicates(string s)
{
    int size = s.size();
    stack<char> st;
    for (int i = 0; i < size; i++)
    {
        if (!st.empty() > 0 && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int celebrityProblem(vector<vector<int>> &m, int n)
{
    stack<int> st;

    // Step1 : push all person(row) in stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a knows b
        if (m[a][b])
        {
            // mean a knows b
            st.push(b);
        }
        else
        {
            // b knows a
            st.push(a);
        }
    }
    // Step3: Check if that Single person from the stack is actually celebrity
    int celeb = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (m[celeb][i] != 0)
        {
            return -1;
        }
    }

    // check if every person knows the celeb
    for (int i = 0; i < n; i++)
    {
        if (m[i][celeb] == 0 && i != celeb)
        {
            return -1;
        }
    }
    return celeb;
}

bool isValid(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'b')
            {
                return false;
            }
            st.push(ch);
        }
        else
        { // ch == "c"
            if (!st.empty() && st.top() == 'a')
            {
                return false;
            }
            if (st.size() > 1 && st.top() == 'b')
            {
                st.pop();
                st.pop();
            }
        }
    }
    bool ans = false;
    if (st.empty())
    {
        ans = true;
    }
    return ans;
}

string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (ch == ']')
        {
            string temp = "";
            while (!st.empty() && st.top() != "[")
            {
                string top = st.top();
                temp += top;
                st.pop();
            }
            st.pop();
            string num = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                num += st.top();
                st.pop();
            }
            reverse(num.begin(), num.end());
            int n = stoi(num);
            // Final Decoding
            string currDecode = "";
            while (n--)
            {
                currDecode += temp;
            }
            st.push(currDecode);
        }
        else
        {
            string store(1, ch);
            st.push(store);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void buildAns(stack<string> &s, string &ans)
{
    if (s.empty())
    {
        return;
    }
    string minpath = s.top();
    s.pop();
    buildAns(s, ans);
    ans += minpath;
}
string simplifyPath(string path)
{
    stack<string> s;
    int i = 0;
    while (i < path.size())
    {
        int start = i;
        int end = i + 1;
        while (end < path.size() && path[end] != '/')
        {
            ++end;
        }
        string minpath = path.substr(start, end - start);
        i = end;
        if (minpath == "/" || minpath == "/.")
        {
            continue;
        }
        if (minpath != "/..")
        {
            s.push(minpath);
        }
        else if (!s.empty())
        {
            s.pop();
        }
    }
    string ans = s.empty() ? "/" : "";
    buildAns(s, ans);
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
int largestRectangleArea(vector<int> &heights)
{
    vector<int> next = nextSmallerElement2(heights);
    // yha pr glti karoge
    for (int i = 0; i < next.size(); i++)
    {
        if (next[i] == -1)
        {
            next[i] = heights.size();
        }
    }
    vector<int> prev = prevSmallerElement2(heights);
    int area = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = next[i] - prev[i] - 1;
        int tempArea = width * heights[i];
        if (tempArea > area)
        {
            area = tempArea;
        }
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < m; j++)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }
    int ans = largestRectangleArea(v[0]);
    vector<int> sum = v[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                sum[j] = 0;
            }
            else
            {
                sum[j] = sum[j] + v[i][j];
            }
        }
        int temp = largestRectangleArea(sum);
        if (temp > ans)
        {
            ans = temp;
        }
    }
    return ans;
}

class Car
{
public:
    int pos, speed;
    Car(int p, int s) : pos(p), speed(s){};
};
static bool myComp(Car &a, Car &b)
{
    return a.pos < b.pos;
}
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<Car> cars;
    for (int i = 0; i < position.size(); i++)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(), cars.end(), myComp);
    stack<float> st;
    for (auto car : cars)
    {
        float time = (target - car.pos) / ((float)car.speed);
        while (!st.empty() && time >= st.top())
        {
            st.pop();
        }
        st.push(time);
    }
    int ans = st.size();
    return ans;
}

int main()
{
    // string s = "}{{}}{{{";
    // int ans = countRev(s);
    // cout << ans;
    // vector<vector<int>> m={{0,1,0},{0,0,0},{0,1,0}};
    // int n=3;
    // int celeb = celebrityProblem(m,n);
    // cout<<"Person No \""<<celeb<<"\" is the Celebrity"<<endl;

    Nstack st(3, 6);
    st.push(10, 1);
    cout << st.pop(1);
    return 0;
}