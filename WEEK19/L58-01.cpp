#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        if (direction == 1)
        {
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << ": {  ";
            for (pair<T, int> p : i.second)
            {
                cout << "{" << p.first << ", " << p.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    bool bfsCycleDetectionUndirected(T src, unordered_map<T, bool> &vis, unordered_map<T, T> &parentsCheck)
    {
        // adjList alrady data member me hai
        // visited

        // queue
        queue<T> q;

        // initial state
        q.push(src);
        vis[src] = true;
        parentsCheck[src] = -1;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();

            // go to nbr
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;

                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                    parentsCheck[nbrData] = frontNode;
                }
                else if (vis[nbrData] && parentsCheck[frontNode] != nbrData)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfsCycleDetectionUndirected(T src, unordered_map<T, bool> &vis, T parent)
    {
        vis[src] = true;

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (nbrData == parent)
            {
                continue;
            }
            if (!vis[nbrData])
            {
                bool ans = dfsCycleDetectionUndirected(nbrData, vis, src);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (vis[nbrData] == 1)
            {
                return true;
            }
        }
        return false;
    }
    bool dfsCycleDetectionDirected(T src, unordered_map<T, bool> &vis, unordered_map<T, bool> &dfsTrack)
    {

        vis[src] = true;
        dfsTrack[src] = true;

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                bool ans = dfsCycleDetectionUndirected(nbrData, vis, dfsTrack);
                if (ans == true)
                {
                    return true;
                }
            }
            else
            {
                if (dfsTrack[nbrData] == true)
                {
                    return true;
                }
            }
        }

        // BackTrack
        dfs[src] = false;

        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 5, 0);
    g.addEdge(1, 2, 10, 0);
    g.addEdge(1, 3, 20, 0);
    g.addEdge(2, 4, 50, 0);
    // g.addEdge(3, 4, 20, 0);
    g.addEdge(4, 5, 50, 0);

    unordered_map<int, bool> vis;
    unordered_map<int, int> parentCheck;

    cout << endl
         << endl
         << "BFS Cycle Detection" << endl;
    int src = 0;
    bool isCyclic = g.bfsCycleDetectionUndirected(src, vis, parentCheck);
    if (isCyclic)
    {
        cout << endl
             << endl
             << "Cycle Present" << endl
             << endl;
    }
    else
    {
        cout << endl
             << endl
             << "Cycle Not Present" << endl
             << endl;
    }

    cout << endl
         << endl
         << "DFS Cycle Detection" << endl;

    unordered_map<int, bool> vis1;
    int src1 = 0;
    bool isCyclicDFS = g.dfsCycleDetectionUndirected(src1, vis1, -1);
    if (isCyclicDFS)
    {
        cout << endl
             << endl
             << "Cycle Present" << endl
             << endl;
    }
    else
    {
        cout << endl
             << endl
             << "Cycle Not Present" << endl
             << endl;
    }

    return 0;
}