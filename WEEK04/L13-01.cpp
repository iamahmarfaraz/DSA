#include <iostream>
#include <vector>
using namespace std;

int getquotient(int divisor, int dividend)
{
    int start = 0;
    int end = dividend;
    int ans = -1;
    for (; start <= end;)
    {
        int mid = (start + ((end - start) / 2));
        if ((mid * divisor) == dividend)
        {
            return mid;
        }
        else if ((mid * divisor) < dividend)
        {
            // ans store
            ans = mid;
            // right me jao
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int binarysearchInNearlySortedArray(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    for (; start <= end;)
    {
        int mid = start + ((end - start) / 2);
        if (mid - 1 >= 0 && arr[mid - 1] == target) // mid-1 should be greater than equal to 0 as mid can be at 0th index
        {
            return mid - 1;
        }
        else if (arr[mid] == target)
        {
            return mid;
        }
        else if (mid + 1 < size && arr[mid + 1] == target) // mid-1 should be greater than equal to 0 as mid can be at 0th index
        {
            return mid + 1;
        }
        else if (arr[mid] > target)
        {
            // 2 block left jao mid se kyunki mid+1 already compare ho chuka h
            end = mid - 2;
        }
        else
        {
            // 2 block right jao mid se kyunki mid-1 already compare ho chuka h
            start = mid + 2;
        }
    }
    return -1;
}

int oddOccuranceElement(vector<int> &arr)
{
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    for (; start <= end;)
    {
        int mid = start + ((end - start) / 2);
        if (start == end)
        {
            return start;
        }

        else if ((mid & 1) == 0)
        {
            if (mid + 1 < size && arr[mid] == arr[mid + 1])
            {
                // right jao cause 'ans' pair ke baad hi hoga
                // mid+2 cause element next to mid in left (mid+1) is same as mid
                start = mid + 2;
            }
            else
            {
                // mid not equal to mid+1 means either we're at right part or at the "ANS" itself
                // 0 based indexing hai aur 'ANS' hmesha pair ke baad aayega so "ANS" guaranteed even index pe hoga
                end = mid; // ans will not be lost
            }
        }
        else if ((mid & 1) == 1)
        {
            if (mid - 1 >= 0 && arr[mid] == arr[mid - 1])
            {
                // i'm at left
                start = mid + 1;
            }
            else
            {
                // i'm at right
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    // int divisor = -7;
    // int dividend = 29;
    // int ans = getquotient(abs(divisor), abs(dividend));
    // if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
    // {
    //     ans = 0 - ans;
    // }

    // cout << "Quotient is : " << ans << endl;

    // int arr[] = {20,
    //              10,
    //              30,
    //              50,
    //              40,
    //              70,
    //              60};
    // int size = 7;
    // int target = 60;
    // int index = binarysearchInNearlySortedArray(arr, size, target);
    // if (index == -1)
    // {
    //     cout << "Target not found" << endl;
    // }
    // else
    // {
    //     cout << "Target found at index : " << index << endl;
    // }

    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(2);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(20);
    v.push_back(20);
    v.push_back(11);
    v.push_back(11);
    v.push_back(10);
    v.push_back(10);

    int oddoccAns = oddOccuranceElement(v);
    if (oddoccAns == -1)
    {
        cout << "No Odd Occuring element" << endl;
    }
    else
    {
        cout << "Odd occuring element is : " <<v[oddoccAns]<<" at "<< oddoccAns << " index" << endl;
    }

    return 0;
}