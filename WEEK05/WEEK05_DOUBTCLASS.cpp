#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums)
{
    // (LEETCODE Q.169)
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    return nums[mid];
}

int main()
{
    // vector<int> arr={2,2,1,1,1,2,2};
    // int ans=majorityElement(arr);
    // cout<<"MAJORITY ELEMENT IN THE ARRAY IS  : "<<ans;

    vector<int> v = {1, 1, 2, 2, 2, 3, 4};
    auto it = lower_bound(v.begin(), v.end(), 2);

    cout << *it << endl;
    cout << "Index: " <<  it - v.begin() << endl;

    auto it2 = upper_bound(v.begin(), v.end(), 2);
    cout << *(it2-1) << endl;
    cout << "Index it2: " << it2 - v.begin()-1 << endl;

    return 0;
}