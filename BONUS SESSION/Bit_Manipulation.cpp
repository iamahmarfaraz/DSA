#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Q.NO-1
string oddEven(int &n)
{
    return (n & 1) == 0 ? "Even" : "Odd";
}

// Q.NO-2
int getIThBit(int &n, int &i)
{
    int mask = (1 << i);
    return (n & mask) == 0 ? 0 : 1;
}

// Q.NO-3
int setIthBit(int &n, int &i)
{
    int mask = (1 << i);
    int ans = (n | mask);
    return ans;
}

// Q.NO-4
int clearIThBit(int &n, int i)
{
    int mask = (1 << i);
    int ans = mask ^ n;
    return ans;
}

// Q.NO-5
int updateIThBit(int &n, int &i, int target)
{
    n = clearIThBit(n, i);
    int mask = (target << i);
    int ans = n | mask;
    return ans;
}

// Q.NO-6        &&         LEETCODE-Q.NO-136
class SingleNumber
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};

int main()
{
    int n = 13;
    cout << "ANSWER OF Q.NO-1 :- " << oddEven(n) << endl;

    int n1 = 10, i = 3;
    cout << "ANSWER OF Q.NO-2 :- " << getIThBit(n1, i) << endl;

    int n2 = 10, i2 = 2;
    cout << "ANSWER OF Q.NO-3 :- " << setIthBit(n2, i2) << endl;

    int n3 = 10, i3 = 1;
    cout << "ANSWER OF Q.NO-4 :- " << clearIThBit(n3, i3) << endl;

    int n4 = 10, i4 = 2;
    cout << "ANSWER OF Q.NO-5   :- " << updateIThBit(n4, i4, 1) << endl;
    return 0;
}