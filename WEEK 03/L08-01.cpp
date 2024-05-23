#include<iostream>
using namespace std;
// CALL BY VALUE
void solve(int jaadu){
    jaadu--;
    cout<<jaadu+10<<endl;
}

// CALL BY REFERENCE
void refrence(int &a){
    a++;
    cout<<a<<endl;
}
int main()
{
    int sundari=100;
    sundari--;
    solve(sundari);
    cout<<sundari<<endl;
    int a=5;
    refrence(a);
    cout<<a<<endl;
return 0;
}