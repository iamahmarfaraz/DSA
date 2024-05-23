#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// STACK IMPLEMENTATION FROM SCRATCH

class stack
{
public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            this->arr[top] = data;
        }
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Can't pop,Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (this->top == -1)
        {
            return true;
        }
        return false;
    }

    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty so no top element" << endl;
            return -1;
        }
        else
        {
            return arr[this->top];
        }
    }

    int getSize()
    {
        return top + 1;
    }
};

int main()
{
    stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.getSize() << endl;
    cout << st.getTop() << endl;
    if (st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack isn't Empty" << endl;
    }
    cout<<"Top element before pop : "<<st.getTop()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout << "After Poping whole element" << endl;
    if (st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack isn't Empty" << endl;
    }
    cout<<"Top element after pop : "<<st.getTop()<<endl;
    return 0;
}