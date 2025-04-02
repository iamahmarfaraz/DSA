#include <iostream>
using namespace std;
int main()
{
cout<<"AHMAR FARAZ"<<endl;
cout<<"MAHMNOOR BHUTTA"<<endl;
float num=1.77;
cout << num<<endl;

// size of num integer,how many byte this integer will occupy
cout<< sizeof(num) << endl;

// OPERATORS

// 1.Arithmetic
int a=45;
int b=55;
cout<<"Arithmetic Operators"<<endl;
cout << a+b << endl;
cout << a-b << endl;
cout << a*b << endl;
cout << b/a << endl;
cout << b%a << endl;

// 2.Relational
int c=10;
int d=5;
cout<<"Relational Operators"<<endl;
cout << (c < d) << endl;
cout << (c > d) << endl;
cout << (c <= d) << endl;
cout << (c >= d) << endl;
cout << (c != d) << endl;
cout << (c == d) << endl;

// 3.Logical
int age=19;
int car=1;
if(age>=18 && car>=1){
    cout<<"Get License"<<endl;
}

// Input in C++
int marks;
cout<<"Enter the Marks:"<<endl;
cin>>marks;
cout<<"marks="<<marks<<endl;
}