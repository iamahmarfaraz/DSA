#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;
#define ll long long

class comp
{
public:
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        return a.first == b.first ? a < b : a.first > b.first;
    }
};

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;
    int freq;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            freq = 0;
        }
        this->isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;
    void insertUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.length())
        {
            root->isTerminal = true;
            root->freq++;
            return;
        }

        char ch = word[i];
        int index = ch - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.length())
        {
            return root->isTerminal;
        }

        char ch = word[i];
        int index = ch - 'a';

        if (root->children[index] == NULL)
        {
            // not found
            return false;
        }
        /// baaaki recursion
        return searchUtil(root->children[index], word, i + 1);
    }

    bool startUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.length())
        {
            return true;
        }

        char ch = word[i];
        int index = ch - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        return startUtil(root->children[index], word, i + 1);
    }

    void traverseUtil(TrieNode *root, string &s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k)
    {
        if (!root)
            return;
        if (root->isTerminal)
        {
            if (pq.size() < k)
            {
                pq.push({root->freq, s});
            }
            else if (pq.size() == k && root->freq > pq.top().first)
            {
                // to maintain minheap
                pq.pop();
                pq.push({root->freq, s});
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                s.push_back(i + 'a');
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back(); // backtracking
            }
        }
    }

public:
    Trie()
    {
        root = new TrieNode('-');
    }

    void insert(string word)
    {
        insertUtil(this->root, word, 0);
    }

    bool search(string word)
    {
        return searchUtil(this->root, word, 0);
    }

    bool startsWith(string prefix)
    {
        return startUtil(this->root, prefix, 0);
    }
    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k)
    {
        string s;
        traverseUtil(root, s, pq, k);
    }
};

class Node
{
public:
    int data;
    Node *Next;

    Node()
    {
        cout << "I'm inside Default Constructor" << endl;
        this->Next = NULL;
    }

    Node(int data)
    {
        cout << "I'm inside Parameterized Constructor" << endl;
        this->data = data;
        this->Next = NULL;
    }
};

// Q.NO-1    &&    GFG
bool isSubset(vector<int> &a, vector<int> &b)
{
    unordered_map<int, int> mp; //{element,occurance}
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (mp.find(b[i]) == mp.end())
        {
            return false;
        }

        // If we only had checked using key(mp.find(b[i]) == mp.end())
        // then we could be wrong as mp[7] = 0 ,it can store like this too
        if (mp[b[i]] > 0)
        {
            mp[b[i]]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Q.NO-2
Node *unionOfTwoLinkedList(Node *head1, Node *head2)
{

    map<int, Node *> mp;
    Node *curr = head1;
    while (curr)
    {
        mp[curr->data] = curr;
        curr = curr->Next;
    }
    curr = head2;
    while (curr)
    {
        mp[curr->data] = curr;
        curr = curr->Next;
    }

    Node *UL = NULL;
    curr = NULL;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (!UL)
        {
            UL = it->second;
            curr = UL;
        }
        else
        {
            curr->Next = it->second;
            curr = curr->Next;
        }
    }
    curr->Next = NULL;
    return UL;
}

// Q.NO-3
Node *intersectionOfTwoLinkedList(Node *head1, Node *head2)
{
    unordered_map<int, int> mp;
    Node *curr = head2;
    while (curr)
    {
        mp[curr->data]++;
        curr = curr->Next;
    }

    curr = head1;
    Node *ans = NULL;
    Node *ansHead = NULL;
    while (curr)
    {
        if (mp.find(curr->data) != mp.end())
        {
            if (!ans)
            {
                ans = curr;
            }
            else
            {
                if (mp[curr->data] > 0)
                {
                    ansHead->Next = curr;
                    mp[curr->data]--;
                }
            }
            ansHead = curr;
        }
        curr = curr->Next;
    }
    ansHead->Next = NULL;
    return ans;
}

// Q.NO-4
bool findPairs(vector<int> a)
{
    int n = a.size();
    unordered_map<int, bool> mp; //{sums,present or not};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if (mp.find(sum) != mp.end())
            {
                return true;
            }
            mp[sum] = true;
        }
    }
    return false;
}

// Q.NO-5
int maxLen(vector<int> &a, int n)
{
    unordered_map<int, int> mp; //{csum,index}
    int csum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        csum += a[i];
        if (csum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (mp.find(csum) != mp.end())
        {
            // csum found again ,meaning there are value in between which have been cancelled out
            int len = i - mp[csum];
            ans = max(ans, len);
        }
        else
        {
            mp[csum] = i;
        }
    }
    return ans;
}

