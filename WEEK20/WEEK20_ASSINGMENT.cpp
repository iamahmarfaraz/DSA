#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Q.NO-1       &&       GFG
class PrimsAlgorithm
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int getMinValueNode(vector<int> &key, vector<bool> &MST)
    {
        int temp = INT_MAX;
        int idx = -1;
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < temp && MST[i] == false)
            {
                temp = key[i];
                idx = i;
            }
        }
        return idx;
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // PRIM'S ALGO
        // code here
        // INITIALIZATION
        vector<int> key(V, INT_MAX);
        key[0] = 0;
        vector<bool> MST(V, false);
        vector<int> parent(V, -1);

        while (true)
        {
            // Step1 - find u
            int u = getMinValueNode(key, MST);
            if (u == -1)
            {
                break;
            }
            // Step2 - MST[u] = true;
            MST[u] = true;

            // Step3 - process all adjacent node to u
            for (auto &edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];

                if (!MST[v] && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        int sum = 0;
        for (auto i : key)
        {
            sum += i;
        }
        return sum;
    }
};

// Q.NO-2      &&      GFG
class KruskalAlgorithm
{
public:
    // Comparator to sort edges by weight
    static bool myComp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    // Find with Path Compression
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    // Union operation - your version: always increment rank
    int unionSet(int u, int v, vector<int> &parent, vector<int> &rank, int w)
    {
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);
        int ans = 0;

        if (uParent != vParent)
        {
            ans = w;
            if (rank[uParent] < rank[vParent])
            {
                parent[uParent] = vParent;
                rank[vParent]++; // Always increment rank
            }
            else
            {
                parent[vParent] = uParent;
                rank[uParent]++; // Always increment rank
            }
        }

        return ans;
    }

    // Main function to find MST weight
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<vector<int>> edges;

        // Create edge list, avoid duplicates (undirected graph)
        for (int u = 0; u < V; u++)
        {
            for (auto &edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                // Avoid duplicate edge
                if (u < v)
                {
                    edges.push_back({u, v, w});
                }
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), myComp);

        int mstWeight = 0;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mstWeight += unionSet(u, v, parent, rank, w);
        }

        return mstWeight;
    }
};

// Q.NO-3      &&       GFG
class EventualSafeStates
{
public:
    bool cycleDetectionDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsTrack, vector<int> adj[], vector<int> &safeNodes)
    {
        visited[src] = true;
        dfsTrack[src] = true;
        safeNodes[src] = 0;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool ans = cycleDetectionDFS(nbr, visited, dfsTrack, adj, safeNodes);
                if (ans == true)
                {
                    return true;
                }
            }
            else
            {
                if (dfsTrack[nbr])
                {
                    return true;
                }
            }
        }
        dfsTrack[src] = false;
        safeNodes[src] = 1;

        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        unordered_map<int, bool> visited, dfsTrack;
        vector<int> safeNodes(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cycleDetectionDFS(i, visited, dfsTrack, adj, safeNodes);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (safeNodes[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}