#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
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

    void SingleSourceShortestPath(T src, stack<int> &st, int n)
    {
        vector<int> dist(n, INT_MAX);
        // T src = st.top();
        dist[src] = 0;
        // Update the distance up until the TopoStack is empty
        while (!st.empty())
        {
            T first = st.top();
            st.pop();
            for (auto nbr : adjList[first])
            {
                T nbrData = nbr.first;
                int nbrWeight = nbr.second;
                if ((dist[first] + nbrWeight) < dist[nbrData])
                {
                    dist[nbrData] = nbrWeight + dist[first];
                }
            }
        }
        cout << "Printing the Distance Array : ";
        for (auto i : dist)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    void DijkstraAlgorithm(T src, T dest, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // Intially push (0,src) in the set and update the dist[src] = 0
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto TopElement = st.begin();
            // Remove the top element
            st.erase(st.begin());
            T frontNode = TopElement->second;
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                int nbrWeight = nbr.second;
                if ((dist[frontNode] + nbrWeight) < dist[nbrData])
                {

                    // Set ki entry daalne se pehle remove the previous entry of nbrData if available
                    // this is the most important part
                    auto previousEntry = st.find({dist[nbrData], nbrData});
                    if (previousEntry != st.end())
                    {
                        st.erase(previousEntry);
                    }

                    dist[nbrData] = dist[frontNode] + nbrWeight;

                    st.insert({dist[nbrData], nbrData});
                }
            }
        }
        cout << "Shortest Distance using Dijkstra from " << src << " to " << dest << " : "<<dist[dest]<<endl;
    }
};

int main()
{
    // Graph<int> g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);

    // unordered_map<int, bool> visited;
    // stack<int> st;

    // int nodeNo = 7;
    // for (int node = 0; node < nodeNo; node++)
    // {
    //     if (!visited[node])
    //     {
    //         g.TopologicalSortByDfs(node, visited, st);
    //     }
    // }
    // int n = 5;
    // int src =0;
    // g.SingleSourceShortestPath(src,st, n);

    Graph<int> g;
    g.addEdge(6, 5, 9, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(5, 4, 6, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(4, 2, 15, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);

    g.DijkstraAlgorithm(6, 4, 6);

    return 0;
}