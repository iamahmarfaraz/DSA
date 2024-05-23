#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// class Graph {
//   public:
//     unordered_map<int, list<int> > adjList;
//     void addEdge(int u, int v, bool direction) {
//       //direction -> 0 -> undirected
//       //direction -> 1 -> directed
//       if(direction == 1) {
//         adjList[u].push_back(v);
//       }
//       else {
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//       }
//       cout << endl << "printing adjList" << endl;
//       printAdjList();
//       cout << endl;
//     }
//     void printAdjList() {
//       for(auto i: adjList) {
//         cout << i.first << "-> {";
//         for(auto neighbour: i.second) {
//           cout << neighbour <<", ";
//         }
//         cout << "}" << endl;
//       }
//     }
// };

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

    // This will Not Run in Case of Disconnected Graph
    // void bfsTraversal(T src)
    // {
    //     unordered_map<T, bool> visited;
    //     queue<T> q;
    //     // Maintain Initial State
    //     q.push(src);
    //     visited[src] = true;

    //     while (!q.empty())
    //     {
    //         T frontNode = q.front();
    //         q.pop();
    //         cout << frontNode << " ";

    //         // Go to Adjacent Neighbour of that node
    //         for (auto nbr : adjList[frontNode])
    //         {
    //             T nbrData = nbr.first;
    //             if (!visited[nbrData])
    //             {
    //                 q.push(nbrData);
    //                 adjList[nbrData] = true;
    //             }
    //         }
    //     }
    // }

    void bfsTraversal(T src, unordered_map<T, bool> &vis)
    {
        // adjList alrady data member me hai
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
};

int main()
{
    //   Graph g;
    //   g.addEdge(0,1,0);
    //   g.addEdge(1,2,0);
    //   g.addEdge(1,3,0);
    //   g.addEdge(2,3,0);

    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    // g.addEdge('a','c',10,0);
    g.addEdge('c', 'd', 20, 0);
    g.addEdge('c', 'e', 50, 0);
    g.addEdge('d', 'e', 20, 0);
    g.addEdge('e', 'f', 50, 0);

    unordered_map<char, bool> vis;
    for (char node = 'a'; node <= 'f'; node++)
    {
        if (!vis[node])
        {
            g.bfsTraversal(node, vis);
        }
    }

    unordered_map<char, bool> visited;
    int count = 0;
    // g.dfs('a',visited);
    for (char node = 'a'; node <= 'f'; node++)
    {
        if (!visited[node])
        {
            count++;
            g.dfs(node, visited);
        }
    }
    cout<<endl<<"No of Disconnected Component : "<<count<<endl<<endl;

    return 0;
}
