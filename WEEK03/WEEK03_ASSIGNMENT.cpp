#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool keypair(int arr[], int size, int x)
{
    // Q.NO 1

    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = (i + 1); i < size; i++)
        {
            int sum = arr[i] + arr[j];
            if (sum == x)
            {
                return true;
            }
        }
        return false;
    }
}
int pivotindex(vector<int> &arr)
{
    // Q.NO 2
    int size = arr.size();
    for (int k = -1; k < (size - 1); k++)
    {
        int sum = 0;
        int sum1 = 0;
        int i;
        for (i = 0; i <= k; i++)
        {
            sum += arr[i];
        }
        for (int j = (k + 2); j < size; j++)
        {
            sum1 += arr[j];
        }

        if (sum == sum1)
        {
            return (k + 1);
        }
    }
    return -1;
}

void sortColors(vector<int> &nums)
{
    // Q.NO 3
    int size = nums.size();
    int start = 0;
    int end = (size - 1);
    for (int i = 0; i <= end;)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[start]);
            i++;
            start++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[end]);
            end--;
        }
        else
        {
            i++;
        }
    }
}

int missingNumber(vector<int> &nums)
{
    // Q.NO 4
    int size = nums.size();
    int sum = 0;
    int sum1 = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
    }
    for (int i = 0; i <= size; i++)
    {
        sum1 += i;
    }
    int total = sum1 - sum;
    return total;
}

void seperateNeg(vector<int> &arr)
{
    // Q.NO 5
    int size = arr.size();
    int left = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[left]);
            left++;
        }
    }
}

