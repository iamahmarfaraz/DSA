#include <iostream>
using namespace std;

int main()
{
    // ''
    int num1 = 5;
    int num2 = 10;
    int num22=10;
    cout << (num1 & num2) << endl;
    cout << (num1 | num2) << endl;
    // XOR OPERATOR
    int num3=5;
    int num4=-5;
    cout<< (num3 ^ num4)<<endl;
    // LEFT SHIFT OPERATOR
    cout<<(num2<<1)<<endl;
    // RIGHT SHIFT OPERATER
    cout<<(num1>>1)<<endl;

    // PRE & POST OPERATOR
    cout<<(--num2)*10<<endl;
    cout<<(num22--)*10<<endl;
}