// Q.NO-6
int largestSubarrayOfZeroAndOne(vector<int> &a, int n)
{

    // // replace all zero with -1
    // for(int i=0;i<n;i++){
    //     if(a[i] == 0){
    //         a[i] = -1;
    //     }
    // }

    unordered_map<int, int> mp; //{csum,index}
    int csum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = a[i] == 0 ? -1 : 1;
        csum += val;
        if (csum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (mp.find(csum) != mp.end())
        {
            // csum found again ,meaning there are value in between which have been cancelled out
            int len = i - mp[csum];
            ans = max(ans, len);
        }
        else
        {
            mp[csum] = i;
        }
    }
    return ans;
}

// Q.NO-7    &&    LEETCODE-Q.NO-648
string replaceWords(vector<string> &dictionary, string sentence)
{
    string ans;
    Trie trie;

    // insert words from dictionary into trie
    for (auto root : dictionary)
    {
        trie.insert(root);
    }

    // pick each word from sentenace and find if it get a match in trie ,
    // if yes replace it
    int s = 0, e = 0;
    while (e < sentence.size())
    {
        if (sentence[e] == ' ' || e == sentence.size() - 1)
        {
            int len = e == sentence.size() - 1 ? sentence.size() : e - s;
            string word = sentence.substr(s, len);
            int trieMatchIndex = trie.search(word);
            ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
            if (sentence[e] == ' ')
            {
                ans += " ";
            }
            s = e + 1;
        }
        e++;
    }
    return ans;
}

// Q.NO-8    &&    LEETCODE-Q.NO-692
vector<string> topKFrequent(vector<string> &words, int k)
{
    Trie trie;
    vector<string> ans;
    for (auto word : words)
    {
        trie.insert(word);
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    trie.traverse(pq, k);

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Q.NO-9     &&     LEETCODE-Q.NO-1023
class TrieNode2
{
public:
    char value;
    TrieNode2 *children[52]; // for 'a'-'z' + 'A'-'Z'
    bool isTerminal;

    TrieNode2(char val)
    {
        this->value = val;
        for (int i = 0; i < 52; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie2
{
    TrieNode2 *root;

    void insertUtil(TrieNode2 *root, string &word, int i)
    {
        if (i >= word.length())
        {
            root->isTerminal = true;
            return;
        }

        char ch = word[i];
        int index;

        if (ch >= 'a' && ch <= 'z')
            index = ch - 'a'; // 0 to 25
        else if (ch >= 'A' && ch <= 'Z')
            index = ch - 'A' + 26; // 26 to 51
        else
            return; // skip or throw error for non-alphabetic chars

        TrieNode2 *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode2(ch);
            root->children[index] = child;
        }

        insertUtil(child, word, i + 1);
    }

    bool searchUtil(TrieNode2 *root, string &word, int i)
    {
        if (i >= word.length())
        {
            return root->isTerminal;
        }

        char ch = word[i];
        int index;

        if (ch >= 'a' && ch <= 'z')
            index = ch - 'a';
        else if (ch >= 'A' && ch <= 'Z')
            index = ch - 'A' + 26;
        else
            return false;

        if (root->children[index] == NULL && word[i] >= 'A' && word[i] <= 'Z')
        {
            // not found
            return false;
        }
        else if (root->children[index] == NULL && word[i] >= 'a' && word[i] <= 'z')
        {
            return searchUtil(root, word, i + 1);
        }
        /// baaaki recursion
        return searchUtil(root->children[index], word, i + 1);
    }

    bool startUtil(TrieNode2 *root, string &word, int i)
    {
        if (i >= word.length())
            return true;

        char ch = word[i];
        int index;

        if (ch >= 'a' && ch <= 'z')
            index = ch - 'a';
        else if (ch >= 'A' && ch <= 'Z')
            index = ch - 'A' + 26;
        else
            return false;

        if (root->children[index] == NULL)
            return false;

        return startUtil(root->children[index], word, i + 1);
    }

public:
    Trie2()
    {
        root = new TrieNode2('-');
    }

    void insert(string word)
    {
        insertUtil(this->root, word, 0);
    }

    bool search(string word)
    {
        return searchUtil(this->root, word, 0);
    }

    bool startsWith(string prefix)
    {
        return startUtil(this->root, prefix, 0);
    }
};

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        Trie2 trie;
        trie.insert(pattern);
        vector<bool> ans;

        for (auto query : queries)
        {
            bool temp = trie.search(query);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{

    return 0;
}