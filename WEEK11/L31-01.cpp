#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

// STACK USING STL

using namespace std;
int main()
{
    // Creation of stack
    stack<int>st;

    // Insertion
    st.push(10);
    st.push(20);
    st.push(30);
    // Size check
    cout<<"Size of Stack : "<<st.size()<<endl;
    // Removal
    st.pop();
    // st.pop();
    // st.pop();
    cout<<"Size of Stack after removal : "<<st.size()<<endl;
    if (st.empty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }

    cout<<"Element at the top of Stack : "<<st.top();
    
return 0;
}