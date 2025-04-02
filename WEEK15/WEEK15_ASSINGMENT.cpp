#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val)
    {
        this->left = NULL;
        this->right = NULL;
    }
};

// Q.NO-1
int noOfNodes(Node *root)
{
    if (!root)
        return 0;
    int left = noOfNodes(root->left);
    int right = noOfNodes(root->right);

    return (1 + left + right);
}

bool completeBinaryTree(Node *root, int i, int &n)
{
    if (!root)
        return true;

    int left = 2 * i;
    int right = (2 * i) + 1;

    if (root->left && ((left > n) || (root->data < root->left->data)))
    {
        return false;
    }
    if (root->right && ((right > n) || (root->data < root->right->data)))
    {
        return false;
    }
    bool leftAns = completeBinaryTree(root->left, left, n);
    bool rightAns = completeBinaryTree(root->right, right, n);

    return (leftAns && rightAns);
}

bool isBinaryHeapTree(Node *root)
{
    int n = noOfNodes(root);

    return completeBinaryTree(root, 1, n);
}

// Q.NO-2
// O-Index Based Heapification
void heapify(vector<int> &arr, int n, int index)
{
    int largestKaIndex = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    if (leftIndex < n && arr[leftIndex] > arr[largestKaIndex])
        largestKaIndex = leftIndex;

    if (rightIndex < n && arr[rightIndex] > arr[largestKaIndex])
        largestKaIndex = rightIndex;

    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largestKaIndex);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Merge the two heaps
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());

    int size = arr1.size();

    // Building max heap from the merged array (0-based indexing)
    for (int index = (size / 2) - 1; index >= 0; index--)
    {
        heapify(arr1, size, index);
    }

    return arr1;
}

// Q.NO-3     &&      LEETCODE-Q.NO-973
class Solution
{
public:
    class myComp
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            int distA = a.first * a.first + a.second * a.second;
            int distB = b.first * b.first + b.second * b.second;
            // Min-heap: keep the smaller distance at the top
            return distA > distB;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        // Min-heap based on distance from origin
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;

        // Push all points into the min-heap
        for (auto &point : points)
        {
            int X = point[0];
            int Y = point[1];
            pq.push({X, Y});
        }

        // Extract the top k elements from the min-heap
        while (!pq.empty() && k--)
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.first, top.second});
        }

        return ans;
    }
};

// Q.NO-4      &&     LEETCODE-Q.NO-1878
bool checkBound(vector<vector<int>> &grid, vector<pair<int, int>> &v)
{
    int m = grid.size();
    int n = grid[0].size();
    for (auto pt : v)
    {
        if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n)
        {
            return false;
        }
    }
    return true;
}
bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, const pair<int, int> &c, int &delta)
{
    pair<int, int> up(c.first - delta, c.second);
    pair<int, int> right(c.first, c.second + delta);
    pair<int, int> down(c.first + delta, c.second);
    pair<int, int> left(c.first, c.second - delta);
    v[0] = up;
    v[1] = right;
    v[2] = down;
    v[3] = left;
    if (checkBound(grid, v))
    {
        return true;
    }
    return false;
}
void getAllSum(vector<vector<int>> &grid, int &i, int &j, priority_queue<int> &pq)
{
    pq.push(grid[i][j]);
    int delta = 1;
    vector<pair<int, int>> v(4); // store 4 corner of each robmus generated
    while (getAllVertices(grid, v, {i, j}, delta))
    {
        pair<int, int> &A = v[0];
        pair<int, int> &B = v[1];
        pair<int, int> &C = v[2];
        pair<int, int> &D = v[3];
        int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];
        // A TO B Path sum
        int a_YAxis = A.first + 1;  // row cordinate
        int a_XAxis = A.second + 1; // col cordinate
        while (a_YAxis < B.first && a_XAxis < B.second)
        {
            csum += grid[a_YAxis][a_XAxis];
            a_YAxis++;
            a_XAxis++;
        }
        // B TO C Path sum
        int b_YAxis = B.first + 1;  // row cordinate
        int b_XAxis = B.second - 1; // col cordinate
        while (b_YAxis < C.first && b_XAxis > C.second)
        {
            csum += grid[b_YAxis][b_XAxis];
            b_YAxis++;
            b_XAxis--;
        }
        // C TO D Path sum
        int c_YAxis = C.first - 1;  // row cordinate
        int c_XAxis = C.second - 1; // col cordinate
        while (c_YAxis > D.first && c_XAxis > D.second)
        {
            csum += grid[c_YAxis][c_XAxis];
            c_YAxis--;
            c_XAxis--;
        }
        // D TO A Path sum
        int d_YAxis = D.first - 1;  // row cordinate
        int d_XAxis = D.second + 1; // col cordinate
        while (d_YAxis > A.first && d_XAxis < A.second)
        {
            csum += grid[d_YAxis][d_XAxis];
            d_YAxis--;
            d_XAxis++;
        }
        pq.push(csum);
        ++delta;
    }
}

bool canPush(vector<int> &ans, int &top)
{
    for (auto val : ans)
    {
        if (val == top)
            return false;
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    vector<int> ans;
    priority_queue<int> pq;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, pq);
        }
    }

    while (!pq.empty() && ans.size() < 3)
    {
        int top = pq.top();
        pq.pop();
        if (canPush(ans, top))
        {
            ans.push_back(top);
        }
    }
    return ans;
}

// Q.NO-5    &&    LEETCODE-Q.NO-2163
#define ll long long
long long minimumDifference(vector<int> &nums)
{
    int n = nums.size() / 3;
    vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
    // prefix[i] store min sum of n element from left side
    // suffix[i] store max sum of n element from right side

    ll sum = 0;
    priority_queue<ll> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        pq.push(nums[i]);
        if (pq.size() > n)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == n)
        {
            prefix[i] = sum;
        }
    }

    sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq2;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        sum += nums[i];
        pq2.push(nums[i]);
        if (pq2.size() > n)
        {
            sum -= pq2.top();
            pq2.pop();
        }
        if (pq2.size() == n)
        {
            suffix[i] = sum;
        }
    }

    ll ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; i++)
    {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }
    return ans;
}

// Q.NO-6      &&     LEETCODE-Q.NO-2163
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int stops = 0;
    int dist = 0;
    int i = 0;
    int fuel = startFuel;
    priority_queue<pair<int, int>> pq; //{fuel,position}
    while (true)
    {
        while (i < stations.size())
        {
            if (stations[i][0] <= dist + fuel)
            {
                pq.push({stations[i][1], stations[i][0]});
            }
            else
            {
                break;
            }
            i++;
        }

        // travel with full fuel level
        dist += fuel;
        fuel = 0;
        if (dist >= target)
        {
            break;
        }

        // no fuel station within reach
        if (pq.empty())
        {
            return -1;
        }

        auto maxStation = pq.top();
        fuel = (dist - maxStation.second) + maxStation.first;
        dist = maxStation.second;
        pq.pop();
        stops++;
    }

    return stops;
}

// Q.NO-7      &&     LEETCODE-Q.NO-239
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>> pq; // {element, index}

    // Process the first window of k elements
    for (int i = 0; i < k; ++i)
    {
        pq.push({nums[i], i});
    }

    // Store the maximum for the first window
    ans.push_back(pq.top().first);

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++)
    {
        // Push the current element into the priority queue
        pq.push({nums[i], i});

        // Remove elements from the top that are out of the current window
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }

        // The top of the heap now contains the maximum element within the window
        ans.push_back(pq.top().first);
    }

    return ans;
}

int main()
{

    return 0;
}