#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> anagramMap(string str)
{
    vector<int> mapping(256, 0);
    for (auto ch : str)
    {
        mapping[ch]++;
    }
    return mapping;
}
bool isAnagram(string s, string t)
{
    // Q.NO 1    &&      LEETCODE Q.242
    if (s.length() != t.length())
    {
        return false; // Anagrams must have the same length
    }

    vector<int> sAns = anagramMap(s);
    vector<int> tAns = anagramMap(t);
    for (int i = 0; i < sAns.size(); i++)
    {
        if (sAns[i] != tAns[i])
        {
            return false;
        }
    }
    return true;
}

string reverseOnlyLetters(string &s)
{
    // Q.NO 2
    int size = s.size();
    int i = -0;
    int j = size - 1;
    while (i <= j)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
        {
            i++;
        }
        else if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')))
        {
            j--;
        }
        else
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}

string longestCommonPrefix(vector<string> &strs)
{
    // Q.NO 3     &&     LEETCODE-14
    string ans = "";
    int i = 0;
    while (true)
    {
        char currEl = 0;
        for (auto str : strs)
        {
            if (i >= str.size())
            {
                currEl = 0;
                break;
            }
            if (currEl == 0)
            {
                currEl = str[i];
            }
            else if (str[i] != currEl)
            {
                currEl = 0;
                break;
            }
        }
        if (currEl == 0)
        {
            break;
        }
        ans.push_back(currEl);
        i++;
    }
    return ans;
}

string reverseVowels(string &s)
{
    // Q.NO 4        &&        LEETCODE-345
    int size = s.size();
    int i = 0;
    int j = size - 1;
    while (i <= j)
    {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
        {
            i++;
        }
        else if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
        {
            j--;
        }
        else
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}
vector<char> charMapping(string str)
{
    vector<char> mapping(256, 0);
    vector<char> ans;
    char start = 'a';
    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            ans.push_back(start);
            start++;
        }
        else
        {
            ans.push_back(mapping[ch]);
        }
    }
    return ans;
}
bool isIsomorphic(string s, string t)
{
    // Q.NO 5      &&        LEETCODE-205
    if (s.size() != t.size())
    {
        return false;
    }
    vector<char> sAns = charMapping(s);
    vector<char> tAns = charMapping(t);

    for (int i = 0; i < sAns.size(); i++)
    {
        if (sAns[i] != tAns[i])
        {
            return false;
        }
    }
    return true;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // Q.NO 6     &&     LEETCODE-49
    map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.push_back(i->second);
    }
    return ans;
}

