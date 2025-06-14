#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Q.NO-1       &&        SPOJ
class DEFKIN
{
public:
    DEFKIN()
    {
        // cout << "DEFKIN" << endl;
    }

    int solve(int &row, int &col, int &tower, vector<pair<int, int>> &pos)
    {
        vector<int> rows, cols;

        // Extract rows and columns separately
        for (auto &p : pos)
        {
            cols.push_back(p.first);
            rows.push_back(p.second);
        }

        // Add boundaries
        rows.push_back(0);
        rows.push_back(row + 1);
        cols.push_back(0);
        cols.push_back(col + 1);

        // Sort them
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        // Find max gaps
        int maxRowGap = 0, maxColGap = 0;
        for (int i = 1; i < rows.size(); i++)
        {
            maxRowGap = max(maxRowGap, rows[i] - rows[i - 1] - 1);
        }
        for (int i = 1; i < cols.size(); i++)
        {
            maxColGap = max(maxColGap, cols[i] - cols[i - 1] - 1);
        }

        return maxRowGap * maxColGap;
    }
};

// Q.NO-2      &&       GFG
class MinimumCostofropes
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : arr)
        {
            pq.push(i);
        }

        int cost = 0;
        while (pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();
            int second_top = pq.top();
            pq.pop();
            int sum = top + second_top;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};

// Q.NO-3     &&       GFG
class FractionalKnapsack
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        priority_queue<pair<double, int>> valToWtRatio; // {ratio, index}

        for (int i = 0; i < val.size(); i++)
        {
            double ratio = (val[i] * 1.0) / wt[i];
            valToWtRatio.push({ratio, i});
        }

        double profit = 0;
        while (!valToWtRatio.empty() && capacity > 0)
        {
            auto topp = valToWtRatio.top();
            valToWtRatio.pop();
            int idx = topp.second;

            if (capacity >= wt[idx])
            {
                profit += val[idx];
                capacity -= wt[idx];
            }
            else
            {
                profit += topp.first * capacity; // ratio * remaining capacity
                capacity = 0;
            }
        }

        return profit;
    }
};

// Q.NO-4   &&    GFG
class Nmeetingsinoneroom
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {end, start}

        int n = start.size();
        for (int i = 0; i < n; ++i)
        {
            pq.push({end[i], start[i]});
        }

        // Pop the first meeting, always selected
        auto prev = pq.top();
        pq.pop();
        int count = 1;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            if (curr.second > prev.first)
            { // if curr.start > prev.end
                count++;
                prev = curr; // update prev meeting to current one
            }
        }

        return count;
    }
};

int main()
{
    int row = 8;
    int col = 15;
    int tower = 3;
    vector<pair<int, int>> pos(tower); // {col, row}
    pos[0] = {3, 8};
    pos[1] = {11, 2};
    pos[2] = {8, 6};

    DEFKIN *D1 = new DEFKIN();
    cout << "ANSWER = " << D1->solve(row, col, tower, pos) << endl;

    priority_queue<int, vector<int>, greater<int>> pq;

    return 0;
}
