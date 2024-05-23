#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int findlength(char ch[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {

        if (ch[i] == '\0')
        {
            // terminate the loop
            break;
        }
        else
        {
            count++;
        }
    }
    return count;
}
void reverseString(char ch[], int size)
{
    int start = 0;
    int end = (size - 1);
    while (start <= end)
    {
        swap(ch[start], ch[end]);
        start++;
        end--;
    }
}
void lowerToUpperCase(char ch[], int size)
{
    int lenght = findlength(ch, size);
    for (int i = 0; i < lenght; i++)
    {
        // check if the char at 'i' index is lower case
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            ch[i] = ch[i] - 'a' + 'A';
        }
    }
}
void upperToLowerCase(char ch[], int size)
{
    int lenght = findlength(ch, size);
    for (int i = 0; i < lenght; i++)
    {
        // check if the char at 'i' index is lower case
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            ch[i] = ch[i] - 'A' + 'a';
        }
    }
}
void conversionAtTheRateToSpace(char ch[], int size)
{
    int length = findlength(ch, size);
    for (int i = 0; i < length; i++)
    {
        if (ch[i] == '@')
        {
            ch[i] = ' ';
        }
    }
}
bool checkPalindrome(char ch[], int size)
{
    int length = findlength(ch, size);
    int start = 0;
    int end = length - 1;
    while (start <= end)
    {
        if (ch[start] == ch[end])
        {
            // Do Nothing
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // Char Array
    // char ch[10];
    // cin>>ch;
    // cout<<ch<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<"Character at index "<<i<<" : "<<ch[i]<<endl;
    // }
    // char temp=ch[5];
    // int value=(int)temp;
    // cout<<"ASCII Value of Null Character is : "<<value<<endl;

    char a[100];
    cin.getline(a, 100);
    cout << a << endl;
    // int length = findlength(a, 100);
    // cout << "The Length of the char array is : " << length<<endl;
    // cout << "The Length of the char array is : " << strlen(a)<<endl;
    // reverseString(a, length);
    // cout << "String after reverse :: " << a<<endl;
    // reverse(a, a + length);
    // cout<<a;

    // lowerToUpperCase(a, 100);
    // cout <<"upper case : "<< a << endl;
    // upperToLowerCase(a, 100);
    // cout <<"lower case : "<< a << endl;

    // conversionAtTheRateToSpace(a, 100);
    // cout << a << endl;
    int checkAnss = checkPalindrome(a, 100);
    if (checkAnss== 1)
    {
        cout << "Char array " << a << " is  palindrome" << endl;
    }
    else
    {
        cout << "Char array " << a << " isn't  palindrome" << endl;
    }

    return 0;
}