bool isPalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
string longestPalindrome(string s)
{
    // Q.NO 7     &&      LEETCODE-5
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int myAtoi(string s)
{
    // Q.NO 8      &&       LEETCODE-8
    int num = 0, i = 0, sign = 1;
    while (s[i] == ' ')
    {
        i++;
    }
    if (i < s.size() && s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    while (i < s.size() && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + digit;
        i++;
    }
    return num * sign;
}

int compress(vector<char> &chars)
{
    // Q.NO 9      &&       LEETCODE-443
    int i = 0;
    int j = 1;
    int index = 0;
    int count = 1;
    while (j < chars.size())
    {
        if (chars[j] == chars[i])
        {
            ++count;
            j++;
        }
        else
        {
            chars[index++] = chars[i];
            if (count > 1)
            {
                int start = index;
                while (count > 0)
                {
                    chars[index++] = (count % 10) + '0'; // Add the count as separate characters
                    count /= 10;
                }
                reverse(chars.begin() + start, chars.begin() + index);
            }
            i = j;
            j++;
            count = 1; // reset count
        }
    }
    // handle last case
    chars[index++] = chars[i];
    if (count > 1)
    {
        int start = index;
        while (count > 0)
        {
            chars[index++] = (count % 10) + '0'; // Add the count as separate characters
            count /= 10;
        }
        reverse(chars.begin() + start, chars.begin() + index);
    }
    return index;
}

string intToRoman(int num)
{
    // Q.NO 10      &&      LEETCODE-12
    string romanSymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int size = sizeof(romanSymbol) / sizeof(romanSymbol[0]);
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    // Roman symbol are mapped with it's value above
    string ans = "";
    while (num > 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (num >= value[i])
            {
                ans += romanSymbol[i];
                num -= value[i];
                break;
            }
        }
    }
    return ans;
}

string convert(string s, int numRows)
{
    // Q.NO 11      &&      LEETCODE-6
    if (numRows == 1)
        return s;
    vector<string> zigzag(numRows);
    int row = 0, i = 0;
    bool direction = 1;
    while (true)
    {
        if (direction)
        {
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else
        {
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if (i >= s.size())
            break;
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i];
    }
    return ans;
}

static bool ahmar(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2; // if t1 > t2 it'll return string "a" as true else "b" as true
}
string largestNumber(vector<int> &nums)
{
    // Q.NO 12     &&      LEETCODE-179
    vector<string> store;
    for (auto c : nums)
    {
        store.push_back(to_string(c));
    }
    sort(store.begin(), store.end(), ahmar);
    if (store[0] == "0")
    {
        return "0";
    }
    string ans = "";
    for (auto c : store)
    {
        ans += c;
    }
    return ans;
}

string reorganizeString(string s)
{
    // Q.NO 13     &&     LEETCODE-767
    int hash[26] = {0};
    // Compact Hashing
    for (auto a : s)
    {
        hash[a - 'a']++;
    }
    // Find the most occurance character
    char most_occ;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            most_occ = i + 'a';
        }
    }
    // Placing Most occured Char after interval of 1
    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = most_occ;
        max_freq--;
        index += 2;
    }
    if (max_freq != 0)
    {
        return "";
    }
    hash[most_occ - 'a'] = 0;
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}

int strStr(string haystack, string needle)
{
    // Q.NO 14    &&     LEETCODE-28
    int j;
    for (int i = 0; i < haystack.size(); i++)
    {
        for (j = 0; j < needle.size(); j++)
        {
            if (needle[j] == haystack[i + j])
            {
            }
            else
            {
                break;
            }
        }
        if (j == needle.size())
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // string s = "anagram";
    // string t = "nagaram";
    // if (isAnagram(s, t))
    // {
    //     cout << "Both the strings are Anagram" << endl;
    // }
    // else
    // {
    //     cout << "Both the strings are not Anagram" << endl;
    // }

    // string qTwo = "Test1ng-Leet==code-Q";
    // reverseOnlyLetters(qTwo);
    // for (int i = 0; i < qTwo.length(); i++)
    // {
    //     cout << qTwo[i];
    // }
    // cout << endl;

    // vector<string> strs = {"flower", "flow", "flight"};
    // string ans = longestCommonPrefix(strs);
    // for (int i = 0; i < ans.length(); i++)
    // {
    //     cout << ans[i];
    // }

    // string s = "leetcode";
    // reverseVowels(s);
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s[i];
    // }
    // cout << endl;

    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // string s = "babad";
    // string ans = longestPalindrome(s);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i];
    // }

    // string s="1234";
    // cout<<"In Integer : "<<myAtoi(s);

    // vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'd'};
    // cout << "Length of Compressed string is : " << compress(s);

    // string s="PAYPALISHIRING";
    // int rowcount=3;
    // string conAns=convert(s,rowcount);
    // for (auto c:conAns)
    // {
    //     cout<<c;
    // }
    // cout<<endl;

    // vector<int> nums={3,30,34,5,9};
    // string ans=largestNumber(nums);
    // for (auto c:ans)
    // {
    //     cout<<c;
    // }
    // cout<<endl;

    // string s = "aab";
    // string ans = reorganizeString(s);
    // cout << "String After Re-Organizing : " << ans;

    string haystack="letsadu";
    string needle="sad";
    cout<<"The index at which \""<<needle<<"\""<<" first appeared inside \""<<haystack<<"\""<<" string is : "<<strStr(haystack,needle); 

    return 0;
}