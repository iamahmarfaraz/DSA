#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    vector<bool> prime(n, true);
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
        {
            count++;
            int j = 2 * i;
            while (j < n)
            {
                prime[j] = 0;
                j += i;
            }
        }
    }
    return count;
}
int hcf(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a == 0 ? b : a; // this will return 'b' if 'a' is 0 ,else it'll return 'a'
}

int fastexponentiation(int a,int b){
    int ans=1;
    while (b>0)
    {
        if (b & 1)
        {
            ans = ans*a;
        }
        a=a*a;
        b>>=1;  //b=b/2
        
    }
    return ans;
}

int main()
{
    // int n = 21;
    // int ans = countPrimes(n);
    // cout << "Number of prime between 1 to " << n << " is : " << ans << endl;

    // int ans1 = hcf(72, 24);
    // cout << ans1 << endl;

    int ans2=fastexponentiation(2,5);
    cout<<ans2<<endl;

    return 0;
}