#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <set>
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
    static bool myComp(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }

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
    bool cycleDetectionDFS(int src, unordered_map<int, bool> &visited,
                           unordered_map<int, bool> &dfsTrack, vector<int> adj[],
                           vector<int> &safeNodes)
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

// Q.NO-4     &&      GFG     &&      LEETCODE-Q.NO-127
class WordLadderI
{
public:
    int wordLadderLength(string beginWord, string endWord,
                         vector<string> &wordList)
    {
        // Code here
        queue<pair<string, int>> q; //{currentWord, number of steps taken to reach
                                    // this word from the beginWord }
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return 0; // endWord must be in wordList

        st.erase(beginWord); // remove beginWord if present - i.e visited

        while (!q.empty())
        {
            pair<string, int> fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            // Check if we reached the destination
            if (currString == endWord)
            {
                return currCount;
            }

            for (int index = 0; index < currString.length(); index++)
            {
                char originalCharacter = currString[index];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;
                    // check in wordlist
                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString); // Mark as visited
                    }
                }
                // bring back currString to its original state
                currString[index] = originalCharacter;
            }
        }
        return 0;
    }
    int wordLadderLengthPractice(string beginWord, string endWord,
                                 vector<string> &wordList)
    {
        queue<pair<string, int>> q; //{currWord,no of step to make this word
                                    // following given operation in question}
        q.push({beginWord, 1});     // Initial put beginWord with step = 1
        unordered_set<string> st(
            wordList.begin(),
            wordList.end()); // To see if the word formed is in wordList or not
        // in quicker o(1) T.C and also to maintain visited word i.e if the word is
        // visited push in queue and pop
        //  from set
        st.erase(beginWord);
        while (!q.empty())
        {
            auto fNode = q.front();
            q.pop();
            string currWord = fNode.first;
            int currSteps = fNode.second;

            if (currWord == endWord)
            {
                return currSteps;
            }

            for (int i = 0; i < currWord.size(); i++)
            {
                // change every index with a-z if its in the wordList then we are 1 step
                // forward; ex - hot -> for i=0 -> check from a-z -> like
                // "aot","bot","cot"... & so on and if that is in wordList then push it
                // in queue with currCount+1; and remove that currWord from set cause
                // its now visited
                char originalCharacter = currWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currWord[i] = ch;
                    if (st.find(currWord) != st.end())
                    {
                        q.push({currWord, currSteps + 1});
                        st.erase(currWord);
                    }
                }
                currWord[i] = originalCharacter;
            }
        }
        return 0;
    }
};

// Q.NO-5    &&    GFG     &&       LEETCODE-Q.NO-126
// User function Template for C++

class WordLadderII
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        // code here
        vector<vector<string>> ans;
        queue<pair<vector<string>, int>> q; //{{der,dfr,dfs},3}
        q.push({{beginWord}, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return {}; // endWord must be in wordList

        int prevLevel = -1;
        vector<string> toBeRemoved;

        while (!q.empty())
        {
            auto fNode = q.front();
            q.pop();

            auto currSeq = fNode.first;
            string currString = currSeq[currSeq.size() - 1];
            int currCount = fNode.second;

            if (currCount != prevLevel)
            {
                for (auto s : toBeRemoved)
                {
                    st.erase(s);
                    toBeRemoved.clear();
                    prevLevel = currCount;
                }
            }

            // Check if we reached the destination
            if (currString == endWord)
            {
                ans.push_back(currSeq);
            }

            for (int index = 0; index < currString.length(); index++)
            {
                char originalCharacter = currString[index];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;
                    // check in wordlist
                    if (st.find(currString) != st.end())
                    {
                        auto temp = currSeq;
                        temp.push_back(currString);
                        q.push({temp, currCount + 1});
                        toBeRemoved.push_back(currString);
                    }
                }
                // bring back currString to its original state
                currString[index] = originalCharacter;
            }
        }
        return ans;
    }
};

// Q.NO-6      &&        GFG
// User function Template for C++

