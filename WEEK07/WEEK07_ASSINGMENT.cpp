#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lastOcc(string s, int &output, char target, int index)
{
    // Q.NO 1
    // Base Cases
    if (index < 0)
    {
        return;
    }
    if (s[index] == target)
    {
        output = index;
        return;
    }

    // Recursive call
    lastOcc(s, output, target, index - 1);
    return;
}

void reverseStr(string &s, int start, int end)
{
    // Base Case
    if (start == end)
    {
        return;
    }
    // Processing
    swap(s[start], s[end]);
    // Recursion
    reverseStr(s, start + 1, end - 1);
    return;
}

void addString(string &s, int p1, string &t, int p2, int carry, string &output)
{
    // Base case
    if (p1 < 0 && p2 < 0)
    {
        if (carry <= 0)
        {
            output.push_back(carry = '0');
        }
        return;
    }
    int n1 = (p1 >= 0 ? s[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? t[p2] : '0') - '0';

    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    output.push_back(digit + '0');
    // Recursion
    addString(s, p1 - 1, t, p2 - 1, carry, output); // Concatinating string
}

void checkPalindrome(string &pal, int start, int end, bool &ans)
{
    // Base Case
    if (start >= end)
    {
        return;
    }
    // Base Case2
    if (pal[start] != pal[end])
    {
        ans = false;
        return;
    }
    checkPalindrome(pal, start + 1, end - 1, ans);
}

void subArrayRE(vector<int> &nums, int start, int end)
{
    // Base Case
    if (end >= nums.size())
    {
        return;
    }
    for (int i = start; i <= end; i++)
    {
        cout << nums[i];
    }
    cout << endl;
    subArrayRE(nums, start, end + 1);
}

void removeOcc(string &s, string &part)
{
    // Base Case
    if (s.find(part) == string::npos)
    {
        return;
    }
    s.erase(s.find(part), part.length());
    removeOcc(s, part);
}

void profitCheck(vector<int> &arr, int index, int &minMrp, int &maxgain)
{
    // Base case
    if (index == arr.size())
        return;
    if (arr[index] < minMrp)
    {
        minMrp = arr[index];
    }
    if ((arr[index] - minMrp) > maxgain)
    {
        maxgain = arr[index] - minMrp;
    }
    profitCheck(arr, index + 1, minMrp, maxgain);
}
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    profitCheck(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int solve(vector<int> &nums, int size, int index)
{
    // base case
    if (index >= size)
    {
        return 0;
    }

    // chori karlo -> ith index pr
    int option1 = nums[index] + solve(nums, size, index + 2);

    // chori mat karo  -> ith index pr
    int option2 = 0 + solve(nums, size, index + 1);

    int finalAns = max(option1, option2);
    return finalAns;
}
int rob(vector<int> &nums)
{
    int size = nums.size();
    int index = 0;
    int ans = solve(nums, size, index);
    return ans;
}

vector<pair<int, string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }
            string b = it.second;
            string c = "";
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }
            return a + b + c;
        }
    }
    return "";
}

bool wildMatch(string &s, string &p, int i, int j)
{
    // Base Cse
    if (i == s.size() && j == p.size())
    {
        return true;
    }
    if (i == s.size() && j < p.size())
    {
        while (j < p.size())
        {
            if (p[j++] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return wildMatch(s, p, i + 1, j + 1);
    }
    if (p[j] == '*')
    {
        bool caseA = wildMatch(s, p, i, j + 1);
        bool caseB = wildMatch(s, p, i + 1, j);
        return caseA || caseB;
    }
    return false;
}
bool isMatch(string &s, string &p)
{

    int i = 0;
    int j = 0;
    bool ans = wildMatch(s, p, i, j);
    return ans;
}

int diceRoll(int n, int k, int target)
{
    // Base Case
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n != 0 && target == 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += diceRoll(n - 1, k, target - i);
    }
    return ans;
}

int numSquares(int n)
{
    // Base Case
    if (n == 0)
        return 0;
    int i = 1;
    int finalans = INT_MAX;
    while ((i * i) <= n)
    {
        int ans = 1 + numSquares(n - (i * i));
        if (ans < finalans)
        {
            finalans = ans;
        }
        i++;
    }
    return finalans;
}

int main()
{
    // string s="abcddefg";
    // char target='d';
    // int output=-1;
    // int end=s.length() - 1;
    // lastOcc(s,output,target,end);
    // cout<<"The last time \" "<<target<<" \" occured in the string \" "<<s<<" \" is at index no. = "<<output;

    // string reverse = "ahmar";
    // int end=reverse.size() - 1;
    // reverseStr(reverse, 0, end);
    // cout << reverse << endl;

    // string s = "456";
    // string t = "77";
    // string output=""
    // int p1 = s.size() - 1;
    // int p2 = t.size() - 1;
    // addString(s, p1, t, p2,0,output);
    // reverse(output.begin(),output.end());
    // cout << "Sum of " << s << " + " << t << " = " <<output<<endl;

    // string s="babbar";
    // bool ans=true;
    // int start=0;
    // int end=s.size()-1;
    // checkPalindrome(s,start,end,ans);
    // if (ans==1)
    // {
    //     cout<<s<<" is a valid palindrome"<<endl;
    // }
    // else{
    //     cout<<"Invalid Plindrome"<<endl;
    // }

    // vector<int> arr = {1, 2, 3, 4, 5};
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     subArrayRE(arr, i, i);
    // }

    // string s = "daabcbaabcbc";
    // string part = "abc";
    // removeOcc(s, part);
    // cout << "String after removal : " << s << endl;

    // vector<int> prices={7,1,5,3,6,4};
    // cout<<"Max Profit : "<<maxProfit(prices)<<endl;

    // vector<int> nums={1,2,3,1};
    // cout<<"Max amount of money robbed : "<<rob(nums);

    // int num=123456;
    // string ansWord=numberToWords(num);
    // cout<<ansWord<<endl;

    // string s="abcdefg";
    // string p="ab*fg";
    // if (isMatch(s,p))
    // {
    //     cout<<"Wildcard Matching Strings"<<endl;
    // }
    // else{
    //     cout<<"Doesn't Matches"<<endl;
    // }

    // int n=3,k=2,target=6;
    // cout<<"No of Possibilities to get Target Sum : "<<diceRoll(n,k,target)<<endl;

    // int n=13;
    // cout<<"The least perfect square sum required to make \" "<<n<<" \" : "<<numSquares(n);

    

    return 0;
}