#include <iostream>
using namespace std;
string removeDuplicates(string s)
{
    int size = s.size();
    string temp = "";
    for (int i = 0; i < size; i++)
    {
        if (temp.size() > 0 && s[i] == temp[temp.size() - 1])
        {
            temp.pop_back();
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    return temp;
}
bool checkKadjacent(string s, int k, int i, int lastCheckindex, string temp)
{
    for (int j = temp.size() - 1; j >= lastCheckindex; j--)
    {
        if (j >= 0 && s[i] != temp[j])
        {
            return false;
        }
        if (j < 0)
        {
            return false;
        }
    }
    return true;
}
string removeDuplicates(string s, int k)
{
    int size = s.size();
    string temp = "";
    for (int i = 0; i < size; i++)
    {
        int lastCheckindex = temp.size() - k + 1;
        int ans = checkKadjacent(s, k, i, lastCheckindex, temp);
        if (ans == 1)
        {
            for (int j = temp.size() - 1; j >= lastCheckindex; j--)
            {
                temp.pop_back();
            }
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    return temp;
}
string removeOccurrences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
bool checkPal(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int size = s.size();
    int i = 0;
    int j = size - 1;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            int ansI = checkPal(s, i + 1, j);
            int ansJ = checkPal(s, i, j - 1);
            return ansI || ansJ;
        }
    }
    return true;
}
int counter(string s, int i, int j)
{
    int size = s.size();
    int count = 0;
    while (i >= 0 && j < size)
    {
        if (s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    return count;
}
int countSubstrings(string s)
{
    int size = s.size();
    int totalcount = 0;
    for (int i = 0; i < size; i++)
    {
        int odd = counter(s, i, i);
        int even = counter(s, i, i + 1);
        totalcount = totalcount + odd + even;
    }
    return totalcount;
}
int main()
{
    
    return 0;
}