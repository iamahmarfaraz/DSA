#include <iostream>
using namespace std;
int main()
{
    // Patterns Q1- Solid Square Pattern
    int size;
    cout << "Enter the side of square= " << endl;
    cin >> size;
    cout << "SOLID SQUARE PATTERN" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << "*";
        }
        cout << "" << endl;
    }

    // Patterns Q2- Hollow Square Pattern
    cout << "HOLLOW SQUARE PATTERN" << endl;
    for (int k = 0; k < size; k++)
    {
        for (int l = 0; l < size; l++)
        {
            if (k == 0 || k == size - 1 || l == 0 || l == size - 1)
            // "K==0" will print stars in 1st row
            // "K==size-1" will print the last row
            // "l==0" will print stars in first column
            // "l==size-1" will print stars in last column
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Patterns Q3- Hollow Inverted Half Pyramid Pattern
    cout<<"HOLLOW INVERTED HALF PYRAMID"<<endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==0 || j==0 || j==size-1-i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // Patterns Q4- Hollow Inverted Half Pyramid Pattern
    cout<<"HOLLOW INVERTED HALF PYRAMID"<<endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==0 || j==0 || j==size-1-i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    // Patterns Q5- Hollow Full Pyramid Pattern
    cout<<"FULL PYRAMID"<<endl;
    for (int i = 0; i < size; i++)
    {
        int k=0;
        for (int j = 0; j < ((2*size)-1); j++)
        {
            if (j<size-1-i)
            {
                cout<<" ";
            }
            else if (k<(2*i)+1)
            {
                if(k==0||k==2*i||i==size-1){
                cout<<"*";
                }
                else{
                    cout<<" ";
                }
                k++;
            }
            else{
                cout<<" ";
            }
            
            
        }
        cout<<endl;
    }
    
}