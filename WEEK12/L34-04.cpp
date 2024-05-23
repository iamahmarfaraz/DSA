#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// DOUBLE ENDED QUEUE

class Dequeue
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
    void push_front(int data)
    {
        if (empty())
        {
            front++;
            rear++;
            arr[front] = data;
            return;
        }
        if (front == 0)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        front--;
        arr[front] = data;
    }
    void push_back(int data)
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
    void pop_front()
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

    void pop_back()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[rear] = -1;
        rear--;
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
    return 0;
}