#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

void storeString(TrieNode *root, vector<string> &ans, string &input, string &prefix)
{
    // base case
    if (root->isTerminal == true)
    {
        // ans store
        ans.push_back(prefix + input);
        // return ?
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = root->children[index];
        if (next != NULL)
        {
            // child exist
            input.push_back(ch);
            // baaaki recursion
            storeString(next, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode *root, string input, vector<string> &ans, string &prefix)
{
    // base case
    if (input.length() == 0)
    {
        TrieNode *lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // child present
        child = root->children[index];
    }
    else
    {
        return;
    }
    // recursive call
    findPrefixString(child, input.substr(1), ans, prefix);
}

void printAllWordOfAGivenChar2(TrieNode *root, string prefix, string temp, vector<string> &ans, vector<vector<string>> &finalans)
{
    temp += root->value;
    if (prefix.size() == 0 && root->isTerminal == true)
    {
        // if (ans.size() >= 3)
        // {
        //     return;
        // }
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
            printAllWordOfAGivenChar2(child, prefix.substr(1), temp, ans, finalans);
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
                printAllWordOfAGivenChar2(root->children[i], prefix, temp, ans, finalans);
            }
        }
    }
}
vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    TrieNode *root = new TrieNode('-');
    for (auto ch : products)
    {
        insertWord(root, ch);
    }
    vector<string> ans;
    vector<vector<string>> finalans;
    string prefix = "";
    for (auto ch : searchWord)
    {
        prefix += ch;
        printAllWordOfAGivenChar2(root, prefix, "", ans, finalans);
        finalans.push_back(ans);
        ans.clear();   // Clear the vector
        ans.resize(0); // Resize the vector to size 0
    }
    return finalans;
}

vector<vector<string> > getSuggestions(TrieNode* root, string input) {

  vector<vector<string> > output;
  TrieNode* prev = root;
  string inputhelper = "";

  for(int i=0; i<input.length(); i++) {
    char lastchar = input[i];
    int index = lastchar - 'a';
    TrieNode* curr = prev->children[index];

    if(curr == NULL) {
      break;
    }
    else {
      vector<string> nicheKaAns;
      inputhelper.push_back(lastchar);
      string dummy = "";
      storeString(curr, nicheKaAns, inputhelper, dummy);
      output.push_back(nicheKaAns);
      //important
      prev = curr;
    }

  }
  return output;
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
    vector<string> ans;
    printAllWordOfAGivenChar(root, "cc", "", ans);

    for (auto ch : ans)
    {
        cout << ch << endl;
    }
    return 0;
}