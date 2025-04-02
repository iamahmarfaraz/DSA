#include <iostream>
using namespace std;
// Debug the code. Take input a character, print 1,
// if its a capital alphabet, print 0, if its a lowercase alphabet, else print -1.
// #include<iostream>
// using namespace std;

// int main() {
// 	char c;
//     cin>>c;
//     if('a'<=c || c<= 'z'){
//         cout<<0;
//     }
// 	else if('A'<=c || c<= 'Z'){
//         cout<<1;
//     }
//     else{
//         cout<<-1;
//     }
// }

// SOLUTION
int main()
{
    char c;
    cout<<"ENTER A CHARACTER: ";
    cin >> c;
    if (c >= 'a' && c <= 'z')
    {
        cout << "0";
    }
    else if (c >= 'A' && c <= 'Z')
    {
        cout << "1";
    }
    else
    {
        cout << "-1";
    }
}