#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// QUEUE IMPLEMENTATION

class queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    queue(int size)
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
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
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

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.print();

    cout << "First Element of the Queue : " << q.Front()<<endl;;
    cout << "Last Element of the Queue : " << q.back()<<endl;
    if (q.empty())
    {
        cout<<"Queue Empty"<<endl;
    }
    else{
        cout<<"Queue is not Empty"<<endl;
    }
    
    q.pop();
    q.print();
    cout << "First Element of the Queue : " << q.Front()<<endl;;
    cout << "Last Element of the Queue : " << q.back()<<endl;
    q.pop();
    q.print();
    q.pop();
    q.print();
    if (q.empty())
    {
        cout<<"Queue Empty"<<endl;
    }
    else{
        cout<<"Queue is not Empty"<<endl;
    }


    return 0;
}