#include <iostream>
#include <vector>
using namespace std;

string decodeMessage(string key, string message)
{
    // create mapping
    char start = 'a';
    char mapping[256] = {0}; // all the 256 block will have 0 value in it
    for (auto i : key)
    {
        if (i != ' ' && mapping[i] == 0)
        {
            mapping[i] = start;
            start++;
        }
    }
    // use mapping
    string ans;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            char compare = message[i]; // encoded
            char decode = mapping[compare];
            ans.push_back(decode);
        }
    }
    return ans;
}
int lastoccurance(vector<string> &garbage, string target)
{
    int size = garbage.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (garbage[i].find(target) != string::npos)
        {
            return i;
        }
    }
    return -1;
}
int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    int totalTime = 0;
    string metalCode = {'M'};
    string paperCode = {"P"};
    string glassCode = {"G"};
    for (int i = 0; i < garbage.size(); i++)
    {
        string charAtIndexI = garbage[i];
        for (int j = 0; j < charAtIndexI.length(); j++)
        {
            totalTime++;
        }
    }
    // metal garbage
    int metal = lastoccurance(garbage, metalCode);
    for (int i = 0; i < metal; i++)
    {
        totalTime += travel[i];
    }
    // paper garbage
    int paper = lastoccurance(garbage, paperCode);
    for (int i = 0; i < paper; i++)
    {
        totalTime += travel[i];
    }
    // glass garbage
    int glass = lastoccurance(garbage, glassCode);
    for (int i = 0; i < glass; i++)
    {
        totalTime += travel[i];
    }
    return totalTime;
}

static string str;
static bool compare(char a, char b)
{
    return (str.find(a) < str.find(b));
}
string customSortString(string order, string s)
{
    str = order;
    sort(s.begin(), s.end(), compare);
    return s;
};
string Solution::str;

void createmapping(string &str)
{
    // Create map
    char start = 'a';
    char mapping[256] = {0};
    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }
    // use Map
    for (int i = 0; i < str.size(); i++)
    {
        char temp = str[i];
        str[i] = mapping[temp];
    }
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    // pattern mapping
    createmapping(pattern);
    vector<string> ans;
    for (string c : words)
    {
        string s = c;
        createmapping(s);
        if (s == pattern)
        {
            ans.push_back(c);
        }
    }
    return ans;
}

int main()
{
    // string key="the quick brown fox jumps over the lazy dog";
    // string message="b wxau l hthd";  //decoded message
    // string ch=decodeMessage(key,message);
    // cout<<ch;

    // vector<string> garbage = {"G", "P", "GP", "GG"};
    // vector<int> travel = {2, 4, 3};
    // int time = garbageCollection(garbage, travel);
    // cout << "The minimum time taken to collect the garbage is : " << time << endl;
    vector<string> timePoints = {"23:59", "00:00"};
    for (int j = 0; j < timePoints.size(); j++)
    {
        string temp = timePoints[j];
        string breaking = {":"};
        int i = -1;
        ;
        while (temp.find(breaking) == string::npos)
        {
            i++;
        }

        string hourS = temp.substr(0, (i - 1));
        for (int k = 0; k < hourS.size(); k++)
        {
            cout << hourS[k];
        }
    }

    return 0;
}