class MinimumMultiplicationsToReachEnd
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        const int MOD = 100000;
        // code here
        queue<pair<int, int>> q; //{multi,steps}
        q.push({start, 0});
        unordered_map<int, bool> visited; //{multiplication,true/false}
        visited[start] = true;

        while (!q.empty())
        {
            auto topp = q.front();
            q.pop();
            int curr = topp.first;
            int step = topp.second;
            if (curr == end)
            {
                return step;
            }

            for (int i = 0; i < arr.size(); i++)
            {
                int next = curr * arr[i] % MOD;
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};

// Q.NO-7       &&       LEETCODE-Q.NO-1319
class NumberofOperationstoMakeNetworkConnected
{
public:
    // Find with Path Compression
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    // Union operation - your version: always increment rank
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank, int &extraEdges)
    {
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent)
        {
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
        else
        {
            extraEdges++;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int extraEdges = 0;
        for (auto edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            unionSet(u, v, parent, rank, extraEdges);
        }

        int noOfComponents = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                noOfComponents++;
            }
        }

        return extraEdges >= (noOfComponents - 1) ? (noOfComponents - 1) : -1;
    }
};

// Q.NO-8         &&         LEETCODE-Q.NO-1334
class FindtheCityWiththeSmallestNumberofNeighborsAtAThresholdDistance
{
public:
    int dijkstra(int src, int n, unordered_map<int, list<pair<int, int>>> &adj, int &threshold)
    {
        vector<int> DIST(n, INT_MAX);
        set<pair<int, int>> st; //{dist from src to that node,node}
        // initially
        DIST[src] = 0;
        st.insert({0, src});

        int reachableCities = 0; // Cities having distance <= threshold from src city

        while (!st.empty())
        {
            auto topp = *st.begin(); // get the actual pair
            st.erase(st.begin());
            int nodeDist = topp.first;
            int node = topp.second;

            if (node != src && nodeDist <= threshold)
            {
                reachableCities++;
            }

            for (auto nbr : adj[node])
            {

                int currDist = nodeDist + nbr.second;
                int currNode = nbr.first;

                if (currDist < DIST[currNode])
                {
                    auto prevEntry = st.find({DIST[currNode], currNode});
                    if (prevEntry != st.end())
                    {
                        st.erase(prevEntry);
                    }
                    DIST[currNode] = currDist;
                    st.insert({currDist, currNode});
                }
            }
        }
        return reachableCities;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int city = 0;
        int reachableCities = INT_MAX;
        for (int u = 0; u < n; u++)
        {
            int ans = dijkstra(u, n, adj, distanceThreshold);
            if (ans <= reachableCities)
            {
                reachableCities = ans;
                city = u;
            }
        }
        return city;
    }
};

// Q.NO-9        &&        LEETCODE-Q.NO-721
class AccountsMerge
{
public:
    // Find with Path Compression
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    // Union operation - your version: always increment rank
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent)
        {
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
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int m = accounts.size();
        vector<int> parent(m);
        for (int i = 0; i < m; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(m, 0);

        unordered_map<string, int> mp; //{johnsmith@mail.com , ParentNode -ex-node-0}
        for (int i = 0; i < m; i++)
        {
            auto account = accounts[i];
            for (int j = 1; j < account.size(); j++)
            {
                string mail = account[j];
                if (mp.find(mail) == mp.end())
                {
                    mp[mail] = i;
                }
                else
                {
                    // union
                    unionSet(mp[mail], i, parent, rank);
                }
            }
        }

        unordered_map<int, set<string>> preAnswer; //{index,mails}
        for (auto it : mp)
        {
            // parent change bhi ho skta h for ex - mp[j3] = 1
            // if we put preAnswer[1] = j3 then it is wrong
            // cause 1 got merged with 0 ,so thats why we find the
            // parent of each it.second and then storing
            int parentOfThisMail = findParent(parent, it.second);
            preAnswer[parentOfThisMail].insert(it.first);
        }

        vector<vector<string>> ans;
        for (auto it : preAnswer)
        {
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);
            for (auto mail : it.second)
            {
                temp.push_back(mail);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

int main() { return 0; }