#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Q.NO-1  
string oddEven(int &n){
    return (n & 1) == 0 ? "Even" : "Odd";
}

int getIThBit(int &n,int &i){
    int mask = (1 << i);
    return (n&mask) == 0 ? 0:1;
}

int setIthBit(int &n, int &i){
    int mask = (1 << i);
    int ans = (n | mask);
    return ans;
}

int main()
{
    int n = 13;
    cout<<"ANSWER OF Q.NO-1 :- "<<oddEven(n)<<endl;

    int n1=10,i=3;
    cout<<"ANSWER OF Q.NO-2 :- "<<getIThBit(n1,i)<<endl;

    int n2=10,i2=2;
    cout<<"ANSWER OF Q.NO-4 :- "<<setIthBit(n2,i2)<<endl; 
    return 0;
}