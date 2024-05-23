#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
// insertion
void insertWord(TrieNode *root, string word)
{
    // cout << "recieved word: " << word << " for insertion " << endl;
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
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
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal; // Return root->isTerminal instead of True cause maybe me got all the char of the string but there is a
                                 //    chance that that word haven't been inserted earlier
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // present or found
        child = root->children[index];
    }
    else
    {
        // not found
        return false;
    }

    /// baaaki recursion
    bool recursionKaAns = searchWord(child, word.substr(1));
    return recursionKaAns;
}

void deleteWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    // 1 case mera
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // not present
        return;
    }
    // baaki recursion tera
    deleteWord(child, word.substr(1));
}

void printAllWordOfAGivenChar(TrieNode *root, string prefix, string temp, vector<string> &ans)
{
    temp += root->value;
    if (prefix.size() == 0 && root->isTerminal == true)
    {
        // Printing all the word with terminal == true after prefix is found
        string words = temp.substr(1);
        ans.push_back(words);
    }
    if (prefix.length() != 0)
    {
        char ch = prefix[0];
        int index = ch - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            printAllWordOfAGivenChar(child, prefix.substr(1), temp, ans);
        }
        else
        {
            return;
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                printAllWordOfAGivenChar(root->children[i], prefix, temp, ans);
            }
        }
    }
}

int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "ccater");
    insertWord(root, "cc");
    insertWord(root, "ccare");
    insertWord(root, "ccom");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "ccat");
    insertWord(root, "ccar");

    // cout << "Insertion Done" << endl;
    // if (searchWord(root, "loved"))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not Found" << endl;
    // }

    // deleteWord(root, "loved");

    // if (searchWord(root, "loved"))
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not Found" << endl;
    // }
    vector<string> ans;
    printAllWordOfAGivenChar(root, "cc", "", ans);

    for (auto ch : ans)
    {
        cout << ch << endl;
    }

    return 0;
}