#include <iostream>
using namespace std;

int main()
{
    // BREAK KEYWORD
    for (int i = 0; i < 5; i++)
    {
        if (i==3)
        {
            break;
        }
        
        cout<<i+1<<endl;
    }
    // CONTINUE KEYWORD
    for (int i = 0; i <= 5; i++)
    {
        if (i==3)
        {
            continue;
        }
        cout<<i+1<<endl;
    }

    // LOCAL VARIABLE
    for (int i = 0; i < 6; i++)
    {
        int a=5;
    }

    // GLOBAL VARIABLE
    int g1=4;
    
    
}
