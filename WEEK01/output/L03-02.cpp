#include<iostream>
using namespace std;
    // FOR-LOOP
    void nameprint(){
        for (int i = 0; i <=10; i++)
        {
            cout<<"AHMAR FARAZ"<<endl;
        }
        
    }

void tableprint(){
    for (int i = 1; i <=10; i++)
{
    cout<<"19 x "<<i<<"="<<19*i<<endl;
}
}

void even(){
    for (int i = 1; i <=100; i++)
    {
        if (i%2==0)
        {
            cout<<i<<endl;
        }
        
    }
    
}


int main(){

    for (int i = 0; i < 10; i++)
    {
        cout<<"Mahnoor cutiee"<<endl;
    }
    for (int i = 1; i <=10; i++)
    {
        cout<<i<<endl;
    }
    cout<<endl;
    for (int i = 10; i <=0; i--)
    {
        cout<<i<<endl;
    }
    // NESTED LOOP
    for (int i = 0; i < 3; i++)
    {
        cout<<"Outer Loop "<<i;
        for (int j = 0; j < 3; j++)
        {
            cout<<" Inner Loop "<<j;
        }
        cout<<endl;
    }

    nameprint();
    tableprint();
    even();
    
}