#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack1 Overflow" << endl;
            return;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack2 Overflow" << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack1 Underflow" << endl;
            return;
        }
        else
        {
            arr[top1]=0;
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack2 Underflow" << endl;
            return;
        }
        else
        {
            arr[top2]=0;
            top2++;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack st(10);
    st.push1(10);
    st.push2(20);
    st.push1(30);
    st.push2(40);
    st.push1(50);
    st.push2(60);
    st.print();
    return 0;
}