int findDuplicate(vector<int> &nums)
{
    // Q.NO 6
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < (size - 1); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}
int missingElemenethavingDublicate(vector<int> &arr)
{
    // Q.NO 7
    int size = arr.size();
    for (int i = 1; i <= size; i++)
    {
        int ans = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == i)
            {
                ans = 1;
            }
        }
        if (ans == 0)
        {
            return i;
        }
    }
    return -1;
}
int firstrepeatingElement(vector<int> &arr)
{
    // Q. NO 8
    int size = arr.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (hash[arr[i]] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}
vector<int> commonElementInSortedArrays(vector<int> &arr, vector<int> &brr, vector<int> &crr)
{
    // Q. NO 9
    vector<int> ans;
    int size = arr.size();
    int size1 = brr.size();
    int size2 = crr.size();
    for (int i = 0, j = 0, k = 0; i < size || j < size1 || k < size2;)
    {
        if (arr[i] == brr[j] && brr[j] == crr[k])
        {
            ans.push_back(arr[i]);
            i++;
            j++;
            k++;
        }

        else if (arr[i] < brr[j])
        {
            i++;
        }
        else if (brr[j] < crr[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return ans;
}

void waveMatrix(vector<vector<int>> &arr)
{
    // Q. NO 10
    int m = arr.size();
    int n = arr[0].size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if ((j & 1) == 0) // accesing even number column
        {
            for (j = 0; j < m; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (j = (m - 1); j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }

        cout << endl;
    }
}
vector<int> spiralMatrix(vector<vector<int>> &nums)
{
    // Q.NO 11
    vector<int> ans;
    int m = nums.size();
    int n = nums[0].size();
    int endcol = (n - 1);
    int endrow = (m - 1);
    int totalelements = (m * n);
    int count = 0;
    for (int i = 0; count < totalelements; i++)
    {
        // printing 1st row
        for (int j = i; j <= endcol; j++)
        {
            ans.push_back(nums[i][j]);
            count++;
        }
        // printing last colomn
        for (int j = (i + 1); j <= endrow; j++)
        {
            ans.push_back(nums[j][endcol]);
            count++;
        }
        endcol--;
        // printing last row
        for (int j = endcol; j >= i; j--)
        {
            ans.push_back(nums[endrow][j]);
            count++;
        }
        endrow--;
        // printing first coloumn
        for (int j = endrow; j > i; j--)
        {
            ans.push_back(nums[j][i]);
            count++;
        }
    }
    return ans;
}

vector<int> sumofTwoArrayStoredDigitbyDigit(vector<int> &arr, vector<int> &brr)
{
    vector<int> ans;
    int size = arr.size();
    int size1 = brr.size();
    int carry = 0;
    if (size == size1)
    {
        for (int i = size - 1, j = size1 - 1; i >= 0 && j >= 0; i--, j--)
        {
            int x = arr[i] + brr[j] + carry;
            int digit = x % 10;
            ans.push_back(digit);
            carry = x / 10;
        }
        if (carry > 0)
        {
            ans.push_back(carry);
        }
    }
    else if (size > size1)
    {
        int i;
        int j;
        for (i = size - 1, j = size1 - 1; j >= 0; i--, j--)
        {
            int x = arr[i] + brr[j] + carry;
            int digit = x % 10;
            ans.push_back(digit);
            carry = x / 10;
        }
        int x = arr[i] + carry;
        int digit = x % 10;
        ans.push_back(digit);
        carry = x / 10;
        if (carry > 0)
        {
            ans.push_back(carry);
        }
    }
    else
    {
        int i;
        int j;
        for (i = size - 1, j = size1 - 1; i >= 0; i--, j--)
        {
            int x = arr[i] + brr[j] + carry;
            int digit = x % 10;
            ans.push_back(digit);
            carry = x / 10;
        }
        int x = brr[j] + carry;
        int digit = x % 10;
        ans.push_back(digit);
        carry = x / 10;
        if (carry > 0)
        {
            ans.push_back(carry);
        }
    }
    return ans;
}
vector<int> factorialofaLargeNumber(int n)
{
    vector<int> ans;
    int size = ans.size();
    int arr[] = {1};
    for (int i = 2; i <= n; i++)
    {
        arr[0] = arr[0] * i;
    }
    while (arr[0] >= 1)
    {
        ans.push_back((arr[0]) % 10);
        arr[0] /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
double findMaxAverageSubArray(vector<int> &nums, int k)
{
    int size = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;
    //  SUM of 1st SubArray
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    maxSum = sum;
    // MaxSum of the rest of the subarray
    for (int i = 0, j = k; j < size; i++, j++)
    {
        sum -= nums[i];
        sum += nums[j];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }
    double maxAvg = static_cast<double>(maxSum) / k;
    return maxAvg;
}

void printVector(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> &arr)
{
    int size = arr.size();
    int size1 = arr[0].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // int arr[] = {1, 4, 45, 6, 10, 8};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int x = 16;
    // if (keypair(arr, size, x))
    // {
    //     cout << "A pair is present in the array who's sum is " << x << endl;
    // }
    // else
    // {
    //     cout << "No such pair present in the array who's sum is " << x << endl;
    // }

    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(7);
    // arr.push_back(3);
    // arr.push_back(6);
    // arr.push_back(5);
    // arr.push_back(6);

    // vector<int> brr;
    // brr.push_back(2);
    // brr.push_back(1);
    // brr.push_back(8);
    // brr.push_back(9);
    // brr.push_back(7);
    // brr.push_back(5);
    // brr.push_back(7);
    // brr.push_back(4);
    // brr.push_back(4);

    // int ans = pivotindex(brr);
    // if (ans == -1)
    // {
    //     cout << "No pivot index found" << endl;
    // }
    // else
    // {
    //     cout << "Pivot Index is : " << ans << endl;
    // }

    // vector<int> crr;
    // crr.push_back(2);
    // crr.push_back(0);
    // crr.push_back(2);
    // crr.push_back(1);
    // crr.push_back(1);
    // crr.push_back(0);
    // sortColors(crr);
    // printVector(crr);

    // vector<int> drr;
    // drr.push_back(9);
    // drr.push_back(6);
    // drr.push_back(4);
    // drr.push_back(2);
    // drr.push_back(3);
    // drr.push_back(5);
    // drr.push_back(7);
    // drr.push_back(0);
    // drr.push_back(1);

    // int missNo=missingNumber(drr);
    // cout<<"The missing number is : "<<missNo<<endl;

    // vector<int> err;
    // err.push_back(1);
    // err.push_back(2);
    // err.push_back(-3);
    // err.push_back(4);
    // err.push_back(-5);
    // err.push_back(6);
    // seperateNeg(err);
    // printVector(err);

    // vector<int> frr;
    // frr.push_back(1);
    // frr.push_back(3);
    // frr.push_back(4);
    // frr.push_back(2);
    // frr.push_back(2);
    // int duplicate = findDuplicate(frr);
    // cout << "The duplicate number in the array is : " << duplicate << endl;

    // vector<int> grr;
    // grr.push_back(1);
    // grr.push_back(3);
    // grr.push_back(5);
    // grr.push_back(3);
    // grr.push_back(4);
    // int missingduplicate = missingElemenethavingDublicate(grr);
    // if (missingduplicate < 0)
    // {
    //     cout << "No Missing Element" << endl;
    // }
    // else
    // {
    //     cout << "The missing element having duplicate number in the array is : " << missingduplicate << endl;
    // }

    // vector<int> hrr;
    // hrr.push_back(1);
    // hrr.push_back(5);
    // hrr.push_back(3);
    // hrr.push_back(4);
    // hrr.push_back(6);

    // vector<int> irr;
    // irr.push_back(1);
    // irr.push_back(5);
    // irr.push_back(10);
    // irr.push_back(20);
    // irr.push_back(40);
    // irr.push_back(80);

    // vector<int> jrr;
    // jrr.push_back(6);
    // jrr.push_back(7);
    // jrr.push_back(20);
    // jrr.push_back(80);
    // jrr.push_back(100);

    // vector<int> krr;
    // krr.push_back(3);
    // krr.push_back(4);
    // krr.push_back(15);
    // krr.push_back(20);
    // krr.push_back(30);
    // krr.push_back(70);
    // krr.push_back(80);
    // krr.push_back(120);

    // vector<int> store = commonElementInSortedArrays(irr, jrr, krr);
    // cout << "Common Elements in the sorted arrays are : ";
    // printVector(store);

    // vector<vector<int>> lrr;
    // vector<int> sub1 = {1, 2, 3, 4};
    // vector<int> sub2 = {5, 6, 7, 8};
    // vector<int> sub3 = {9, 10, 11, 12};
    // lrr.push_back(sub1);
    // lrr.push_back(sub2);
    // lrr.push_back(sub3);
    // waveMatrix(lrr)
    // print2DVector(lrr);

    // vector<vector<int>> mrr;
    // vector<int> sub1 = {1, 2, 3};
    // vector<int> sub2 = {4, 5, 6};
    // vector<int> sub3 = {7, 8, 9};
    // vector<int> sub4 = {10, 11, 12};
    // mrr.push_back(sub1);
    // mrr.push_back(sub2);
    // mrr.push_back(sub3);
    // mrr.push_back(sub4);

    // vector<int> spiralmatrixAns = spiralMatrix(mrr);
    // printVector(spiralmatrixAns);

    // vector<int> arr;
    // vector<int> brr;
    // arr.push_back(9);
    // arr.push_back(5);
    // arr.push_back(4);
    // arr.push_back(9);

    // brr.push_back(2);
    // brr.push_back(1);
    // brr.push_back(4);

    // vector<int> sumAns = sumofTwoArrayStoredDigitbyDigit(arr, brr);
    // reverse(sumAns.begin(), sumAns.end());
    // int sizefinal = sumAns.size();
    // cout << "Sum of these vector is : ";
    // printVector(sumAns);

    // int n = 50;
    // vector<int> ans1 = factorialofaLargeNumber(n);
    // cout << "factorial of " << n << " is : ";
    // printVector(ans1);

    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(-5);
    v.push_back(-6);
    v.push_back(50);
    v.push_back(3);
    int k=4;
    double maxAnsSubArray=findMaxAverageSubArray(v,k);
    cout<<"Maximum Average subarray : "<<maxAnsSubArray;

    return 0;
}