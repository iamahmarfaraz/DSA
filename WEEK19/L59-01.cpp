#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
#include <queue>
#include <stack>
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

    void bfsTraversal(T src, unordered_map<T, bool> &vis)
    {
        // adjList already data member me hai
        // visited

        // queue
        queue<T> q;

        // initial state
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // go to nbr
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;

                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &vis)
    {
        vis[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                dfs(nbrData, vis);
            }
        }
    }

    void TopologicalSortByDfs(T src, unordered_map<T, bool> &vis, stack<T> &st)
    {
        vis[src] = true;

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                TopologicalSortByDfs(nbrData, vis, st);
            }
        }
        st.push(src);
    }

    void TopologicalSortByBfs()
    {
        queue<T> q;
        unordered_map<T, int> indegree;

        // Initialize Indegree of each Node in Graph
        for (auto node : adjList)
        {

            for (auto nbr : node.second)
            {
                T front = nbr.first;
                indegree[front]++;
            }
        }

        // for(auto i:indegree){
        //     cout<<i.first<<"->"<<i.second<<endl;
        // }

        for (auto i : adjList)
        {
            if (indegree[i.first] == 0)
            {
                q.push(i.first);
            }
        }

        // Bfs
        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ",";
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                indegree[nbrData]--;
                if (indegree[nbrData] == 0)
                {
                    q.push(nbrData);
                }
            }
        }
    }

    bool CycleDetectionBfs(vector<T> &topo)
    {
        queue<T> q;
        unordered_map<T, int> indegree;

        // Initialize Indegree of each Node in Graph
        for (auto node : adjList)
        {

            for (auto nbr : node.second)
            {
                T front = nbr.first;
                indegree[front]++;
            }
        }

        // for(auto i:indegree){
        //     cout<<i.first<<"->"<<i.second<<endl;
        // }

        for (auto i : adjList)
        {
            if (indegree[i.first] == 0)
            {
                q.push(i.first);
            }
        }

        // Bfs
        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            topo.push_back(frontNode);
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                indegree[nbrData]--;
                if (indegree[nbrData] == 0)
                {
                    q.push(nbrData);
                }
            }
        }
        if (adjList.size() == topo.size())
        {
            return false;
        }
        return true;
    }

    void ShortestPathBFS(T src, T dest, unordered_map<T, bool> &vis, unordered_map<T, T> &parent, vector<T> &ans)
    {
        queue<T> q;
        // Initial State
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        // Setting Parent of each Node cause through parent we can reach at any node through shortest path
        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData]=true;
                    parent[nbrData] = frontNode;
                }
            }
        }

        T final = parent[src]; // final se pehle tk loop chalega to src node tk pahuch jayenge agr src node beech me bhi hua to

        // // Parent Array tayar hone ke baad
        // while (dest != -1)
        // {
        //     // Basically we are traversing in backward direction from destination to build the shortest node till source
        //     ans.push_back(dest);
        //     dest = parent[dest];
        // }

        // Parent Array tayar hone ke baad
        while (dest != final)
        {
            // Basically we are traversing in backward direction from destination to build the shortest node till source
            ans.push_back(dest);
            dest = parent[dest];
        }
        reverse(ans.begin(),ans.end());
    }
};

class Solution
{
public:
    class Graphyy
    {
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v)
        {
            adjList[u].push_back(v);
        }

        bool CycleDetectionBfs()
        {
            vector<int> topo;
            queue<int> q;
            unordered_map<int, int> indegree;

            // Initialize Indegree of each Node in Graph
            for (auto node : adjList)
            {

                for (auto nbr : node.second)
                {
                    indegree[nbr]++;
                }
            }

            for (auto i : adjList)
            {
                if (indegree[i.first] == 0)
                {
                    q.push(i.first);
                }
            }

            // Bfs
            while (!q.empty())
            {
                int frontNode = q.front();
                q.pop();
                topo.push_back(frontNode);
                for (auto nbr : adjList[frontNode])
                {
                    indegree[nbr]--;
                    if (indegree[nbr] == 0)
                    {
                        q.push(nbr);
                    }
                }
            }
            if (adjList.size() == topo.size())
            {
                return false;
            }
            return true;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        Graphyy g;
        for (auto row : prerequisites)
        {
            g.addEdge(row[1], row[0]);
        }
        bool ans = g.CycleDetectionBfs();
        return !ans;
    }
};

int main()
{
    // Graph<int> g;
    // g.addEdge(0, 1, 0, 1);
    // g.addEdge(1, 2, 0, 1);
    // g.addEdge(2, 3, 0, 1);
    // g.addEdge(3, 4, 0, 1);
    // g.addEdge(3, 5, 0, 1);
    // g.addEdge(4, 6, 0, 1);
    // g.addEdge(5, 6, 0, 1);
    // g.addEdge(6, 7, 0, 1);

    // g.printAdjList();

    // unordered_map<int, bool> visited;
    // stack<int> st;

    // int nodeNo = 8;
    // for (int node = 0; node < nodeNo; node++)
    // {
    //     if (!visited[node])
    //     {
    //         g.TopologicalSortByDfs(node, visited, st);
    //     }
    // }
    // cout << "PRINTING TOPOLOGICAL SORT : " << endl;
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout<<endl;

    // Graph<int> g;
    // g.addEdge(0, 1, 0, 1);
    // g.addEdge(1, 2, 0, 1);
    // g.addEdge(2, 3, 0, 1);
    // g.addEdge(3, 5, 0, 1);
    // g.addEdge(5, 4, 0, 1);
    // g.addEdge(4, 2, 0, 1);
    // g.addEdge(5, 6, 0, 1);
    // g.addEdge(5, 7, 0, 1); // this graph is cyclic

    // g.TopologicalSortByBfs();
    // cout << endl;

    // vector<int> topo;
    // if (g.CycleDetectionBfs(topo))
    // {
    //     cout << "Cycle present in Graph" << endl
    //          << endl;
    // }
    // else
    // {
    //     cout << "Cycle isn't present in Graph" << endl
    //          << endl;
    // }

    // int n = 2;
    // vector<vector<int>> preRequisit{{1, 0}, {0, 1}};

    Graph<int> g;
    g.addEdge(0, 4, 0, 0);
    g.addEdge(0, 3, 0, 0);
    g.addEdge(0, 6, 0, 0);
    g.addEdge(4, 1, 0, 0);
    g.addEdge(3, 5, 0, 0);
    g.addEdge(6, 2, 0, 0);
    g.addEdge(1, 5, 0, 0);
    g.addEdge(2, 5, 0, 0);

    unordered_map<int, bool> Vis;
    unordered_map<int, int> parent;
    vector<int> ans;
    int src = 0;
    int dest = 5;
    g.ShortestPathBFS(src,dest,Vis,parent,ans);
    cout<<"SHORTEST PATH FROM \""<<src<<"\" to \""<<dest<<"\" is : ";
    for (auto i:ans)
    {
        cout<<i<<" -> ";
    }
    cout<<endl;
    

    return 0;
}