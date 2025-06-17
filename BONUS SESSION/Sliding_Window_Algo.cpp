#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Q.NO-1     &&      LEETCODE-Q.NO-239
class SlidingWindowMaximum
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq; //{nums[i],i};
        vector<int> ans;

        // Process first window of k-size
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        // Process rest of the windows
        for (int i = k; i < nums.size(); i++)
        {
            pq.push({nums[i], i});

            while ((i - pq.top().second) >= k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

// Q.NO-2        &&        LEETCODE-Q.NO-209
class MinimumSizeSubarraySum
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        int sum = 0;
        int i = 0;
        int j = 0;
        while (i <= j && j < nums.size())
        {
            sum += nums[j];
            if (sum >= target)
            {
                ans = min(ans, (j - i + 1));
                sum = sum - nums[i] - nums[j];
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Q.NO-3         &&          LEETCODE-Q.NO-1
class Solution
{
public:
    //  2-Pointer Approach - T.C :- O(nlogn)
    vector<int> twoSumTwoPointerApproach(vector<int> &nums, int target)
    {
        vector<pair<int, int>> numsAndIndex; //{nums[i],i}
        for (int i = 0; i < nums.size(); i++)
        {
            numsAndIndex.push_back({nums[i], i});
        }
        sort(numsAndIndex.begin(), numsAndIndex.end());

        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            if (numsAndIndex[s].first + numsAndIndex[e].first == target)
            {
                return {numsAndIndex[s].second, numsAndIndex[e].second};
            }
            else if (numsAndIndex[s].first + numsAndIndex[e].first < target)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return {};
    }

    // Hash map Approach - T.C :- O(n)
    vector<int> twoSumHashMapApproach(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); ++i)
        {
            int remain = target - nums[i];

            if (mp.find(remain) != mp.end())
            {
                return {mp[remain], i};
            }

            mp[nums[i]] = i;
        }

        return {}; // fallback, not needed if exactly one solution exists
    }
};

// Q.NO-4          &&          LEETCODE-Q.NO-930
class BinarySubarraysWithSum
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int s = 0;
        int e = 0;
        int sum = 0;
        int ans = 0;
        int prefixZero = 0;
        while (e < nums.size())
        {
            sum += nums[e];

            // Minimize wala case
            while (s < e && (sum > goal || nums[s] == 0))
            {
                if (nums[s] == 1)
                {
                    prefixZero = 0;
                }
                else
                {
                    prefixZero += 1;
                }

                sum -= nums[s];
                s++;
            }

            if (sum == goal)
            {
                ans += prefixZero + 1;
            }
            e++;
        }
        return ans;
    }
};

// Q.NO-5         &&          LEETCODE-Q.NO-76
class MinimumWindowSubstring
{
public:
    string minWindow(string s, string t)
    {
        // InValid Case
        int m = s.size();
        int n = t.size();

        if (m < n)
        {
            return "";
        }

        // Valid Case
        int ansStartIdx = -1;
        int ansLen = INT_MAX;
        int start = 0;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (auto ch : t)
        {
            tMap[ch]++;
        }

        int count = 0; // stores No of pattern(t) wala string ka characters present in
        // curr window
        for (int i = 0; i < m; i++)
        {
            char ch = s[i];
            // update Freq in sMap
            sMap[ch]++;
            if (sMap[ch] <= tMap[ch])
            {
                // valid char
                count++;
            }

            if (count == n)
            {
                // ans found now minimize
                // minimize only if start index pe faltu character ho(jo pattern me na ho) ya
                // extra hai(freq us char ki sMap me zyada hogyi tMap se)
                while (sMap[s[start]] > tMap[s[start]])
                {

                    sMap[s[start]]--;

                    start++;
                }
                // store this minimized ans if its smaller than existing one
                int currAnsWindowLen = i - start + 1;
                if (currAnsWindowLen < ansLen)
                {
                    ansLen = currAnsWindowLen;
                    ansStartIdx = start;
                }
            }
        }
        if (ansStartIdx == -1)
        {
            return "";
        }
        return s.substr(ansStartIdx, ansLen);
    }
};

int main()
{

    return 0;
}