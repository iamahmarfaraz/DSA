#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Cqueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Cqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if (empty())
        {
            front++;
            rear++;
            arr[rear] = data;
            return;
        }
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (rear == size - 1 && front != 0)
        {
            // Circular case
            rear = 0;
            arr[rear] = data;
            return;
        }
        // Normal Case
        rear++;
        arr[rear] = data;
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
            return;
        }

        arr[front] = -1;
        front++;
    }
    int Size()
    {
        if (empty())
        {
            return 0;
        }

        return (rear - front + 1);
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    int Front()
    {
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return INT_MIN;
        }
        return arr[front];
    }
    int back()
    {
        if (rear == -1)
        {
            return INT_MIN;
        }
        return arr[rear];
    }
    void print()
    {
        if (empty())
        {
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    Cqueue c(5);
    c.print();

    c.push(10);
    c.print();

    c.push(20);
    c.print();

    c.push(30);
    c.print();
    // cout<<c.Front()<<endl;
    // cout<<c.back()<<endl;

    c.push(40);
    c.print();

    c.push(50);
    c.print();

    c.push(60);

    cout << c.Front() << endl;
    cout << c.back() << endl;
    c.pop();
    c.print();
    c.pop();
    c.print();
    c.pop();
    c.print();

    c.push(60);
    c.print();

    c.push(70);
    c.print();

    c.push(80);
    c.print();

    c.push(90);
   // c.print();
    
    return 0;
}