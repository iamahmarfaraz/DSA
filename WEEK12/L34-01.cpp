#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(6);
    cout<<"Size of Queue : "<<q.size()<<endl;
    if (q.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    cout<<endl;

    q.pop();
    cout<<"Size of Queue : "<<q.size()<<endl;
    if (q.empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"First Element of the Queue : "<<q.front()<<endl;
    cout<<"Last Element of the Queue : "<<q.back()<<endl;
    
return 0;
}