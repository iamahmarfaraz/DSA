#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<stack>
using namespace std;

bool isValidParanthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            // for Open Bracket -> just push
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                if (ch == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool redundentBracket(string &s){
    stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch=s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int count = 0;
            while (!st.empty() && st.top()!='(')
            {
                char temp=st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    count++;
                }
                st.pop();
            }
            st.pop();
            if (count == 0)
            {
                return true;
            } 
        }
    }
    return false;
}

int main()
{
    // string s="()[]{}";
    // if (isValidParanthesis(s))
    // {
    //     cout<<"Valid Parenthesis"<<endl;
    // }
    // else{
    //     cout<<"Not Valid Parenthesis"<<endl;
    // }

    string t="(a+(b*c))";
    bool ans=redundentBracket(t);
    if (ans==true)
    {
        cout<<"Redundent Bracket is present"<<endl;
    }
    else{
        cout<<"Redundent Bracket is not present"<<endl;
    }
    
    
    return 0;
}